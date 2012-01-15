
#define ConditionTypeUninit	0
#define ConditionTypeIf		1
#define ConditionTypeWhile	2


#define EXITLineNumber		0
#define UninitLineNumber	0xffffffff
#define NoLineNumber		0xfffffffe

#define SourceLineNum		10000

#define MaxMethodLines		1000

#define MethodMain		"main"

struct GraphNode
{
	unsigned int lineNum;
	struct GraphNode*next;
	int mark;
};
extern void intraProc(struct Goal* root);
extern void interProcedure(struct Goal* root);
extern unsigned int allUnreachedLines[SourceLineNum]; 
extern unsigned int totalUnreachedLines;

extern void addEdge(struct GraphNode graph[],unsigned int from,unsigned int to);

extern int comp(const void*a,const void*b);

extern void printGraphLinks(struct GraphNode *base,unsigned int size);

extern void dfsVisit(struct GraphNode*graph,struct GraphNode*root,int currentMark);
