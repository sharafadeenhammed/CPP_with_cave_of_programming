#ifndef CAT_H_
#define CAT_H_ 1
#include <iostream>

using namespace std;

class Person{
  private:
    string name  = "" ;

  public:
    Person();
    ~Person();
    void setName(string name);
    string getName();
 };

#endif // CAT_H_ 