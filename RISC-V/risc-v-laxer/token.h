#ifndef TOKEN_H_INCLUDED
#define TOKEN_H_INCLUDED

#include <string>
using namespace std;

class Token {

public:
   bool IsNewline(char ch);
   bool IsSpace(char ch);
   bool IsComma(char ch);
   bool IsComment(char ch);
   bool IsNumeric(string &name);
   bool IsDigit(char ch);
   void SkipSpaces(string &source, int &i);
   void SkipComment(string &source, int &i);
   void SkipLastSpace(string &s);
};

#endif // TOKEN_H_INCLUDED
