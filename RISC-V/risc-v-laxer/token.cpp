#include <string>
#include "token.h"
using namespace std;

bool Token::IsNewline(char ch) {
   return ch == '\n';
}

bool Token::IsSpace(char ch) {
   return ch == ' ';
}

bool Token::IsComma(char ch) {
   return ch == ',';
}

bool Token::IsComment(char ch) {
   return ch == '#';
}

bool Token::IsNumeric(string &name) {
   for(char ch : name) {
      if(!IsDigit(ch)) return false;
   }
   return true;
}

bool Token::IsDigit(char ch) {
   return ch >= '0' && ch <= '9';
}

void Token::SkipSpaces(string &source, int &i) {
   while(!IsNewline(source[i]) && IsSpace(source[i])) i++;
}

void Token::SkipComment(string &source, int &i) {
   if(IsComment(source[i])) {
      while(!IsNewline(source[i])) i++;
   }
}

void Token::SkipLastSpace(string &s) {
   while(s.size() && IsSpace(s.back())) {
      s.pop_back();
   }
}
