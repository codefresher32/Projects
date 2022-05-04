#ifndef PREPROCESSING_H_INCLUDED
#define PREPROCESSING_H_INCLUDED

#pragma once
#include <string>
#include "token.h"
using namespace std;

class PreProcessing: public Token {
private:
   string source;
   string name;
   string preprocess;

public:
   PreProcessing(string source);
   void preprocessed();
   string OperatorString(int &i);
   string OperandString(int &i);
   string GetPreProcessString();
};

#endif // PREPROCESSING_H_INCLUDED
