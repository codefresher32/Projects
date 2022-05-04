#include <bits/stdc++.h>
#include "validgrammer.h"
using namespace std;


ValidGrammer::ValidGrammer(string source, string generated_rule, vector<string> Operators, vector<vector<string>> Operands) {
   Line = 0;
   this->source = source;
   this->generated_rule = generated_rule;
   this->Operators = Operators;
   this->Operands = Operands;
   Rule = {"op-code", "op-code operand", "op-code operand,operand", "op-code operand,operand,operand"};
   Operator = {{"add", 3}, {"addi", 3}, {"sub", 3}, {"subi", 3}, {"la", 2}, {"li", 2}, {"ecall", 0}};
   Operand = {"x0", "x1", "x2", "x3", "x4", "x5", "x6", "x7", "x8", "x9", "x10", "x11", "x12", "x13",
                       "x14", "x15", "x16", "x17", "x18", "x19", "x20", "x21", "x22", "x23", "x24", "x25", "x26",
                       "x27", "x28", "x29", "x30", "x31", "zero", "ra", "sp", "gp", "tp", "t0", "t1", "t2", "s0",
                       "fp", "s1", "a0", "a1", "a2", "a3", "a4", "a5", "a6", "a7", "s2", "s3", "s4", "s5", "s6",
                       "s7", "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"};
}

void ValidGrammer::ValidityCheck() {
   ofstream right_instractions, wrong_instractions;
   right_instractions.open("right.txt");
   wrong_instractions.open("wrong.txt");
   string name, rule_name;
   for(int i = 0, j = 0; i < source.size(); i++, j++) {
      name = Get(source, i);
      rule_name = Get(generated_rule, j);
      if(name.size()) {
         if(IsValid(rule_name)) {
            right_instractions << "Line ";
            right_instractions << Line + 1;
            right_instractions << ": ";
            right_instractions << name;
            right_instractions << "\n";
         }
         else {
            wrong_instractions << "Line ";
            wrong_instractions << Line + 1;
            wrong_instractions << ": ";
            wrong_instractions << name;
            wrong_instractions << "\n";
         }
      }
      Line++;
   }
   right_instractions.close();
   wrong_instractions.close();
}

string ValidGrammer::Get(string &s, int &i) {
   string name = "";
   while(!IsNewline(s[i])) {
      name += s[i];
      i++;
   }
   return name;
}

bool ValidGrammer::IsValidLine(string &name) {
   return Rule.find(name) != Rule.end() && Operands[Line].size() == Operator[Operators[Line]];
}

bool ValidGrammer::IsValidOperator(string name) {
   transform(name.begin(), name.end(), name.begin(), ::tolower);
   return Operator.find(name) != Operator.end();
}

bool ValidGrammer::IsValidOperand(vector<string> &vs) {
   for(string name : vs) {
      bool ok = Operand.find(name) != Operand.end() || IsNumeric(name);
      if(!ok) return false;
   }
   return true;
}

bool ValidGrammer::IsValid(string &name) {
   return IsValidLine(name) && IsValidOperator(Operators[Line]) && IsValidOperand(Operands[Line]);
}

