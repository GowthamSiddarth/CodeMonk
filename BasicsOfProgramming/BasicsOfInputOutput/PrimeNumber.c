/**
 *
Problem Statement:

You are given an integer N. You need to print the series of all prime numbers
till N.

Input Format

The first and only line of the input contains a single integer N denoting the
number till where you need to find the series of prime number.

Output Format

Print the desired output in single line separated by spaces.

Constraints

1<=N<=1000

https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/prime-number-8/

*/

#include <malloc.h>
#include <math.h>
#include <stdio.h>

void sieveOfEratosthenes(int *flag, int n) {
  int m = sqrt(n);
  for (int i = 2; i <= m; i++) {
    if (0 == flag[i]) {
      for (int j = i * 2; j <= n; j += i) {
        flag[j] = 1;
      }
    }
  }
}

void printPrimesInRange(int n) {
  int *flag = (int *)calloc(n + 1, sizeof(int));

  sieveOfEratosthenes(flag, n);
  for (int i = 2; i <= n; i++) {
    if (0 == flag[i]) {
      printf("%d ", i);
    }
  }
}

int main() {
  int n = 9;
  printPrimesInRange(n);
  return 0;
}
