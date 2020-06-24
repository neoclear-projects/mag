#pragma once

#include <string>
#include <vector>

enum NodeType {
    ADD_EXPR,
    MINUS_EXPR,
    TIMES_EXPR,
    DIV_EXPR,
    NEG_EXPR,
    INT_CONST_EXPR,
    STR_CONST_EXPR,
    IDENTIFIER_EXPR,
    LOCAL_DEF_INIT_STMT,
    LOCAL_DEF_NOINIT_STMT,
    ASSIGN_STMT,
};

class AstNode {
public:
    AstNode();
    std::string toString();
    NodeType getType();
};

class Expr : public AstNode {
public:
    Expr();
    virtual std::string toString();
};

class AddExpr : public Expr {
private:
    Expr *lhs, *rhs;

public:
    AddExpr(Expr *lhs, Expr *rhs);
    std::string toString();
};

class MinusExpr : public Expr {
private:
    Expr *lhs, *rhs;

public:
    MinusExpr(Expr *lhs, Expr *rhs);
    std::string toString();
};

class TimesExpr : public Expr {
private:
    Expr *lhs, *rhs;

public:
    TimesExpr(Expr *lhs, Expr *rhs);
    std::string toString();
};

class DivExpr : public Expr {
private:
    Expr *lhs, *rhs;

public:
    DivExpr(Expr *lhs, Expr *rhs);
    std::string toString();
};

class NegExpr : public Expr {
private:
    Expr *expr;

public:
    NegExpr(Expr *expr);
    std::string toString();
};

class IntConstExpr : public Expr {
private:
    int val;

public:
    IntConstExpr(int val);
    std::string toString();
};

class StrConstExpr : public Expr {
private:
    std::string s;

public:
    StrConstExpr(std::string s);
    std::string toString();
};

class IdentifierExpr : public Expr {
private:
    std::string name;

public:
    IdentifierExpr(std::string name);
    std::string toString();
};

class Stmt : public AstNode {
public:
    Stmt();
    virtual std::string toString();
};

class AssignStmt : public Stmt {
private:
    std::string idName;
    Expr *expr;
public:
    AssignStmt(std::string idName, Expr *expr);
    virtual std::string toString();
};

class LocalDefStmt : public Stmt {
public:
    LocalDefStmt();
    virtual std::string toString();
};

class LocalDefNoInitStmt : LocalDefStmt {
private:
    std::string idName;
public:
    LocalDefNoInitStmt(std::string idName);
    virtual std::string toString();
};

class LocalDefInitStmt : LocalDefStmt {
private:
    std::string idName;
    Expr *expr;
public:
    LocalDefInitStmt(std::string idName, Expr *expr);
    virtual std::string toString();
};



extern std::vector<Stmt *> astList;
