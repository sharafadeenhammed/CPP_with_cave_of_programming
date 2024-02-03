#include <sstream>
#include "person.h"


Person::Person(){
  name = "";
  age = 0;
}

Person::Person(string name, int age){
  this->name = name;
  this->age = age;
  cout << "memory location for the object " << name << " is " << this << endl;
}


string Person::toString(){
  stringstream ss;
  ss << "name is " << name << " and age is " << age;
  return ss.str();
}


