#include <sstream>
#include "person.h"

string Person::toString()
{
  stringstream ss;
  ss << "name is " << name << " and age is " << age;
  return ss.str();
}