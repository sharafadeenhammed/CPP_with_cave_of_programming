#include "person.h"
#include "person2.h"

using namespace person1;
int main(int args, char **argv)
{
  Person person; // person created implictly from the picked up namespace(person1)
  person.speak();
  person2::Person person2; // person created expilcity from the person2 namespace
  person2.speak();
  person1::Person person3; // person created expicitly from the person1 namespace
  person3.speak();

  return 0;
}