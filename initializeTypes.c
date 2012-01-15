#include"part2.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void initFactor(struct Factor*node,struct Scope currentScope);

void initializeTypes(void *node,int nodeType,struct Scope currentScope)
{
	switch(nodeType)
	{
		case(Node_Lvalue):
		{
			struct Lvalue *lval = (struct Lvalue*)node;
			switch(lval->rule)
			{
				case(Lvalue_Rule_1):
				{
					//Identifier might represent a class name in this case.
					int defCount = findClass(lval->production.Identifier);
					if(1<defCount)
					{
						kprintf("multiple declarations for Class %s \n",lval->production.Identifier);
						return;
					}
					if(defCount == 0)
					{
						//Or it might be a variable of a user defined type.
						struct VariableEntry ve;
						int isFound = findVarDHelper(lval->production.Identifier,currentScope,&ve);
						if(!isFound)
						{
							kprintf("Neither class nor variable definition found for %s\n",lval->production.Identifier);
							fprintf(stderr,"Error %d: Variable not defined in correct scope\n", 5);
							return;
						}
						if(DataType_UserDefined != ve.type)
						{

							kprintf("initializeTypeLvalRule1 variable %s must of class type\n",lval->production.Identifier);
							fprintf(stderr,"Error %d: Variable not defined in correct scope\n", 5);
							return;
						}
						lval->typeInfo.type = DataType_UserDefined;
						strcpy(lval->typeInfo.className,ve.className);
						return;
					}
					//Identifier is a class name.	
					lval->typeInfo.type = DataType_UserDefined;
					strcpy(lval->typeInfo.className,lval->production.Identifier);
					return;
				}
				case(Lvalue_Rule_2):
				{
					//Accessing an instance variable.
					kprintf("In initializeTypes Lvalue_Rule_2\n");
					struct Lvalue *childLvalue = lval->production.lvalue_2.lvalue;
					char* id = lval->production.lvalue_2.Identifier;
					if(childLvalue->typeInfo.type != DataType_UserDefined)
					{
						kprintf("initializeTypeLvalRul2 childLval must be of Userdefined type\n");
						fprintf(stderr,"Error %d: Variable not defined in correct scope\n", 5);
						return;
					} 
					struct VariableEntry ve;
					int isFound = checkClassVarAccess(childLvalue->typeInfo.className,id,&ve);
					if(isFound)
					{
						lval->typeInfo.type = ve.type;
						strcpy(lval->typeInfo.className,ve.className);
						kprintf("in initializeTypesLvalueRule_2 Accessing variable name %s type %s\n",id,ve.className);
						return;
					}
					else
					{
						kprintf("initializeTypeLvalRule2 varD %s not found in class %s\n",childLvalue->typeInfo.className);
						return;

					}
					return;
				}
				case(Lvalue_Rule_3):
				case(Lvalue_Rule_4):
				{

					//Calling constructor of the class,Identifier must represent a class name in this case.
					int defCount = findClass(lval->production.Identifier);
					if(1<defCount)
					{
						kprintf("initializeTypeLvalRule3_4 multiple declarations for Class %s \n",lval->production.Identifier);
						return;
					}
					if(defCount == 0)
					{
						kprintf("initializeTypeLvalRule3_4 no def for class %s\n",lval->production.Identifier);
						fprintf(stderr,"Error %d: Variable not defined in correct scope\n", 5);
						return;
					}

					//Identifier is a class name.	
					lval->typeInfo.type = DataType_UserDefined;
					strcpy(lval->typeInfo.className,lval->production.Identifier);
					return;
				}
				default:
				{
					kprintf("Unknown rule %d in initializeTypeLval\n",lval->rule);
					return;
				}
			}
			return;
		}
		case (Node_Factor):
		{
			struct Factor *fac = (struct Factor*)node;
			initFactor(fac,currentScope);
			return;
		}
		case(Node_Term):
		{
			struct Term *term =(struct Term*) node;
			switch(term->rule)
			{
				case(Term_Rule_1):
				{
					struct Term*childTerm = term->production.term_1.term;
					struct Factor*fac = term->production.term_1.factor;
					if(-1 == childTerm->typeInfo.type || -1 == fac->typeInfo.type)
					{
						/*At least type for one of the child is not initialized.
						 * So the error like variable declaration not found 
						 * would have got printed already
						 */
						kprintf("ERROR unitialized types at Node_Term_Rule_1 in initializeTypes\n");
						return;
					}
					int isOK = 1;
					if(!isEqualVarInfoType(&(childTerm->typeInfo),&(fac->typeInfo)))
					{
						isOK =0;
						kprintf("Type mismatch in Node_Term_Rule_1 childTerm %d fac %d\n",childTerm->typeInfo.type,fac->typeInfo.type);
						fprintf(stderr,"Error %d: both the operands of * must be of same type\n",1);
					}
					if(!isBasicType(childTerm->typeInfo.type)||!isBasicType(fac->typeInfo.type))
					{
						isOK =0;
						kprintf("Node_Term_Rule_1 type is not basic type\n");
						fprintf(stderr,"Error %d: both the operands of * must be of basic type\n",1);
					}
					if(isOK)
					{
						term->typeInfo = childTerm->typeInfo;
					}
					return;
				}
				case(Term_Rule_2):
				{
					struct Factor *fac = term->production.factor;
					term->typeInfo = fac->typeInfo;
					return;
				}
				default:
				{
					kprintf("Unknown rule %d in initiTypeNodeTerm\n",term->rule);
					return;
				}
			}
			return;
		}
		case(Node_Expression):
		{
			struct Expression*expr = (struct Expression*)node;
			switch(expr->rule)
			{
				case(Expression_Rule_1):
				case(Expression_Rule_2):
				{
					struct Expression* childExpr = expr->production.expr_1_2.expr;
					struct Term* childTerm = expr->production.expr_1_2.term;
					if(-1 == childExpr->typeInfo.type || -1 == childTerm->typeInfo.type)
					{
						/*At least type for one of the child is not initialized.
						 * So the error like variable declaration not found 
						 * would have got printed already
						 */
						kprintf("ERROR unitialized types at Node_Expression in initializeTypes\n");
						return;
					}
					int isOK =1;
					if(!isEqualVarInfoType(&(childExpr->typeInfo),&(childTerm->typeInfo)))
					{
						isOK = 0;
						kprintf("Type mismatch Node_Expr_Rule_1 childExpr %d childTerm %d\n",childExpr->typeInfo.type,childTerm->typeInfo.type);
						fprintf(stderr,"Error %d: both the operands of +/- must be of same type\n",1);
					}
					if(!isBasicType(childTerm->typeInfo.type)||!isBasicType(childExpr->typeInfo.type))
					{
						isOK =0;
						kprintf("NodeExpressionRule_1_2 type is not basic type\n");
						fprintf(stderr,"Error %d: both the operands of +/- must be of basic type\n",1);
					}
					if(isOK)
					{
						expr->typeInfo = childTerm->typeInfo;
					}
					return;
				}
				case(Expression_Rule_3):
				{
					struct Term*term = expr->production.term;
					expr->typeInfo = term->typeInfo;
					return;
				}
				default:
				{
					kprintf("Unknown rule %d in inittypeNodeExpression\n",expr->rule);
					return;
				}
				return;
			}
			return;
		}
		case(Node_OptExpression):
		{
			struct OptExpression*oe = (struct OptExpression *)node;
			struct OptExpression*childOptExpr = oe->optExpr;
			struct Expression*expr = oe->expr;
			int i =0;
			for(;childOptExpr&& i<childOptExpr->argCount;++i)
			{
				oe->argList[i]=childOptExpr->argList[i];
			}
			oe->argList[i] =expr->typeInfo;
			oe->argCount = i+1;
			return;
		}
		
	}
}

int isEqualVarInfoType(struct VarTypeInfo *one,struct VarTypeInfo *two)
{
	return ( (0 == strcmp(one->className,two->className)) && (one->type == two->type));
}
int isBasicType(int type)
{
	return (DataType_String == type || DataType_Int == type || -1 == type);
}
