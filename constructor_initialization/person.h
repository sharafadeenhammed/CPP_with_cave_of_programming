#ifndef PERSON_H_
#define PERSON_H_ 1
#include <iostream>

using namespace std;

class Person {
  private:
    string name;
    int age;

  public:
    Person(): name("undefined"), age(0){};
    Person(string name, int age): name(name), age(age){}
    string toString();
};

#endif // PERSON_H_