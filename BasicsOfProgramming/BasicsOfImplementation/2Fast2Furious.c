/**
Dom and Brian were trying to evade the truck drivers of Verone's gang. They were
too fast, too furious for them, and could get away from the truck drivers
easily. They decided to race with each other, and divided the city into N
checkpoints for the same. Mia was monitoring Dom and Brian throughout the race
and she noted down their speeds at every checkpoint.

Roman was jobless, as usual, and told Mia that Dom would definitely have the
maximum change in speed between any two consecutive checkpoints. Mia, disagreed
with him and challenged him that Brian would have maximum change in speed.

Help Mia and Roman to find out who has the maximum change in speed between any
two consecutive checkpoints - Dom or Brian. Note: Both negative and positive
changes have to be considered. Hence, absolute value of maximum change in speed
is to be considered.

Input:
First line contains a positive integer N - total number of checkpoints
Second line contains N space-separated integers - a(i) - the speeds of Dom's car
at each checkpoint. Third line contains N space-separated integers - b(i) - the
speeds of Brian's car at each checkpoint.

Output:
Print who had the maximum change in speed between 2 consecutive checkpoints -
Dom or Brian. If both have equal maximum change in speed, print "Tie". Print a
single integer on a new line - the maximum absolute change in speed between 2
consecutive checkpoints.

Constraints:
2 ≤ N ≤ 106
-10^9 ≤ a(i) ≤ 10^9

https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/2-fast-2-furious/
*/
#define DOM 1
#define BRIAN 2
#define TIE 3

#include <stdio.h>
#include <math.h>

struct WinnerInfo {
    int winner, maxChangeInSpeed;
};

struct WinnerInfo getWinnerInfo(int *speedsOfDom, int *speedsOfBrian, int numOfSpeeds) {
    int currChangeInSpeedForDom = 0;
    int maxChangeInSpeedForDom = 0;
    int currChangeInSpeedForBrian = 0;
    int maxChangeInSpeedForBrian = 0;

    for (int itr = 0; itr < numOfSpeeds - 1; itr++) {
        currChangeInSpeedForDom = abs(speedsOfDom[itr + 1] - speedsOfDom[itr]);
        if (currChangeInSpeedForDom > maxChangeInSpeedForDom) {
            maxChangeInSpeedForDom = currChangeInSpeedForDom;
        }

        currChangeInSpeedForBrian = abs(speedsOfBrian[itr + 1] - speedsOfBrian[itr]);
        if (currChangeInSpeedForBrian > maxChangeInSpeedForBrian) {
            maxChangeInSpeedForBrian = currChangeInSpeedForBrian;
        }
    }

    struct WinnerInfo winnerInfo;
    if (maxChangeInSpeedForDom > maxChangeInSpeedForBrian) {
        winnerInfo.winner = DOM;
        winnerInfo.maxChangeInSpeed = maxChangeInSpeedForDom;
    } else if (maxChangeInSpeedForDom < maxChangeInSpeedForBrian) {
        winnerInfo.winner = BRIAN;
        winnerInfo.maxChangeInSpeed = maxChangeInSpeedForBrian;
    } else {
        winnerInfo.winner = TIE;
        winnerInfo.maxChangeInSpeed = maxChangeInSpeedForBrian;
    }

    return winnerInfo;
}

void printIntArray(int *arr, int len) {
    for (int idx = 0; idx < len; idx++) {
        printf("%d ", arr[idx]);
    }
    printf("\n");
}

int main() {
    int numOfSpeeds = 3;
    int speedsOfDom[3] = {1, 2, 3};
    int speedsOfBrian[3] = {1, 2, 4};

    printf("%d\n", numOfSpeeds);
    printIntArray(speedsOfDom, numOfSpeeds);
    printIntArray(speedsOfBrian, numOfSpeeds);

    struct WinnerInfo res = getWinnerInfo(speedsOfDom, speedsOfBrian, numOfSpeeds);
    switch (res.winner) {
        case BRIAN:
            printf("BRIAN\n%d", res.maxChangeInSpeed);
            break;
        case DOM:
            printf("DOM\n%d", res.maxChangeInSpeed);
            break;
        case TIE:
            printf("TIE\n%d", res.maxChangeInSpeed);
            break;
    }

    return 0;
}