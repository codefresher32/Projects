#ifndef VALIDGRAMMER_H_INCLUDED
#define VALIDGRAMMER_H_INCLUDED

#pragma once
#include <bits/stdc++.h>
#include "token.h"
using namespace std;

class ValidGrammer: public Token {
private:
   int Line;
   string source;
   string generated_rule;
   vector<string> Operators;
   vector<vector<string>> Operands;
   set<string> Rule;
   set<string> Operand;
   map<string, int> Operator;
   bool IsValidLine(string &name);
   bool IsValidOperator(string name);
   bool IsValidOperand(vector<string> &vs);
   bool IsValid(string &name);
   string Get(string &s, int &i);

public:
   ValidGrammer(string source, string generated_rule, vector<string> Operators, vector<vector<string>> Operands);
   void ValidityCheck();
};

#endif // VALIDGRAMMER_H_INCLUDED
