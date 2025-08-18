#ifndef CAT_H_
#define CAT_H_ 1
using namespace std;

class Cat
{
  // private data members
private:
  bool happy;

  // public data members, and methods
public:
  bool catHappyState();
  void speak();
  void makeHappy();
  void makeSad();
};

#endif // CAT_H_