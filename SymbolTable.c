#include"part2.h"
#include<string.h>

void printSTabValue(struct SymbolTableValue*);
/*Declare Symbol Table*/
struct SymbolTableEntry *symbolTable = NULL;

static void addToLinkedList(struct SymbolTableValue*head,struct SymbolTableValue*arg)
{
	if(!head)
	{
		kprintf("error in SymbolTable.c addToLinkedList head is null\n");
		return;
	}
	while(head->next)
	{
		head = head->next;
	}
	head->next = arg;
}
void insertItem(char *name,struct SymbolTableValue*arg)
{
	if(!name || !arg)
	{
		kprintf("error in SymbolTable.c insertItem name/arg is null\n");
	}
	//check if we already have this key in use.
	struct SymbolTableEntry *retVal;
	HASH_FIND_STR(symbolTable,name,retVal);
	if(retVal)
	{
	struct SymbolTableValue *local = (struct SymbolTableValue*)malloc(sizeof(struct SymbolTableValue));
		memcpy(local,arg,sizeof(struct SymbolTableValue));
		//add the arg entry to end of the linked list	
		addToLinkedList(&(retVal->value),local);
	}
	else
	{

		struct SymbolTableEntry* entry =(struct SymbolTableEntry*)malloc(sizeof(struct SymbolTableEntry));
		memcpy(&(entry->value),arg,sizeof(struct SymbolTableValue));
		memcpy(entry->name,name,strlen(name));
		entry->value.next = 0;
		HASH_ADD_STR(symbolTable,name,entry);
	}
}

void printSTab() {
	struct SymbolTableEntry *s;
	for(s=symbolTable; s != NULL; s=s->hh.next) 
	{
		kprintf("name %s\n",s->name);
		kprintf("Entries Begins\n");	
		printSTabValue(&(s->value));
		kprintf("Entries Ends\n");	
	}
}
void printSTabValue(struct SymbolTableValue*sVal)
{
	int i =0;
	while(sVal)
	{
		switch(sVal->entryType)
		{
			case EntryTypeVarDeclaration:
				kprintf("VarDeclaration\n");
				if(sVal->entry.vEntry.type == DataType_UserDefined)
				{
					kprintf("Type  Name %s\n",sVal->entry.vEntry.className);
				}
				else
				{
					kprintf("Type is %d\n",sVal->entry.vEntry.type);
				}
				kprintf("Scope:MethodName %s ClassName %s Depth is %d\n",sVal->entry.vEntry.entryScope.methodName,sVal->entry.vEntry.entryScope.className,sVal->entry.vEntry.entryScope.depth);
			break;

			case EntryTypeClass:
				kprintf("ClassDeclaration\n");
				break;
			case EntryTypeMethod:
			{
				struct MethodEntry me = sVal->entry.mEntry;
				kprintf("MethodDeclaration\n");
				kprintf("Return type is %d Paramcount is %d\n",me.returnType,me.paramCount);
				int i=0;
				kprintf("Parameters\n");
				for(i=0;i<me.paramCount;++i)
				{
					kprintf("%d ",me.params[i]);
				}
				kprintf("\n");
				kprintf("Scope:MethodName %s ClassName %s Depth %d\n",me.entryScope.methodName,me.entryScope.className,me.entryScope.depth);
				break;
			}
			default:
				kprintf("ERROR in printSTabValue\n");
		}
		++i;
		sVal = sVal->next;
	}
	kprintf("Total Entries with this key %d\n",i);
}
/**
 * Returns number of variable declarations with a given
 * name ,and returns number of entries found.
 * A value of 0 means not found, a value greater than
 * 1 implies multiple definitions for a variable.
 */
int findVarDInScope(char *name,struct Scope currentScope,struct VariableEntry* var)
{
	struct SymbolTableValue tempVal;
	struct SymbolTableValue*symVal = &tempVal;
	if(!findByName(name,symVal))
	{
		return 0;
	}
	int itemsFound1= 0;
	int itemsFound2=0;
	struct VariableEntry var2Temp;
	struct VariableEntry *var2= &var2Temp;
	while(symVal)
	{
		if(EntryTypeVarDeclaration == symVal->entryType)
		{
			struct VariableEntry ve = symVal->entry.vEntry;
			//Check for a definition in the current class and method
			if(isEqualScope(&currentScope,&(ve.entryScope)))
			{
				*var = ve;
				++itemsFound1;			
			}
			else
			{
				//Check for a class specific definition
				if( 0 == strcmp(currentScope.className,ve.entryScope.className) && 1 == ve.entryScope.depth)
				{
					*var2=ve;
					++itemsFound2;
				}
			}
		}
		symVal = symVal->next;
	}
	if(itemsFound1)
	{
		return itemsFound1;
	}
	if(itemsFound2)
	{
		*var = *var2;
	}
	return itemsFound2;
}
/*Given a method name and optionally the type and count
 * of method parameter,it populates the MethodEntry
 * structure with return type/parameter information
 */
int findMethodDInScope(char*name,struct MethodEntry*me,int checkParams)
{
	struct SymbolTableValue tempVal,*symVal;
	symVal = &tempVal;
	int findCount =0;
	if(!findByName(name,symVal))
	{      
		return findCount;
	}
	while(symVal)
	{
		if(EntryTypeMethod == symVal->entryType && isEqualScope(&(me->entryScope),&(symVal->entry.mEntry.entryScope)))
		{
			struct MethodEntry *currentME = &(symVal->entry.mEntry);
			if(!checkParams)
			{
				if(!findCount)
				{
					*me = *currentME;
				}
				++findCount;
			}
			else
			{
				if(me->paramCount == currentME->paramCount)
				{
					int i =0;
					for(;i<me->paramCount && me->params[i] == currentME->params[i];++i );
					if(i == me->paramCount)
					{
						*me = *currentME;
						++findCount;
					}
				}
			}
		}
		symVal = symVal->next;
	}
	return findCount;
}
int findClass(char *name)
{
	struct SymbolTableValue symVal;
	struct SymbolTableValue * temp = &symVal;
	if(findByName(name,temp) == 0)
	{
		return 0;
	}
	int findCount = 0;
	while(temp)
	{
		if(EntryTypeClass == temp->entryType)
		{
			++findCount;
		}
		temp = temp->next;
	}
	return findCount;
}
/*Find head of the linked list which maps to a 
 * given name.
 */
int findByName(char *name,struct SymbolTableValue *symVal)
{
	struct SymbolTableEntry *retVal;
	HASH_FIND_STR(symbolTable,name,retVal);
	if(!retVal)
	{
		return 0;
	}
	*symVal = retVal->value;
	return 1;
}
int isEqualScope(struct Scope *scope1,struct Scope*scope2)
{
	return (scope1->depth == scope2->depth && (strcmp(scope1->className,scope2->className)==0) && (strcmp(scope1->methodName,scope2->methodName)==0));
}
