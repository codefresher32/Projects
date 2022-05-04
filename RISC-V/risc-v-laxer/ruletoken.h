#ifndef RULETOKEN_H_INCLUDED
#define RULETOKEN_H_INCLUDED

#pragma once
#include <string>
#include <map>
#include <set>
using namespace std;


set<string> Rule = {"op-code", "op-code operand", "op-code operand,operand", "op-code operand,operand,operand"};
map<string, int> Operator = {{"add", 3}, {"addi", 3}, {"sub", 3}, {"subi", 3}, {"la", 2}, {"li", 2}, {"ecall", 0}};
set<string> Operand = {"x0", "x1", "x2", "x3", "x4", "x5", "x6", "x7", "x8", "x9", "x10", "x11", "x12", "x13",
                       "x14", "x15", "x16", "x17", "x18", "x19", "x20", "x21", "x22", "x23", "x24", "x25", "x26",
                       "x27", "x28", "x29", "x30", "x31", "zero", "ra", "sp", "gp", "tp", "t0", "t1", "t2", "s0",
                       "fp", "s1", "a0", "a1", "a2", "a3", "a4", "a5", "a6", "a7", "s2", "s3", "s4", "s5", "s6",
                       "s7", "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"};

#endif // RULETOKEN_H_INCLUDED
