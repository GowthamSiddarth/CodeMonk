/**
Gary likes to solve problems of array, but he doesn't like problems that involve
queries. His school teacher gave him an assignment full of problems but one of
them involve queries. Can you help Gary in solving that problem so that he can
go and play with his friends? The problem is :

Given an Array A consisting of N positive integers, you have to answer Q queries
on it. Queries can be of the two types: * 1 X Y - Update X at location Y in the
array. * 2 L R - Print the sum of range [L, R], i.e. Both L and R are inclusive.

Note:- Array indexing is from 0.

Input:
The first line contains two space separated integers N(Length of Array) and
Q(Queries). Next Line contains N space separated integers denoting array A. Next
Q Line contains 3 space separated integers for each line, as described above

Output: 
Answer to the each query of type 2 in a new line, only when range is
valid, otherwise ouput `-1`

Constraints: 
1 <= N <= 10^9 1 <= Q <= 10^5 1 <= A[i], X, Y, L, R <= 10^5

https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/array-insert/
*/
#include <malloc.h>

enum QueryType {UPDATE = 1, SUM = 2};

struct Query {
    enum QueryType type;
    int param1, param2;
};

int * getCumulativeSums(int *arr, int len) {
    int * cumulativeSums = (int *)malloc(sizeof(int) * len);
    int idx, cumulativeSum = 0;

    for (idx = 0; idx < len; idx++) {
        cumulativeSum = cumulativeSum + arr[idx];
        cumulativeSums[idx] = cumulativeSum;
    }

    return cumulativeSums;
}

void updateArray(int *arr, int len, int pos, int value, int *cumulativeSumsArr) {
    int prevVal = arr[pos];
    arr[pos] = value;

    int idx = pos;
    while (idx < len) {
        cumulativeSumsArr[idx] = cumulativeSumsArr[idx] + prevVal - value;
        idx++;
    }
}

int getSumInRange(int *cumulativeSumsArr, int len, int start, int end) {
    return start > 0 ? cumulativeSumsArr[end] - cumulativeSumsArr[start - 1] : cumulativeSumsArr[end];
}

void processQueries(struct Query *queries, int numOfQueries, int *arr, int len, int *cumulativeSumsArr) {
    int idx;
    for (idx = 0; idx < numOfQueries; idx++) {
        struct Query currQuery = queries[idx];
        switch (currQuery.type) {
            case UPDATE:
                updateArray(arr, len, currQuery.param1, currQuery.param2, cumulativeSumsArr);
                break;
            case SUM:
                int sumInRange = getSumInRange(cumulativeSumsArr, len, currQuery.param1, currQuery.param2);
                break;
        }
    }
}