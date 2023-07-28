#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"

SymbolTable symbolTable;

void parseAssignments(stringstream& in);

// Function to print a table separator line
void printTableSeparator();

// Function to print a table header
void printTableHeader() {
    const int COLUMN_WIDTH = 40;
	cout << "\n";
    cout << "+------------+" << string(COLUMN_WIDTH + 2, '-') << "+------------+" << endl;
    cout << "| " << setw(10) << left << "Iteration" << " | " << setw(COLUMN_WIDTH) << right << "Expression" << " | " << setw(11) << right << "Result" << "|" << endl;
    cout << "+------------+" << string(COLUMN_WIDTH + 2, '-') << "+------------+" << endl;
}

// Function to print a table separator line
void printTableSeparator() {
    const int COLUMN_WIDTH = 40;
    cout << "+------------+" << string(COLUMN_WIDTH + 2, '-') << "+------------+" << endl;
}

// Function to print a table row
void printTableRow(int iteration, const string& expression, double result) {
    const int COLUMN_WIDTH = 40;
    cout << "| " << setw(10) << iteration << " | " << setw(COLUMN_WIDTH) << left << expression << " | " << setw(10) << right << fixed << setprecision(2) << result << " |" << endl;
}

int main() {
    const int SIZE = 256;
    Expression* expression;
    char paren, comma, line[SIZE];

    ifstream fin("../input.txt");
    if (!fin.is_open()) {
        cout << "File did not open" << endl;
        return 1;
    }

    // Print table header
    printTableHeader();

    int iteration = 1;
    while (true) {
        symbolTable.init();
        fin.getline(line, SIZE);
        if (!fin)
            break;
        stringstream in(line, ios_base::in);
        in >> paren;

        try {
            expression = SubExpression::parse(in);
            in >> comma;
            parseAssignments(in);
            double result = expression->evaluate();

            // Print table row
            printTableRow(iteration, line, result);
            iteration++;
        } catch (string message) {
            // Print error message above table row
            cout << message << endl;

            // Print table row
            printTableRow(iteration, line, 0.0);
            iteration++;
        }
    }

    // Print table bottom and new line for visibility
    printTableSeparator();
	cout << "\n";

    return 0;
}

void parseAssignments(stringstream& in) {
    char assignop, delimiter;
    string variable;
    int value;
    do {
        variable = parseName(in);
        in >> ws >> assignop >> value >> delimiter;
        symbolTable.insert(variable, value);
    } while (delimiter == ',');
}
