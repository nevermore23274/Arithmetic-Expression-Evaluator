#ifndef ANDOP_H
#define ANDOP_H

class AndOp: public SubExpression {
    public:
    AndOp(Expression* left, Expression* right): SubExpression(left, right){}
    double evaluate()
    {
        return left->evaluate() && right->evaluate();
    }
};

#endif