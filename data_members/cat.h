#ifndef CAT_H_
#define CAT_H_ 1
#include<iostream>

using namespace std;

class Cat{
  private:
    bool happy;

  public:
    void speak();
    void makeHappy();
    void makeSad();
 };

#endif // CAT_H_ 