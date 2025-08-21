#include <iostream>

using namespace std;

// static keyword is uded to create properties and methods tha are now uniqueo to a particular object instance but can be accesed without the need of creating an instance of the class and all static property is acessible   to every object created

// .h source file
class Test
{
private:
  int id;
  static int count;

public:
  static const int MAX = 100;

public:
  Test();
  static void showInfo();
  int getId();
};

// .cpp source file
Test::Test() : id(++count) {}

void Test::showInfo()
{
  cout << "current count Value : " << count << endl;
}

int Test::getId()
{
  return id;
}

int Test::count = 0;

int main(int args, char **argv)
{
  cout << "Constant value of max : " << Test::MAX << endl;
  Test test;
  cout << "test one id : " << test.getId() << endl;
  Test test2;
  Test::showInfo();
  return 0;
}