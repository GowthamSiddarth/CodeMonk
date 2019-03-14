/**
2^N participants (P1 , P2 , P3 .... , PN ) have enrolled for a knockout chess
tournament. In the first round, each participant P2k-1 is to play against
participant P2k, (1 ≤ k ≤ 2^(N-1)) .

Some information about all the participants is known in the form of a triangular
matrix A with dimensions (2^N-1) X (2^N-1). If Aij = 1 (i > j), participant Pi
is a better player than participant Pj, otherwise Aij = 0 and participant Pj is
a better player than participant Pi. Given that the better player always wins,
who will be the winner of the tournament?

Note : Being a better player is not transitive i.e if Pi is a better player than
Pj and Pj is a better player than Pk, it is not necessary that Pi is a better
player than Pk .

Input
The first line consists of N. Then, 2N-1 lines follow, the ith line consisting
of i space separated integers Ai+1 1 , Ai+1 2 , .... Ai+1 i

Output
A single integer denoting the id of the winner of the tournament.

Constraints
1 ≤ N ≤ 10
Aij = {0, 1} (i > j)

https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/chess-tournament-4/description/
*/
#include <malloc.h>
#include <stdio.h>
#include <math.h>

void getCurrRoundPlayers(int * players, int numOfPlayers, int start, int *currPlayer1, int *currPlayer2) {
    *currPlayer1 = 1 == players[start] ? start : (1 == players[start + 1] ? start + 1 : -1);
    if (-1 == *currPlayer1) {
        *currPlayer1 = start;
        *currPlayer2 = start + 1;
    } else {
        int itr = start + 2;
        while (itr < numOfPlayers && 0 == players[itr]) {
            itr++;
        }

        *currPlayer2 = itr;
    }
}

int getWinner(int **winnerMatrix, int dim, int numOfPlayers) {
    int *players = (int *)calloc(numOfPlayers, sizeof(int));
    int numOfPlayersEliminated = 0, start = -2, currWinner;

    while (numOfPlayersEliminated < numOfPlayers - 1) {
        start = (start + 2) %  numOfPlayers;
        int currPlayer1, currPlayer2;
        getCurrRoundPlayers(players, numOfPlayers, start, &currPlayer1, &currPlayer2);

        players[currWinner = winnerMatrix[currPlayer2 - 1][currPlayer1] ? currPlayer2 : currPlayer1] = 1;
        numOfPlayersEliminated++;
    }
    
    free(players);
    return currWinner + 1;
}

int main() {
    int n = 2;
    int numOfPlayers = pow(2, n);

    int **winnerMatrix = (int **)malloc(sizeof(int) * (numOfPlayers - 1));
    for (int itr = 0; itr < (numOfPlayers - 1); itr++) {
        winnerMatrix[itr] = (int *)malloc(sizeof(int) * (numOfPlayers - 1));
    }

    winnerMatrix[0][0] = 0;
    winnerMatrix[1][0] = 1;
    winnerMatrix[1][1] = 0;
    winnerMatrix[2][0] = 1;
    winnerMatrix[2][1] = 1;
    winnerMatrix[2][2] = 1;

    int winner = getWinner(winnerMatrix, 3, numOfPlayers);

    return 0;
}