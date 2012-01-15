#include<stdio.h>
#include<string.h>
#include"part2.h"

void resetScope(struct Scope *currentScope)
{
	currentScope->methodName[0] ='\0';
	currentScope->className[0] ='\0';
	currentScope->depth = 0;
	currentScope->returnType = -1;
	currentScope->conditionScope = ConditionTypeUninit;
	currentScope->condLineNumber = UninitLineNumber;
	currentScope->methodLineNumber = UninitLineNumber;
	currentScope->paramCount = -1;
}
/**
 * Given the root node of the AST 
 * the below method traverses the tree in
 * depth first order.
 */

void dfsAST(void *node,int nodeType,struct Scope currentScope,void(*func)(void*,int,struct Scope))
{
	if(!node)
	{
		return ;
	}
	//kprintf("NodeType %d\n",nodeType);
	switch(nodeType)
	{
		case Node_Goal:
		{
			struct Goal*goal = (struct Goal*)node;
			resetScope(&currentScope);
			dfsAST(goal->classDeclaration,Node_ClassDeclaration,currentScope,func);
			dfsAST(goal->goal,Node_Goal,currentScope,func);
			break;
		}
		case Node_ClassDeclaration:
		{
			struct ClassDeclaration*cd = (struct ClassDeclaration*)node;
			if(currentScope.depth != 0)
			{
				kprintf("Invalid depth %d in Node_Classdeclaration\n",currentScope.depth);
				break;
			}
			struct Scope childScope ;
			childScope = currentScope;
			childScope.methodName[0] ='\0';
			strcpy(childScope.className,cd->Identifier);
			childScope.depth = currentScope.depth + 1;
			dfsAST(cd->classBody,Node_ClassBody,childScope,func);
			break;
		}
		case Node_ClassBody:
		{
			struct ClassBody*bd =(struct ClassBody*)node;
			if(bd->rule == ClassBody_Rule_1 )
			{
				dfsAST(bd->production.cb_1.varD,Node_VarDeclaration,currentScope,func);
				dfsAST(bd->production.cb_1.classBody,Node_ClassBody,currentScope,func);
				break;
			}
			if(bd->rule == ClassBody_Rule_2)
			{
				dfsAST(bd->production.mdl,Node_MethodDeclarationList,currentScope,func);
				break;
			}
			kprintf("Error in ClassBody node doesn;t have a valid rule type\n");
			break;
		}
		case Node_MethodDeclarationList:
		{
			struct MethodDeclarationList*mdl= (struct MethodDeclarationList*)node;
			dfsAST(mdl->md,Node_MethodDeclaration,currentScope,func);
			dfsAST(mdl->mdl,Node_MethodDeclarationList,currentScope,func);
			break;
		}
		case Node_MethodDeclaration:
		{
			struct MethodDeclaration*md = (struct MethodDeclaration*)node;
			if(currentScope.depth != 1)
			{
				kprintf("Invalid depth %d in Node_MethodDeclaration\n",currentScope.depth);
				break;
			}
			currentScope.methodLineNumber = md->lineNumber;
			struct Scope childScope = currentScope;
			strcpy(childScope.methodName,md->Identifier);
			childScope.depth = currentScope.depth + 1;
			childScope.returnType = md->type;
			childScope.paramCount = md->param?(md->param)->paramCount:0;
			int i =0;
			for(i=0;i<childScope.paramCount;++i)
			{
				childScope.params[i] = md->param->params[i].dataType;
			}
			dfsAST(md->param,Node_Parameters,childScope,func);
			dfsAST(md->methodBody,Node_MethodBody,childScope,func);
			break;
		}
		case Node_MethodBody:
		{
			struct MethodBody *mb = (struct MethodBody*)node;
			if(MethodBody_Rule_1 == mb->rule)
			{
				dfsAST(mb->production.mb_1.varD,Node_VarDeclaration,currentScope,func);
				dfsAST(mb->production.mb_1.methodBody,Node_MethodBody,currentScope,func);
				break;
			}
			if(MethodBody_Rule_2 == mb->rule)
			{
				dfsAST(mb->production.stmtList,Node_StatementList,currentScope,func);
				break;
			}
			kprintf("Unable to recognise rule %d in NodeMethodBody\n",mb->rule);
			break;

		}
		case Node_StatementList:
		{
			struct StatementList *sl =(struct StatementList*)node;
			dfsAST(sl->stmt,Node_Statement,currentScope,func);
			dfsAST(sl->stmtList,Node_StatementList,currentScope,func);
			break;
		}
		case Node_VarDeclaration:
		{
			struct VarDeclaration*vd  = (struct VarDeclaration*)node;
			if(VarDeclaration_Rule_1 == vd->rule)
			{

				break;
			}
			if(VarDeclaration_Rule_2 == vd->rule)
			{
				break;
			}
			kprintf("Unable to recognise rule %d in NodeVarDecl\n",vd->rule);
			break;
		}
		case Node_Parameters:
		{
			struct Parameters *param = (struct Parameters*)node;
			dfsAST(param->paramList,Node_ParameterList,currentScope,func);
			break;
		}
		case Node_ParameterList:
		{
			struct ParameterList *pl =(struct ParameterList*)node;
			dfsAST(pl->paramList,Node_ParameterList,currentScope,func);
			break;
		}
		case Node_Statement:
		{
			struct Statement*st =(struct Statement*)node;
			switch(st->rule)
			{
				case(Statement_Rule_1):
				{
					dfsAST(st->production.stmtList,Node_StatementList,currentScope,func);
					break;
				}
				case(Statement_Rule_2):
				{
					struct Scope childScope = currentScope;
					childScope.conditionScope = ConditionTypeIf;
					childScope.condLineNumber = st->firstLineNum;

					dfsAST(st->production.stmt_2.cond,Node_Condition,childScope,func);	
					dfsAST(st->production.stmt_2.stmt1,Node_Statement,childScope,func);
					dfsAST(st->production.stmt_2.stmt2,Node_Statement,childScope,func);
					break;
				}
				case(Statement_Rule_3):
				{
					struct Scope childScope = currentScope;
					childScope.conditionScope = ConditionTypeWhile;
					childScope.condLineNumber = st->firstLineNum;

					dfsAST(st->production.stmt_3.cond,Node_Condition,childScope,func);
					dfsAST(st->production.stmt_3.stmt,Node_Statement,childScope,func);
					break;
				}
				case(Statement_Rule_4):
				{
					dfsAST(st->production.stmt_4.expr,Node_Expression,currentScope,func);
					dfsAST(st->production.stmt_4.optExpr,Node_OptExpression,currentScope,func);
					break;
				}
				case(Statement_Rule_5):
				{
					dfsAST(st->production.stmt_5.lvalue,Node_Lvalue,currentScope,func);
					dfsAST(st->production.stmt_5.expr,Node_Expression,currentScope,func);
					break;
				}
				case(Statement_Rule_6):
				case(Statement_Rule_7):
				{
					dfsAST(st->production.stmt_6_7.expr,Node_Expression,currentScope,func);
					break;
				}
				case(Statement_Rule_8):
				{
					dfsAST(st->production.stmt_8,Node_Expression,currentScope,func);
					break;
				}
				case(Statement_Rule_9):
				{
					dfsAST(st->production.stmt_9.lvalue,Node_Lvalue,currentScope,func);	
					dfsAST(st->production.stmt_9.expr,Node_Expression,currentScope,func);	
					dfsAST(st->production.stmt_9.optExpr,Node_OptExpression,currentScope,func);	
					break;
				}
				case(Statement_Rule_10):
				{
					dfsAST(st->production.stmt_10.lvalue,Node_Lvalue,currentScope,func);
					break;
				}
				case(Statement_Rule_11):
				{
					dfsAST(st->production.stmt_11.expr,Node_Expression,currentScope,func);
					dfsAST(st->production.stmt_11.optExpr,Node_OptExpression,currentScope,func);
					break;
				}
				case(Statement_Rule_12):
				{
					break;
				}
				default:
				{
					kprintf("Unable to match rule for Statement %d\n",st->rule);
					break;
				}
			}	
			break;
		}
		case(Node_Condition):
		{
			struct Condition* cond = (struct Condition*)node;
			dfsAST(cond->expr1,Node_Expression,currentScope,func);
			dfsAST(cond->expr2,Node_Expression,currentScope,func);
			break;
		}
		case(Node_Expression):
		{
			struct Expression*expr = (struct Expression*)node;
			//kprintf("Type is %d Rule %d Id %d\n",expr->nodeType,expr->rule,expr->nodeId);
			if(Expression_Rule_1 == expr->rule || Expression_Rule_2 == expr->rule)
			{
				dfsAST(expr->production.expr_1_2.expr,Node_Expression,currentScope,func);
				dfsAST(expr->production.expr_1_2.term,Node_Term,currentScope,func);
				break;
			}
			if(Expression_Rule_3 == expr->rule)
			{
				dfsAST(expr->production.term,Node_Term,currentScope,func);
				break;
			}
			kprintf("Unrecognised rule no %d in Expression\n",expr->rule);
			break;
		}
		case(Node_Term):
		{
			struct Term*term = (struct Term*)node;
			if(Term_Rule_1 == term->rule)
			{
				dfsAST(term->production.term_1.term,Node_Term,currentScope,func);
				dfsAST(term->production.term_1.factor,Node_Factor,currentScope,func);
				break;
			}
			if(Term_Rule_2 == term->rule)
			{
				dfsAST(term->production.factor,Node_Factor,currentScope,func);
				break;
			}

			kprintf("Unrecognised rule no %d in Term\n",term->rule);
			break;
		}
		case(Node_Factor):
		{
			struct Factor*fac =(struct Factor*)node;
			if(Factor_Rule_1 == fac->rule || Factor_Rule_2 == fac->rule || Factor_Rule_7 == fac->rule || Factor_Rule_9 == fac->rule)
			{
				break;
			}
			if(Factor_Rule_3 == fac->rule)
			{
				dfsAST(fac->production.expr,Node_Expression,currentScope,func);	
				break;
			}
			if(Factor_Rule_4 == fac->rule || Factor_Rule_5 == fac->rule)
			{
				dfsAST(fac->production.factor_4_5.lvalue,Node_Lvalue,currentScope,func);
				break;
			}
			if(Factor_Rule_6 == fac->rule)
			{
				dfsAST(fac->production.factor_6.lvalue,Node_Lvalue,currentScope,func);
				dfsAST(fac->production.factor_6.expr,Node_Expression,currentScope,func);
				dfsAST(fac->production.factor_6.optExpr,Node_OptExpression,currentScope,func);
				break;
			}
			if(Factor_Rule_8 == fac->rule)
			{
				dfsAST(fac->production.factor_8.expr,Node_Expression,currentScope,func);
				dfsAST(fac->production.factor_8.optExpr,Node_OptExpression,currentScope,func);
				break;
			}
			kprintf("Unrecognised rule no %d in Factor\n",fac->rule);
			break;
		}
		case(Node_Lvalue):
		{
			struct Lvalue*lval =(struct Lvalue*)node;
			//kprintf("In Node_Lvalue rule is %d nodeId %d\n",lval->rule,lval->nodeId);
			if(Lvalue_Rule_1 == lval->rule || Lvalue_Rule_3 == lval->rule || Lvalue_Rule_4 == lval->rule)
			{
				break;
			}
			if(Lvalue_Rule_2 == lval->rule)
			{
				dfsAST(lval->production.lvalue_2.lvalue,Node_Lvalue,currentScope,func);
				break;
			}
			kprintf("Unrecognised rule no %d in Lvalue\n",lval->rule);
			break;
		}
		case(Node_OptExpression):
		{
			struct OptExpression*oe =(struct OptExpression*)node;
			dfsAST(oe->optExpr,Node_OptExpression,currentScope,func);
			dfsAST(oe->expr,Node_Expression,currentScope,func);
			break;
		}
		default:
		{
			kprintf("Unrecongnised node Type %d\n",nodeType);
			break;
		}
	}
	(*func)(node,nodeType,currentScope);
}
void fillSymbolTable(void*node,int nodeType,struct Scope currentScope)
{
	switch(nodeType)
	{
		case(Node_MethodDeclaration):
		{
			struct MethodDeclaration *md =(struct MethodDeclaration*)node;
			char *name = md->Identifier;
			struct MethodEntry me;
			me.returnType = md->type;
			me.paramCount = md->param?(md->param)->paramCount:0;
			if(md->param)
			{
				int i = 0;
				for(i=0;i<md->param->paramCount;++i)
				{
					//Store the method's signature.
					me.params[i] = md->param->params[i].dataType;
					/* for each of the parameters create a variable declaration entry in symbol
					 * table*/
					char *name = md->param->params[i].id;
					struct SymbolTableValue symVal;
					struct VariableEntry ve;
					ve.type = me.params[i];
					ve.className[0] ='\0';
					strcpy(ve.entryScope.className, currentScope.className);
					strcpy(ve.entryScope.methodName, md->Identifier);
					ve.entryScope.depth =2;
					symVal.entry.vEntry = ve;
					symVal.entryType = EntryTypeVarDeclaration;
					symVal.next = 0;
					insertItem(name,&symVal);
				}
					
			}
			me.entryScope = currentScope;
			struct SymbolTableValue symVal;
			symVal.entry.mEntry = me;
			symVal.entryType = EntryTypeMethod;
			symVal.next = 0;
			insertItem(name,&symVal);
			return;
		}

		case(Node_ClassDeclaration):
		{
			struct ClassDeclaration* cd = (struct ClassDeclaration*)node;
			char *name = cd->Identifier;
			struct SymbolTableValue symVal;
			symVal.entryType = EntryTypeClass;
			symVal.next = 0;
			insertItem(name,&symVal);
			return;
		}
		case(Node_VarDeclaration):
		{
			struct VarDeclaration *vd =(struct VarDeclaration*)node;
			char *name ;
			struct SymbolTableValue symVal;
			struct VariableEntry ve;
			if(VarDeclaration_Rule_1 == vd->rule)
			{
			  	struct VarDeclaration_1 vd1 = vd->production.varD_1;	
				name = vd1.id;
				ve.type = vd1.dataType;
				ve.className[0] = '\0';
			}
			if(VarDeclaration_Rule_2 == vd->rule)
			{
				struct VarDeclaration_2 vd2 = vd->production.varD_2;
				name = vd2.id_2;
				ve.type = DataType_UserDefined;
				strcpy(ve.className,vd2.id_1);
			}
			ve.entryScope = currentScope;
			symVal.entry.vEntry = ve;
			symVal.entryType = EntryTypeVarDeclaration;
			symVal.next = 0;
			insertItem(name,&symVal);
			return ;
		}
		default:
			return;
	}
}

