#ifndef VARIABLE_H
#define VARIABLE_H

class Variable: public Operand {
public:
    Variable(string name) {
        this->name = name;
    }
    double evaluate();
private:
    string name;
};

#endif