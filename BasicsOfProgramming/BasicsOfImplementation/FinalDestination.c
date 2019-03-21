/**
Bob and Khatu are stuck in matrix. The command center sent them a string which
decodes to the their final destination. Since Bob and Khatu are not good at
problem solving help them to figure out their final destination. They are
initially at (0, 0). String contains L, R, U, D denoting left, right, up and
down. In each command they will traverse 1 unit distance in the respective
direction. For example if they are at (2, 0) and the command is they will go to
(1, 0).

Input:

Input contains a single string.

Output:

Print the final destination location of Bob and Khatu.

Constraints:

1 ≤ |S| ≤ 10^5

https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/final-destination-cakewalk/
*/
#define MAX_LEN 100000

#include <stdio.h>
#include <string.h>

struct Position {
    int x, y;
};

struct Position getFinalDestination(char * steps) {
    struct Position finalDestination;
    finalDestination.x = 0;
    finalDestination.y = 0;

    int idx = 0;
    while ('\0' != steps[idx]) {
        switch (steps[idx]) {
            case 'L':
                finalDestination.x = finalDestination.x - 1;
                break;
            case 'R':
                finalDestination.x = finalDestination.x + 1;
                break;
            case 'U':
                finalDestination.y = finalDestination.y + 1;
                break;
            case 'D':
                finalDestination.y = finalDestination.y - 1;
                break;
        }

        idx++;
    }

    return finalDestination;
}

int main() {
    char steps[MAX_LEN];
    memcpy(steps, "LLRDDR", 7);

    struct Position finalDestination = getFinalDestination(steps);
    printf("%d %d\n", finalDestination.x, finalDestination.y);

    return 0;
}