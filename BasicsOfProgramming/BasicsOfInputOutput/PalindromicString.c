/**
You have been given a String S. You need to find and print whether this string
is a palindrome or not. If yes, print "YES" (without quotes), else print "NO"
(without quotes).

Input Format
The first and only line of input contains the String S. The String shall consist
of lowercase English alphabets only.

Output Format
Print the required answer on a single line.

Constraints: 1 <= |S| <= 100

Note:
String S consists of lowercase English Alphabets only.

https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/palindrome-check-2/
*/
#include <stdio.h>
#include <string.h>

int lenOfString(char *s) {
    int idx = 0;
    while('\0' != s[idx]) {
        idx++;
    }

    return idx;
}

int isPalindrome(char *s) {
    int right = lenOfString(s) - 1;
    int left = 0;

    while (left < right && s[left] == s[right]) {
        left++;
        right--;
    }

    return left >= right;
}

int main() {
    char s[101];
    memcpy(s, "abababa", 7);
    printf("%s\n", s);
    
    int res = isPalindrome(s);
    printf("%s", 1 == res ? "YES" : "NO");

    return 0;
}