%{
	#include"part2.h"

	int yylex(void);
	void yyerror(const char *);
	FILE* fd ;
	unsigned int uniqueId = 0;
	extern unsigned int currentLineNumber;
	struct Goal*program = 0;
	unsigned int methodLineNumber = 0;
%}

 %union	{
	/*Used in the lexical anlysis phase.*/
 	char* identifier;
	int intConstant;
	char* strConstant;
	/**
	*Pointer types for the structs defined to represent each non-terminal
	*in the grammar.
	*/
	struct OptExpression* TypeOptExpression;
	struct Expression* TypeExpression;
	struct Lvalue *TypeLvalue;
	struct Factor*TypeFactor;
	struct Term*TypeTerm;
	struct Condition*TypeCondition;
	struct StatementList*TypeStatementList;
	struct Statement*TypeStatement;
	struct ParameterList*TypeParameterList;
	struct Parameters*TypeParameters;
	struct VarDeclaration *TypeVarDeclaration ;
	struct MethodBody*TypeMethodBody;
	struct MethodDeclaration*TypeMethodDeclaration;
	struct MethodDeclarationList*TypeMethodDeclarationList;
	struct ClassBody*TypeClassBody;
	struct ClassDeclaration*TypeClassDeclaration;
	struct Goal*TypeGoal;
 	int TypeType;/*Type of the non-terminal Type*/
 }

/**
* Tokens that will be returned by the lexical analyzer.
*/
 %token T_Class T_String T_Int T_New T_If T_While T_Println T_EQ <identifier>T_Id <intConstant>T_IntConstant <strConstant>T_StrConstant  T_Return  T_Else

/**
* Definitions of the data types for the non terminals in the grammar.
*/
 %type<TypeOptExpression>OptExpression
 %type<TypeExpression>Expression
 %type<TypeGoal>Goal
 %type<TypeClassDeclaration>ClassDeclaration
 %type<TypeClassBody>ClassBody
 %type<TypeMethodDeclarationList>MethodDeclarationList
 %type<TypeMethodDeclaration>MethodDeclaration
 %type<TypeMethodBody>MethodBody
 %type<TypeStatementList>StatementList
 %type<TypeVarDeclaration>VarDeclaration
 %type<TypeParameters>Parameters
 %type<TypeParameterList>ParameterList
 %type<TypeStatement>Statement
 %type<TypeCondition>Condition
 %type<TypeTerm>Term
 %type<TypeType>Type
 %type<TypeFactor>Factor
 %type<TypeLvalue>Lvalue
 %type<identifier>Identifier

 %error-verbose

 %%

Goal:
	ClassDeclaration Goal	
		{
			//fprintf(fd,"Goal-> ClassDeclaration Goal\n");
			$$ = mkNodeGoal($1,$2);
			kprintf("Node ClassDeclaration NodeId %d NodeType %d\n", $$->nodeId,$$->nodeType);
			program = $$;
		}
	|
		{
			$$ = 0;
		}
	;

ClassDeclaration:
	T_Class Identifier '{'ClassBody'}' 
		{
			//fprintf(fd,"ClassDeclaration-> class Identifier {class body}\n");
			$$ = mkNodeClassDeclaration($2,$4);
			kprintf("Node ClassDeclaration NodeId %d NodeType %d\n", $$->nodeId,$$->nodeType);
		}
	;
ClassBody:
	VarDeclaration	ClassBody    
		{
			//fprintf(fd,"ClassBody-> VarDeclaration ClassBody\n");
			$$ = mkNodeClassBodyByRule1($1,$2);
		}
	|MethodDeclarationList   	
		{
			//fprintf(fd,"ClassBody-> Identifier Identifier; ClassBody\n");
			$$ = mkNodeClassBodyByRule2($1);
			kprintf("Node ClassBody RuleId %d NodeId %d NodeType %d\n",$$->rule, $$->nodeId,$$->nodeType);
		}
	;
MethodDeclarationList:
	MethodDeclaration MethodDeclarationList 
		{
			//fprintf(fd,"MethodDeclarationList-> MethodDeclaration MethodDeclarationList\n");
			$$ = mkNodeMethodDeclarationList($1,$2);
			kprintf("Node MethodDeclarationList NodeId %d NodeType %d\n", $$->nodeId,$$->nodeType);
		}
	|	
		{
			//fprintf(fd,"MethodDeclarationList-> NULL\n");
			$$  = 0;
		}
	;
MethodDeclaration: 
	Type Identifier '('Parameters')' '{' MethodBody '}'  
		{
			//fprintf(fd,"MethodDeclaration->Type Identifier (Parameters){MethodBody}\n");
			////fprintf(fd,"Type is %d\n",$1);
			$$ = mkNodeMethodDeclaration($1,$2,$4,$7,methodLineNumber);
			//kprintf("Node MethodDeclaration NodeId %d NodeType %d\n", $$->nodeId,$$->nodeType);
			kprintf("Method name %s Line Number %u\n",$2,methodLineNumber);
			/*int i=0;
			kprintf("Paramcount is %d for method %s \n",($4?$4->paramCount:0),$2);	
			/*for(i=0;$4 && i< $4->paramCount;++i)
			{
				kprintf("%s %d , ",$4->params[i].id,$4->params[i].dataType);
			}
			kprintf("\n");*/
		}
	;	
MethodBody: 
	VarDeclaration MethodBody
		{
			$$ = mkNodeMethodBodyByRule1($1,$2);
		}
	|StatementList
		{
			$$ = mkNodeMethodBodyByRule2($1);
			kprintf("Node MethodBody Rule %d NodeId %d NodeType %d\n", $$->rule,$$->nodeId,$$->nodeType);
		}
	;
StatementList:
	Statement StatementList 
		{
			//fprintf(fd,"StatmentList->Statement StatementList\n");
			unsigned int lastLineNumber = 0;
			$$ = mkNodeStatementList($1,$2);

			kprintf("Node StatementList NodeId %d NodeType %d\n", $$->nodeId,$$->nodeType);
		}
	|	
		{
			//fprintf(fd,"StatementList -> NULL\n");
			$$ = 0;
		}
	;
VarDeclaration:
	Type Identifier ';'
	{
		$$ = mkNodeVarDeclarationByRule1($1,$2);
	}
	|Identifier Identifier ';'
	{
		//fprintf(fd,"VarDeclaration -> Id  Id \n");
		//fprintf(fd,"Id1 is %s and Id2 is %s\n",$1,$2);
		$$ = mkNodeVarDeclarationByRule2($1,$2);
	}

Parameters:
	Type Identifier ParameterList   
		{
			//fprintf(fd,"Parameters-> Identifier ParameterList \n");
			$$ = mkNodeParameters($1,$2,$3);
			kprintf("Node Parameters  NodeId %d NodeType %d\n", $$->nodeId,$$->nodeType);
			methodLineNumber = currentLineNumber;
		}
	|  
		{
			//fprintf(fd,"Parameters->NULL \n");
			$$ = 0;
			methodLineNumber = currentLineNumber;
		}
	;
ParameterList:
	',' Type Identifier ParameterList 
		{
			//fprintf(fd,"ParameterList->','Type Identifier ParameterList\n");
			$$ = mkNodeParameterList($2,$3,$4);
		}
	| 
		{
			//fprintf(fd,"ParameterList->NULL \n");
			$$ = 0;
		}
	;

Type :
	T_String 
		{
			//fprintf(fd,"Type->string\n");
			$$ = DataType_String;
		}
	|T_Int	
		{
			//fprintf(fd,"Type->int\n");
			$$ = DataType_Int;
		}
	;

Statement:
	'{'StatementList'}'
		{
			//fprintf(fd,"Statement->{StatementList} \n");
			$$ = mkNodeStatementByRule1($2);
			//($2)?($$->lineNum = $2->lineNum):($$->lineNum = 0);
		}
	|T_If '(' Condition ')' Statement T_Else Statement 
		{
			//fprintf(fd,"Statement->if (condition) statement else statement\n");
			$$ = mkNodeStatementByRule2($3,$5,$7);
			kprintf("If FirstLineNumber %u LastLineNum %u\n",$$->firstLineNum,$$->lastLineNum);
		}
	|T_While '(' Condition ')' Statement 
		{
			//fprintf(fd,"Statement->while (condition) statement \n");
			$$ = mkNodeStatementByRule3($3,$5);
			kprintf("While FirstLineNumber %u LastLineNum %u\n",$$->firstLineNum,$$->lastLineNum);
		}
	|T_Println '(' Expression OptExpression')'';' 
		{
			//fprintf(fd,"Statement->println(expression optexpression); \n");
			$$ = mkNodeStatementByRule4($3,$4,currentLineNumber);
			kprintf("Node Statement Rule %d NodeId %d NodeType %d\n", $$->rule,$$->nodeId,$$->nodeType);
			kprintf("Line Number %u\n",currentLineNumber);
		}
	|Lvalue'.'Identifier '=' Expression ';'
		{
			//fprintf(fd,"Statement->Lvalue.Identifier=Expression; \n");
			$$ = mkNodeStatementByRule5($1,$3,$5,currentLineNumber);
		}
	|Identifier '=' Expression ';'
		{
			//fprintf(fd,"Statement->Identifier=Expression; \n");
			$$ = mkNodeStatementByRule6($1,$3,currentLineNumber);
		}
	|T_New Identifier '=' Expression ';'
		{
			//fprintf(fd,"Statement-> new Identifier=Expression; \n");
			$$ = mkNodeStatementByRule7($2,$4,currentLineNumber);
		}
	|T_Return Expression ';'
		{
			//fprintf(fd,"Statement-> return Expression; \n");
			$$ = mkNodeStatementByRule8($2,currentLineNumber);
		}
	|Lvalue'.'Identifier'('Expression OptExpression')'';' 
		{
			//fprintf(fd,"Statement -> Lvalue.Identifier(Expression OptExpression); \n");
			$$ = mkNodeStatementByRule9($1,$3,$5,$6,currentLineNumber);
		}
	|Lvalue'.'Identifier'('')'';' 
		{
			//fprintf(fd,"Statement -> Lvalue.Identifier(); \n");
			$$ = mkNodeStatementByRule10($1,$3,currentLineNumber);
		}
	|Identifier'('Expression OptExpression')'';' 
		{
			//fprintf(fd,"Statement -> Identifier(Expression OptExpression); \n");
			$$ = mkNodeStatementByRule11($1,$3,$4,currentLineNumber);
		}
	|Identifier'('')'';' 
		{
			//fprintf(fd,"Statement -> Identifier(); \n");
			$$ = mkNodeStatementByRule12($1,currentLineNumber);
		}
	;

Condition:
	Expression '<' Expression  
		{
			//fprintf(fd,"Condition -> Expression <  Expression\n");
			$$ = mkNodeConditionByRule1($1,$3,currentLineNumber);
		}
	|Expression '>' Expression 
		{
			//fprintf(fd,"Condition -> Expression >  Expression\n");
			$$ = mkNodeConditionByRule2($1,$3,currentLineNumber);
		}
	|Expression T_EQ Expression 
		{
			//fprintf(fd,"Condition -> Expression ==  Expression\n");
			$$ = mkNodeConditionByRule3($1,$3,currentLineNumber);
		}
	;

Expression :
	Expression '+' Term 
		{
			//fprintf(fd,"Expression -> Expression + Term\n");
			$$ = mkNodeExpressionByRule1($1,$3);
		} 
	|Expression '-' Term  
		{
			//fprintf(fd,"Expression -> Expression - Term\n");
			$$ = mkNodeExpressionByRule2($1,$3);
		} 
	|Term   
		{
			//fprintf(fd,"Expression -> Term\n");
			$$ = mkNodeExpressionByRule3($1);
			kprintf("Node Expreession Rule %d NodeId %d NodeType %d\n", $$->rule,$$->nodeId,$$->nodeType);
		} 
	;
Term :
	Term '*' Factor  
		{
			//fprintf(fd,"Term -> Term*Factor \n");
			$$ = mkNodeTermByRule1($1,$3);
		} 
	|Factor 
		{
			//fprintf(fd,"Term -> Factor \n");
			$$ = mkNodeTermByRule2($1);
			kprintf("Node Term Rule %d NodeId %d NodeType %d\n", $$->rule,$$->nodeId,$$->nodeType);
		} 
	;
Factor :
	T_IntConstant  
		{
			//fprintf(fd,"Factor -> Integer\n");
			$$ = mkNodeFactorByRule1($1,currentLineNumber);
			kprintf("Node Factor Rule %d NodeId %d NodeType %d\n", $$->rule,$$->nodeId,$$->nodeType);
		}
	|T_StrConstant  
		{
			//fprintf(fd,"Factor -> String\n");
			$$ = mkNodeFactorByRule2($1,currentLineNumber);
		} 
	|'('Expression')'  
		{
			//fprintf(fd,"Factor -> (Expression)\n",currentLineNumber);
			$$ = mkNodeFactorByRule3($2,currentLineNumber);
		} 
	|Lvalue'.'Identifier 
		{
			//fprintf(fd,"Factor ->Lvalue.Identifier \n");
			$$ = mkNodeFactorByRule4($1,$3,currentLineNumber);
		} 
	|Lvalue'.'Identifier '('')' 
		{
			//fprintf(fd,"Factor ->Lvalue.Identifier() \n");
			$$ = mkNodeFactorByRule5($1,$3,currentLineNumber);
		} 
	|Lvalue'.'Identifier'('Expression OptExpression')' 
		{
			//fprintf(fd,"Factor -> Lvalue.Identifier(Expression OptExpression) \n");
			$$ = mkNodeFactorByRule6($1,$3,$5,$6,currentLineNumber);
		}
	|Identifier   
		{
			//fprintf(fd,"Factor ->Identifier\n");
			$$ = mkNodeFactorByRule7($1,currentLineNumber);
		} 
	|Identifier'('Expression OptExpression')' 
		{
			//fprintf(fd,"Factor -> Identifier(Expression OptExpression) \n");
			$$ = mkNodeFactorByRule8($1,$3,$4,currentLineNumber);
		} 
	|Identifier'('')' 
		{
			//fprintf(fd,"Factor -> Identifier() \n");
			$$ = mkNodeFactorByRule9($1,currentLineNumber);
		} 
	;
Lvalue:
	Identifier  
		{
			//fprintf(fd,"Lvalue ->Identifier\n");
			$$ = mkNodeLvalueByRule1($1);
		}
	|Lvalue '.' Identifier	
		{
			//fprintf(fd,"Lvalue ->Lvalue.Identifier\n");
			$$ = mkNodeLvalueByRule2($1,$3);
			kprintf("Node Lvalue NodeId %d NodeType %d rule 2 should be %d\n", $$->nodeId,$$->nodeType,$$->rule);

		}
	|T_New Identifier  
		{
			//fprintf(fd,"Lvalue ->new Identifier\n");
			$$ = mkNodeLvalueByRule3($2);
		}
	|T_New Identifier '(' ')' 
		{
			//fprintf(fd,"Lvalue ->new Identifier()\n");
			$$ = mkNodeLvalueByRule4($2);
			kprintf("Node Lvalue NodeId %d NodeType %d rule 4 should be %d\n", $$->nodeId,$$->nodeType,$$->rule);
		}
	;
OptExpression:
	OptExpression','Expression 
		{
			$$ = mkNodeOptExpr($1,$3);
			//fprintf(fd,"OptExpression -> OptExpression,Expression\n");
			kprintf("Node OptExpression NodeId %d NodeType %d\n", $$->nodeId,$$->nodeType);
		}
	|  
		{  	
			$$ =0; 
			//fprintf(fd,"OptExpression -> NULL\n"); 
		}
	;
Identifier:
	T_Id 
		{
			//fprintf(fd,"Identifier->%s\n",$1);  
			$$ = $1;
		}
	;

 %%

 int main(void)
 {
	fd= stdout;
	yyparse();
	if(program)
	{
		struct Scope currentScope;
		resetScope(&currentScope);
		kprintf("Initializing symbol table\n");
		dfsAST(program,Node_Goal,currentScope,fillSymbolTable);	
		kprintf("printing SymTab\n");
		printSTab();
		kprintf("Initializing types \n");
		memset(&currentScope,'\0',sizeof(struct Scope));
		dfsAST(program,Node_Goal,currentScope,initializeTypes);
		dfsAST(program,Node_Goal,currentScope,checkStatement);
		checkMain();
		intraProc(program);
		interProcedure(program);
	}
	else
	{
		kprintf("Program is empty\n");
	}
	close(fd);
	return 0;
 }

void yyerror (const char *s)
{
	//fprintf (stderr, "%s\n", s);
}

