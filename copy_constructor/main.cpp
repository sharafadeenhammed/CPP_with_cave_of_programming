#include <iostream>

using namespace std;

class Person
{
private:
  string name;

public:
  Person() { cout << "person object created..." << endl; }
  Person(const Person &person) : name(person.name)
  {
    cout << "person object created with the copy constructor..." << endl;
    // person.setName("sdfsfdfg"); // this will not work as person is marked const only methods marked as const will work.
  }
  void setName(string name)
  {
    this->name = name;
  }
  void speak() const
  {
    cout << "my name is " << name << endl;
  }
};

int main(int args, char **argv)
{
  Person person;
  person.setName("John");
  Person person2 = person;
  person2.speak();
  person2.setName("Charles");
  person.speak();
  person2.speak();
  Person person3(person);
  person3.speak();

  return 0;
}