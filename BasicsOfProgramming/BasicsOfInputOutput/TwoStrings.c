/**
Given two strings of equal length, you have to tell whether they both strings
are identical.

Two strings S1 and S2 are said to be identical, if any of the permutation of
string S1 is equal to the string S2. See Sample explanation for more details.

Input :

First line, contains an intger 'T' denoting no. of test cases.
Each test consists of a single line, containing two space separated strings S1
and S2 of equal length. Output:

For each test case, if any of the permutation of string S1 is equal to the
string S2 print YES else print NO. Constraints:

1<= T <=100
1<= |S1| = |S2| <= 10^5
String is made up of lower case letters only.
Note : Use Hashing Concept Only . Try to do it in O(string length).

https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/two-strings-4/
*/
#include <stdio.h>
#include <string.h>

int isIdentical(char *s1, char *s2) {
    int ascii[256] = {0};
    int idx;

    idx = 0;
    while ('\0' != s1[idx]) {
        ascii[s1[idx]] = ascii[s1[idx]] + 1;
        idx++;
    }

    idx = 0;
    while ('\0' != s2[idx]) {
        ascii[s2[idx]] = ascii[s2[idx]] - 1;
        idx++;
    }

    idx = 0;
    while (idx < 256) {
        if (0 != ascii[idx]) {
            return 0;
        }

        idx++;
    }

    return 1;
}

int main () {
    char s1[6], s2[6];
    memcpy(s1, "sumit", 5);
    memcpy(s2, "mitsu", 5);

    int res = isIdentical(s1, s2);
    printf("%s\n", 1 == res ? "YES" : "NO");

    return 0;
}