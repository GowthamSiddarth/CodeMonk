/**
Aditya is fond of ladders. Everyday he goes through pictures of ladders online
but unfortunately today he ran out of ladder pictures online. Write a program to
print “ladder with N steps”, which he can use to get his daily dose of ladder
love.

INPUT:
Input contains integer N, the number of steps in the ladder

OUTPUT:

Print the ladder with the gap between two side rails being 3 spaces(“   “).

Check the sample output for format of printing the ladder.

CONSTRAINTS:

1<=N<=40
*/
#include <stdio.h>

void printSideRails() {
    printf("*   *\n*   *\n");
}

void printStep() {
    printf("*****\n");
}

void printLadder(int numOfSteps) {
    printSideRails();

    while(numOfSteps--) {
        printStep();
        printSideRails();
    }
}

int main() {
    int n = 1;
    printLadder(n);

    return 0;
}