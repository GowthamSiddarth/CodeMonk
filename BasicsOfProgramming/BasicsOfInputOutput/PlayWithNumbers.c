/**
You are given an array of n numbers and q queries. For each query you have to
print the floor of the expected value(mean) of the subarray from L to R.

First line contains two integers N and Q denoting number of array elements and
number of queries.

Next line contains N space seperated integers denoting array elements.

Next Q lines contain two integers L and R(indices of the array).

print a single integer denoting the answer.

1<= N ,Q,L,R <= 10^6

1<= Array elements <= 10^9

https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/play-with-numbers-2/
*/
#include <stdio.h>

void getCumulativeSumArray(int *arr, int len, int *cumulativeSumArray) {
  int cumulativeSum = 0;
  for (int idx = 0; idx < len; idx++) {
    cumulativeSum += arr[idx];
    cumulativeSumArray[idx] = cumulativeSum;
  }
}

int expected(int *cumulativeSumArray, int from, int to) {
  return (cumulativeSumArray[to - 1] -
          ((from > 1) ? cumulativeSumArray[from - 2] : 0)) /
         (to - from + 1);
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int len = sizeof(arr) / sizeof(arr[0]);

    int cumulativeSumArray[5] = {0};
    getCumulativeSumArray(arr, len, cumulativeSumArray);

    int from[3] = {1, 2, 2};
    int to[3] = {5, 4, 5};

    int numOfQueries = sizeof(from) / sizeof(from[0]);
    for (int i = 0; i < numOfQueries; i++) {
        int expectedValue = expected(cumulativeSumArray, from[i], to[i]);
        printf("%d\n", expectedValue);
    }

    return 0;
}