#include"part2.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int findVarDHelper(char*name,struct Scope currentScope,struct VariableEntry*ve);
void initFactor(struct Factor*node,struct Scope currentScope)
{
	switch(node->rule)
	{
		case (Factor_Rule_1):
		{
			node->typeInfo.type = DataType_Int;
			return;
		}
		case (Factor_Rule_2):
		{
			node->typeInfo.type = DataType_String;
			return;
		}
		case (Factor_Rule_3):
		{
			struct Expression *expr = node->production.expr;
			node->typeInfo = expr->typeInfo;
			return;
		}
		case (Factor_Rule_4):
		{
			struct Lvalue *lval = node->production.factor_4_5.lvalue;
			char *id = node->production.factor_4_5.Identifier;
			if(lval->typeInfo.type != DataType_UserDefined)
			{
				kprintf("initTypeFactorRule_4 Lval must be of Userdefined type\n");
				fprintf(stderr,"Error %d: Variable not defined in correct scope\n", 5);
				return;
			} 
			struct VariableEntry ve;
			int isFound = checkClassVarAccess(lval->typeInfo.className,id,&ve);
			if(isFound)
			{
				node->typeInfo.type = ve.type;
				strcpy(node->typeInfo.className,ve.className);
				kprintf("in initTypeFactorRule_4 Accessing variable name %s type %s\n",id,ve.className);
				return;
			}
			else
			{
				kprintf("initTypeFactorRule_4 varD %s not found in class %s\n",id,lval->typeInfo.className);
				return;

			}
			return;
		}
		case (Factor_Rule_5):
		{

			struct Lvalue *lval = node->production.factor_4_5.lvalue;
			char *id = node->production.factor_4_5.Identifier;
			if(lval->typeInfo.type != DataType_UserDefined)
			{
				kprintf("initTypeFactorRule_5 Lval must be of Userdefined type\n");
				fprintf(stderr,"Error %d: Method not defined in current scope\n", 5);
				return;
			}
			struct MethodEntry me;
			me.paramCount = 0;
			me.entryScope.depth = 1;
			strcpy(me.entryScope.className,lval->typeInfo.className);
			me.entryScope.methodName[0]= '\0';
			if(!findMethodDInScope(id,&me,1))
			{
				fprintf(stderr,"Error %d: Method  arg and param don't match\n",4);
				return;
			}
			node->typeInfo.type = me.returnType;
			node->typeInfo.className[0] ='\0';
			kprintf("initTypeFactorRule_5 method %s in class %s return type %d is called\n",id,lval->typeInfo.className,me.returnType);
			return;
		}
		case (Factor_Rule_6):
		{
			struct Lvalue *lval = node->production.factor_6.lvalue;
			struct Expression *expr =node->production.factor_6.expr; 
			struct OptExpression *optExpr =node->production.factor_6.optExpr; 
			char*id =node->production.factor_6.Identifier; 
			if(lval->typeInfo.type != DataType_UserDefined)
			{
				kprintf("initTypeFactorRule_6 Lval must be of Userdefined type\n");
				fprintf(stderr,"Error %d: Method not defined in current scope\n", 5);
				return;
			}
			struct MethodEntry me;
			me.paramCount = 1+(optExpr?optExpr->argCount:0);
			int i=0;
			me.params[i++] = expr->typeInfo.type;
			for(;optExpr&&i<me.paramCount;++i)
			{
				me.params[i]= optExpr->argList[i-1].type;
			}
			me.entryScope.depth = 1;
			strcpy(me.entryScope.className,lval->typeInfo.className);
			me.entryScope.methodName[0]= '\0';
			if(!findMethodDInScope(id,&me,1))
			{
				kprintf("initTypeFactorRule_6 method %s mismatch\n",id);
				fprintf(stderr,"Error %d: Method  arg and param don't match\n",4);
				return;
			}
			node->typeInfo.type = me.returnType;
			node->typeInfo.className[0] ='\0';
			kprintf("initTypeFactorRule_6 method %s in class %s return type %d is called\n",id,lval->typeInfo.className,me.returnType);
			return;
		}
		case (Factor_Rule_7):
		{
			struct VariableEntry ve;
			if(findVarDHelper(node->production.Identifier,currentScope,&ve) == 0)
			{
				kprintf("initTypeFactorRule_7 varD not found for %s\n",node->production.Identifier);
				return;
			}
			node->typeInfo.type = ve.type;
			strcpy(node->typeInfo.className,ve.className);
			return;
		}
		case(Factor_Rule_8):
		{
			struct MethodEntry me;
			struct Expression *expr =node->production.factor_8.expr; 
			struct OptExpression *optExpr =node->production.factor_8.optExpr; 
			char *id = node->production.Identifier;
			me.entryScope.depth = 1;
			strcpy(me.entryScope.className,currentScope.className);
			me.entryScope.methodName[0] = '\0';
			me.paramCount = 1+(optExpr?optExpr->argCount:0);
			me.params[0] = expr->typeInfo.type;
			int i =1;
			for(;optExpr && i<me.paramCount;++i)
			{
				me.params[i] = optExpr->argList[i-1].type;
			}
			if(findMethodDInScope(id,&me,1) == 0)
			{
				kprintf("initTypeFactorRule_8 method %s mismatch argCount %d\n",id);
				fprintf(stderr,"Error %d: Method arg and param don't match\n",4);
				return;
			}
			node->typeInfo.type = me.returnType;
			node->typeInfo.className[0] ='\0';
			kprintf("initTypeFactorRule_8 method %s in class %s return type %d is called\n",id,currentScope.className,me.returnType);
			return;
		}
		case (Factor_Rule_9):
		{
			char*id =node->production.Identifier; 
			struct MethodEntry me;
			me.paramCount = 0;
			me.entryScope.depth = 1;
			strcpy(me.entryScope.className,currentScope.className);
			me.entryScope.methodName[0]= '\0';
			if(!findMethodDInScope(id,&me,1))
			{
				fprintf(stderr,"Error %d: Method arg and param don't match\n",4);
				return;
			}
			node->typeInfo.type = me.returnType;
			node->typeInfo.className[0] ='\0';
			kprintf("initTypeFactorRule_9 method %s in class %s return type %d is called\n",id,currentScope.className,me.returnType);
			return;
		}
		default:
		{
			kprintf("Unknown rule %d in initializeTypeFactor\n",node->rule);
			return;
		}
	}
}
/*
 * Checks whethere there is a variable defined within in a class or not
 * and if it is then updates variable entry.
 */
int checkClassVarAccess(char*className,char*varName,struct VariableEntry*ve)
{
	struct Scope desiredScope;
	desiredScope.depth  = 1;
	desiredScope.methodName[0] = '\0';
	strcpy(desiredScope.className,className);
	return findVarDHelper(varName,desiredScope,ve);
}
int findVarDHelper(char*name,struct Scope currentScope,struct VariableEntry*ve)
{
	int defCount = findVarDInScope(name,currentScope,ve);
	if(0 == defCount)
	{
		kprintf("VarD not found for %s in class %s in method %s\n",name,currentScope.className,currentScope.methodName);
		fprintf(stderr,"Error %d: Variable not defined in correct scope\n", 5);
		return 0;
	}
	if(1 < defCount)
	{
		kprintf("Multiple VarD for %s in class %s in method %s\n",name,currentScope.className,currentScope.methodName);
		return 0;
	}
	return 1;
}
/*int checkClassMethodAccess(char*className,char*methodName,struct MethodEntry*me)
{
	struct Scope desiredScope;
	desiredScope.depth =1 ;
	desiredScope.methodName[0]='\0';
	strcpy(desiredScope.className,className);
	findMethodDHelper(methodName,&desiredScope,me);
}*/
