#include"uthash.h"
#include"part2.h"

#define EntryTypeClass		1
#define EntryTypeMethod 	2
#define EntryTypeVarDeclaration	3


//Stores the inforamation about under which class
//and/or method we are in.
//If we are inside a class but not a method depth 
//would be 1 otherwise it would be 2.
struct Scope
{
	char className[NAME_LEN];
	char methodName[NAME_LEN];
	int depth ;
	int returnType; //Return type of the method.
	int conditionScope;	//Are we inside an If or While.One of ConditionType..
	unsigned int condLineNumber; 	//Line number of the conidtion we are in.
	unsigned int methodLineNumber; 	//Line number of the method we are in.
	int paramCount;
	enum DataType params[PARAM_COUNT];

};
struct MethodEntry
{
	enum DataType returnType;
	int paramCount ;
	enum DataType params[PARAM_COUNT];
	struct Scope entryScope; /*In which class this is defined.Not applicable for entry type class*/
};
struct VariableEntry
{
	enum DataType type; 	/* type of this variable*/
	char className[NAME_LEN]; /* if the type of the variable is not int or string then the user defined type of the variable*/
	struct Scope entryScope; /*In which class/method this is defined.Not applicable for entry type class*/
};
struct SymbolTableValue
{
	union
	{
		struct MethodEntry mEntry;
		struct VariableEntry vEntry;
	}entry;
	int entryType; 	/*Is this entry for a method or class or variable*/
	struct SymbolTableValue*next; //next entry with the same name
};
struct SymbolTableEntry
{
	char name[NAME_LEN];  /*key*/
	struct SymbolTableValue value;	
	UT_hash_handle hh;
};

extern struct SymbolTableEntry *symbolTable ;
extern void insertItem(char *,struct SymbolTableValue*);
extern void printSTab() ;
int findMethodDInScope(char*name,struct MethodEntry*me,int checkParams);
