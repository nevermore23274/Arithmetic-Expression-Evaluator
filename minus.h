#ifndef MINUS_H
#define MINUS_H

class Minus: public SubExpression {
    public:
    Minus(Expression* left, Expression* right): SubExpression(left, right) {}
    double evaluate()
    {
        return left->evaluate() - right->evaluate();
    }
};

#endif