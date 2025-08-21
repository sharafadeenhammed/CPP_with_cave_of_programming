#include <iostream>
#include <sstream>

using namespace std;

int main(int args, char **argv)
{
  string name = "john";
  int age = 27;
  // stringstram gives us a convinient way for concatinating other
  // data type such as int, float char etc to a string
  // example is like so
  stringstream ss;
  ss << "name: " + name + " and is age: " << age;
  cout << ss.str() << endl;
}