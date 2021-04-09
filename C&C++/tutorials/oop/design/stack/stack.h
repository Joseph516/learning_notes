#pragma once

template <typename T>
class Stack {
  public:
  Stack() {}
  virtual ~Stack() {}

  virtual void pop() = 0;
  virtual T top() = 0;
  virtual void push(T e) = 0;
  virtual bool empty() = 0;
};