/*Rule number begins from 1.*/
#define Lvalue_Rule_1 1
#define Lvalue_Rule_2 2
#define Lvalue_Rule_3 3
#define Lvalue_Rule_4 4

#define Factor_Rule_1 1
#define Factor_Rule_2 2
#define Factor_Rule_3 3
#define Factor_Rule_4 4
#define Factor_Rule_5 5
#define Factor_Rule_6 6
#define Factor_Rule_7 7
#define Factor_Rule_8 8
#define Factor_Rule_9 9

#define Term_Rule_1 1
#define Term_Rule_2 2

#define Condition_Rule_1 1
#define Condition_Rule_2 2
#define Condition_Rule_3 3

#define  Statement_Rule_1 1
#define  Statement_Rule_2 2
#define  Statement_Rule_3 3
#define  Statement_Rule_4 4
#define  Statement_Rule_5 5
#define  Statement_Rule_6 6
#define  Statement_Rule_7 7
#define  Statement_Rule_8 8
#define  Statement_Rule_9 9
#define  Statement_Rule_10 10
#define  Statement_Rule_11 11
#define  Statement_Rule_12 12

#define Expression_Rule_1 1
#define Expression_Rule_2 2
#define Expression_Rule_3 3

#define MethodBody_Rule_1 1 
#define MethodBody_Rule_2 2

#define ClassBody_Rule_1 1 
#define ClassBody_Rule_2 2

#define VarDeclaration_Rule_1 1 
#define VarDeclaration_Rule_2 2 

#define Node_Goal 1
#define Node_ClassDeclaration 2
#define Node_ClassBody 3
#define Node_MethodDeclarationList 4
#define Node_MethodDeclaration 5
#define Node_MethodBody 6
#define Node_StatementList 7
#define Node_VarDeclaration 8
#define Node_Parameters 9
#define Node_ParameterList 10
#define Node_Type 11
#define Node_Statement 12
#define Node_Condition 13
#define Node_Expression 14
#define Node_Term  15
#define Node_Factor 16
#define Node_Lvalue 17
#define Node_OptExpression 18
	



struct Gen_1
{
	struct Lvalue *lvalue;
	char *Identifier;
};
struct VarTypeInfo
{
	enum DataType type;	//One of int,string or user defined class name
	char className[NAME_LEN];	//Name of user defined type.
};
struct OptExpression
{
	unsigned int nodeId;
	struct 	OptExpression *optExpr;
	struct Expression *expr;
	int nodeType ;
	struct VarTypeInfo argList[PARAM_COUNT];
	int argCount;
};
struct Gen_2
{
	struct Lvalue *lvalue;
	char *Identifier;
	struct Expression *expr;
	struct OptExpression *optExpr;
};
struct Gen_3
{
	char *Identifier;
	struct Expression *expr;
	struct OptExpression*optExpr;
};
struct Lvalue
{
	unsigned int nodeId;
	union 
	{
		char*Identifier;
		struct Gen_1 lvalue_2;
	}production;
	int nodeType ;
	int rule;
	struct VarTypeInfo typeInfo;
};
struct Factor
{
	unsigned int nodeId;
	union 
	{
		int IntConstant;
		char *StrConstant;
		struct Expression * expr;
		struct Gen_1 factor_4_5;
		struct Gen_2 factor_6;
		char *Identifier;
		struct Gen_3 factor_8;
	}production;
	int rule;
	int nodeType; 
	struct VarTypeInfo typeInfo;
	unsigned int firstLineNum;
};
struct Term_1
{
	struct Term *term;
	struct Factor *factor;
};
struct Term
{
	unsigned int nodeId;
	union 
	{
		struct Term_1 term_1;
		struct Factor* factor;
	}production;
	int rule;
	int nodeType; 
	struct VarTypeInfo typeInfo;
};
struct Expression_1_2
{
	struct Expression*expr;
	struct Term*term;
};
struct Expression
{
	unsigned int nodeId;
	union
	{
		struct Expression_1_2 expr_1_2;
		struct Term*term;
	}production;
	int rule;
	int nodeType; 
	struct VarTypeInfo typeInfo;
};
struct Condition
{
	unsigned int nodeId;
	struct Expression*expr1;
	struct Expression*expr2;
	int rule;
	int nodeType; 
	unsigned int lineNum;
};
struct StatementList
{
	unsigned int nodeId;
	struct Statement* stmt;
	struct StatementList* stmtList;
	int nodeType; 
	unsigned int firstLineNum;
	unsigned int lastLineNum;
};

struct Statement_2
{
	struct Condition* cond;
	struct Statement * stmt1;
	struct Statement * stmt2;
};
struct Statement_3
{
	struct Condition* cond;
	struct Statement * stmt;
};
struct Statement_4
{
	struct Expression *expr;
	struct OptExpression *optExpr;
};
struct Statement_5
{
	struct Lvalue *lvalue;
	char*Identifier;
	struct Expression* expr;
};
struct Statement_6
{
	char*Identifier;
	struct Expression*expr;
};
struct Statement
{
	unsigned int nodeId;
	union 
	{
		struct StatementList* stmtList;
		struct Statement_2 stmt_2;
		struct Statement_3 stmt_3;
		struct Statement_4 stmt_4;
		struct Statement_5 stmt_5;
		struct Statement_6 stmt_6_7;
		struct Expression*stmt_8;
		struct Gen_2 stmt_9;
		struct Gen_1 stmt_10;
		struct Gen_3 stmt_11;
		char*Identifier;
	}production;
	int rule;
	int nodeType; 
	unsigned int firstLineNum;
	unsigned int lastLineNum;
};
struct VarDeclaration_1
{
	enum DataType dataType;
	char* id; 
};
struct ParameterList
{
	unsigned int nodeId;
	enum DataType type;
	char *Identifier;
	struct ParameterList* paramList;
	//Synthesized attribute
	struct VarDeclaration_1 params[PARAM_COUNT];
	int paramCount;
	int nodeType; 
};
struct Parameters
{

	unsigned int nodeId;
	enum DataType type;
	char *Identifier;
	struct ParameterList* paramList;
	//Synthesized attribute
	struct VarDeclaration_1 params[PARAM_COUNT];
	int paramCount;
	int nodeType; 
};
struct VarDeclaration_2
{
	char* id_1; 
	char* id_2; 
};
struct VarDeclaration 
{
	unsigned int nodeId;
	union
	{
		struct VarDeclaration_1 varD_1;
		struct VarDeclaration_2 varD_2;
	}production;
	int rule;
	int nodeType; 
};
struct MethodBody_1
{
	struct VarDeclaration *varD;
	struct MethodBody * methodBody;
};
struct MethodBody
{
	unsigned int nodeId;
	union 
	{
		struct MethodBody_1 mb_1;
		struct StatementList * stmtList;
	}production;
	int rule;
	int nodeType; 
};
struct MethodDeclaration
{
	unsigned int nodeId;
	enum DataType type;
	char*Identifier;
	struct Parameters*param;
	struct MethodBody*methodBody;
	int nodeType; 
	unsigned int lineNumber;
};
struct MethodDeclarationList
{
	unsigned int nodeId;
	struct MethodDeclaration * md;
	struct MethodDeclarationList *mdl;
	int nodeType; 
};
struct ClassBody_1
{
	struct VarDeclaration*varD;
	struct ClassBody*classBody;
};
struct ClassBody
{
	unsigned int nodeId;
	union 
	{
		struct ClassBody_1 cb_1;
		struct MethodDeclarationList*mdl;
	}production;
	int rule;
	int nodeType; 
};
struct ClassDeclaration
{
	unsigned int nodeId;
	char*Identifier;
	struct ClassBody*classBody;
	int nodeType;
};
struct Goal
{
	unsigned int nodeId;
	struct ClassDeclaration*classDeclaration;
	struct Goal*goal;
	int nodeType; 
};

struct OptExpression* mkNodeOptExpr (struct OptExpression* optExpr,struct Expression* expr);

struct Lvalue*mkNodeLvalueByRule1 (char *id);
struct Lvalue* mkNodeLvalueByRule2 (struct Lvalue*lval, char *ident);
struct Lvalue*mkNodeLvalueByRule3 (char *id);
struct Lvalue*mkNodeLvalueByRule4 (char *id);


struct Expression*mkNodeExpressionByRule1(struct Expression*expr,struct Term*term);
struct Expression*mkNodeExpressionByRule2(struct Expression*expr,struct Term*term);
struct Expression*mkNodeExpressionByRule3(struct Term*term);

struct Term*mkNodeTermByRule1(struct Term*term,struct Factor*fac);
struct Term*mkNodeTermByRule2(struct Factor*fac);

struct Factor*mkNodeFactorByRule1(int val,unsigned int curretnLineNumber);
struct Factor*mkNodeFactorByRule2(char* val,unsigned int curretnLineNumber);
struct Factor*mkNodeFactorByRule3(struct Expression* val,unsigned int curretnLineNumber);
struct Factor*mkNodeFactorByRule4(struct Lvalue* lval,char*id,unsigned int curretnLineNumber);
struct Factor*mkNodeFactorByRule5(struct Lvalue* lval,char*id,unsigned int curretnLineNumber);
struct Factor*mkNodeFactorByRule6(struct Lvalue* lval,char*id,struct Expression*expr,struct OptExpression*optExpr,unsigned int curretnLineNumber);
struct Factor*mkNodeFactorByRule7(char*id,unsigned int curretnLineNumber);
struct Factor*mkNodeFactorByRule8(char*id,struct Expression*expr,struct OptExpression*optExpr,unsigned int curretnLineNumber);
struct Factor*mkNodeFactorByRule9(char*id,unsigned int curretnLineNumber);


struct Statement*mkNodeStatementByRule1(struct StatementList*sl);
struct Statement*mkNodeStatementByRule2(struct Condition* cond,struct Statement*stmt1,struct Statement*stmt2);
struct Statement*mkNodeStatementByRule3(struct Condition* cond,struct Statement*stmt);
struct Statement*mkNodeStatementByRule4(struct Expression*expr,struct OptExpression*optExpr,unsigned int lineNumber);
struct Statement*mkNodeStatementByRule5(struct Lvalue*lvalue,char*id,struct Expression*expr,unsigned int lineNumber);
struct Statement*mkNodeStatementByRule6(char*id,struct Expression*expr,unsigned int lineNumber);
struct Statement*mkNodeStatementByRule7(char*id,struct Expression*expr,unsigned int lineNumber);
struct Statement*mkNodeStatementByRule8(struct Expression*expr,unsigned int lineNumber);
struct Statement*mkNodeStatementByRule9(struct Lvalue*lval,char*id,struct Expression*expr,struct OptExpression*optExpr,unsigned int lineNumber);
struct Statement*mkNodeStatementByRule10(struct Lvalue*lval,char*id,unsigned int lineNumber);
struct Statement*mkNodeStatementByRule11(char*id,struct Expression*expr,struct OptExpression*optExpr,unsigned int lineNumber);
struct Statement*mkNodeStatementByRule12(char*id,unsigned int lineNumber);

struct ParameterList*mkNodeParameterList(enum DataType type,char*id,struct ParameterList*pl);
struct Parameters*mkNodeParameters(enum DataType type,char *id,struct ParameterList*pl);

struct VarDeclaration*mkNodeVarDeclarationByRule1(enum DataType type,char*id);
struct VarDeclaration*mkNodeVarDeclarationByRule2(char*id1,char*id2);

struct StatementList*mkNodeStatementList(struct Statement*stmt,struct StatementList*sl);

struct MethodBody*mkNodeMethodBodyByRule1(struct VarDeclaration*varD,struct MethodBody*mb);
struct MethodBody*mkNodeMethodBodyByRule2(struct StatementList*sl);
struct MethodDeclaration*mkNodeMethodDeclaration(enum DataType type,char *id,struct Parameters*params,struct MethodBody*mb,unsigned int methodLineNumber);
struct MethodDeclarationList*mkNodeMethodDeclarationList(struct MethodDeclaration*md,struct MethodDeclarationList*mdl);

struct Condition*mkNodeConditionByRule1(struct Expression*expr1,struct Expression*expr2,unsigned int lineNumber);
struct Condition*mkNodeConditionByRule2(struct Expression*expr1,struct Expression*expr2,unsigned int lineNumber);
struct Condition*mkNodeConditionByRule3(struct Expression*expr1,struct Expression*expr2,unsigned int lineNumber);

struct ClassBody*mkNodeClassBodyByRule1(struct VarDeclaration* varD,struct ClassBody*cb);
struct ClassBody*mkNodeClassBodyByRule2(struct MethodDeclarationList*mdl);
struct ClassDeclaration*mkNodeClassDeclaration(char*id,struct ClassBody*cb);

struct Goal*mkNodeGoal(struct ClassDeclaration*cd,struct Goal*goal);
