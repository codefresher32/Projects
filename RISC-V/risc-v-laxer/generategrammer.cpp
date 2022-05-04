#include <string>
#include <vector>
#include "generategrammer.h"
using namespace std;


GenerateGrammer::GenerateGrammer(string source) {
   this->source = source;
   this->generated_rule = "";
}

void GenerateGrammer::generatedgrammer() {
   for(int i = 0; i < source.size(); i++) {
      /// Operator rule include
      string name = OperatorString(i);
      Operators.push_back(name);
      if(name.size()) {
         generated_rule += "op-code";
      }
      generated_rule += source[i];

      /// Operand rule include
      vector<string> temp;
      while(!IsNewline(source[i])) {
         name = OperandString(i);
         temp.push_back(name);
         generated_rule += "operand";
         generated_rule += source[i];
         if(IsComma(source[i])) i++;
      }
      Operands.push_back(temp);
   }
}

string GenerateGrammer::GetRuleString() {
   return generated_rule;
}

vector<string> GenerateGrammer::GetOperators() {
   return Operators;
}

vector<vector<string>> GenerateGrammer::GetOperands() {
   return Operands;
}

string GenerateGrammer::OperatorString(int &i) {
   string name = "";
   SkipSpaces(source, i);
   while(!IsNewline(source[i]) && !IsSpace(source[i]) && !IsComment(source[i])) {
      name += source[i];
      i++;
   }
   return name;
}

string GenerateGrammer::OperandString(int &i) {
   string name = "";
   SkipSpaces(source, i);
   while(!IsNewline(source[i]) && !IsComma(source[i]) && !IsComment(source[i])) {
      name += source[i];
      i++;
   }
   SkipLastSpace(name);
   return name;
}

