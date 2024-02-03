#include <iostream>
#include <cmath>
using namespace std;

/*
  arithmetic operators...
  1. + addition operator
  2. += compound addition operator
  3. - subtraction operator
  4. -= compound subtraction operator
  5. / division operator
  6. /= compound division operator
  9. * multiplication operator
  10. *= compound multiplication operator
  11. % modulos operator (only works for integer values)
  12. %= compound modulos operator (only works for integer values)
  13. power operator using the pow() helper function from the cmath standard library
  14. aritmetic precedence and use of "()"

*/

int main(int args, char **argv)
{
  int int1 = 10;
  int int2 = 3;
  float float1 = 10.0;
  float float2 = 3.0;
  //  addition operation
  cout << "addition opertion on integer values is " << int1 + int2 << endl;
  cout << "addition opertion on float values is " << float1 + float2 << endl
       << endl;

  // subtraction operation
  cout << "subtraction opertion on integer values is " << int1 - int2 << endl;
  cout << "subtraction opertion on float values is " << float1 - float2 << endl
       << endl;

  // division operation
  cout << "division opertion on integer values is " << int1 / int2 << endl;
  cout << "division opertion on float values is " << float1 / float2 << endl
       << endl;

  // multiplication operation
  cout << "multiplication opertion on integer values is " << int1 * int2 << endl;
  cout << "multiplication opertion on float values is " << float1 * float2 << endl
       << endl;

  // modulos operation
  cout << "modulos opertion on integer values is " << int1 % int2 << endl
       << endl;

  // compound modulos operation
  {
    int value = int1;
    value %= int2;
    cout << "compound modulos opertion on integer values is " << value << endl
         << endl;
  }

  // power operator
  {
    cout << "power opertion on integer values is " << pow(int1, int2) << endl;
    cout << "power opertion on float values is " << pow(float1, float2) << endl
         << endl;
  }

  return 0;
}