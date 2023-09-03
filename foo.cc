module;

#include <iostream>

export module foo;

// Forwad declaration of function is not needed
// baceuse e.g. it was not used in cosntrucor in class declaration
// but if also want to hold signatures in one place..
// export int publicFunction(int a, int b);

// Whole class export
export class foo {
public:
  foo() = default;
  ~foo();
  void helloworld(int n);
};

// It can not be done in class declaration because of std:: import use
foo::~foo() {
    std::cout << "Destructor called \n";
}

// Method example
void foo::helloworld(int n) {
  std::cout << "hello world " << n << std::endl;
}

int privateFunction(int a, int b) {
  return a * b;
}

export int publicFunction(int a, int b) {
  return privateFunction(a, b);
}
