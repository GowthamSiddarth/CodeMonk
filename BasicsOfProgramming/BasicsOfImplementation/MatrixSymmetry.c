/**
You are given a square matrix of size n. Rows are indexed 1 to n from top to
bottom and columns are indexed 1 to n form left to right. Matrix consists of
only '*' and '.'. You need to check whether matrix is symmetric or not. if it
is, check it is symmetric about vertical axis or horizontal axis or both.

A matrix is said to be symmetric about horizontal axis if 1st row is identical
to nth row, 2nd is identical to (n - 1)th row and so on...

A matrix is said to be symmetric about vertical axis if 1st column is identical
to nth column, 2nd identical to (n - 1)th and so on for all columns.

INPUT :

First line contains t,the number of test cases. First line of each test case
contains n the size of matrix. Each of next n lines contain n characters.

OUTPUT:

Output t lines, answer for each test case. Print "HORIZONTAL" if symmetric about
horizontal axis. Print "VERTICAL" if symmetric about vertical axis. Print "BOTH"
if symmetric about both axes. print "NO" if it is not symmetric.

Constraints :
1 < t <= 500
1 < n < 50

https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/matrix-symmetry/
*/

int identical(char *s1, char *s2, int len) {
    int idx = 0;

    while (idx < len && s1[idx] == s2[idx]) {
        idx++;
    }

    return idx == len;
}