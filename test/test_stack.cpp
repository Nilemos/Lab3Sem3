#include "TStack.h"

#include <gtest.h>

TEST(TStack, stack_is_full)
{
  TStack <int> stack(3);
  stack.Push(1);
  stack.Push(2);
  stack.Push(3);
  EXPECT_EQ(true, stack.isFull());
}

TEST(TStack, stack_is_empty)
{
  TStack <int> stack(1);
  stack.Push(1);
  stack.Pop();
  EXPECT_EQ(true, stack.isEmpty());
}

TEST(TStack, managed_to_get_the_top_element)
{
  TStack <int> stack(4);
  stack.Push(1);
  stack.Push(2);
  stack.Push(3);
  stack.Push(4);
  stack.Pop();
  EXPECT_EQ(3, stack.TopElem());
}

TEST(TStack, return_correct_size)
{
  TStack <int> stack(4);
  stack.Push(1);
  stack.Push(2);
  stack.Push(3);
  stack.Push(4);
  stack.Pop();
  EXPECT_EQ(3, stack.Size());
}

TEST(TStack, you_cannot_extract_a_value_from_an_empty_stack)
{
  TStack <int> stack(1);
  stack.Push(1);
  stack.Pop();
  ASSERT_ANY_THROW(stack.Pop());
}

TEST(TStack, you_cannot_take_the_top_element_from_an_empty_stack)
{
  TStack <int> stack(1);
  stack.Push(1);
  stack.Pop();
  ASSERT_ANY_THROW(stack.TopElem());
}

TEST(TStack, the_pop_function_returns_the_correct_value)
{
  TStack <int> stack(4);
  stack.Push(1);
  stack.Push(2);
  stack.Push(3);
  stack.Push(4);
  EXPECT_EQ(4, stack.Pop());
}

TEST(TStack, copy_constructor_test)
{
  TStack <int> st(4);
  st.Push(10);
  st.Push(20);
  st.Push(30);
  st.Push(40);
  TStack <int> st2(st);
  st2.Pop();
  EXPECT_EQ(30, st2.Pop());

}