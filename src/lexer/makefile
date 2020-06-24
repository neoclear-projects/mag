OBJ = lex.yy.o y.tab.o ast.o

ast: $(OBJ)
	g++ -o ast $(OBJ)

y.tab.o: y.tab.c
	g++ -c y.tab.c

ast.o: ast.cpp
	g++ -c ast.cpp

lex.yy.c: mag.l
	flex mag.l

lex.yy.o: lex.yy.c y.tab.c
	g++ -c lex.yy.c

y.tab.c: mag.y
	bison -vdty mag.y

.PHONY:
	clean

clean:
	-rm *.o ast lex.yy.c y.tab.c y.tab.h
