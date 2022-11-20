#include <iostream>
#include <iomanip>
#include "TFormula.h"
#include "TStack.h"

using namespace std;


int main()
{
  setlocale(LC_ALL, "Russian");


  TStack <int> pt(3);
  pt.Push(1);
  pt.Push(2);
  cout << "Размер стека " << pt.Size() << endl;
  cout << "Верхний элемент стека pt  " << pt.TopElem() << endl;
  pt.Pop();
  pt.Pop();
  pt.Push(3);
  cout << "Верхний элемент стека pt  " << pt.TopElem() << endl;
  cout << "Размер стека pt " << pt.Size() << endl;
  pt.Pop();

  if (pt.isEmpty()) {
    cout << "Стек пуст\n" << endl;
  }
  else {
    cout << "Стек не пуст\n" << endl;
  }

  TStack <int> pt2(4);
  pt2.Push(111);
  pt2.Push(180);
  pt2.Push(228);
  pt2.Push(337);
  cout << "Верхний элемент стека pt2  " << pt2.TopElem() << endl;
  cout << "Размер стека pt2 " << pt2.Size() << endl;
  TStack <int> pt3(pt2);
  cout << "Верхний элемент стека pt3  " << pt3.TopElem() << endl;
  cout << "Размер стека pt3 " << pt3.Size() << endl;

 
  string exprStr;
  cout << "Введите инфиксное выражение без пробелов " << endl;
  cin >> exprStr;
  TFormula expr(exprStr);
  cout << "Инфиксное выражение:  " << expr.GetInfix() << endl;
  cout << "Постфиксное выражение: " << expr.GetPostfix() << endl;
  vector <char> operands = expr.GetOperands();
  map <char, double> values;
  double value;
  for (const auto& operand : operands)
  {
    cout << "Введите значение для операнда " << operand << endl;
    cin >> value;
    values[operand] = value;
  }

  cout << "Результат = " << expr.Calculate(values) << endl;

  return 0;
}