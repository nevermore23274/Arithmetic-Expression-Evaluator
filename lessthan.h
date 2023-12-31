#ifndef LESSTHAN_H
#define LESSTHAN_H

class LessThan: public SubExpression {
    public:
    LessThan(Expression* left, Expression* right): SubExpression(left, right) {}
    double evaluate()
    {
        return left->evaluate() < right->evaluate();
    }
};

#endif