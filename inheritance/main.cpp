#include <iostream>

using namespace std;

class Animal
{

public:
  void speak()
  {
    cout << "animal class speaking..." << endl;
  }
};

class Cat : public Animal // extending animal class...
{
public:
  void jump()
  {
    cout << "Cat jumping..." << endl;
  }
};

class Tiger : public Cat
{
public:
  void attackAntelope()
  {
    cout << "Attacking antelope..." << endl;
  }
};

int main(int args, char **argv)
{
  Animal animal;
  animal.speak();
  Cat cat;
  cat.speak();
  cat.jump();
  Tiger tiger;
  tiger.jump();
  tiger.speak();
  tiger.attackAntelope();

  return 0;
}