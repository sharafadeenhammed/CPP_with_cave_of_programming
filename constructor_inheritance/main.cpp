#include <iostream>

using namespace std;

// contructors are not inherited but the base class contructor get called...

class Machine
{
private:
  int id;

public:
  Machine() : id(0) { cout << "Machine no constructor argument called" << endl; }
  Machine(int id) : id(id) { cout << "Machine with arguments constructor called" << endl; }
  void info()
  {
    cout << "ID : " << id << endl;
  }
};

class Vehicle : public Machine
{
public:
  Vehicle() { cout << "Vehicle no constructor argument called" << endl; }
  Vehicle(int id) : Machine(id) { cout << "Vehicle with argument  constructor  called" << endl; }
};

class Car : public Vehicle
{
public:
  Car() : Vehicle(12) { cout << "Car no constructor argument called" << endl; }
};
int main(int args, char **argv)
{
  Vehicle vehicle(20);
  vehicle.info();

  return 0;
}
