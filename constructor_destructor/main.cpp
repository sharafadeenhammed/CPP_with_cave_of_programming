#include <iostream>
#include"cat.h"
using namespace std;

int main(int args, char **argv){
  cout << "program started..." << endl;
  {
    // putting the class object in its own scope block to see the effect of
    // constrctor and destructor of the Cat class...
    Cat cat;
    cat.speak();
  }
  cout << "program ended..." << endl;
  return 0;
} 