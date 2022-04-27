//
// 3.5.move.semantics.cpp
// modern c++ tutorial
//
// created by changkun at changkun.de
// https://github.com/changkun/modern-cpp-tutorial
//

#include <iostream>

class A {
public:
  int *pointer, *val;

  A() : pointer(new int(1)), val(new int(3)) {
    std::cout << "construct " << pointer << std::endl;
  }

  A(A &a) : pointer(new int(*a.pointer)), val(new int(*a.val)) {
    // meaningless object copy
    std::cout << "copy " << pointer << std::endl;
  }

  A(A &&a) : pointer(a.pointer), val(a.val) {
    a.pointer = nullptr;
    a.val = nullptr;
    std::cout << "move " << pointer << std::endl;
  }

  ~A() {
    std::cout << "destruct " << pointer << std::endl;
    delete pointer;
    delete val;
  }
};

// avoid compiler optimization
A return_rvalue(bool test) {
  A a, b;
  if (test)
    // equal to static_cast<A&&>(a);
    return a;
  else
    // equal to static_cast<A&&>(b);
    return b;
}

int main() {
  A obj = return_rvalue(false);

  std::cout << "obj:" << std::endl;
  std::cout << obj.pointer << std::endl;
  std::cout << obj.val << std::endl;
  std::cout << *obj.pointer << std::endl;
  std::cout << *obj.val << std::endl;
  // obj:
  // <address of the newly allocated integer (can be different each time)>
  // 1
  // destruct <address of the integer>: this is destructor of the obj
  return 0;
}
