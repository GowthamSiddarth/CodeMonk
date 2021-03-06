/**
Little Jhool always wanted to have some psychic powers so that he could showoff
his skills, and magic to people and impress them. (Specially, his girlfriend Big
Jhool!) But, in spite all his efforts, hardwork, dedication, Googling, watching
youtube videos he couldn't garner any psychic abilities!

He knew everyone was making fun of him, so to stop all of that - he came up with
a smart plan. Anyone who came to him to know about their future, he asked them
to write a binary number for him - and then, he smartly told them if the future
for that person had good in store, or bad.

The algorithm which Little Jhool follows is, as following:

If the binary number written by the person has six consecutive 0s, or 1s, his
future is bad. Otherwise, he says that their future is good. Input format:

Single line contains a binary number.

Output format:

You need to print "Good luck!" (Without quotes, and WITH exclamation mark!) if
the Jhool is going to tell them that they're going to have a good time. Else,
print "Sorry, sorry!" if the person is going to be told that he'll have a hard
time!

Constraints:

The binary number will be in string format, with the maximum length being 100
characters.

https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/psychic-powers/
*/
#define MAX_LEN 101

#include <stdio.h>
#include <string.h>

enum Boolean {FALSE, TRUE};

enum Boolean hasNConsecutive0sOr1s(char *string, int n) {
    int idx = 0, countOfZeros = 0, countOfOnes = 0;
    char prevChar = string[0];
    while ('\0' != string[idx] && n != countOfZeros && n != countOfOnes) {
        int *count = '0' == string[idx] ? &countOfZeros : &countOfOnes;
        *count = prevChar == string[idx] ? *count + 1 : 1;
        prevChar = string[idx];
        idx++;
    }
    
    return n == countOfZeros || n == countOfOnes ? TRUE : FALSE;
}

int main() {
    char string[MAX_LEN];
    memcpy(string, "0001111110", 11);
    int n = 6;

    int res = hasNConsecutive0sOr1s(string, n);
    printf("%s\n", !res ? "Good luck!" : "Sorry, sorry!");

    return 0;
}