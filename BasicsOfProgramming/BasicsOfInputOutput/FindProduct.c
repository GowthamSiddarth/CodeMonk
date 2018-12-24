/**
You have been given an array A of size N consisting of positive integers. You
need to find and print the product of all the number in this array Modulo 10^9
+ 7.

Input Format:
The first line contains a single integer N denoting the size of the array. The
next line contains N space separated integers denoting the elements of the array

Output Format:
Print a single integer denoting the product of all the elements of the array
Modulo 10^9 + 7.

Constraints:
1 <= N <= 1000
1 <= A[i] <= 1000
*/
#include <stdio.h>

int findProduct(int *arr, int len, int modulo) {
  int product = 1;
  for (int i = 0; i < len; i++) {
    product = (product * arr[i]) % modulo;
  }

  return product;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int len = sizeof(arr) / sizeof(arr[0]);
  int modulo = 1000000007;

  int res = findProduct(arr, len, modulo);
  printf("%d", res);

  return 0;
}