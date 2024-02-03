


#include "person.h"


int main (int args, char** argv){
  Person person;
  Person person2("hammed");
  Person person3("john", 30);
  cout << person.toString() << endl;
  cout << person2.toString() << endl;
  cout << person3.toString() << endl;
  return 0;
}