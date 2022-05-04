#include <bits/stdc++.h>
#include "token.h"
#include "preprocessing.h"
#include "generategrammer.h"
#include "validgrammer.h"

using namespace std;



int main()
{
    ifstream inFile("input.txt");
    string source((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
    source += '\n';
    PreProcessing *p = new PreProcessing(source);
    p->preprocessed();
    GenerateGrammer *gg = new GenerateGrammer(p->GetPreProcessString());
    gg->generatedgrammer();
    ValidGrammer *vg = new ValidGrammer(p->GetPreProcessString(), gg->GetRuleString(), gg->GetOperators(), gg->GetOperands());
    vg->ValidityCheck();
    delete(p);
    delete(gg);
    delete(vg);
    return 0;
}
