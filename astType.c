#include"part2.h"
#include<stdlib.h>
extern int uniqueId;

void static initTypeInfo(struct VarTypeInfo *);

struct OptExpression* mkNodeOptExpr
	(struct OptExpression* optExpr,struct Expression* expr)
{
	
	struct OptExpression *node = (struct OptExpression*)(malloc(sizeof(struct OptExpression)));
	node->nodeId = uniqueId++;
	node->optExpr = optExpr;
	node->expr = expr;
	node->nodeType = Node_OptExpression;
	node->argCount = 0;
	return node;
}

struct Lvalue* mkNodeLvalueHelper(char *id)
{
	struct Lvalue *node = (struct Lvalue*)(malloc(sizeof(struct Lvalue)));
	node->nodeId = uniqueId++;
	node->production.Identifier = id;
	node->nodeType = Node_Lvalue;
	node->typeInfo.type = -1;
	node->typeInfo.className[0]='\0';
	return node;
}
struct Lvalue*mkNodeLvalueByRule1
	(char *id
	)
{
	struct Lvalue*node = mkNodeLvalueHelper(id);
	node->rule = Lvalue_Rule_1;
	return node;
}
struct Lvalue* mkNodeLvalueByRule2
	(struct Lvalue*lval,
	 char *ident
	)
{
	struct Lvalue *node = (struct Lvalue*)(malloc(sizeof(struct Lvalue)));
	node->production.lvalue_2.lvalue = lval;
	node->production.lvalue_2.Identifier = ident;
	node->rule = Lvalue_Rule_2;
	node->nodeId = uniqueId++;
	node->nodeType = Node_Lvalue;
	return node;
}

struct Lvalue*mkNodeLvalueByRule3
	(char *id
	)
{
	struct Lvalue*node = mkNodeLvalueHelper(id);
	node->rule = Lvalue_Rule_3;
	return node;
}
struct Lvalue*mkNodeLvalueByRule4
	(char *id
	)
{
	struct Lvalue*node = mkNodeLvalueHelper(id);
	node->rule = Lvalue_Rule_4;
	return node;
}

struct Factor*mkNodeFactorHelper(unsigned int currentLineNumber)
{
	struct Factor * fac = (struct Factor*)malloc(sizeof(struct Factor));
	fac->nodeId = uniqueId++;
	fac->nodeType = Node_Factor;
	initTypeInfo(&(fac->typeInfo));
	fac->firstLineNum = currentLineNumber;
	return fac;
}
struct Factor*mkNodeFactorByRule1(int val,unsigned int currentLineNumber)
{
	struct Factor*node = mkNodeFactorHelper(currentLineNumber);
	node->production.IntConstant = val;
	node->rule = Factor_Rule_1;
	return node;
}
struct Factor*mkNodeFactorByRule2(char* val,unsigned int currentLineNumber)
{
	struct Factor*node = mkNodeFactorHelper(currentLineNumber);
	node->production.StrConstant = val;
	node->rule = Factor_Rule_2;
	return node;
}
struct Factor*mkNodeFactorByRule3(struct Expression* val,unsigned int currentLineNumber)
{
	struct Factor*node = mkNodeFactorHelper(currentLineNumber);
	node->production.expr = val;
	node->rule = Factor_Rule_3;
	return node;
}
struct Factor*mkNodeFactorByRule4(struct Lvalue* lval,char*id,unsigned int currentLineNumber)
{
	struct Factor*node = mkNodeFactorHelper(currentLineNumber);
	node->production.factor_4_5.lvalue = lval;
	node->production.factor_4_5.Identifier = id;
	node->rule = Factor_Rule_4;
	return node;
}
struct Factor*mkNodeFactorByRule5(struct Lvalue* lval,char*id,unsigned int currentLineNumber)
{
	struct Factor*node = mkNodeFactorHelper(currentLineNumber);
	node->production.factor_4_5.lvalue = lval;
	node->production.factor_4_5.Identifier = id;
	node->rule = Factor_Rule_5;
	return node;
}
struct Factor*mkNodeFactorByRule6(struct Lvalue* lval,char*id,struct Expression*expr,struct OptExpression*optExpr,unsigned int currentLineNumber)
{
	struct Factor*node = mkNodeFactorHelper(currentLineNumber);
	node->production.factor_6.lvalue = lval;
	node->production.factor_6.Identifier = id;
	node->production.factor_6.expr = expr;
	node->production.factor_6.optExpr = optExpr;
	node->rule = Factor_Rule_6;
	return node;
}
struct Factor*mkNodeFactorByRule7(char*id,unsigned int currentLineNumber)
{
	struct Factor*node = mkNodeFactorHelper(currentLineNumber);
	node->production.Identifier =id; 
	node->rule = Factor_Rule_7;
	return node;
}
struct Factor*mkNodeFactorByRule8(char*id,struct Expression*expr,struct OptExpression*optExpr,unsigned int currentLineNumber)
{
	struct Factor*node = mkNodeFactorHelper(currentLineNumber);
	node->production.factor_8.Identifier = id;
	node->production.factor_8.expr = expr;
	node->production.factor_8.optExpr = optExpr;
	node->rule = Factor_Rule_8;
	return node;
}
struct Factor*mkNodeFactorByRule9(char*id,unsigned int currentLineNumber)
{
	struct Factor*node = mkNodeFactorHelper(currentLineNumber);
	node->production.Identifier =id;
	node->rule = Factor_Rule_9;
	return node;
}
struct Term*mkNodeTermHelper()
{
	struct Term*term = (struct Term*)malloc(sizeof(struct Term));
	term->nodeId = uniqueId++;
	term->nodeType = Node_Term;
	initTypeInfo(&(term->typeInfo));
	return term;
}
struct Term*mkNodeTermByRule1(struct Term*term,struct Factor*fac)
{
	struct Term*node = mkNodeTermHelper();
	node->production.term_1.term =term;
	node->production.term_1.factor =fac;
	node->rule = Term_Rule_1;
	return node;
}
struct Term*mkNodeTermByRule2(struct Factor*fac)
{
	struct Term*node = mkNodeTermHelper();
	node->production.factor =fac;
	node->rule = Term_Rule_2;
	return node;
}
struct Expression*mkNodeExpressionHelper()
{
	struct Expression*node = (struct Expression*)malloc(sizeof(struct Expression));
	node->nodeId = uniqueId++;
	node->nodeType = Node_Expression;
	initTypeInfo(&(node->typeInfo));
	return node;
}
struct Expression*mkNodeExpressionByRule1(struct Expression*expr,struct Term*term)
{
	struct Expression*node = mkNodeExpressionHelper();
	node->production.expr_1_2.expr =expr;
	node->production.expr_1_2.term =term;
	node->rule = Expression_Rule_1;
	return node;
}
struct Expression*mkNodeExpressionByRule2(struct Expression*expr,struct Term*term)
{
	struct Expression*node = mkNodeExpressionHelper();
	node->production.expr_1_2.expr =expr;
	node->production.expr_1_2.term =term;
	node->rule = Expression_Rule_2;
	return node;
}
struct Expression*mkNodeExpressionByRule3(struct Term*term)
{
	struct Expression*node = mkNodeExpressionHelper();
	node->production.term =term;
	node->rule = Expression_Rule_3;
	return node;
}
struct Condition*mkNodeConditionHelper(struct Expression*expr1,struct Expression*expr2,unsigned int lineNumber)
{
	struct Condition*node = (struct Condition*)malloc(sizeof(struct Condition));
	node->nodeId = uniqueId++;
	node->nodeType = Node_Condition;
	node->expr1= expr1;
	node->expr2= expr2;
	node->lineNum = lineNumber;
	return node;
}
struct Condition*mkNodeConditionByRule1(struct Expression*expr1,struct Expression*expr2,unsigned int lineNumber)
{
	struct Condition*node = mkNodeConditionHelper(expr1,expr2,lineNumber);
	node->rule = Condition_Rule_1;
	return node;	
}
struct Condition*mkNodeConditionByRule2(struct Expression*expr1,struct Expression*expr2,unsigned int lineNumber)
{
	struct Condition*node = mkNodeConditionHelper(expr1,expr2,lineNumber);
	node->rule = Condition_Rule_2;
	return node;	
}
struct Condition*mkNodeConditionByRule3(struct Expression*expr1,struct Expression*expr2,unsigned int lineNumber)
{
	struct Condition*node = mkNodeConditionHelper(expr1,expr2,lineNumber);
	node->rule = Condition_Rule_3;
	return node;	
}
struct Statement*mkNodeStatementHelper()
{
	struct Statement* node = (struct Statement*)malloc(sizeof(struct Statement));
	node->nodeId = uniqueId++;
	node->nodeType = Node_Statement;
	return node;
}
struct Statement*mkNodeStatementByRule1(struct StatementList*sl)
{
	struct Statement *node = mkNodeStatementHelper();
	node->production.stmtList = sl;
	node->rule = 1;
	if(!sl)
	{
		node->firstLineNum = node->lastLineNum = NoLineNumber;
	}
	else
	{
		node->firstLineNum = sl->firstLineNum;
		node->lastLineNum = sl->lastLineNum;
	}
	return node;	
}
struct Statement*mkNodeStatementByRule2(struct Condition* cond,struct Statement*stmt1,struct Statement*stmt2)
{
	struct Statement *node = mkNodeStatementHelper();
	node->production.stmt_2.cond = cond;
	node->production.stmt_2.stmt1 = stmt1;
	node->production.stmt_2.stmt2 = stmt2;
	node->rule = 2;
	node->firstLineNum = cond->lineNum;
	node->lastLineNum = stmt2->lastLineNum;
	return node;	
}
struct Statement*mkNodeStatementByRule3(struct Condition* cond,struct Statement*stmt)
{
	struct Statement *node = mkNodeStatementHelper();
	node->production.stmt_3.cond = cond;
	node->production.stmt_3.stmt = stmt;
	node->rule = 3;
	node->firstLineNum = cond->lineNum;
	node->lastLineNum = stmt->lastLineNum;
	return node;	
}
struct Statement*mkNodeStatementByRule4(struct Expression*expr,struct OptExpression*optExpr,unsigned int lineNumber)
{
	struct Statement *node = mkNodeStatementHelper();
	node->production.stmt_4.expr = expr;
	node->production.stmt_4.optExpr = optExpr;
	node->rule = 4;
	node->firstLineNum = node->lastLineNum = lineNumber;
	return node;	
}
struct Statement*mkNodeStatementByRule5(struct Lvalue*lvalue,char*id,struct Expression*expr,unsigned int lineNumber)
{
	struct Statement *node = mkNodeStatementHelper();
	node->production.stmt_5.lvalue = lvalue;
	node->production.stmt_5.Identifier = id;
	node->production.stmt_5.expr = expr;
	node->rule = 5;
	node->firstLineNum = node->lastLineNum = lineNumber;
	return node;	
}
struct Statement*mkNodeStatementByRule6(char*id,struct Expression*expr,unsigned int lineNumber)
{
	struct Statement *node = mkNodeStatementHelper();
	node->production.stmt_6_7.Identifier = id;
	node->production.stmt_6_7.expr = expr;
	node->rule = 6;
	node->firstLineNum = node->lastLineNum = lineNumber;
	return node;	
}
struct Statement*mkNodeStatementByRule7(char*id,struct Expression*expr,unsigned int lineNumber)
{
	struct Statement *node = mkNodeStatementHelper();
	node->production.stmt_6_7.Identifier = id;
	node->production.stmt_6_7.expr = expr;
	node->rule = 7;
	node->firstLineNum = node->lastLineNum = lineNumber;
	return node;	
}
struct Statement*mkNodeStatementByRule8(struct Expression*expr,unsigned int lineNumber)
{
	struct Statement *node = mkNodeStatementHelper();
	node->production.stmt_8 = expr;
	node->rule = 8;
	node->firstLineNum = node->lastLineNum = lineNumber;
	return node;	
}
struct Statement*mkNodeStatementByRule9(struct Lvalue*lval,char*id,struct Expression*expr,struct OptExpression*optExpr,unsigned int lineNumber)
{
	struct Statement *node = mkNodeStatementHelper();
	node->production.stmt_9.lvalue = lval;
	node->production.stmt_9.Identifier = id;
	node->production.stmt_9.expr = expr;
	node->production.stmt_9.optExpr = optExpr;
	node->rule = 9;
	node->firstLineNum = node->lastLineNum = lineNumber;
	return node;	
}
struct Statement*mkNodeStatementByRule10(struct Lvalue*lval,char*id,unsigned int lineNumber)
{
	struct Statement *node = mkNodeStatementHelper();
	node->production.stmt_10.lvalue = lval;
	node->production.stmt_10.Identifier = id;
	node->rule = 10;
	node->firstLineNum = node->lastLineNum = lineNumber;
	return node;	
}
struct Statement*mkNodeStatementByRule11(char*id,struct Expression*expr,struct OptExpression*optExpr,unsigned int lineNumber)
{
	struct Statement *node = mkNodeStatementHelper();
	node->production.stmt_11.Identifier = id;
	node->production.stmt_11.expr = expr;
	node->production.stmt_11.optExpr = optExpr;
	node->rule = 11;
	node->firstLineNum = node->lastLineNum = lineNumber;
	return node;	
}
struct Statement*mkNodeStatementByRule12(char*id,unsigned int lineNumber)
{
	struct Statement *node = mkNodeStatementHelper();
	node->production.Identifier= id;
	node->rule = 12;
	node->firstLineNum = node->lastLineNum = lineNumber;
	return node;	
}
struct ParameterList*mkNodeParameterList(enum DataType type,char*id,struct ParameterList*pl)
{
	struct ParameterList*node = (struct ParameterList*)malloc(sizeof(struct ParameterList));
	node->nodeId = uniqueId++;
	node->type = type;
	node->Identifier = id;
	node->paramList = pl;
	node->nodeType = Node_ParameterList;
	//Set the syntesized attribute.
	node->paramCount = 1;
	node->params[node->paramCount-1].dataType = type;
	node->params[node->paramCount-1].id = id;
	int i =0;
	for(i=0;pl && i<pl->paramCount;++i)
	{
		node->params[++node->paramCount-1]= pl->params[i];
	}
	return node;
}
struct Parameters*mkNodeParameters(enum DataType type,char *id,struct ParameterList*pl)
{
	struct Parameters *node = (struct Parameters*)malloc(sizeof(struct Parameters));
	node->nodeId = uniqueId++;
	node->type = type;
	node->Identifier = id;
	node->paramList = pl;
	node->nodeType = Node_Parameters;
	//Set the syntesized attribute.
	node->paramCount = 1;
	node->params[node->paramCount-1].dataType = type;
	node->params[node->paramCount-1].id = id;
	int i =0;
	for(i=0;pl && i<pl->paramCount;++i)
	{
		node->params[++node->paramCount-1] = pl->params[i];
	}
	return node;
}
struct VarDeclaration*mkNodeVarDeclarationHelper()
{
	struct VarDeclaration* node = (struct VarDeclaration*)malloc(sizeof(struct VarDeclaration));
	node->nodeType = Node_VarDeclaration;
	node->nodeId = uniqueId++;
	return node;
}
struct VarDeclaration*mkNodeVarDeclarationByRule1(enum DataType type,char*id)
{
	struct VarDeclaration* node = mkNodeVarDeclarationHelper();
	node->production.varD_1.dataType= type;
	node->production.varD_1.id= id;
	node->rule = VarDeclaration_Rule_1;
	return node;
}
struct VarDeclaration*mkNodeVarDeclarationByRule2(char*id1,char*id2)
{
	struct VarDeclaration* node = mkNodeVarDeclarationHelper();
	node->production.varD_2.id_1= id1;
	node->production.varD_2.id_2= id2;
	node->rule = VarDeclaration_Rule_2;
	return node;
}
struct StatementList*mkNodeStatementList(struct Statement*stmt,struct StatementList*sl)
{
	struct StatementList*node = (struct StatementList*)malloc(sizeof(struct StatementList));
	node->nodeId= uniqueId++;
	node->stmt = stmt;
	node->stmtList =sl;
	node->nodeType = Node_StatementList;
	if(stmt->firstLineNum != NoLineNumber)
	{
		node->firstLineNum = stmt->firstLineNum;
	}
	else
	{
		if(sl)
		{
			node->firstLineNum = sl->firstLineNum;
		}
		else
		{
			node->firstLineNum = NoLineNumber;
		}
	}
	if(sl)
	{
		if(NoLineNumber != sl->lastLineNum)
		{
			node->lastLineNum = sl->lastLineNum;
		}
		else
		{
			node->lastLineNum = stmt->lastLineNum;
		}
	}
	else
	{
		node->lastLineNum = stmt->lastLineNum;
	}
	return node;
}
struct MethodBody*mkNodeMethodBodyHelper()
{
	struct MethodBody* mb = (struct MethodBody*)malloc(sizeof(struct MethodBody));
	mb->nodeId = uniqueId++;
	mb->nodeType = Node_MethodBody;
	return mb;
}
struct MethodBody*mkNodeMethodBodyByRule1(struct VarDeclaration*varD,struct MethodBody*mb)
{
	struct MethodBody*node =mkNodeMethodBodyHelper();
	node->production.mb_1.varD = varD;
	node->production.mb_1.methodBody = mb;
	node->rule = MethodBody_Rule_1;
	return node;
}
struct MethodBody*mkNodeMethodBodyByRule2(struct StatementList*sl)
{
	struct MethodBody*node =mkNodeMethodBodyHelper();
	node->production.stmtList=sl;
	node->rule = MethodBody_Rule_2;
	return node;
}
struct MethodDeclaration*mkNodeMethodDeclaration(enum DataType type,char *id,struct Parameters*params,struct MethodBody*mb,unsigned int lineNumber)
{
	struct MethodDeclaration*node = (struct MethodDeclaration*)malloc(sizeof(struct MethodDeclaration));
	node->nodeId = uniqueId++;
	node->type = type;
	node->Identifier = id;
	node->param = params;
	node->methodBody = mb;
	node->nodeType = Node_MethodDeclaration;
	if(lineNumber == 0)
	{
		kprintf("astType.c mkNodeMethodDeclaration lineNumber not initialized\n");
	}
	else
	{
		node->lineNumber = lineNumber;
	}
	return node;
}
struct MethodDeclarationList*mkNodeMethodDeclarationList(struct MethodDeclaration*md,struct MethodDeclarationList*mdl)
{
	struct MethodDeclarationList*node = (struct MethodDeclarationList*)malloc(sizeof(struct MethodDeclarationList));
	node->nodeId = uniqueId++;
	node->md = md;
	node->mdl = mdl;
	node->nodeType = Node_MethodDeclarationList;
	return node;
}
struct ClassBody* mkNodeClassBodyHelper()
{
	struct ClassBody* node = (struct ClassBody*)malloc(sizeof(struct ClassBody));
	node->nodeId = uniqueId++;
	node->nodeType = Node_ClassBody;
	return node;
}
struct ClassBody*mkNodeClassBodyByRule1(struct VarDeclaration* varD,struct ClassBody*cb)
{
	struct ClassBody*node = mkNodeClassBodyHelper();
	node->production.cb_1.varD = varD;
	node->production.cb_1.classBody = cb;
	node->rule = ClassBody_Rule_1;
	return node;
}
struct ClassBody*mkNodeClassBodyByRule2(struct MethodDeclarationList*mdl)
{
	struct ClassBody*node = mkNodeClassBodyHelper();
	node->production.mdl = mdl;
	node->rule = ClassBody_Rule_2;
	return node;
}
struct ClassDeclaration*mkNodeClassDeclaration(char*id,struct ClassBody*cb)
{
	struct ClassDeclaration* node = (struct ClassDeclaration*)malloc(sizeof(struct ClassDeclaration));
	node->nodeId = uniqueId++;
	node->nodeType = Node_ClassDeclaration;
	node->Identifier = id;
	node->classBody = cb;
	return node;
}
struct Goal*mkNodeGoal(struct ClassDeclaration*cd,struct Goal*goal)
{
	struct Goal*node = (struct Goal*)malloc(sizeof(struct Goal));
	node->nodeId = uniqueId++;
	node->nodeType = Node_Goal;
	node->classDeclaration = cd;
	node->goal = goal;
	return node;
}
void static initTypeInfo(struct VarTypeInfo *t)
{
	t->type = -1;
	t->className[0]='\0';
}
