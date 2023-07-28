#ifndef OPERAND_H
#define OPERAND_H

class Operand: public Expression {
    public:
    static Expression* parse(stringstream& in);
};

#endif