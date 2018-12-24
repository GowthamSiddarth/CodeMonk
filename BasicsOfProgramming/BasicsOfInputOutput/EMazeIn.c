/**
Ankit is in maze. The command center sent him a string which decodes to come out
from the maze. He is initially at (0, 0). String contains L, R, U, D denoting
left, right, up and down. In each command he will traverse 1 unit distance in
the respective direction.

For example if he is at (2, 0) and the command is L he will go to (1, 0).

Input:

Input contains a single string.

Output:

Print the final point where he came out.

Constraints:

1 ≤ |S| ≤ 200

https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/e-maze-in-1aa4e2ac/
*/
#include <stdio.h>
#include <string.h>

void navigate(char *steps, int *startX, int *startY) {
  int idx = 0;
  while ('\0' != steps[idx]) {
    switch (steps[idx]) {
      case 'L':
        *startX = *startX - 1;
        break;
      case 'R':
        *startX = *startX + 1;
        break;
      case 'U':
        *startY = *startY + 1;
        break;
      case 'D':
        *startY = *startY - 1;
        break;
    }

    idx++;
  }
}

int main() {
  char steps[201];
  memcpy(steps, "LLRDDR", 7);

  int x = 0, y = 0;
  printf("%s\n", steps);
  printf("%d %d\n", x, y);

  navigate(steps, &x, &y);
  printf("%d %d\n", x, y);

  return 0;
}