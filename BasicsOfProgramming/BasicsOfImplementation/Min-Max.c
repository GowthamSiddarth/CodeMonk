/**
Given an array of integers . Check if all the numbers between minimum and
maximum number in array exist's within the array .

Print 'YES' if numbers exist otherwise print 'NO'(without quotes).

Input:

Integer N denoting size of array

Next line contains N space separated integers denoting elements in array

Output:

Output your answer

Constraints:

1<= N <= 1000
1<= a[i] <= 100

https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/min-max-3/
*/
#include <stdio.h>

enum Boolean {FALSE, TRUE};

enum Boolean rangeExistsBetweenMinAndMax(int *arr, int len) {
    enum Boolean exists[100] = {FALSE};
    int minVal = 101, maxVal = 0, idx;

    for (idx = 0; idx < len; idx++) {
        exists[arr[idx] - 1] = TRUE;
        if (arr[idx] < minVal) minVal = arr[idx];
        if (arr[idx] > maxVal) maxVal = arr[idx];
    }

    for (idx = minVal - 1; idx <= maxVal - 1; idx++) {
        if (!exists[idx]) {
            return FALSE;
        }
    }

    return TRUE;
}

int main() {
    int arr[] = {4, 2, 1, 3, 5, 6};
    int len = sizeof(arr) / sizeof(arr[0]);

    enum Boolean res = rangeExistsBetweenMinAndMax(arr, len);
    printf("%s\n", res ? "YES" : "NO");
    
    return 0;
}