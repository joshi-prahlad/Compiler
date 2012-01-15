/* A Bison parser, made by GNU Bison 2.4.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "SimpleJava.y"

	#include"part2.h"

	int yylex(void);
	void yyerror(const char *);
	FILE* fd ;
	unsigned int uniqueId = 0;
	extern unsigned int currentLineNumber;
	struct Goal*program = 0;
	unsigned int methodLineNumber = 0;


/* Line 189 of yacc.c  */
#line 85 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 214 of yacc.c  */
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
 


/* Line 214 of yacc.c  */
#line 182 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 194 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   193

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  29
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  57
/* YYNRULES -- Number of states.  */
#define YYNSTATES  140

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   270

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      18,    19,    28,    26,    21,    27,    22,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    20,
      24,    23,    25,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    16,     2,    17,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     7,    13,    16,    18,    21,    22,
      31,    34,    36,    39,    40,    44,    48,    52,    53,    58,
      59,    61,    63,    67,    75,    81,    88,    95,   100,   106,
     110,   119,   126,   133,   138,   142,   146,   150,   154,   158,
     160,   164,   166,   168,   170,   174,   178,   184,   192,   194,
     200,   204,   206,   210,   213,   218,   222,   223
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      30,     0,    -1,    31,    30,    -1,    -1,     3,    48,    16,
      32,    17,    -1,    37,    32,    -1,    33,    -1,    34,    33,
      -1,    -1,    40,    48,    18,    38,    19,    16,    35,    17,
      -1,    37,    35,    -1,    36,    -1,    41,    36,    -1,    -1,
      40,    48,    20,    -1,    48,    48,    20,    -1,    40,    48,
      39,    -1,    -1,    21,    40,    48,    39,    -1,    -1,     4,
      -1,     5,    -1,    16,    36,    17,    -1,     7,    18,    42,
      19,    41,    15,    41,    -1,     8,    18,    42,    19,    41,
      -1,     9,    18,    43,    47,    19,    20,    -1,    46,    22,
      48,    23,    43,    20,    -1,    48,    23,    43,    20,    -1,
       6,    48,    23,    43,    20,    -1,    14,    43,    20,    -1,
      46,    22,    48,    18,    43,    47,    19,    20,    -1,    46,
      22,    48,    18,    19,    20,    -1,    48,    18,    43,    47,
      19,    20,    -1,    48,    18,    19,    20,    -1,    43,    24,
      43,    -1,    43,    25,    43,    -1,    43,    10,    43,    -1,
      43,    26,    44,    -1,    43,    27,    44,    -1,    44,    -1,
      44,    28,    45,    -1,    45,    -1,    12,    -1,    13,    -1,
      18,    43,    19,    -1,    46,    22,    48,    -1,    46,    22,
      48,    18,    19,    -1,    46,    22,    48,    18,    43,    47,
      19,    -1,    48,    -1,    48,    18,    43,    47,    19,    -1,
      48,    18,    19,    -1,    48,    -1,    46,    22,    48,    -1,
       6,    48,    -1,     6,    48,    18,    19,    -1,    47,    21,
      43,    -1,    -1,    11,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    75,    75,    83,    89,    97,   102,   110,   117,   123,
     140,   144,   151,   160,   166,   170,   178,   186,   193,   199,
     206,   211,   219,   225,   231,   237,   244,   249,   254,   259,
     264,   269,   274,   279,   287,   292,   297,   305,   310,   315,
     323,   328,   336,   342,   347,   352,   357,   362,   367,   372,
     377,   384,   389,   396,   401,   409,   416,   422
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_Class", "T_String", "T_Int", "T_New",
  "T_If", "T_While", "T_Println", "T_EQ", "T_Id", "T_IntConstant",
  "T_StrConstant", "T_Return", "T_Else", "'{'", "'}'", "'('", "')'", "';'",
  "','", "'.'", "'='", "'<'", "'>'", "'+'", "'-'", "'*'", "$accept",
  "Goal", "ClassDeclaration", "ClassBody", "MethodDeclarationList",
  "MethodDeclaration", "MethodBody", "StatementList", "VarDeclaration",
  "Parameters", "ParameterList", "Type", "Statement", "Condition",
  "Expression", "Term", "Factor", "Lvalue", "OptExpression", "Identifier", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   123,   125,    40,    41,
      59,    44,    46,    61,    60,    62,    43,    45,    42
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    29,    30,    30,    31,    32,    32,    33,    33,    34,
      35,    35,    36,    36,    37,    37,    38,    38,    39,    39,
      40,    40,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    42,    42,    42,    43,    43,    43,
      44,    44,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    46,    46,    46,    46,    47,    47,    48
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     5,     2,     1,     2,     0,     8,
       2,     1,     2,     0,     3,     3,     3,     0,     4,     0,
       1,     1,     3,     7,     5,     6,     6,     4,     5,     3,
       8,     6,     6,     4,     3,     3,     3,     3,     3,     1,
       3,     1,     1,     1,     3,     3,     5,     7,     1,     5,
       3,     1,     3,     2,     4,     3,     0,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     3,    57,     0,     1,     2,     8,    20,
      21,     0,     6,     8,     8,     0,     0,     4,     7,     0,
       5,     0,     0,     0,    17,    14,    15,     0,     0,     0,
      19,    13,     0,    16,     0,     0,     0,     0,     0,    13,
       0,    11,    13,     0,    13,     0,    51,     0,    53,     0,
       0,     0,     0,    42,    43,     0,     0,    39,    41,     0,
      48,     0,    51,     9,    10,     0,    12,     0,     0,     0,
      19,     0,     0,     0,     0,     0,    56,    53,     0,    29,
       0,     0,     0,     0,     0,    22,    52,     0,    56,     0,
      18,    54,     0,     0,     0,     0,     0,     0,     0,    44,
      37,    38,    40,    45,    50,    56,     0,     0,    33,     0,
      27,    28,     0,    36,    34,    35,    24,     0,     0,     0,
       0,     0,    56,     0,     0,     0,    25,    55,    46,    56,
      49,    31,     0,    26,    32,    23,     0,     0,    47,    30
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    11,    12,    13,    40,    41,    14,    27,
      33,    15,    44,    73,    74,    57,    58,    59,    98,    60
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -89
static const yytype_int16 yypact[] =
{
      51,    25,    63,    51,   -89,    36,   -89,   -89,    21,   -89,
     -89,   101,   -89,    79,    21,    25,    25,   -89,   -89,    25,
     -89,     2,    74,   113,    79,   -89,   -89,   120,    25,   124,
     128,   139,    79,   -89,    25,   134,   136,   147,   145,   153,
     151,   -89,   139,    25,   153,   149,     6,    25,    67,   145,
     145,   145,    25,   -89,   -89,   145,     8,   144,   -89,   152,
      87,   156,    68,   -89,   -89,   155,   -89,    25,    95,   145,
     128,   157,   145,   158,    54,   159,    77,   161,   -16,   -89,
     145,   145,   145,    25,   104,   -89,    75,   160,    77,    29,
     -89,   -89,    33,   153,   145,   145,   145,   153,   -17,   -89,
     144,   144,   -89,   148,   -89,    77,   114,   145,   -89,    52,
     -89,   -89,   166,    77,    77,    77,   -89,   162,   145,   123,
      76,   163,    77,    49,   164,   153,   -89,    77,   -89,    77,
     -89,   -89,   100,   -89,   -89,   -89,   109,   165,   -89,   -89
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -89,   183,   -89,   173,   175,   -89,   150,    28,   -30,   -89,
     119,    26,   -88,   140,    -7,    57,   111,   -23,   -82,    -1
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -53
static const yytype_int16 yytable[] =
{
       5,    42,   117,    99,   118,   112,   109,    16,    45,   116,
      80,    81,    42,    16,    21,    22,    45,     4,    23,    45,
      24,    45,    25,   120,    68,     9,    10,    30,    79,    69,
      46,    56,     4,    48,    80,    81,     4,   135,    62,    19,
     132,    46,    65,    62,    76,    22,    70,   136,    78,   110,
      28,    77,     8,   111,     1,    80,    81,    43,    47,    80,
      81,    88,    89,     6,    94,    92,    86,    61,    43,   133,
      45,   124,    66,   118,    45,    80,    81,   105,    95,    96,
      80,    81,   103,     9,    10,    71,    68,   113,   114,   115,
      72,    69,    62,   106,    26,   130,    62,   118,   107,   122,
     123,    52,    45,    80,    81,    84,     4,    53,    54,   -51,
      52,   127,   129,    55,    87,     4,    53,    54,    17,   137,
      52,   118,    55,   104,    62,     4,    53,    54,   138,    52,
     118,    24,    55,   121,     4,    53,    54,   100,   101,    29,
      31,    55,   128,     9,    10,    34,    35,    36,    37,    32,
       4,    52,    49,    38,    50,    39,     4,    53,    54,    34,
      35,    36,    37,    55,     4,    51,   119,    38,    63,    39,
     -52,    67,    82,    85,    83,    25,    91,    93,    97,    71,
     108,   125,   126,   131,   134,   139,     7,    20,    18,    90,
      75,     0,    64,   102
};

static const yytype_int16 yycheck[] =
{
       1,    31,    19,    19,    21,    93,    88,     8,    31,    97,
      26,    27,    42,    14,    15,    16,    39,    11,    19,    42,
      18,    44,    20,   105,    18,     4,     5,    28,    20,    23,
      31,    38,    11,    34,    26,    27,    11,   125,    39,    13,
     122,    42,    43,    44,    51,    46,    47,   129,    55,    20,
      24,    52,    16,    20,     3,    26,    27,    31,    32,    26,
      27,    68,    69,     0,    10,    72,    67,    39,    42,    20,
      93,    19,    44,    21,    97,    26,    27,    84,    24,    25,
      26,    27,    83,     4,     5,    18,    18,    94,    95,    96,
      23,    23,    93,    18,    20,    19,    97,    21,    23,   106,
     107,     6,   125,    26,    27,    18,    11,    12,    13,    22,
       6,   118,   119,    18,    19,    11,    12,    13,    17,    19,
       6,    21,    18,    19,   125,    11,    12,    13,    19,     6,
      21,    18,    18,    19,    11,    12,    13,    80,    81,    19,
      16,    18,    19,     4,     5,     6,     7,     8,     9,    21,
      11,     6,    18,    14,    18,    16,    11,    12,    13,     6,
       7,     8,     9,    18,    11,    18,    18,    14,    17,    16,
      22,    22,    28,    17,    22,    20,    19,    19,    19,    18,
      20,    15,    20,    20,    20,    20,     3,    14,    13,    70,
      50,    -1,    42,    82
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    30,    31,    11,    48,     0,    30,    16,     4,
       5,    32,    33,    34,    37,    40,    48,    17,    33,    40,
      32,    48,    48,    48,    18,    20,    20,    38,    40,    19,
      48,    16,    21,    39,     6,     7,     8,     9,    14,    16,
      35,    36,    37,    40,    41,    46,    48,    40,    48,    18,
      18,    18,     6,    12,    13,    18,    43,    44,    45,    46,
      48,    36,    48,    17,    35,    48,    36,    22,    18,    23,
      48,    18,    23,    42,    43,    42,    43,    48,    43,    20,
      26,    27,    28,    22,    18,    17,    48,    19,    43,    43,
      39,    19,    43,    19,    10,    24,    25,    19,    47,    19,
      44,    44,    45,    48,    19,    43,    18,    23,    20,    47,
      20,    20,    41,    43,    43,    43,    41,    19,    21,    18,
      47,    19,    43,    43,    19,    15,    20,    43,    19,    43,
      19,    20,    47,    20,    20,    41,    47,    19,    19,    20
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1464 of yacc.c  */
#line 76 "SimpleJava.y"
    {
			//fprintf(fd,"Goal-> ClassDeclaration Goal\n");
			(yyval.TypeGoal) = mkNodeGoal((yyvsp[(1) - (2)].TypeClassDeclaration),(yyvsp[(2) - (2)].TypeGoal));
			kprintf("Node ClassDeclaration NodeId %d NodeType %d\n", (yyval.TypeGoal)->nodeId,(yyval.TypeGoal)->nodeType);
			program = (yyval.TypeGoal);
		}
    break;

  case 3:

/* Line 1464 of yacc.c  */
#line 83 "SimpleJava.y"
    {
			(yyval.TypeGoal) = 0;
		}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 90 "SimpleJava.y"
    {
			//fprintf(fd,"ClassDeclaration-> class Identifier {class body}\n");
			(yyval.TypeClassDeclaration) = mkNodeClassDeclaration((yyvsp[(2) - (5)].identifier),(yyvsp[(4) - (5)].TypeClassBody));
			kprintf("Node ClassDeclaration NodeId %d NodeType %d\n", (yyval.TypeClassDeclaration)->nodeId,(yyval.TypeClassDeclaration)->nodeType);
		}
    break;

  case 5:

/* Line 1464 of yacc.c  */
#line 98 "SimpleJava.y"
    {
			//fprintf(fd,"ClassBody-> VarDeclaration ClassBody\n");
			(yyval.TypeClassBody) = mkNodeClassBodyByRule1((yyvsp[(1) - (2)].TypeVarDeclaration),(yyvsp[(2) - (2)].TypeClassBody));
		}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 103 "SimpleJava.y"
    {
			//fprintf(fd,"ClassBody-> Identifier Identifier; ClassBody\n");
			(yyval.TypeClassBody) = mkNodeClassBodyByRule2((yyvsp[(1) - (1)].TypeMethodDeclarationList));
			kprintf("Node ClassBody RuleId %d NodeId %d NodeType %d\n",(yyval.TypeClassBody)->rule, (yyval.TypeClassBody)->nodeId,(yyval.TypeClassBody)->nodeType);
		}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 111 "SimpleJava.y"
    {
			//fprintf(fd,"MethodDeclarationList-> MethodDeclaration MethodDeclarationList\n");
			(yyval.TypeMethodDeclarationList) = mkNodeMethodDeclarationList((yyvsp[(1) - (2)].TypeMethodDeclaration),(yyvsp[(2) - (2)].TypeMethodDeclarationList));
			kprintf("Node MethodDeclarationList NodeId %d NodeType %d\n", (yyval.TypeMethodDeclarationList)->nodeId,(yyval.TypeMethodDeclarationList)->nodeType);
		}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 117 "SimpleJava.y"
    {
			//fprintf(fd,"MethodDeclarationList-> NULL\n");
			(yyval.TypeMethodDeclarationList)  = 0;
		}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 124 "SimpleJava.y"
    {
			//fprintf(fd,"MethodDeclaration->Type Identifier (Parameters){MethodBody}\n");
			////fprintf(fd,"Type is %d\n",$1);
			(yyval.TypeMethodDeclaration) = mkNodeMethodDeclaration((yyvsp[(1) - (8)].TypeType),(yyvsp[(2) - (8)].identifier),(yyvsp[(4) - (8)].TypeParameters),(yyvsp[(7) - (8)].TypeMethodBody),methodLineNumber);
			//kprintf("Node MethodDeclaration NodeId %d NodeType %d\n", $$->nodeId,$$->nodeType);
			kprintf("Method name %s Line Number %u\n",(yyvsp[(2) - (8)].identifier),methodLineNumber);
			/*int i=0;
			kprintf("Paramcount is %d for method %s \n",($4?$4->paramCount:0),$2);	
			/*for(i=0;$4 && i< $4->paramCount;++i)
			{
				kprintf("%s %d , ",$4->params[i].id,$4->params[i].dataType);
			}
			kprintf("\n");*/
		}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 141 "SimpleJava.y"
    {
			(yyval.TypeMethodBody) = mkNodeMethodBodyByRule1((yyvsp[(1) - (2)].TypeVarDeclaration),(yyvsp[(2) - (2)].TypeMethodBody));
		}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 145 "SimpleJava.y"
    {
			(yyval.TypeMethodBody) = mkNodeMethodBodyByRule2((yyvsp[(1) - (1)].TypeStatementList));
			kprintf("Node MethodBody Rule %d NodeId %d NodeType %d\n", (yyval.TypeMethodBody)->rule,(yyval.TypeMethodBody)->nodeId,(yyval.TypeMethodBody)->nodeType);
		}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 152 "SimpleJava.y"
    {
			//fprintf(fd,"StatmentList->Statement StatementList\n");
			unsigned int lastLineNumber = 0;
			(yyval.TypeStatementList) = mkNodeStatementList((yyvsp[(1) - (2)].TypeStatement),(yyvsp[(2) - (2)].TypeStatementList));

			kprintf("Node StatementList NodeId %d NodeType %d\n", (yyval.TypeStatementList)->nodeId,(yyval.TypeStatementList)->nodeType);
		}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 160 "SimpleJava.y"
    {
			//fprintf(fd,"StatementList -> NULL\n");
			(yyval.TypeStatementList) = 0;
		}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 167 "SimpleJava.y"
    {
		(yyval.TypeVarDeclaration) = mkNodeVarDeclarationByRule1((yyvsp[(1) - (3)].TypeType),(yyvsp[(2) - (3)].identifier));
	}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 171 "SimpleJava.y"
    {
		//fprintf(fd,"VarDeclaration -> Id  Id \n");
		//fprintf(fd,"Id1 is %s and Id2 is %s\n",$1,$2);
		(yyval.TypeVarDeclaration) = mkNodeVarDeclarationByRule2((yyvsp[(1) - (3)].identifier),(yyvsp[(2) - (3)].identifier));
	}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 179 "SimpleJava.y"
    {
			//fprintf(fd,"Parameters-> Identifier ParameterList \n");
			(yyval.TypeParameters) = mkNodeParameters((yyvsp[(1) - (3)].TypeType),(yyvsp[(2) - (3)].identifier),(yyvsp[(3) - (3)].TypeParameterList));
			kprintf("Node Parameters  NodeId %d NodeType %d\n", (yyval.TypeParameters)->nodeId,(yyval.TypeParameters)->nodeType);
			methodLineNumber = currentLineNumber;
		}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 186 "SimpleJava.y"
    {
			//fprintf(fd,"Parameters->NULL \n");
			(yyval.TypeParameters) = 0;
			methodLineNumber = currentLineNumber;
		}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 194 "SimpleJava.y"
    {
			//fprintf(fd,"ParameterList->','Type Identifier ParameterList\n");
			(yyval.TypeParameterList) = mkNodeParameterList((yyvsp[(2) - (4)].TypeType),(yyvsp[(3) - (4)].identifier),(yyvsp[(4) - (4)].TypeParameterList));
		}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 199 "SimpleJava.y"
    {
			//fprintf(fd,"ParameterList->NULL \n");
			(yyval.TypeParameterList) = 0;
		}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 207 "SimpleJava.y"
    {
			//fprintf(fd,"Type->string\n");
			(yyval.TypeType) = DataType_String;
		}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 212 "SimpleJava.y"
    {
			//fprintf(fd,"Type->int\n");
			(yyval.TypeType) = DataType_Int;
		}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 220 "SimpleJava.y"
    {
			//fprintf(fd,"Statement->{StatementList} \n");
			(yyval.TypeStatement) = mkNodeStatementByRule1((yyvsp[(2) - (3)].TypeStatementList));
			//($2)?($$->lineNum = $2->lineNum):($$->lineNum = 0);
		}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 226 "SimpleJava.y"
    {
			//fprintf(fd,"Statement->if (condition) statement else statement\n");
			(yyval.TypeStatement) = mkNodeStatementByRule2((yyvsp[(3) - (7)].TypeCondition),(yyvsp[(5) - (7)].TypeStatement),(yyvsp[(7) - (7)].TypeStatement));
			kprintf("If FirstLineNumber %u LastLineNum %u\n",(yyval.TypeStatement)->firstLineNum,(yyval.TypeStatement)->lastLineNum);
		}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 232 "SimpleJava.y"
    {
			//fprintf(fd,"Statement->while (condition) statement \n");
			(yyval.TypeStatement) = mkNodeStatementByRule3((yyvsp[(3) - (5)].TypeCondition),(yyvsp[(5) - (5)].TypeStatement));
			kprintf("While FirstLineNumber %u LastLineNum %u\n",(yyval.TypeStatement)->firstLineNum,(yyval.TypeStatement)->lastLineNum);
		}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 238 "SimpleJava.y"
    {
			//fprintf(fd,"Statement->println(expression optexpression); \n");
			(yyval.TypeStatement) = mkNodeStatementByRule4((yyvsp[(3) - (6)].TypeExpression),(yyvsp[(4) - (6)].TypeOptExpression),currentLineNumber);
			kprintf("Node Statement Rule %d NodeId %d NodeType %d\n", (yyval.TypeStatement)->rule,(yyval.TypeStatement)->nodeId,(yyval.TypeStatement)->nodeType);
			kprintf("Line Number %u\n",currentLineNumber);
		}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 245 "SimpleJava.y"
    {
			//fprintf(fd,"Statement->Lvalue.Identifier=Expression; \n");
			(yyval.TypeStatement) = mkNodeStatementByRule5((yyvsp[(1) - (6)].TypeLvalue),(yyvsp[(3) - (6)].identifier),(yyvsp[(5) - (6)].TypeExpression),currentLineNumber);
		}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 250 "SimpleJava.y"
    {
			//fprintf(fd,"Statement->Identifier=Expression; \n");
			(yyval.TypeStatement) = mkNodeStatementByRule6((yyvsp[(1) - (4)].identifier),(yyvsp[(3) - (4)].TypeExpression),currentLineNumber);
		}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 255 "SimpleJava.y"
    {
			//fprintf(fd,"Statement-> new Identifier=Expression; \n");
			(yyval.TypeStatement) = mkNodeStatementByRule7((yyvsp[(2) - (5)].identifier),(yyvsp[(4) - (5)].TypeExpression),currentLineNumber);
		}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 260 "SimpleJava.y"
    {
			//fprintf(fd,"Statement-> return Expression; \n");
			(yyval.TypeStatement) = mkNodeStatementByRule8((yyvsp[(2) - (3)].TypeExpression),currentLineNumber);
		}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 265 "SimpleJava.y"
    {
			//fprintf(fd,"Statement -> Lvalue.Identifier(Expression OptExpression); \n");
			(yyval.TypeStatement) = mkNodeStatementByRule9((yyvsp[(1) - (8)].TypeLvalue),(yyvsp[(3) - (8)].identifier),(yyvsp[(5) - (8)].TypeExpression),(yyvsp[(6) - (8)].TypeOptExpression),currentLineNumber);
		}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 270 "SimpleJava.y"
    {
			//fprintf(fd,"Statement -> Lvalue.Identifier(); \n");
			(yyval.TypeStatement) = mkNodeStatementByRule10((yyvsp[(1) - (6)].TypeLvalue),(yyvsp[(3) - (6)].identifier),currentLineNumber);
		}
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 275 "SimpleJava.y"
    {
			//fprintf(fd,"Statement -> Identifier(Expression OptExpression); \n");
			(yyval.TypeStatement) = mkNodeStatementByRule11((yyvsp[(1) - (6)].identifier),(yyvsp[(3) - (6)].TypeExpression),(yyvsp[(4) - (6)].TypeOptExpression),currentLineNumber);
		}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 280 "SimpleJava.y"
    {
			//fprintf(fd,"Statement -> Identifier(); \n");
			(yyval.TypeStatement) = mkNodeStatementByRule12((yyvsp[(1) - (4)].identifier),currentLineNumber);
		}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 288 "SimpleJava.y"
    {
			//fprintf(fd,"Condition -> Expression <  Expression\n");
			(yyval.TypeCondition) = mkNodeConditionByRule1((yyvsp[(1) - (3)].TypeExpression),(yyvsp[(3) - (3)].TypeExpression),currentLineNumber);
		}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 293 "SimpleJava.y"
    {
			//fprintf(fd,"Condition -> Expression >  Expression\n");
			(yyval.TypeCondition) = mkNodeConditionByRule2((yyvsp[(1) - (3)].TypeExpression),(yyvsp[(3) - (3)].TypeExpression),currentLineNumber);
		}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 298 "SimpleJava.y"
    {
			//fprintf(fd,"Condition -> Expression ==  Expression\n");
			(yyval.TypeCondition) = mkNodeConditionByRule3((yyvsp[(1) - (3)].TypeExpression),(yyvsp[(3) - (3)].TypeExpression),currentLineNumber);
		}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 306 "SimpleJava.y"
    {
			//fprintf(fd,"Expression -> Expression + Term\n");
			(yyval.TypeExpression) = mkNodeExpressionByRule1((yyvsp[(1) - (3)].TypeExpression),(yyvsp[(3) - (3)].TypeTerm));
		}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 311 "SimpleJava.y"
    {
			//fprintf(fd,"Expression -> Expression - Term\n");
			(yyval.TypeExpression) = mkNodeExpressionByRule2((yyvsp[(1) - (3)].TypeExpression),(yyvsp[(3) - (3)].TypeTerm));
		}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 316 "SimpleJava.y"
    {
			//fprintf(fd,"Expression -> Term\n");
			(yyval.TypeExpression) = mkNodeExpressionByRule3((yyvsp[(1) - (1)].TypeTerm));
			kprintf("Node Expreession Rule %d NodeId %d NodeType %d\n", (yyval.TypeExpression)->rule,(yyval.TypeExpression)->nodeId,(yyval.TypeExpression)->nodeType);
		}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 324 "SimpleJava.y"
    {
			//fprintf(fd,"Term -> Term*Factor \n");
			(yyval.TypeTerm) = mkNodeTermByRule1((yyvsp[(1) - (3)].TypeTerm),(yyvsp[(3) - (3)].TypeFactor));
		}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 329 "SimpleJava.y"
    {
			//fprintf(fd,"Term -> Factor \n");
			(yyval.TypeTerm) = mkNodeTermByRule2((yyvsp[(1) - (1)].TypeFactor));
			kprintf("Node Term Rule %d NodeId %d NodeType %d\n", (yyval.TypeTerm)->rule,(yyval.TypeTerm)->nodeId,(yyval.TypeTerm)->nodeType);
		}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 337 "SimpleJava.y"
    {
			//fprintf(fd,"Factor -> Integer\n");
			(yyval.TypeFactor) = mkNodeFactorByRule1((yyvsp[(1) - (1)].intConstant),currentLineNumber);
			kprintf("Node Factor Rule %d NodeId %d NodeType %d\n", (yyval.TypeFactor)->rule,(yyval.TypeFactor)->nodeId,(yyval.TypeFactor)->nodeType);
		}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 343 "SimpleJava.y"
    {
			//fprintf(fd,"Factor -> String\n");
			(yyval.TypeFactor) = mkNodeFactorByRule2((yyvsp[(1) - (1)].strConstant),currentLineNumber);
		}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 348 "SimpleJava.y"
    {
			//fprintf(fd,"Factor -> (Expression)\n",currentLineNumber);
			(yyval.TypeFactor) = mkNodeFactorByRule3((yyvsp[(2) - (3)].TypeExpression),currentLineNumber);
		}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 353 "SimpleJava.y"
    {
			//fprintf(fd,"Factor ->Lvalue.Identifier \n");
			(yyval.TypeFactor) = mkNodeFactorByRule4((yyvsp[(1) - (3)].TypeLvalue),(yyvsp[(3) - (3)].identifier),currentLineNumber);
		}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 358 "SimpleJava.y"
    {
			//fprintf(fd,"Factor ->Lvalue.Identifier() \n");
			(yyval.TypeFactor) = mkNodeFactorByRule5((yyvsp[(1) - (5)].TypeLvalue),(yyvsp[(3) - (5)].identifier),currentLineNumber);
		}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 363 "SimpleJava.y"
    {
			//fprintf(fd,"Factor -> Lvalue.Identifier(Expression OptExpression) \n");
			(yyval.TypeFactor) = mkNodeFactorByRule6((yyvsp[(1) - (7)].TypeLvalue),(yyvsp[(3) - (7)].identifier),(yyvsp[(5) - (7)].TypeExpression),(yyvsp[(6) - (7)].TypeOptExpression),currentLineNumber);
		}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 368 "SimpleJava.y"
    {
			//fprintf(fd,"Factor ->Identifier\n");
			(yyval.TypeFactor) = mkNodeFactorByRule7((yyvsp[(1) - (1)].identifier),currentLineNumber);
		}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 373 "SimpleJava.y"
    {
			//fprintf(fd,"Factor -> Identifier(Expression OptExpression) \n");
			(yyval.TypeFactor) = mkNodeFactorByRule8((yyvsp[(1) - (5)].identifier),(yyvsp[(3) - (5)].TypeExpression),(yyvsp[(4) - (5)].TypeOptExpression),currentLineNumber);
		}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 378 "SimpleJava.y"
    {
			//fprintf(fd,"Factor -> Identifier() \n");
			(yyval.TypeFactor) = mkNodeFactorByRule9((yyvsp[(1) - (3)].identifier),currentLineNumber);
		}
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 385 "SimpleJava.y"
    {
			//fprintf(fd,"Lvalue ->Identifier\n");
			(yyval.TypeLvalue) = mkNodeLvalueByRule1((yyvsp[(1) - (1)].identifier));
		}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 390 "SimpleJava.y"
    {
			//fprintf(fd,"Lvalue ->Lvalue.Identifier\n");
			(yyval.TypeLvalue) = mkNodeLvalueByRule2((yyvsp[(1) - (3)].TypeLvalue),(yyvsp[(3) - (3)].identifier));
			kprintf("Node Lvalue NodeId %d NodeType %d rule 2 should be %d\n", (yyval.TypeLvalue)->nodeId,(yyval.TypeLvalue)->nodeType,(yyval.TypeLvalue)->rule);

		}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 397 "SimpleJava.y"
    {
			//fprintf(fd,"Lvalue ->new Identifier\n");
			(yyval.TypeLvalue) = mkNodeLvalueByRule3((yyvsp[(2) - (2)].identifier));
		}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 402 "SimpleJava.y"
    {
			//fprintf(fd,"Lvalue ->new Identifier()\n");
			(yyval.TypeLvalue) = mkNodeLvalueByRule4((yyvsp[(2) - (4)].identifier));
			kprintf("Node Lvalue NodeId %d NodeType %d rule 4 should be %d\n", (yyval.TypeLvalue)->nodeId,(yyval.TypeLvalue)->nodeType,(yyval.TypeLvalue)->rule);
		}
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 410 "SimpleJava.y"
    {
			(yyval.TypeOptExpression) = mkNodeOptExpr((yyvsp[(1) - (3)].TypeOptExpression),(yyvsp[(3) - (3)].TypeExpression));
			//fprintf(fd,"OptExpression -> OptExpression,Expression\n");
			kprintf("Node OptExpression NodeId %d NodeType %d\n", (yyval.TypeOptExpression)->nodeId,(yyval.TypeOptExpression)->nodeType);
		}
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 416 "SimpleJava.y"
    {  	
			(yyval.TypeOptExpression) =0; 
			//fprintf(fd,"OptExpression -> NULL\n"); 
		}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 423 "SimpleJava.y"
    {
			//fprintf(fd,"Identifier->%s\n",$1);  
			(yyval.identifier) = (yyvsp[(1) - (1)].identifier);
		}
    break;



/* Line 1464 of yacc.c  */
#line 2102 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1684 of yacc.c  */
#line 429 "SimpleJava.y"


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


