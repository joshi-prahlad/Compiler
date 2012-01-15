#include"part2.h"
#include<stdio.h>

void checkMain()
{
	struct SymbolTableValue *sVal,tempVal;
	sVal=&tempVal;
	if(!findByName("main",sVal))
	{
		fprintf(stderr,"Error %d: main method not found\n",6);
		return;
	}
	int defCount = 0;
	struct MethodEntry me;
	while(sVal)
	{
		if(EntryTypeMethod == sVal->entryType && sVal->entry.mEntry.entryScope.depth == 1)
		{
			me = sVal->entry.mEntry;
			++defCount;
		}
		sVal =sVal->next;
	}
	if( 0 == defCount)
	{
		fprintf(stderr,"Error %d: main method not found in any class\n",6);
		return;
	}
	if( 1 < defCount)
	{
		fprintf(stderr,"Error %d: duplicate entries for main\n",6);
		return;
	}
	if(me.returnType != DataType_Int)
	{
		fprintf(stderr,"Error %d: main must have return type of int\n",6);
		return;
	}
}
