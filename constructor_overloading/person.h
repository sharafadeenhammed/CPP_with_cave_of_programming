#ifndef PERSON_H_
#define PERSON_H_ 1
#include<iostream>

using namespace std;

class Person{
  private:
    string name;
    int age;

  public:
    Person();
    Person(string);
    Person(string, int);
    string toString();
};

#endif // PERSON_H_

