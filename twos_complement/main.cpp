#include <iostream>

using namespace std;

int main(int args, char **argv)
{

  return 0;
}

// 000 =0
// 001 = 1
// 010 = 2
// 011 = 3
// 100 = -0
// 101 = -1
// 110 = -2
// 111 = -3

// 001 (1)+
// 101 (-1) =
// 110 (-2) wrong answer

// one's complement
// 000 =0
// 001 = 1
// 010 = 2
// 011 = 3
// 100 = -3
// 101 = -2
// 110 = -1
// 111 = -0

// 001 (1)+
// 110 (-1) =
// 111 (-0 = 0) right answer

// 0011 (1) +
// 0101 (-2) =
// 1000 add overflow bit to right: 000 + 1 = 001
// 001 (right answer)

// two's complement
// 000 =0
// 001 = 1
// 010 = 2
// 011 = 3
// 100 = -3
// 101 = -2
// 110 = -2
// 111 = -1
