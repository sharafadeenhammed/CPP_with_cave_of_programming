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
  ~Person() { cout << "person object destroyed..." << endl; }
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
  Person *const pPerson = new Person(); // allocating memory for a new person object and return the pointer.

  // invoking the person methods with the . operator from the pointer
  //(*person).setName("John");
  //(*person).speak();

  // invoking the person methods using the -> operator with the pointer.
  pPerson->setName("John");
  pPerson->speak();

  // do not do this
  // Person *pPerson2 = NULL;
  // delete pPerson2;

  // freeing pPerson allocated memory.
  delete pPerson;

  return 0;
}