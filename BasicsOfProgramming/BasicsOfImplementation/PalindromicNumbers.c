/**
Given A and B, count the numbers N such that A ≤ N ≤ B and N is a palindrome.

Examples:
Palindromes: 121, 11, 11411
Not Palindromes: 122, 10

Input:
First line contains T, the number of testcases. Each testcase consists of two
integers A and B in one line.

Output:
For each testcase, print the required answer in one line.

Constraints:
1 ≤ T ≤ 10
0 ≤ A ≤ B ≤ 10^5

https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/palindromic-numbers-7/description/
*/

int reverse(int num) {
    int reverseNum = 0;
    while (num) {
        reverseNum = reverseNum * 10 + num % 10;
        num = num / 10;
    }

    return reverseNum;
}

int getPalindromesInRange(int start, int end) {
    int count = 0;
    for (int itr = start; itr <= end; itr++) {
        if (itr == reverse(itr)) {
            count++;
        }
    }

    return count;
}