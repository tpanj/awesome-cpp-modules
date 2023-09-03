import foo;

int main()
{
  // Class creation and constructor call
  foo f;

  // Using exported function output as agument to method
  f.helloworld(publicFunction(6, 7) + publicFunction(5, 7));
  return 0;
}
