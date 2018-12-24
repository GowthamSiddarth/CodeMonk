/**
Given two strings, a and b , that may or may not be of the same length,
determine the minimum number of character deletions required to make a and b
anagrams. Any characters can be deleted from either of the strings.

Input :

test cases,t
two strings a and b, for each test case
Output:

Desired O/p

Constraints :

string lengths<=10000

Note :

Anagram of a word is formed by rearranging the letters of the word.

For e.g. -> For the word RAM - MAR,ARM,AMR,RMA etc. are few anagrams.

https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/anagrams-651/
*/

int minNumOfCharsToBeDeletedToMakeAnagrams(char *s1, char *s2) {
    int count[256] = {0};
    int idx;

    idx = 0;
    while ('\0' != s1[idx]) {
        count[s1[idx]] = count[s1[idx]] + 1;
        idx++;
    }

    idx = 0;
    while ('\0' != s2[idx]) {
        count[s2[idx]] = (0 == count[s2[idx]] ? 1 : count[s2[idx]] - 1);
        idx++;
    }

    int total = 0;
    for (idx = 0; idx < 256; idx++) {
        total = total + count[idx];
    }

    return total;
}