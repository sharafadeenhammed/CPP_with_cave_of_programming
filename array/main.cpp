#include <iostream>
using namespace std;

string myWords[][3] = {
    {"cat", "dog", "cattle"},
    {"lion", "leopard", "tiger"}
  };

int main(int args, char **argv ){
  for (uint32_t i = 0; i < sizeof(myWords)/sizeof(myWords[0]); i++){

    for (uint32_t j = 0; j < sizeof(myWords[i])/sizeof(string); j++){
      cout << myWords[i][j] << " " << flush;
    }
    cout << endl;
  }
    return 0;
}

