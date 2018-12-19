/**
You have been given a positive integer N. You need to find and print the
Factorial of this number. The Factorial of a positive integer N refers to the
product of all number in the range from 1 to N. You can read more about the
factorial of a number here.

Input Format:
The first and only line of the input contains a single integer N denoting the
number whose factorial you need to find.

Output Format
Output a single line denoting the factorial of the number N.

Constraints
1 <= N <= 10

https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/find-factorial/
*/
#include <stdio.h>

int factorial(int n) {
    int prod = 1;
    while (n > 1) {
        prod = prod * n;
        n--;
    }

    return prod;
}

int main() {
    int n = 10;
    int res = factorial(n);
    printf("%d", res);

    return 0;
}