#ifndef EQUALTO_H
#define EQUALTO_H

class EqualTo: public SubExpression {
    public:
    EqualTo(Expression* left, Expression* right): SubExpression(left, right){}
    double evaluate()
    {
        return left->evaluate() == right->evaluate();
    }
};

#endif