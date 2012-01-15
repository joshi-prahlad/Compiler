#include"part2.h"
#include<stdlib.h>
#include<stdio.h>


void checkStatement(void *node,int nodeType,struct Scope currentScope)
{
	if(Node_Statement != nodeType)
	{
		return;
	}
	struct Statement *stmt = (struct Statement*)node;
	switch(stmt->rule)
	{
		case(Statement_Rule_4):
		{
			struct Expression*expr =stmt->production.stmt_4.expr;
			struct OptExpression*optExpr = stmt->production.stmt_4.optExpr;
			int isBasic =1,isSame =1;
			if( !isBasicType(expr->typeInfo.type))
			{
				isBasic = 0;
				kprintf("Node_Statement_Rule_4 type is not basic type\n");
			}
			int i =0;
			int oneType = expr->typeInfo.type;
			for(;optExpr && i< optExpr->argCount;++i)
			{
				if(oneType != optExpr->argList[i].type)
				{
					isSame = 0;
				kprintf("Node_Statement_Rule_4 type is not of same type\n");
				}
				if(!isBasicType(optExpr->argList[i].type))
				{
					isBasic = 0;
				kprintf("Node_Statement_Rule_4 type is not basic type\n");
				}

			}
			/*if(!isSame)
			{
				fprintf(stderr,"Error %d: all the arguments of println must be of same type\n",1);
			}*/
			if(!isBasic)
			{
				fprintf(stderr,"Error %d: all the arguments of println must be of basic type\n",1);
			}
			return;
		}
		case(Statement_Rule_5):
		{
			struct Lvalue*lval = stmt->production.stmt_5.lvalue;
			char*id = stmt->production.stmt_5.Identifier;
			struct Expression*expr = stmt->production.stmt_5.expr;
			struct VariableEntry ve;
			if(checkClassVarAccess(lval->typeInfo.className,id,&ve))
			{
				if(ve.type != expr->typeInfo.type || strcmp(ve.className,expr->typeInfo.className) !=0)
				{
					fprintf(stderr,"Error %d: types mismatch for = op\n",2);
					kprintf("Error in Statement_Rule_5\n");
					return;
				}
			}
			return;
		}
		case(Statement_Rule_6):
		{
			char*id = stmt->production.stmt_6_7.Identifier;
			struct Expression*expr = stmt->production.stmt_6_7.expr;
			struct VariableEntry ve;
			if(findVarDHelper(id,currentScope,&ve))
			{
				if(ve.type != expr->typeInfo.type || strcmp(ve.className,expr->typeInfo.className) !=0)
				{
					fprintf(stderr,"Error %d: types mismatch for = op\n",2);
					kprintf("Error in Statement_Rule_6\n");
					return;
				}
			}
			return;
		}
		case(Statement_Rule_7):
		{
			char*id = stmt->production.stmt_6_7.Identifier;
			struct Expression*expr = stmt->production.stmt_6_7.expr;
			if(!findClass(id))
			{
				fprintf(stderr,"Error %d: no class def found\n",5);
				kprintf("Class %s not found\n",id);
			}
			if( 0!= strcmp(id,expr->typeInfo.className))
			{

				fprintf(stderr,"Error %d: types mismatch for = op\n",2);
				kprintf("Error in Statement_Rule_7\n");
			}
			return;
		}
		case(Statement_Rule_8):
		{
			struct Expression*expr = stmt->production.stmt_8;
			if(expr->typeInfo.type != currentScope.returnType)
			{
				fprintf(stderr,"Error %d: Method return type mismatch\n",3);
			}
			return;
		}
		case(Statement_Rule_9):
		{
			struct Lvalue*lval = stmt->production.stmt_9.lvalue;
			char*id = stmt->production.stmt_9.Identifier;
			struct Expression*expr = stmt->production.stmt_9.expr;
			struct OptExpression*optExpr = stmt->production.stmt_9.optExpr;
			if(lval->typeInfo.type != DataType_UserDefined)
			{
				kprintf("checkStatement_9 Lval must be of Userdefined type\n");
				fprintf(stderr,"Error %d: Method not defined in current scope\n", 5);
				return;
			}
			struct MethodEntry me;
			me.entryScope.depth = 1;
			strcpy(me.entryScope.className,lval->typeInfo.className);
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
				kprintf("checkStatement_9 method %s mismatch argCount %d\n",id);
				fprintf(stderr,"Error %d: Method  arg and param don't match\n",4);
			}
			return;
		}
		case(Statement_Rule_10):
		{
			struct Lvalue*lval = stmt->production.stmt_10.lvalue;
			char*id = stmt->production.stmt_10.Identifier;
			if(lval->typeInfo.type != DataType_UserDefined)
			{
				kprintf("checkStatement_10 Lval must be of Userdefined type\n");
				fprintf(stderr,"Error %d: Method not defined in current scope\n", 5);
				return;
			}
			struct MethodEntry me;
			me.entryScope.depth = 1;
			strcpy(me.entryScope.className,lval->typeInfo.className);
			me.entryScope.methodName[0] = '\0';
			me.paramCount = 0;
			if(findMethodDInScope(id,&me,1) == 0)
			{
				kprintf("checkStatement_10 method %s mismatch argCount %d\n",id);
				fprintf(stderr,"Error %d: Method  arg and param don't match\n",4);
			}
			return;
		}
		case(Statement_Rule_11):
		{
			char*id = stmt->production.stmt_11.Identifier;	
			struct Expression*expr = stmt->production.stmt_11.expr;	
			struct OptExpression*optExpr = stmt->production.stmt_11.optExpr;	
			struct MethodEntry me;
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
				kprintf("StatementRule11 method %s mismatch argCount %d\n",id);
				fprintf(stderr,"Error %d: Method arg and param don't match\n",4);
			}
			return;
		}
		case(Statement_Rule_12):
		{
			char *id = stmt->production.Identifier;
			struct MethodEntry me;
			me.paramCount = 0;
			me.entryScope.depth = 1;
			strcpy(me.entryScope.className,currentScope.className);
			me.entryScope.methodName[0]= '\0';
			if(!findMethodDInScope(id,&me,1))
			{
				fprintf(stderr,"Error %d: Method arg and param don't match\n",4);
			}
			return;
		}
		return;	
	}
}
