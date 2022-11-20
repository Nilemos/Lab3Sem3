#include "TStack.h"
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
class TFormula
{
protected: 
  string InfixForm; 
  string PostfixForm;
  vector <char> lexems; 
  map <char, int> priority; 
  map <char, double> opers; 
public: 
  TFormula(string _infix); 
  string GetInfix() const; 
  string GetPostfix() const; 
  vector <char> GetOperands() const; 
  double Calculate(const map <char, double>& values); 
  void ToPostfix(); 
  void Par(); 
};
