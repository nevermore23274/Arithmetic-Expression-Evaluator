#ifndef OROP_H
#define OROP_H

class OrOp : public SubExpression {
    public:
    OrOp(Expression* left, Expression* right)
            : SubExpression(left, right) {}

    double evaluate() override {
        return (left->evaluate() || right->evaluate()) ? 1.0 : 0.0;
    }
};

#endif