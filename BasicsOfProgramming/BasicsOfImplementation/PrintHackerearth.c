/**
As a beginner to the programming, Mishki came to Hackerearth platform, to become
a better programmer. She solved some problems and felt very confident. Later
being a fan of Hackerearth, she gave a problem to her friends to solve. They
will be given a string containing only lower case characters (a-z), and they
need to find that by using the characters of the given string, how many times
they can print "hackerearth"(without quotes). As they are new to programming
world, please help them.

Input:
The first line will consists of one integer N denoting the length of string.
Next line will contain the string Str containing only lower case characters.

Output:
Print one integer, denoting the number of times her friends can print
"hackerearth" (without quotes).

Constraints:
1 <= N <= 10^6

Each character of string Str will be in range [a, z]

https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/print-hackerearth/
*/
#define MAX_LEN 1000001

#include <stdio.h>
#include <string.h>

int numberOfTargetWordsInString(char *string, char *target) {
    int count[26] = {0}, idx = 0;
    while ('\0' != string[idx]) {
        count[string[idx] - 'a']++;
        idx++;
    }

    int minOcc = MAX_LEN;
    idx = 0;
    while ('\0' != target[idx]) {
        minOcc = count[target[idx] - 'a'] < minOcc ? count[target[idx] - 'a'] : minOcc;
        idx++;
    }

    return minOcc;
}

int main() {
    char string[MAX_LEN], target[MAX_LEN];
    memcpy(string, "aahkcreeatrha", 14);
    memcpy(target, "hackerearth", 12);

    int res = numberOfTargetWordsInString(string, target);
    printf("%d\n", res);

    return 0;
}