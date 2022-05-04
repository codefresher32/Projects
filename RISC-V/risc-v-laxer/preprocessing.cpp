#include <string>
#include "preprocessing.h"


PreProcessing::PreProcessing(std::string source) {
   this->source = source;
   this->name = "";
   this->preprocess = "";
}

void PreProcessing::preprocessed() {
   for(int i = 0; i < source.size(); i++) {
      /// Operator Include
      name = OperatorString(i);
      preprocess += name;
      if(name.size() == 0) preprocess += '\n';
      if(!IsComment(source[i])) preprocess += source[i];
      SkipComment(source, i);
      if(IsNewline(source[i])) continue;

      /// Operand Include
      while(!IsNewline(source[i])) {
         name = OperandString(i);
         preprocess += name;
         SkipComment(source, i);
         SkipLastSpace(preprocess);
         preprocess += source[i];
         if(IsComma(source[i])) i++;
      }
   }
   return ;
}

std::string PreProcessing::GetPreProcessString() {
   return preprocess;
}

std::string PreProcessing::OperatorString(int &i) {
   name = "";
   SkipSpaces(source, i);
   while(!IsNewline(source[i]) && !IsSpace(source[i]) && !IsComment(source[i])) {
      name += source[i];
      i++;
   }
   return name;
}

std::string PreProcessing::OperandString(int &i) {
   name = "";
   SkipSpaces(source, i);
   while(!IsNewline(source[i]) && !IsComma(source[i]) && !IsComment(source[i])) {
      name += source[i];
      i++;
   }
   SkipLastSpace(name);
   return name;
}
