#include <iostream>

using namespace std;

class Person
{
private:
  string name;

public:
  Person()
  {
    cout << "Creating person object..." << endl;
  }
  Person(const Person &person) : name(person.name)
  {
    cout << "Creating person object with copy constuctor..." << endl;
  }
  ~Person()
  {
    cout << "Destroying person object... name: " << this->name << endl;
  }
  void setName(string name)
  {
    this->name = name;
  }
  void speak() const
  {
    cout << "hello my name is " << name << endl;
  }
  void clean() const
  {
    cout << "cleaning person with name: " << this->name << endl;
    delete this;
  }
};

Person createPerson(string name)
{
  Person person;
  person.setName(name);
  return person;
}

Person &CreatePersonByReference(string name) // bad practise...
{
  Person person;
  person.setName(name);
  return person;
}

Person *createPersonByPointer(string name)
{
  Person *person = new Person;
  person->setName(name);
  return person;
}

int main(int args, char **argv)
{
  Person person = createPerson("Dray");
  person.speak();
  // Person person2 = CreatePersonByReference("Lowell"); // bad practise
  // person2.speak(); // program crashed calling this method
  Person *person3 = createPersonByPointer("Sarah");
  person3->speak();
  person3->clean();
  return 0;
}