#ifndef DIVIDE_H
#define DIVIDE_H

class Divide : public SubExpression {
    public:
    Divide(Expression* left, Expression* right) : SubExpression(left, right) {}
    double evaluate() {
        double denominator = right->evaluate();
        if (denominator != 0.0) {
            return left->evaluate() / denominator;
        } else {
            // Handle division by zero error
            throw std::runtime_error("Division by zero error");
        }
    }
};

#endif