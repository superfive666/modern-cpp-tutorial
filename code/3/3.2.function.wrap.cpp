//
// 3.2.function.wrap.cpp
// chapter 03 runtime enhancement
// modern c++ tutorial
//
// created by changkun at changkun.de
// https://github.com/changkun/modern-cpp-tutorial
//

#include <functional>
#include <iostream>

using foo = void(int); // function pointer
void functional(foo f) { f(1); }

int foo2(int para) { return para; }

int foo3(int a, int b, int c) {
  // The printting function is to check the value of the variables passed in
  std::cout 
    << "a = " <<  a 
    << " b = " << b 
    << " c = " << c 
    << std::endl;
  return a + b + c;
}

int main() {
  auto f = [](int value) -> void { std::cout << value << std::endl; };
  functional(f); // call by function pointer, output: 1
  f(1);          // call by lambda expression, output: 1

  // std::function wraps a function that take int paremeter and returns int
  // value
  std::function<int(int)> func = foo2;

  int important = 10;
  std::function<int(int)> func2 = [&](int value) -> int {
    return 1 + value + important;
  };
  std::cout << func(10) << std::endl;
  // output: 10
  std::cout << func2(10) << std::endl;
  // output: 21

  // Additional sample code snnipet to run
  // auto important = std::make_unique<int>(10);
  // std::function<int(int)> func2 = [imp = *important](int value) -> int {
  //   return 1 + value + imp;
  // };
  // std::cout << func(10) << std::endl;
  // // output: 10
  // std::cout << func2(10) << std::endl;
  // // output: 21

  // bind parameter 1, 2 on function foo, and use std::placeholders::_1 as
  // placeholder for the first parameter.
  auto bindFoo = std::bind(foo3, std::placeholders::_1, 1, 2);
  // when call bindFoo, we only need one param left
  auto bs = bindFoo(1);
  // output: 112
  std::cout << bs << std::endl;
  // output: 4

  return 0;
}
