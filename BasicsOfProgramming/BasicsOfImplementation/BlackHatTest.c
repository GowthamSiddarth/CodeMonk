/**
Nicholas Hathaway, a young programmer, always wanted to be a part of a hacking
group, named fsociety and he is fortunate to find that fsociety is currently
accepting more members but, this is not a simple task. He had to pass a
challenge to become a member of fsociety. The challenge is to encrypt a string
using modified ROT13 algorithm.

ROT13 is a simple letter substitution cipher that replaces a letter with the
letter 13 letters after it in the alphabet. Similiarly for any ROTn each letter
of string is replaced by the letter n letters after it.

In modified ROT13, you have to apply ROT13 on each letter of string. If any
letter repeats in the given string, then for that letter, use higher ROT i.e. on
the second occurrence use ROT14 then ROT15 and so on. So for kth occurrence of
any letter use ROTn , where n = (13 + k - 1). NOTE: n should not be more than 26
so after ROT26, apply ROT1.

Input Format:
The first line of the input contains an integer T, denoting the number of test
cases. Each test case contains a string comprising of only small characters
i.e., [a-z]. Output Format: For each test case, output the modified string
followed by a newline.

Constraints:
1 ≤ T ≤ 100
1 ≤ Length of string ≤ 1000

https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/rot13-modified/
*/

int isUpper(char c) {
    return c >= 'A' && c <= 'Z';
}

char rotn(char c, int n) {
    char startLetter = isUpper(c) ? 'A' : 'a';
    return (c - startLetter + n) % 26 + startLetter;
}

void encryptByROTN(char *s, int n) {
    int charsOccurrence[256] = {0};
    int idx = 0;

    while ('\0' != s[idx]) {
        charsOccurrence[s[idx]] = charsOccurrence[s[idx]] + 1;
        s[idx] = rotn(s[idx], n + charsOccurrence[s[idx]] - 1);        
        idx++;
    }
}