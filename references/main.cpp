#include <iostream>

using namespace std;

void changeSomething(float &value)
{
  value *= 2;
}

int main(int args, char **argv)
{
  // integer value...
  int intValue1 = 18;

  // refrence variable to integer value (integer variable alias/nickname)...
  int &intValue2 = intValue1;
  intValue2 = 200;

  cout << "intValue1 : " << intValue1 << endl;
  cout << "intValue2 : " << intValue2 << endl;

  float floatValue = 20.56;
  cout << floatValue << " : ";
  changeSomething(floatValue);
  cout << floatValue << endl;

  return 0;
}