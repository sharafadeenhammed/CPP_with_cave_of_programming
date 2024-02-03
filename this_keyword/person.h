#ifndef PERSON_H_
#define PERSON_H_ 1


#include <iostream>

using namespace std;

class Person{
  private:
    int age;
    string name;
  
  public:
    Person();
    Person(string, int);
    string toString();
};

#endif // PERSON_H_