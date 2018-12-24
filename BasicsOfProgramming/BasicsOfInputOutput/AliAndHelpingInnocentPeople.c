/**
Arpasland has surrounded by attackers. A truck enters the city. The driver
claims the load is food and medicine from Iranians. Ali is one of the soldiers
in Arpasland. He doubts about the truck, maybe it's from the siege. He knows
that a tag is valid if the sum of every two consecutive digits of it is even and
its letter is not a vowel. Determine if the tag of the truck is valid or not.

We consider the letters "A","E","I","O","U","Y" to be vowels for this problem.

Input Format

The first line contains a string of length 9. The format is "DDXDDD-DD", where D
stands for a digit (non zero) and X is an uppercase english letter.

Output Format

Print "valid" (without quotes) if the tag is valid, print "invalid" otherwise
(without quotes)

https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/cartag-948c2b02/
*/
#include <stdio.h>
#include <string.h>

int isVowel(char c) {
    return 'A' == c || 'E' == c || 'I' == c || 'O' == c || 'U' == c || 'Y' == c;
}

int isEven(int num) {
    return 0 == (num & 1);
}

char * validateTruck(char *tag, int letterIdx, int *digitIndices, int numOfDigits) {
    if (isVowel(tag[letterIdx])) {
        return "invalid";
    }

    for (int i = 0; i < numOfDigits - 1; i++) {
        if (!isEven(tag[digitIndices[i] + tag[digitIndices[i + 1]]])) {
            return "invalid";
        }
    }

    return "valid";
}

int main() {
    char tag[10];
    memcpy(tag, "12X345-67", 10);

    int letterIdx = 2;
    int digitIndices[] = {0, 1, 3, 4, 5, 7, 8};
    int numOfDigits = sizeof(digitIndices) / sizeof(digitIndices[0]);    

    char *res = validateTruck(tag, letterIdx, digitIndices, numOfDigits);
    printf("%s", res);

    return 0;
}