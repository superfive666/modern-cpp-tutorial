//
// 3.3.rvalue.cpp
// modern c++ tutorial
//
// created by changkun at changkun.de
// https://github.com/changkun/modern-cpp-tutorial
//

#include <iostream>
#include <string>

void reference(std::string &str) { std::cout << "lvalue" << std::endl; }
void reference(std::string &&str) { std::cout << "rvalue" << std::endl; }

int main() {
  // lv1 is a lvalue
  std::string lv1 = "string,";

  // illegal, rvalue can't ref to lvalue
  // std::string&& r1 = lv1;

  // legal, std::move can convert lvalue to rvalue
  std::string &&rv1 = std::move(lv1);
  std::cout << rv1 << std::endl; // string,

  // legal, const lvalue reference can extend temp variable's lifecycle
  const std::string &lv2 = lv1 + lv1;
  // illegal, const ref can't be modified
  // lv2 += "Test";
  std::cout << lv2 << std::endl; // string,string

  // legal, rvalue ref extend lifecycle
  std::string &&rv2 = lv1 + lv2;

  reference(rv2);
  // output: lvalue

  // legal, non-const reference can be modified
  rv2 += "string";

  std::cout << rv2 << std::endl;
  // output: string,string,string,string

  reference(rv2);
  // output: lvalue

  return 0;
}
