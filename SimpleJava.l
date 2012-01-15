%{
  #include<stdio.h>
  #include"y.tab.h"
  unsigned int currentLineNumber = 1;
%}
/* Define regular expressions for later use.*/

LETTER		[a-zA-Z]
DIGIT		[0-9]
WS		[ \t]
OP 		[-+*><;{}(),.=]
COMMENT		"//".*\n
StringLiteral	"'"[^'\n]*"'"

%%

"=="		return T_EQ;
{OP}		return yytext[0];	
"class"	  	return T_Class;	
"string"	return T_String;	
"int"		return T_Int;	
"new"		return T_New;	
"if"		return T_If;	
"while"		return T_While;	
"println"	return T_Println;
"else"		return T_Else;
"return"	return T_Return;
{LETTER}({LETTER}|{DIGIT})* 	{yylval.identifier = strdup(yytext);return T_Id;}
{DIGIT}+	{yylval.intConstant = atoi(yytext);return T_IntConstant;}
{StringLiteral} {yylval.strConstant = strdup(yytext);return T_StrConstant;}
\n		++currentLineNumber;
{WS}		;
{COMMENT}	++currentLineNumber;	
.		yyerror("Unknown character");	

%%


int yywrap(void)
{
	return 1;
}


