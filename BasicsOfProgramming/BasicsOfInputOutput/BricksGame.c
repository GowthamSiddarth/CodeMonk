/**
Patlu and Motu works in a building construction, they have to put some number of
bricks N from one place to another, and started doing their work. They decided ,
they end up with a fun challenge who will put the last brick.

They to follow a simple rule, In the i'th round, Patlu puts i bricks whereas
Motu puts ix2 bricks.

There are only N bricks, you need to help find the challenge result to find who
put the last brick.

Input:

First line contains an integer N.

Output:

Output "Patlu" (without the quotes) if Patlu puts the last bricks
,"Motu"(without the quotes) otherwise.

Constraints:

1 ≤ N ≤ 10000

https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/bricks-game-5140869d/
*/
#define true 1
#include <stdio.h>

char* getWorkerNameForLastBrick(int numOfBricks) {
  int itr = 1;
  int patluCount, motuCount, totalCount = 0;

  while (true) {
    patluCount = itr;
    totalCount += patluCount;
    if (totalCount >= numOfBricks) {
      return "PATLU";
    }

    motuCount = 2 * itr;
    totalCount += motuCount;
    if (totalCount >= numOfBricks) {
      return "MOTU";
    }

    itr++;
  }
}

int main() {
  int numOfBricks = 19;
  char* worker = getWorkerNameForLastBrick(numOfBricks);
  printf("%s", worker);

  return 0;
}