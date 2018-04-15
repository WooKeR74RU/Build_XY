#pragma once
#include "Utilities.h"

typedef bool(*Unary)(double&, double);
typedef bool(*Binary)(double&, double, double);

void initOperations();

struct Block
{
	enum BlockType { VALUE, VARIABLE, UNARY, BINARY } type;
	double value;
	string variable;
	Unary unary;
	Binary binary;
	Block(double value);
	Block(const string& variable);
	Block(Unary unary);
	Block(Binary binary);
};

int getPrior(const string& oper);
bool isRightAssoc(const string& oper);
vector<Block> toRPN(const string& expr);
bool calc(double& res, const vector<Block>& sequence, const map<string, double>& vars);

class Expression
{
private:
	vector<Block> sequence;
	map<string, double> variables;
public:
	Expression();
	Expression(const string& expr);
	void setVariable(const string& variable, double value);
	bool consider(double& res) const;
};