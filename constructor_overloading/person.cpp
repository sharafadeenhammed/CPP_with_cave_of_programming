#include <sstream>
#include "person.h"

Person::Person(){
  age = 0;
  name = "undefined";
}

Person::Person(string newName){
  name = newName;
  age = 0;
}

Person::Person(string newName, int newAge){
  name = newName;
  age = newAge;
}

string Person::toString(){
  stringstream ss;
  ss << "name is " << name << " and age is " << age;
  return ss.str();
}