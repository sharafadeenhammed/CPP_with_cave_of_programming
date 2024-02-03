#include <iostream>

using namespace std;

class Person
{
private:
  string name;

public:
  Person() {}
  // Person(const Person &person)
  // {
  //   // name == "this name " + person.name + "is copied...";
  //   name = "this name " + person.name + " is copied";
  // }
  void setName(string name)
  {
    this->name = name;
  }
  void speak() const // this method is marked const as it does not change any menber variables...
  {
    cout << "My name is " << this->name << endl;
    // this.name = "john" this line will result in to an error as it is making a change to a member variable
  }
};

int main(int args, char **argv)
{
  int number = 80; // variable int
  int *pNumber = &number;
  cout << number << endl;

  int number2 = 67;
  int const *pNumber2 = &number2; // a constant pointer (the reference cannot be changed...)

  const int number3 = 54;               // a constant int
  const int *const pNumber3 = &number3; // a constant pointer to a conatant int

  cout << "value of number3 : " << number3 << endl;
  const int *pTest = &number;

  Person person;
  person.setName("Hammed");
  person.speak();
  return 0;
}