#include "ast.h"
#include <iostream>

AstNode::AstNode() {}

std::string AstNode::toString() {
    return "";
}

AddExpr::AddExpr(Expr *lhs, Expr *rhs) {
    this->lhs = lhs;
    this->rhs = rhs;
}

Expr::Expr() {}

std::string Expr::toString() {
    return "";
}

std::string AddExpr::toString() {
    return "{\n" +
           lhs->toString() + "\n" +
           "+\n" +
           rhs->toString() + "\n" +
           "}";
}

MinusExpr::MinusExpr(Expr *lhs, Expr *rhs) {
    this->lhs = lhs;
    this->rhs = rhs;
}

std::string MinusExpr::toString() {
    return "{\n" +
           lhs->toString() + "\n" +
           "-\n" +
           rhs->toString() + "\n" +
           "}";
}

TimesExpr::TimesExpr(Expr *lhs, Expr *rhs) {
    this->lhs = lhs;
    this->rhs = rhs;
}

std::string TimesExpr::toString() {
    return "{\n" +
           lhs->toString() + "\n" +
           "*\n" +
           rhs->toString() + "\n" +
           "}";
}

DivExpr::DivExpr(Expr *lhs, Expr *rhs) {
    this->lhs = lhs;
    this->rhs = rhs;
}

std::string DivExpr::toString() {
    return "{\n" +
           lhs->toString() + "\n" +
           "/\n" +
           rhs->toString() + "\n" +
           "}";
}

NegExpr::NegExpr(Expr *expr) {
    this->expr = expr;
}

std::string NegExpr::toString() {
    return "{\n-" +
           expr->toString() + "\n" +
           "}";
}

IntConstExpr::IntConstExpr(int val) {
    this->val = val;
}

std::string IntConstExpr::toString() {
    return std::to_string(val);
}

StrConstExpr::StrConstExpr(std::string s) {
    this->s = s;
}

std::string StrConstExpr::toString() {
    return s;
}

IdentifierExpr::IdentifierExpr(std::string name) {
    this->name = name;
}

std::string IdentifierExpr::toString() {
    return "id@" + this->name;
}

Stmt::Stmt() {}

std::string Stmt::toString() { return ""; }

AssignStmt::AssignStmt(std::string idName, Expr *expr) {
    this->idName = idName;
    this->expr = expr;
}

std::string AssignStmt::toString() {
    return idName + " =\n" + expr->toString();
}

LocalDefStmt::LocalDefStmt() {}

std::string LocalDefStmt::toString() { return ""; }

LocalDefNoInitStmt::LocalDefNoInitStmt(std::string idName) {
    this->idName = idName;
}

std::string LocalDefNoInitStmt::toString() {
    return "let " + idName;
}

LocalDefInitStmt::LocalDefInitStmt(std::string idName, Expr *expr) {
    this->idName = idName;
    this->expr = expr;
}

std::string LocalDefInitStmt::toString() {
    return "let " + idName + " =\n" + expr->toString();
}

std::vector<Stmt *> astList;
int yyparse();

int main() {
    yyparse();
    for (Stmt *it : astList)
        std::cout << it->toString() << std::endl;
    return 0;
}
