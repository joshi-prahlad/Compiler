#include"part2.h"

unsigned int allUnreachedLines[SourceLineNum];
unsigned int totalUnreachedLines = 0;
struct LineToParentLineMap
{
	unsigned int lineNum; /*Key*/
	unsigned int parentLineNum;
	int parentCondType;
	UT_hash_handle hh;
};
struct LineToParentLineMap *lnPrntLnMap = NULL;

/*
 * Maps the line number of a If/While satement to
 * the line number of a statement that immediately
 * follows If/While block.
 * If no such statement exists set to it that of 
 * parent.
 */
struct PseudoIfWhileNextMap
{
	//Line number of If/While statement
	unsigned int lineNum;	/*Key*/
	unsigned int nextLineNum;
	UT_hash_handle hh;
};
struct PseudoIfWhileNextMap * condToNextMap = NULL;
void printCondNext() {
	struct PseudoIfWhileNextMap  *s;
	for(s=condToNextMap; s != NULL; s=s->hh.next) 
	{
		kprintf("lineNumber %u next %u\n",s->lineNum,s->nextLineNum);
	}
}
/*
 * Set the uninitialized next lines by following
 * parent line numbers
 */
void initCondNextHelper()
{
	struct PseudoIfWhileNextMap*map;
	for(map =condToNextMap; map != NULL; map = map->hh.next)
	{
		if(UninitLineNumber == map->nextLineNum)
		{
			unsigned int currentLineNum = map->lineNum;
			while(1)
			{
				struct LineToParentLineMap * prntMap;
				prntMap = NULL;
				HASH_FIND_INT(lnPrntLnMap,&currentLineNum,prntMap);
				if(!prntMap)
				{
					kprintf("initCondNextHelper ERROR parent not found\n");
					return;
				}
				if(ConditionTypeWhile == prntMap->parentCondType)
				{
					map->nextLineNum = prntMap->parentLineNum;
					break;
				}
				else
				{
					struct PseudoIfWhileNextMap* nextMap;
					nextMap = NULL;
					HASH_FIND_INT(condToNextMap,&(prntMap->parentLineNum),nextMap);
					if(!nextMap)
					{
						kprintf("initCondNextHelper ERROR next not found\n");
						return;
					}
					if(UninitLineNumber == nextMap->nextLineNum)
					{
						currentLineNum = prntMap->parentLineNum;
						continue;
					}
					else
					{
						map->nextLineNum = nextMap->nextLineNum;
						break;
					}
				}
			}
		}
	}
}
void initCondToNextMap(void *node,int nodeType,struct Scope curScope)
{
	if(Node_StatementList != nodeType && Node_Statement != nodeType)
	{
		return;
	}
	if(Node_Statement == nodeType)
	{
		struct Statement * stmt = (struct Statement*)node;
		if(Statement_Rule_2 == stmt->rule || Statement_Rule_3 == stmt->rule)
		{
			struct PseudoIfWhileNextMap*retVal;
			HASH_FIND_INT(condToNextMap,&stmt->firstLineNum,retVal);
			if(retVal)
			{
				kprintf("initCondToNextMap error already set\n");
				return;
			}
			retVal = (struct PseudoIfWhileNextMap*)malloc(sizeof(struct PseudoIfWhileNextMap));
			retVal->lineNum = stmt->firstLineNum;
			retVal->nextLineNum = UninitLineNumber;
			HASH_ADD_INT(condToNextMap,lineNum,retVal);
			kprintf("NEXT Setting default for lineNumber %u \n", retVal->lineNum);
		}
		return;
	}
	struct StatementList *stList = (struct StatementList*)node;
	struct Statement* childSt = stList->stmt;
	struct StatementList* childStList = stList->stmtList;
	if(Statement_Rule_3 == childSt->rule || Statement_Rule_2 == childSt->rule)
	{
		unsigned int condLineNumber = childSt->firstLineNum;
		unsigned int nextLineNumber = UninitLineNumber;
		if(childStList)
		{
			 nextLineNumber = childStList->firstLineNum;	
		}
		else
		{
			/*
			 * If there is no satement following this if/while
			 * and it is not within any if/while then exit node
			 * follows this if/while.
			 */
			if(ConditionTypeUninit == curScope.conditionScope)
			{
				nextLineNumber = EXITLineNumber;
			}
		}
		struct PseudoIfWhileNextMap*retVal;
		HASH_FIND_INT(condToNextMap,&condLineNumber,retVal);
		if(!retVal)
		{
			kprintf("initCondToNextMap ERROR default not set for line %u\n",condLineNumber);
			return;
		}
		retVal->nextLineNum = nextLineNumber;
		kprintf("NEXT Setting lineNumber %u nextLineNumber %u \n", retVal->lineNum,retVal->nextLineNum);
	}
}
void initLineToParentMap(void *node,int nodeType,struct Scope curScope)
{
	if(Node_Statement != nodeType)
	{
		return;
	}
	struct Statement*st =(struct Statement*)node;
	if(Statement_Rule_1 != st->rule && (ConditionTypeUninit != curScope.conditionScope))
	{
		unsigned int childLineNum,parentLineNum;
		struct LineToParentLineMap *retVal;	
		HASH_FIND_INT(lnPrntLnMap,&(st->firstLineNum),retVal);
		if(retVal)
		{
			kprintf("initLineToParentMap error already set\n");
			return;
		}
		retVal = (struct LineToParentLineMap*)malloc(sizeof(struct LineToParentLineMap));
		retVal->lineNum = st->firstLineNum;
		retVal->parentLineNum = curScope.condLineNumber;
		retVal->parentCondType = curScope.conditionScope;
		HASH_ADD_INT(lnPrntLnMap,lineNum,retVal);
		kprintf("Setting %u to child of %u of type %d\n", retVal->lineNum,retVal->parentLineNum,retVal->parentCondType);
	}
}

struct GraphNode intraFlowGraph[SourceLineNum];
void initIntraFlowGraph()
{
	memset((char*)intraFlowGraph,0,sizeof(struct GraphNode) * SourceLineNum);
}
int isInRange(unsigned int nodeNo)
{
	return (nodeNo >=0 && nodeNo < SourceLineNum);
}
void addEdge(struct GraphNode graph[],unsigned int from,unsigned int to)
{
	if(!isInRange(from) || !isInRange(to))
	{
		kprintf("ERROR in addEdge from %u to %u\n",from,to);
		return;
	}
	if(from == to)
	{
		kprintf("WARNING trying to add a self loop at %u\n",from);
	}
	struct GraphNode* head = &graph[from];
	struct GraphNode* node = head->next;
	while(node)
	{
		if(node->lineNum == to)
		{
			kprintf("Edge already exists from %u to %u\n",from,to);
			return;
		}
		node = node->next;
	}
	node = head->next;
	head->next = (struct GraphNode*)malloc(sizeof(struct GraphNode));
	head->next->lineNum = to;
	head->next->next = node;
}
void setIntraFlowGraphLinks(void *node,int nodeType,struct Scope currentScope)
{
	if(Node_StatementList != nodeType && Node_Statement != nodeType)
	{
		return;
	}
	//Set the flow links for IF , while and return
	if(Node_Statement == nodeType)
	{
		struct Statement* stmt = (struct Statement*)node;
		if(Statement_Rule_8 == stmt->rule)
		{
			addEdge(intraFlowGraph,stmt->firstLineNum,EXITLineNumber);
			return;
		}
		if(Statement_Rule_2 == stmt->rule)
		{
			struct Statement *stmt1 = stmt->production.stmt_2.stmt1;
			struct Statement *stmt2 = stmt->production.stmt_2.stmt2;
			if(stmt1->firstLineNum != NoLineNumber)
			{
				addEdge(intraFlowGraph,stmt->firstLineNum,stmt1->firstLineNum);
			}
			if(stmt2->firstLineNum != NoLineNumber)
			{
				addEdge(intraFlowGraph,stmt->firstLineNum,stmt2->firstLineNum);
			}
			if(stmt1->firstLineNum == NoLineNumber  || stmt2->firstLineNum == NoLineNumber )
			{
				struct PseudoIfWhileNextMap*nextLineMap;
				nextLineMap = NULL;
				HASH_FIND_INT(condToNextMap,&(stmt->firstLineNum),nextLineMap);
				if(!nextLineMap)
				{
					kprintf("setIntraFlowGraphLinks ERROR no next line found for if %u\n",stmt->firstLineNum);
					return;
				}
				else
				{
					addEdge(intraFlowGraph,stmt->firstLineNum,nextLineMap->nextLineNum);
				}
			}
			return;
		}
		if(Statement_Rule_3 == stmt->rule)
		{
			struct Statement* stmt1 = stmt->production.stmt_3.stmt;
			if(stmt1->firstLineNum != NoLineNumber)
			{
				addEdge(intraFlowGraph,stmt->firstLineNum,stmt1->firstLineNum);
			}
			struct PseudoIfWhileNextMap*nextLineMap;
			nextLineMap = NULL;
			HASH_FIND_INT(condToNextMap,&(stmt->firstLineNum),nextLineMap);
			if(!nextLineMap)
			{
				kprintf("setIntraFlowGraphLinks ERROR no next line found for while %u\n",stmt->firstLineNum);
				return;
			}
			else
			{
				addEdge(intraFlowGraph,stmt->firstLineNum,nextLineMap->nextLineNum);
			}
			return;
		}
		
	}
	else
	{
		struct StatementList*stmtList = (struct StatementList*)node;
		struct StatementList*childSl = stmtList->stmtList;
		struct Statement *childSt = stmtList->stmt;
		if(Statement_Rule_1 == childSt->rule || Statement_Rule_2 == childSt->rule
			|| Statement_Rule_3 == childSt->rule || Statement_Rule_8 == childSt->rule)
		{
			return ;	
		}
		if(childSl)
		{
			if(NoLineNumber != childSl->firstLineNum)
			{
				addEdge(intraFlowGraph,childSt->firstLineNum,childSl->firstLineNum);
			}
		}
	}
}

void setIntraFlowGraphLinks2(void *node,int nodeType,struct Scope currentScope)
{
	/*Set the next link for the statments which are not if
	 * while or return and occur at the end of if/else/while
	 * or function definition
	 */
	if(Node_Statement != nodeType)
	{
		return ;
	}
	struct Statement* stmt = (struct Statement*)node;
	if(Statement_Rule_1 == stmt->rule || Statement_Rule_2 == stmt->rule
		|| Statement_Rule_3 == stmt->rule || Statement_Rule_8 == stmt->rule)
	{
		return;	
	}
	/*Next should not already be initialized otherwise this statement wouldn't
	 * be at the end of a block*/
	if(intraFlowGraph[stmt->firstLineNum].next)
	{
		return;
	}
	//Find parent of this line
	struct LineToParentLineMap *prntMap;
	prntMap = NULL;
	HASH_FIND_INT(lnPrntLnMap,&(stmt->firstLineNum),prntMap);
	if(!prntMap)
	{
		addEdge(intraFlowGraph,stmt->firstLineNum,EXITLineNumber);
	}
	else
	{
		if(ConditionTypeWhile == prntMap->parentCondType)
		{
			addEdge(intraFlowGraph,stmt->firstLineNum,prntMap->parentLineNum);
		}
		else
		{
			struct PseudoIfWhileNextMap*nextMap;
			nextMap = NULL;
			HASH_FIND_INT(condToNextMap,&(prntMap->parentLineNum),nextMap);
			if(!nextMap)
			{
				kprintf("setIntraFlowGraphLinks2 ERROR next line not found for %u\n",prntMap->parentLineNum);
			}
			addEdge(intraFlowGraph,stmt->firstLineNum,nextMap->nextLineNum);
		}
	}
}
void printGraphLinks(struct GraphNode *base,unsigned int size)
{
	int i =0;
	for(i=0;i<size;++i)
	{
		struct GraphNode *node=base[i].next;
		while(node)
		{
			kprintf("%u--->%u\n",i,node->lineNum);
			node = node->next;
		}
	}
}
struct MethodLineInfo
{
	unsigned int lines[MaxMethodLines];
	unsigned int lineCount;
	unsigned int unVisitedLines[MaxMethodLines];
	unsigned int unVisitedLinesCount;
};
struct MethodToLineInfoMap
{
	//Line number of method
	unsigned int lineNum; /*Key*/
	struct MethodLineInfo lineInfo;
	UT_hash_handle hh;
};
struct MethodToLineInfoMap *methodInfoMap = NULL;
void initMethodInfoMap(void *node,int nodeType,struct Scope curScope)
{
	if(Node_MethodDeclaration == nodeType)
	{
		struct MethodDeclaration * md = (struct MethodDeclaration*)node;
		struct MethodToLineInfoMap *lineInfoMap = (struct MethodToLineInfoMap*)malloc((sizeof(struct MethodToLineInfoMap)));
		lineInfoMap->lineNum = md->lineNumber;
		memset(&lineInfoMap->lineInfo,0,sizeof(struct MethodLineInfo));
		HASH_ADD_INT(methodInfoMap,lineNum,lineInfoMap);
		return;
	}
}
void initMethodInfoMap2(void *node,int nodeType,struct Scope curScope)
{
	if(Node_Statement == nodeType)
	{
		struct Statement* stmt = (struct Statement*)node;
		if(Statement_Rule_1 == stmt->rule)
		{
			return;
		}
		struct MethodToLineInfoMap *lineInfoMap;
		lineInfoMap = NULL;
		HASH_FIND_INT(methodInfoMap,&curScope.methodLineNumber,lineInfoMap);
		if(!lineInfoMap)
		{
			kprintf("ERROR initMethodInfoMap2 entry not found for methodLine %u\n",curScope.methodLineNumber);
			return;
		}
		struct MethodLineInfo* mLineInfo = &lineInfoMap->lineInfo;
		mLineInfo->lines[mLineInfo->lineCount]=stmt->firstLineNum;
		mLineInfo->lineCount++;
	}
}

int comp(const void*a,const void*b)
{
	
	if(*(unsigned int*)a==*(unsigned int*)b)
		return 0;
	if(*(unsigned int*)a < *(unsigned int*)b)
	{
		return -1;
	}
	return 1;
}
void dfsVisit(struct GraphNode*graph,struct GraphNode*root,int currentMark)
{
	if(!root || currentMark == root->mark )
	{
		return;
	}
	root->mark = currentMark;
	struct GraphNode*nextNode = root->next;
	while(nextNode)
	{
		dfsVisit(graph,&graph[nextNode->lineNum],currentMark);
		nextNode = nextNode->next;
	}
}
void findUnvisitedLines(struct MethodLineInfo*minfo,int currentMark)
{
	int i =0;
	for(i=0;i<minfo->lineCount;++i)
	{
		if(currentMark != intraFlowGraph[minfo->lines[i]].mark)
		{
			minfo->unVisitedLines[minfo->unVisitedLinesCount++] = minfo->lines[i];
		}
	}
	if(minfo->unVisitedLinesCount > 0)
	{
		qsort(minfo->unVisitedLines,minfo->unVisitedLinesCount,sizeof(unsigned int),comp);
	}
}
void visitMethods()
{
	struct MethodToLineInfoMap  *s;
	for(s=methodInfoMap; s != NULL; s=s->hh.next) 
	{
		kprintf("Method lineNumber %u \n",s->lineNum);
		struct MethodLineInfo * minfo = &s->lineInfo;
		kprintf("Total Lines %u\n",minfo->lineCount);
		int i =0;
		qsort(minfo->lines,minfo->lineCount,sizeof(unsigned int),comp);
		for(i=0;i<minfo->lineCount;++i)
		{
			kprintf("%u\n",minfo->lines[i]);
		}
		kprintf("Done\n");
		kprintf("Unvisited lines\n");
		int currentMark = 1;
		if(0 < minfo->lineCount)
		{
			struct GraphNode * root = &intraFlowGraph[minfo->lines[0]];
			dfsVisit(intraFlowGraph,root,currentMark);
			findUnvisitedLines(minfo,currentMark);
			if(minfo->unVisitedLinesCount > 0 )
			{
				int i =0;
				for(i;i<minfo->unVisitedLinesCount;++i)
				{
					printf("%u ",minfo->unVisitedLines[i]);
					allUnreachedLines[totalUnreachedLines++] = minfo->unVisitedLines[i];
				}
			}
		}
		kprintf("DONE\n");
	}
	if(totalUnreachedLines)
	{
		qsort(allUnreachedLines,totalUnreachedLines,sizeof(unsigned int),comp);
	}
}
void intraProc(struct Goal* root)
{
	struct Scope curScope;
	resetScope(&curScope);

	memset(allUnreachedLines,0,sizeof(unsigned int)*SourceLineNum);
	totalUnreachedLines = 0;

	dfsAST(root,Node_Goal,curScope,initLineToParentMap);
	/*Initializing pseudo next for If/While round1*/
	resetScope(&curScope);
	dfsAST(root,Node_Goal,curScope,initCondToNextMap);
	kprintf("Printing condNext\n");
	printCondNext();
	kprintf("End of condNext\n");
	initCondNextHelper();
	kprintf("Printing condNext\n");
	printCondNext();
	kprintf("End of condNext\n");
	initIntraFlowGraph();
	resetScope(&curScope);
	dfsAST(root,Node_Goal,curScope,setIntraFlowGraphLinks);
	resetScope(&curScope);
	dfsAST(root,Node_Goal,curScope,setIntraFlowGraphLinks2);
	kprintf("GraphLinks\n");
	printGraphLinks(intraFlowGraph,SourceLineNum);

	resetScope(&curScope);
	dfsAST(root,Node_Goal,curScope,initMethodInfoMap);
	resetScope(&curScope);
	dfsAST(root,Node_Goal,curScope,initMethodInfoMap2);
	
	visitMethods();
}


