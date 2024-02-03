#include "person.h"


int main(int args, char ** argv){
  Person person;
  Person person2("hammed", 15);
  cout << person.toString() << endl;
  cout << person2.toString() << endl;
  return 0;
}