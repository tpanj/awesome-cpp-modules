import foo;
import speech;

#include <iostream>
#include <cstdlib>


int main()
{
  // Class creation and constructor call
  foo f;

  std::cout << get_phrase_sl() << std::endl;
  std::cout << get_phrase_es() << std::endl;

  // Using exported function output as agument to method
  f.helloworld(publicFunction(6, LUCKY_NUMBER) + publicFunction(5, LUCKY_NUMBER));
  return 0;
}
