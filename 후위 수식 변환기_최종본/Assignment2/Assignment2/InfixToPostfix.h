#ifndef __INFIX_TO_POSTFIX_H__
#define __INFIX_TO_POSTFIX_H__
#include <string>
using namespace std;

string read_expression(string s);
string convert_to_postfix(string s);
double evaluate_postfix(string s);

#endif