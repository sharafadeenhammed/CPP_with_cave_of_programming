#include <iostream>
#include "person.h"

using namespace std;

Person::Person()
{
  cout << "Person Created..." << endl;
  name = "no name";
}

Person::~Person()
{
  cout << "Person destoyed..." << endl;
}

void Person::setName(string newName)
{
  name = newName;
}

string Person::getName()
{
  return name;
}

string Person::toString()
{
  return "Person's name is, " + name;
}
