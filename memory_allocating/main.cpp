#include <iostream>

using namespace std;

class Person
{
private:
  string name;

public:
  Person()
  {
    cout << "person object created..." << endl;
  }
  ~Person()
  {
    cout << "Destroying person name: " << this->name << endl;
  }
  void setName(string name)
  {
    this->name = name;
  }
  void speak()
  {
    cout << "My name is " << this->name << endl;
  }
  void clean()
  {
    cout << "cleaning person with name :" << this->name << endl;
    delete this;
  }
};

int main(int args, char **argv)
{
  int *myint = new int;
  delete myint;

  Person *people = new Person[10];
  people[5].setName("James...");
  people[5].speak();
  delete[] people;

  char c = 'a';
  string name(10, c);

  cout << name << endl;
  return 0;
}