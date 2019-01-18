/**
A string is said to be complete if it contains all the characters from a to z.
Given a string, check if it complete or not.

Input
First line of the input contains the number of strings N. It is followed by N
lines each contains a single string.

Output
For each test case print "YES" if the string is complete, else print "NO"

Constraints
1 <= N <= 10
The length of the string is at max 100 and the string contains only the
characters a to z

https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/complete-string-4/
*/
#define COMPLETE 1
#define NOT_COMPLETE 0

int isCompleteString(char *string) {
    int occurrence[26] = {0};
    int idx = 0;

    while ('\0' != string[idx]) {
        occurrence[string[idx] - 'a']++;
        idx++;
    }

    idx = 0;
    while (idx < 26 && occurrence[idx] > 0) {
        idx++;
    }

    return 26 == idx ? COMPLETE : NOT_COMPLETE;
}