//
// 3.4.historical.cpp
// modern c++ tutorial
//
// created by changkun at changkun.de
// https://github.com/changkun/modern-cpp-tutorial
//

#include <iostream>

int main() {
  // illegal, non-const lvalue reference cannot ref rvalue
  // int &a = std::move(1);

  // legal, const lvalue reference can
  const int &b = std::move(1);

  std::cout << b << std::endl;
}
