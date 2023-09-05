module;

#include <iostream>

export module foo;

export extern const int LUCKY_NUMBER = 7;

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

// Exporting namespaces also works: hi::english() and hi::french() will be visible.
export namespace hi
{
    char const* english() { return "Hello"; }
    char const* french()  { return "Salut"; }
}

// Method example
void foo::helloworld(int n) {
  std::cout << hi::english() << " world " << n << std::endl;
}

int privateFunction(int a, int b) {
  return a * b;
}

export int publicFunction(int a, int b) {
  return privateFunction(a, b);
}
