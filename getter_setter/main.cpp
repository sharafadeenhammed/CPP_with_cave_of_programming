#include <iostream>
#include "person.h"
using namespace std;

int main(int args, char **argv)
{
  cout << "program started..." << endl;
  Person person;
  cout << person.getName() << endl;
  person.setName("Hammed");
  cout << person.getName() << endl;
  cout << person.toString() << endl;
  cout << "program ended..." << endl;
  return 0;
}