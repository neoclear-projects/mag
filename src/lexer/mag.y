%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
void yyerror(const char*);
#define YYSTYPE char *
int yylex();
%}

%token T_StringConstant T_IntConstant T_Identifier T_Let T_Print

%left '+' '-'
%left '*' '/'
%right U_neg

%%

Prog:   
    /**/                            { /* empty */ }
|   Prog Stmt                       { astList.push_back((Stmt *) $2); }
;

Stmt:
    AssignStmt                      { $$ = $1; }
|   LocalDefStmt                    { $$ = $1; }
;

AssignStmt:
    T_Identifier '=' E ';'          { $$ = (char *) new AssignStmt($1, (Expr *) $3); }
;

LocalDefStmt:
    T_Let T_Identifier '=' E ';'    { $$ = (char *) new LocalDefInitStmt($2, (Expr *) $4); }
|   T_Let T_Identifier ';'          { $$ = (char *) new LocalDefNoInitStmt($2); }

E:
    E '+' E                         { $$ = (char *) new AddExpr((Expr *) $1, (Expr *) $3); }
|   E '-' E                         { $$ = (char *) new MinusExpr((Expr *) $1, (Expr *) $3); }
|   E '*' E                         { $$ = (char *) new TimesExpr((Expr *) $1, (Expr *) $3); }
|   E '/' E                         { $$ = (char *) new DivExpr((Expr *) $1, (Expr *) $3); }
|   '-' E %prec U_neg               { $$ = (char *) new NegExpr((Expr *) $2); }
|   T_IntConstant                   { $$ = (char *) new IntConstExpr(atoi($1)); }
|   T_StringConstant                { $$ = (char *) new StrConstExpr($1); }
|   T_Identifier                    { $$ = (char *) new IdentifierExpr($1); }
|   '(' E ')'                       { $$ = $1; }
;

%%
