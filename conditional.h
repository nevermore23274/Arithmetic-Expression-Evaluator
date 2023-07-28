#ifndef CONDITIONAL_H
#define CONDITIONAL_H

class Conditional : public SubExpression {
    public:
    Conditional(Expression* left, Expression* right, Expression* condition)
            : SubExpression(left, right, condition) {}

    double evaluate() override {
        if (condition->evaluate()) {
            return left->evaluate();
        } else {
            return right->evaluate();
        }
    }
};

#endif