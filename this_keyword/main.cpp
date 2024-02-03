#include "person.h"


int main(int args, char ** argv){
  Person person;
  Person person2("hammed", 38);
  Person person3("julie", 20);
  cout << person.toString() << " and memory location is at " << &person << endl;
  cout << person2.toString() << " and memory location is at " << &person2 << endl;
  cout << person3.toString() << " and memory location is at " << &person3 << endl;
  return 0;
}