#ifndef NEGATE_H
#define NEGATE_H

class Negate: public SubExpression {
    public:
    Negate(Expression* left): SubExpression(left) {}
    double evaluate()
    {
        return !left->evaluate();
    }
};

#endif