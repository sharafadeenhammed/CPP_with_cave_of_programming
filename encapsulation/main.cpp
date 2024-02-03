#include <iostream>

using namespace std;

// data encapsulation isthe process of hidding properties and methods away from end user i.e these methods and properties are not accesible out of the class
class Animal
{
private:
  string name; // name is being encapsulated

private:
  string getName() // getName is being encapsulated
  {
    return name;
  }

public:
  Animal(string name) : name(name) {}
  void info()
  {
    cout << "My name is : " << getName() << endl;
  }
};

int main(int args, char **argv)
{
  Animal frog("frog");
  frog.info();
  return 0;
}
