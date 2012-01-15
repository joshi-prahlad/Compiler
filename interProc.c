#include"part2.h"
struct GraphNode interProcedureCFG[SourceLineNum];

struct MethodSignature
{
	char className[NAME_LEN];
	char methodName[NAME_LEN];
	int paramCount;
	enum DataType params[PARAM_COUNT];
};
struct MethodToGraphNodeId
{
	struct MethodSignature mSign; //Key
	unsigned int graphNodeId;
	unsigned int lineNum;
	UT_hash_handle hh;
};
struct MethodToGraphNodeId *methodToNodeIdMap = NULL;
unsigned int mainMethodGraphNodeId = ~0;
unsigned int totalMethodCount  = 0;
void createCallGraphNodes()
{
	struct SymbolTableEntry * s;
	unsigned int currentId = 0;
	for(s=symbolTable; s != NULL; s=s->hh.next) 
	{
		struct SymbolTableValue *sVal = &s->value;	
		while(sVal)
		{
			if(EntryTypeMethod == sVal->entryType)
			{
				struct MethodToGraphNodeId *record = (struct MethodToGraphNodeId*)malloc(sizeof(struct MethodToGraphNodeId));
				memset(record,0,sizeof(struct MethodToGraphNodeId));
				strcpy(record->mSign.className,sVal->entry.mEntry.entryScope.className);
				strcpy(record->mSign.methodName,s->name);
				record->mSign.paramCount = sVal->entry.mEntry.paramCount;
				if(record->mSign.paramCount)
				{
					memcpy(record->mSign.params,sVal->entry.mEntry.params,sizeof(int)*record->mSign.paramCount);
				}
				record->lineNum = sVal->entry.mEntry.entryScope.methodLineNumber;

				record->graphNodeId = currentId++;
				HASH_ADD(hh,methodToNodeIdMap,mSign,sizeof(struct MethodSignature),record);

				if(0 == strcmp(MethodMain,record->mSign.methodName))
				{
					mainMethodGraphNodeId = record->graphNodeId;
					kprintf("Main method has graph node Id of %u\n",mainMethodGraphNodeId);
				}
			}
			sVal= sVal->next;
		}
	}
	totalMethodCount = currentId;
	kprintf("Total Methods found %u\n",totalMethodCount);
}
struct MethodToGraphNodeId*  getCallGraphNode(char*className,char*methodName,int paramCount,enum DataType *params)
{
	kprintf("looking for className %s methodName %s parCount %d\n",className,methodName,paramCount);
	struct MethodToGraphNodeId *retVal,arg;
	retVal = NULL;
	memset(&arg,0,sizeof(struct MethodToGraphNodeId));
	strcpy(arg.mSign.className,className);
	strcpy(arg.mSign.methodName,methodName);
	arg.mSign.paramCount = paramCount;
	int i =0;
	for(i=0;i<paramCount;++i)
	{
		arg.mSign.params[i] = params[i];
		kprintf("param %d\n",params[i]);
	}
	HASH_FIND(hh,methodToNodeIdMap,&arg.mSign,sizeof(struct MethodSignature),retVal);
	return  retVal;

}
void getArgArray(struct Expression*expr,struct OptExpression*optExpr,enum DataType*params,int *count)
{
	*count = 1+(optExpr?optExpr->argCount:0);
	params[0] = expr->typeInfo.type;
	int i =1;
	for(;optExpr && i < *count;++i)
	{
		params[i] = optExpr->argList[i-1].type;
	}
}
unsigned int getCurrentMethodGraphNodeId(struct Scope*curScope)
{
	struct MethodToGraphNodeId *retVal = getCallGraphNode(curScope->className,curScope->methodName,curScope->paramCount,curScope->params);
	if(!retVal)
	{
		kprintf("ERROR createCallGraphEdges method not found\n");
		return;
	}
	unsigned int currentMethodNodeId = retVal->graphNodeId;
	kprintf("CurrentMethodNodeId %u\n",currentMethodNodeId);
	return currentMethodNodeId;
}
void createCallGraphEdges(void *node,int nodeType,struct Scope curScope)
{
	enum DataType params[PARAM_COUNT];
	memset(params,0,sizeof(int)*PARAM_COUNT);
	int paramCount = 0;
	/*Once a method definition is entered 
	 * set currentMethodNodeId to that
	 * method's graph node id.
	 */
	/*if(Node_MethodDeclaration == nodeType)
	{
		struct MethodDeclaration *md = (struct MethodDeclaration*)node;
		
		struct MethodToGraphNodeId *retVal,arg;
		retVal = NULL;
		paramCount = md->param?(md->param)->paramCount:0;
		int i =0;
		for(i=0;i<paramCount;++i)
		{
			params[i] = md->param->params[i].dataType;
		}
		retVal = getCallGraphNode(curScope.className,md->Identifier,paramCount,params);
		if(!retVal)
		{
			kprintf("ERROR createCallGraphEdges method not found\n");
			return;
		}
		currentMethodNodeId = retVal->graphNodeId;
		kprintf("CurrentMethodNodeId %u\n",currentMethodNodeId);
		return;
	}*/
	
	if(Node_Statement == nodeType)
	{
		struct Statement* stmt = (struct Statement*)node;
		/*It the current statement is not a method call
		 * then return
		 */
		if(Statement_Rule_9 != stmt->rule && Statement_Rule_10 != stmt->rule 
			&& Statement_Rule_11 != stmt->rule && Statement_Rule_12 != stmt->rule)
		{
			return;
		}
		int currentMethodNodeId = getCurrentMethodGraphNodeId(&curScope);
		/*If the statment line number is unreachable then return*/
		if(totalUnreachedLines && bsearch(&stmt->firstLineNum,allUnreachedLines,totalUnreachedLines,sizeof(unsigned int),comp))
		{
			kprintf("Function call at line number %u is unreachable\n",stmt->firstLineNum);
			return;
		}
		if(Statement_Rule_9 == stmt->rule)
		{

			struct Lvalue*lval = stmt->production.stmt_9.lvalue;
			char*id = stmt->production.stmt_9.Identifier;
			struct Expression*expr = stmt->production.stmt_9.expr;
			struct OptExpression*optExpr = stmt->production.stmt_9.optExpr;
			getArgArray(expr,optExpr,params,&paramCount);
			struct MethodToGraphNodeId *retVal;
			retVal	= getCallGraphNode(lval->typeInfo.className,id,paramCount,params);
			if(!retVal)
			{

				kprintf("ERROR createCallGraphEdges method not found\n");
				return;
			}
			addEdge(interProcedureCFG,currentMethodNodeId,retVal->graphNodeId);
			return;
		}
		if(Statement_Rule_10 == stmt->rule)
		{
			kprintf("foud satement type 10 @ line num %u CurrentMethodNodeId %u\n",currentMethodNodeId,stmt->firstLineNum);
			struct Lvalue*lval = stmt->production.stmt_10.lvalue;
			char*id = stmt->production.stmt_10.Identifier;
			struct MethodToGraphNodeId *retVal;
			retVal	= getCallGraphNode(lval->typeInfo.className,id,paramCount,params);
			if(!retVal)
			{

				kprintf("ERROR createCallGraphEdges method not found\n");
				return;
			}
			addEdge(interProcedureCFG,currentMethodNodeId,retVal->graphNodeId);
			return;
		}
		if(Statement_Rule_11 == stmt->rule)
		{

			char*id = stmt->production.stmt_11.Identifier;	
			struct Expression*expr = stmt->production.stmt_11.expr;	
			struct OptExpression*optExpr = stmt->production.stmt_11.optExpr;	
			getArgArray(expr,optExpr,params,&paramCount);
			struct MethodToGraphNodeId *retVal;
			retVal	= getCallGraphNode(curScope.className,id,paramCount,params);
			if(!retVal)
			{

				kprintf("ERROR createCallGraphEdges method not found\n");
				return;
			}
			addEdge(interProcedureCFG,currentMethodNodeId,retVal->graphNodeId);
			return;
		}
		if(Statement_Rule_12 == stmt->rule)
		{
			char *id = stmt->production.Identifier;
			struct MethodToGraphNodeId *retVal;
			retVal	= getCallGraphNode(curScope.className,id,paramCount,params);
			if(!retVal)
			{

				kprintf("ERROR createCallGraphEdges method not found\n");
				return;
			}
			addEdge(interProcedureCFG,currentMethodNodeId,retVal->graphNodeId);
			return;
		}
		return;
	}
	if(Node_Factor == nodeType)
	{
		struct Factor*fac = (struct Factor*)node;
		if(Factor_Rule_5 != fac->rule && Factor_Rule_6 != fac->rule 
			&& Factor_Rule_8 != fac->rule && Factor_Rule_9 != fac->rule)
		{
			return;
		}
		int currentMethodNodeId = getCurrentMethodGraphNodeId(&curScope);
		if(totalUnreachedLines && bsearch(&fac->firstLineNum,allUnreachedLines,totalUnreachedLines,sizeof(unsigned int),comp))
		{
			kprintf("Function call at line number %u is unreachable\n",fac->firstLineNum);
			return;
		}
		if(Factor_Rule_5 == fac->rule)
		{
			struct Lvalue *lval = fac->production.factor_4_5.lvalue;
			char *id = fac->production.factor_4_5.Identifier;
			struct MethodToGraphNodeId *retVal;
			retVal	= getCallGraphNode(lval->typeInfo.className,id,paramCount,params);
			if(!retVal)
			{

				kprintf("ERROR createCallGraphEdges method not found\n");
				return;
			}
			addEdge(interProcedureCFG,currentMethodNodeId,retVal->graphNodeId);
			return;
		}
		if(Factor_Rule_6 == fac->rule)
		{
			struct Lvalue *lval = fac->production.factor_6.lvalue;
			struct Expression *expr =fac->production.factor_6.expr; 
			struct OptExpression *optExpr =fac->production.factor_6.optExpr; 
			char*id =fac->production.factor_6.Identifier; 

			getArgArray(expr,optExpr,params,&paramCount);
			struct MethodToGraphNodeId *retVal;
			retVal	= getCallGraphNode(lval->typeInfo.className,id,paramCount,params);
			if(!retVal)
			{

				kprintf("ERROR createCallGraphEdges method not found\n");
				return;
			}
			addEdge(interProcedureCFG,currentMethodNodeId,retVal->graphNodeId);
			return;
		}
		if(Factor_Rule_8 == fac->rule)
		{
			struct Expression *expr =fac->production.factor_8.expr; 
			struct OptExpression *optExpr =fac->production.factor_8.optExpr; 
			char *id = fac->production.Identifier;

			getArgArray(expr,optExpr,params,&paramCount);
			struct MethodToGraphNodeId *retVal;
			retVal	= getCallGraphNode(curScope.className,id,paramCount,params);
			if(!retVal)
			{

				kprintf("ERROR createCallGraphEdges method not found\n");
				return;
			}
			addEdge(interProcedureCFG,currentMethodNodeId,retVal->graphNodeId);
			return;
		}
		if(Factor_Rule_9 == fac->rule)
		{
			char*id =fac->production.Identifier; 
			struct MethodToGraphNodeId *retVal;
			retVal	= getCallGraphNode(curScope.className,id,paramCount,params);
			if(!retVal)
			{

				kprintf("ERROR createCallGraphEdges method not found\n");
				return;
			}
			addEdge(interProcedureCFG,currentMethodNodeId,retVal->graphNodeId);
			return;
		}
		return;
	}
}
void printCallGraphNodes()
{
	struct MethodToGraphNodeId* s;
	for(s=methodToNodeIdMap;s;s=s->hh.next)
	{
		kprintf("MethodName %s Class Name %s params %d lineNum %u nodeId %u\n",s->mSign.methodName,s->mSign.className,s->mSign.paramCount,s->lineNum,s->graphNodeId);
	}
}
void printUnreachedMethodLineNumbers(int currentMark)
{
	struct MethodToGraphNodeId* s;
	for(s=methodToNodeIdMap;s;s=s->hh.next)
	{
		if(currentMark != interProcedureCFG[s->graphNodeId].mark)
		{
			printf("%u ",s->lineNum);	
		}
	}
}
void interProcedure(struct Goal*root)
{
	memset(interProcedureCFG,0,sizeof(int)*SourceLineNum);
	createCallGraphNodes();
	printCallGraphNodes();
	struct Scope curScope;
	memset(&curScope,0,sizeof(struct Scope));
	dfsAST(root,Node_Goal,curScope,createCallGraphEdges);
	printGraphLinks(&interProcedureCFG[0],totalMethodCount);
	int currentMark = 1;
	dfsVisit(interProcedureCFG,&interProcedureCFG[mainMethodGraphNodeId],currentMark);
	printUnreachedMethodLineNumbers(currentMark);
}
