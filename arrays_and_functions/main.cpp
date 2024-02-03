#include <iostream>

using namespace std;

void show1(const int numOfElem, const string friuts[])
{
  cout << "running show1...." << endl;
  // cout << sizeof(friuts) << endl; // this loses the context of items in the array ... but return th size of a pointer(long ) instead
  for (int i = 0; i < numOfElem; i++)
  {
    cout << friuts[i] << endl;
  }
  cout << endl;
}

void show2(const int numOfElem, string *friuts)
{
  cout << "running show2...." << endl;
  // cout << sizeof(friuts) << endl; // this loses the context of items in the array ... but return th size of a pointer(long ) instead
  for (int i = 0; i < numOfElem; i++)
  {
    cout << friuts[i] << endl;
  }
  cout << endl;
}

void show3(string (&fruits)[3])
{
  cout << "running show3...." << endl;
  for (int i = 0; i < sizeof(fruits) / sizeof(string); i++)
  {
    cout << fruits[i] << endl;
  }
}

char *getMemory()
{
  char *newMem = new char[100];
  return newMem;
}

void freeMem(char *mem)
{
  delete[] mem;
}

int main(int args, char **argv)
{
  string fruits[] = {"oranges", "bananas", "grapes"};
  cout << sizeof(fruits) << endl;
  show1(sizeof(fruits) / sizeof(string), fruits);
  show2(sizeof(fruits) / sizeof(string), fruits);
  show3(fruits);
  char *charMem = getMemory(); // allocate memory...
  freeMem(charMem);            // deallocate memory...

  return 0;
}