import foo;
import speech;

#include <cstdio>

int main()
{
  // Class creation and constructor call
  foo f;

  printf("%s\n%s\n", get_phrase_sl(), get_phrase_es());

  // Using exported function output as agument to method
  f.helloworld(publicFunction(6, LUCKY_NUMBER) + publicFunction(5, LUCKY_NUMBER));
  return 0;
}
