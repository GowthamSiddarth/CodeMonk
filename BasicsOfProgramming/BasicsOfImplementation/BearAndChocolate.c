/**
Limak is a little polar bear. Today he found something delicious in the snow.
It's a square bar of chocolate with N x N pieces. Some pieces are special
because there are cherries on them. You might be surprised by cherries on a
chocolate but you've never been on the Arctic Circle, have you?

Limak is going to use his claws and break a chocolate into two parts. He can
make a cut between two rows or between two columns. It means that he can't break
any piece!

Limak will eat one part right now, saving the second part for tomorrow. Cherries
are very important to him so he wants to have equal number of cherries today and
tomorrow. Though parts don't have to have equal numbers of pieces of chocolate.

Given description of a chocolate, could you check if Limak can make a cut
dividing a chocolate into two parts with equal number of cherries?

Note: It's guaranteed that a chocolate contains at least one cherry.

Input format:

The first line contains one integer number T, denoting number of test cases.
Then T test cases follow, each describing one bar of chocolate.

For each test case the first line contains one integer number N, denoting size
of a chocolate. Each of the next N lines contains a string of size N. Each
character in a string is either # (denoting cherry) or . (empty piece). In each
test case at least one character is #.

Output format:

For each test case output an answer in the single line. If Limak can break a
chocolate according to rules above print YES. Otherwise, print NO.

Constraints:

1 <= T <= 10
2 <= N <= 1000
*/
#define YES 1
#define NO 0
#define ROWS 1000
#define COLS 1000

#include <stdio.h>
#include <string.h>
#include <malloc.h>

int hasEqualNumOfCherriesFor2Days(char chocolate[ROWS][COLS], int dim) {
    int *cumulativeRowSum = (int *)malloc(sizeof(int) * dim);

    for (int itr1 = 0; itr1 < dim; itr1++) {
        int currRowSum = 0;
        for (int itr2 = 0; itr2 < dim; itr2++) {
            if ('#' == chocolate[itr1][itr2]) {
                currRowSum++;
            }
        }

        cumulativeRowSum[itr1] = currRowSum;
    }

    int *cumulativeColSum = (int *)malloc(sizeof(int) * dim);

    for (int itr1 = 0; itr1 < dim; itr1++) {
        int currColSum = 0;
        for (int itr2 = 0; itr2 < dim; itr2++) {
            if ('#' == chocolate[itr2][itr1]) {
                currColSum++;
            }
        }

        cumulativeColSum[itr1] = currColSum;
    }

    int totalCherries = cumulativeRowSum[dim - 1];

    for (int itr = 0; itr < dim; itr++) {
        if (totalCherries / 2 == cumulativeRowSum[itr] || totalCherries / 2 == cumulativeColSum[itr]) {
            return YES;
        }
    }

    free(cumulativeRowSum);
    free(cumulativeColSum);
    return NO;
}