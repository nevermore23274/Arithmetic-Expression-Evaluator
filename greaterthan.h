#ifndef GREATERTHAN_H
#define GREATERTHAN_H

class GreaterThan: public SubExpression {
    public:
    GreaterThan(Expression* left, Expression* right): SubExpression(left, right){}
    double evaluate()
    {
        return left->evaluate() > right->evaluate();
    }
};

#endif