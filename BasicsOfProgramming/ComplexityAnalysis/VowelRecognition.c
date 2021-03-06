/**
{a,e,i,o,u,A,E,I,O,U}

Natural Language Understanding is the subdomain of Natural Language Processing
where people used to design AI based applications have ability to understand the
human languages. HashInclude Speech Processing team has a project named Virtual
Assistant. For this project they appointed you as a data engineer (who has good
knowledge of creating clean datasets by writing efficient code). As a data
engineer your first task is to make vowel recognition dataset. In this task you
have to find the presence of vowels in all possible substrings of the given
string. For each given string you have to print the total number of vowels.

Input

First line contains an integer T, denoting the number of test cases.

Each of the next lines contains a string, string contains both lower case and
upper case .

Output

Print the vowel sum
Answer for each test case should be printed in a new line.

Input Constraints

1<=T<=10

1<=|S|<=100000

https://www.hackerearth.com/practice/basic-programming/complexity-analysis/time-and-space-complexity/practice-problems/algorithm/vowel-game-f1a1047c/
*/
#include <stdio.h>

int isVowel(char c) {
    return 'A' == c || 'E' == c || 'I' == c || 'O' == c || 'U' == c ||
        'a' == c || 'e' == c || 'i' == c || 'o' == c || 'u' == c;
}

int len(char *s) {
    int idx = 0;
    while ('\0' != s[idx]) {
        idx++;
    }

    return idx;
}

int getVowelCountInAllSubStrings(char *s) {
    int total = 0;
    int idx = 0;
    int l = len(s);

    while ('\0' != s[idx]) {
        if (isVowel(s[idx])) {
            total = total + (l - idx) * (idx + 1);
        }

        idx++;
    }

    return total;
}

int main() {
    char *s = "baced";
    int res = getVowelCountInAllSubStrings(s);
    printf("%d", res);

    return 0;
}