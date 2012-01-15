
Parser:lex.yy.c y.tab.c 
	gcc -o Parser -g lex.yy.c y.tab.c astType.c kprintf.c TypeCheck.c SymbolTable.c initializeTypes.c initTypeFactor.c checkStatement.c checkMain.c intraProc.c interProc.c  -lfl

lex.yy.c:SimpleJava.l y.tab.c
	flex SimpleJava.l

y.tab.c:SimpleJava.y
	bison -vdty SimpleJava.y
clean:
	rm Parser y.tab.* lex.yy.c y.output


