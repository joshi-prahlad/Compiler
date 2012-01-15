extern void dfsAST(void *node,int nodeType,struct Scope currentScope,void(*func)(void*,int,struct Scope));
extern void fillSymbolTable(void*node,int nodeType,struct Scope currentScope);
extern void initializeTypes(void *node,int nodeType,struct Scope currentScope);
extern int checkClassVarAccess(char*className,char*varName,struct VariableEntry*ve);
extern int isBasicType(int type);
extern void checkStatement(void*,int,struct Scope);
extern void resetScope(struct Scope*);
