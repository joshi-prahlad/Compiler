/* A Bison parser, made by GNU Bison 2.4.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006,
   2009, 2010 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_Class = 258,
     T_String = 259,
     T_Int = 260,
     T_New = 261,
     T_If = 262,
     T_While = 263,
     T_Println = 264,
     T_EQ = 265,
     T_Id = 266,
     T_IntConstant = 267,
     T_StrConstant = 268,
     T_Return = 269,
     T_Else = 270
   };
#endif
/* Tokens.  */
#define T_Class 258
#define T_String 259
#define T_Int 260
#define T_New 261
#define T_If 262
#define T_While 263
#define T_Println 264
#define T_EQ 265
#define T_Id 266
#define T_IntConstant 267
#define T_StrConstant 268
#define T_Return 269
#define T_Else 270




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1685 of yacc.c  */
#line 13 "SimpleJava.y"

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
 


/* Line 1685 of yacc.c  */
#line 112 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


