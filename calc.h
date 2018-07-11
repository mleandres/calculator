#ifndef CALC_H
#define CALC_H
#include <iostream>

struct Calc {

  Calc();
  Calc(const Calc &other);

  bool error;
  int display;
  char oper;
  int result;
  int memory;

  void digit(int digit);
  void op(char opera);
  void equals();

  void memPlus();
  void memClear();
  void memRecall();

  bool isError();

  void allClear();
};

std::ostream &operator<<(std::ostream &out, const Calc &c);

#endif

