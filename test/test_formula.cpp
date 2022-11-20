#include "TFormula.h"
#include"TStack.h"
#include <gtest.h>

TEST(TFormula, test_GetPostfix_function)
{
  string exprStr = "(a+b)-b*c";
  TFormula expr(exprStr);
  EXPECT_EQ("ab+bc*-", expr.GetPostfix());
}
TEST(TFormula, test_GetInfix_function)
{
  string exprStr = "(a+b)-b*c";
  TFormula expr(exprStr);
  EXPECT_EQ("(a+b)-b*c", expr.GetInfix());
}
TEST(TFormula, incorrect_placement_of_brackets)
{
  string exprStr = "((a+b)-b*c";
  ASSERT_ANY_THROW(TFormula expr(exprStr));
}
TEST(TFormula, test_Calculate_function)
{
  string exprStr = "(a+b)-b*c";
  TFormula expr(exprStr);
  vector <char> operands = expr.GetOperands();
  map <char, double> values;
  values['a'] = 100;
  values['b'] = 10;
  values['c'] = 2;
  EXPECT_EQ(90, expr.Calculate(values));
}
TEST(TFormula, division_by_zero_is_not_possible)
{
  string exprStr = "a+b/(c-c)";
  TFormula expr(exprStr);
  vector <char> operands = expr.GetOperands();
  map <char, double> values;
  double value;
  values['a'] = 1;
  values['b'] = 2;
  values['c'] = 3;
  ASSERT_ANY_THROW(expr.Calculate(values));
}
TEST(TFormula, not_enough_operands)
{
  string exprStr = "a++b";
  TFormula expr(exprStr);
  vector <char> operands = expr.GetOperands();
  map <char, double> values;
  double value;
  values['a'] = 1;
  values['b'] = 2;
  ASSERT_ANY_THROW(expr.Calculate(values));
}