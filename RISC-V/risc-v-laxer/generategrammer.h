#ifndef GENERATEGRAMMER_H_INCLUDED
#define GENERATEGRAMMER_H_INCLUDED

#pragma once
#include <string>
#include <vector>
#include "token.h"
using namespace std;

class GenerateGrammer: public Token {
private:
   string source;
   string generated_rule;
   vector<string> Operators;
   vector<vector<string>> Operands;

public:
   GenerateGrammer(string source);
   void generatedgrammer();
   string OperatorString(int &i);
   string OperandString(int &i);
   string GetRuleString();
   vector<string> GetOperators();
   vector<vector<string>> GetOperands();
};


#endif // GENERATEGRAMMER_H_INCLUDED
