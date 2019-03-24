/**
Alakazam has the unique ability to teleport itself during fights. He has
realized that he can use this ability not just in Poke'mon fights, but also
during real time manipulation of arrays. Abra, his non-evolution form has an
interesting array of N integers, A1, A2, ... , AN-1, AN.

Since, Alakazam wants to try his teleporation power on arrays too, he decides to
formalize it: he can move from any position i to a position  in any array of the
world. Now, he is currently standing at a position he calls S. He wants you to
figure out if he can reach the position E.

Input format:
The first line consists of a single integer N. The second line consists of N
integers A1, A2, ... , AN-1, AN, which are separated by a space. The next line
consists of two integers S and E.

Output format:
Print Yes if he can reach the position E starting from position S, else print
No.

Constraints:
1 ≤ N ≤ 1000
1 ≤ Ai ≤ N
1 ≤ S, E ≤ N

https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/the-psychic-type/
*/
#include <malloc.h>
#include <stdio.h>

enum Boolean {FALSE, TRUE};

enum Boolean canReachDestination(int *positions, int numOfPositions, int source, int destination) {
    int currPos = source;
    enum Boolean *visited = (enum Boolean *)calloc(numOfPositions + 1, sizeof(enum Boolean));

    while (TRUE) {
        if (currPos == destination) {
            return TRUE;
        } else if (visited[currPos]) {
            return FALSE;
        } else {
            visited[currPos] = TRUE;
            currPos = positions[currPos - 1];
        }
    }

    free(visited);
}

int main() {
    int numOfPositions = 5;
    int positions[] = {3, 4, 2, 5, 5};
    int source = 1;
    int destination = 5;

    char *canReach = canReachDestination(positions, numOfPositions, source, destination) ? "YES" : "NO";
    printf("%s\n", canReach);

    return 0;
}