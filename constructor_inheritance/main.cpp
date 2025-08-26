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

class Vehicle : public Machine // vehicle call extending the machine class
{
public:
  Vehicle() { cout << "Vehicle no constructor argument called" << endl; }
  Vehicle(int id) : Machine(id) { cout << "Vehicle with argument  constructor  called" << endl; }
};

class Car : public Vehicle // car class extending the vehicle class
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
