/**
You are given an array of integers of size . You need to print the sum of the
elements in the array, keeping in mind that some of those integers may be quite
large.

Input Format

The first line of the input consists of an integer . The next line contains
space-separated integers contained in the array.

Output Format

Print a single value equal to the sum of the elements in the array.

Constraints

1<=N<=10 0<=a[i]<=10^10

https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/array-sum-2-725368ac/
*/
#include <stdio.h>

long long int arraySum(long long int *array, int len) {
    long long int sum = 0;
    int idx;
    for (idx = 0; idx < len; idx++) {
        sum = sum + array[idx];
    }

    return sum;
}

int main() {
    long long int array[] = {1000000001, 1000000002, 1000000003, 1000000004, 1000000005};
    int len = sizeof(array) / sizeof(array[0]);

    long long int sum = arraySum(array, len);
    printf("%lld\n", sum);

    return 0;
}