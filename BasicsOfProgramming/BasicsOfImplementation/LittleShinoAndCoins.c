/**
Little Shino loves to play with coins. In the city she lives, there are 26
different types of coins. Each coin is represented with a lowercase letter a, b,
c,..., y, z . Shino has some number of coins and she placed them in some random
sequence, S, on the table. She is wondering how many pairs (i, j) are there,
where i <= j, such that number of distinct coins in sequence S(i), S(i + 1), S(i
+ 2),..., S(j - 1), S(j) is exactly equal to K. Two coins of same type (same
letters) are considered equal and two coins of different types (different
letters) are considered distinct.

Input:
First line contains one integer, K.
Second line contains a string, S, consist of lowercase letters only.

Output:
Print one integer, number of pairs (i, j), where i <= j, such that number of distinct coins
in sequence S(i), S(i + 1), S(i + 2),..., S(j - 1), S(j) is exactly equal to K.

Constraints:
1 <= K <= 26
1 <= |S| <= 5 * 10^3

S consists of lowercase letters only.

https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/little-shino-and-coins-3/
*/
#include <stdio.h>
#include <string.h>

int getNumOfSubStrWithDistinctChars(char *string, int numOfDistinctChars) {
    int itr1 = 0, totalCount = 0;
    while ('\0' != string[itr1]) {
        int letters[26] = {0};
        int itr2 = itr1, count = 0;

        while ('\0' != string[itr2]) {
            if (0 == letters[string[itr2] - 'a']) {
                letters[string[itr2] - 'a'] = 1;
                count++;                
            }

            if (count == numOfDistinctChars) {
                totalCount++;
            }

            itr2++;
        }

        itr1++;
    } 

    return totalCount;       
}

int main() {
    int numOfDistinctChars = 3;
    char string[5001] = {'\0'};
    memcpy(string, "abcaa", 6);

    printf("%d\n%s\n", numOfDistinctChars, string);

    int res = getNumOfSubStrWithDistinctChars(string, numOfDistinctChars);
    printf("%d", res);

    return 0;
}