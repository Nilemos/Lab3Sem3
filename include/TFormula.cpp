#include "TFormula.h"

void TFormula::ToPostfix()
{
  Par(); 
  TStack <char> stack; 
  char stackSymbol; 
  int OpenBreketsCount = 0;
  int CloseBreketsCount = 0; 
  for (char symbol : lexems)
  {
    if (symbol == '(')
    {
      stack.Push(symbol); 
      OpenBreketsCount++; 
      continue; 
    }
    else if (symbol == ')')
    {
      stackSymbol = stack.Pop(); 
      CloseBreketsCount++; 
      while (stackSymbol != '(')
      {
        PostfixForm += stackSymbol; 
        stackSymbol = stack.Pop();
      }
      continue; 
    }
    else if ((symbol == '+') || (symbol == '-') || (symbol == '*') || (symbol == '/'))
    {
      while (!stack.isEmpty())
      {
        stackSymbol = stack.Pop(); 
        if (priority[symbol] <= priority[stackSymbol])
        {
          PostfixForm += stackSymbol; 
        }
        else
        {
          stack.Push(stackSymbol); 
          break; 
        }
      }
      stack.Push(symbol); 
      continue; 
    }
    else
    {
      opers.insert({ symbol,0.0 }); 
      PostfixForm += symbol;
    }
  }
  while (!stack.isEmpty())
  {
    stackSymbol = stack.Pop();
    PostfixForm += stackSymbol; 
  }
  if (OpenBreketsCount != CloseBreketsCount)
    throw "ERROR"; 
}

void TFormula::Par()
{
  for (char i : InfixForm)
    lexems.push_back(i); 
}

TFormula::TFormula(string _InfixForm)
{
  InfixForm = _InfixForm; 
  priority = { {'+',1},{'-',1},{'*',2},{'/',2} };
  ToPostfix();
}

string TFormula::GetInfix() const
{
  return InfixForm; 
}

string TFormula::GetPostfix() const
{
  return PostfixForm; 
}

vector <char> TFormula::GetOperands() const
{
  vector <char> op;
  for (const auto& symbol : opers)
    op.push_back(symbol.first); 
  return op; 
}

double TFormula::Calculate(const map<char, double>& values)
{
  for (auto& val : values)
  {
    try
    {
      opers.at(val.first) = val.second;
    }
    catch (out_of_range& c) {}
  }
  TStack <double> stack; 
  double leftOper, rightoper; 
  for (char lexem : PostfixForm)
  {
    if (lexem == '+')
    {
      if (stack.isEmpty())
        throw "ERROR";
      rightoper = stack.Pop();
      leftOper = stack.Pop();
      stack.Push(leftOper + rightoper);
      continue;
    }
    else if (lexem == '-')
    {
      if (stack.isEmpty())
        throw "ERROR";
      rightoper = stack.Pop();
      leftOper = stack.Pop();
      stack.Push(leftOper - rightoper);
      continue;
    }
    else if (lexem == '*')
    {
      if (stack.isEmpty())
        throw "ERROR";
      rightoper = stack.Pop();
      leftOper = stack.Pop();
      stack.Push(leftOper * rightoper);
      continue;
    }
    else if (lexem == '/')
    {
      if (stack.isEmpty())
        throw "ERROr";
      rightoper = stack.Pop();
      leftOper = stack.Pop();
      if (rightoper == 0)
        throw "ERROR";
      stack.Push(leftOper / rightoper);
      continue;
    }
    else
      stack.Push(opers[lexem]);
  }
  return stack.Pop();
}
