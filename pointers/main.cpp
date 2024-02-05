#include <iostream>

using namespace std;

void manipulate(double *pvalue)
{
  cout << "2. value of value at via pointer is " << *pvalue << endl;
  *pvalue = 7.45;
  cout << "3. value of value at via pointer is " << *pvalue << endl;
}

int main(int args, char **argv)
{
  double value = 12.75;
  cout << "1. value of value is " << value << endl;
  manipulate(&value);
  cout << "4. value of value is finally " << value << endl;
  return 0;
}