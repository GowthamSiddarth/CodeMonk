/**
Little Bear has received a home assignment to find the sum of all digits in a
number N. Following his affinity towards single digit number, he intends to
repeatedly compute the sum of all digits until the sum itself becomes a single
digit number.

Can you write a program to compute the final single-digit sum?

As the number N is very big, it is given in the following run length encoded
format - N is represented as a sequence of M blocks, where each block i (0 ≤ i <
M) is represented by two integers - (len[i], d[i]). This implies that the digit
d[i] occurs len[i] number of times.

For example, {(2,1), (1,2), (2,9)} represents the number 11299.

Input:
The first line contains a single integer T, denoting the number of test cases.
Each test case starts with a single integer M, which is the number of following
run-length encoded blocks. Each of the next M lines contains two space separated
integers: len[i] and d[i].

Output:
Print the single-digit sum for each of the T test cases in a new line.

Constraints:
0 ≤ d[i] ≤ 9
1 ≤ len[i] ≤ 10^15
1 ≤ M ≤ 10^4
1 ≤ T ≤ 10

https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/recursive-sums/
*/
#include <malloc.h>
#include <stdio.h>

struct Digit {
    int freq, digit;
};

unsigned long long int getSumOfDigitsOfNum(unsigned long long int number) {
    unsigned long long int sum = 0;
    while (number) {
        sum = sum + (number % 10);
        number = number / 10;
    }

    return sum;
}

int getDigitByRecursiveSums(int numOfDistinctDigits, struct Digit * digits) {
    int itr = 0;
    unsigned long long int sum = 0;
    while (itr < numOfDistinctDigits) {
        sum = sum + getSumOfDigitsOfNum(digits[itr].freq * digits[itr].digit);
        itr++;
    }

    return getSumOfDigitsOfNum(sum);
}

int main() {
    int numOfDistinctDigits = 3;
    struct Digit *digitsArr = (struct Digit *)malloc(sizeof(struct Digit) * numOfDistinctDigits);
    int freqs[] = {2, 1, 2};
    int digits[] = {1, 2, 9};

    for (int itr = 0; itr < numOfDistinctDigits; itr++) {
        digitsArr[itr].digit = digits[itr];
        digitsArr[itr].freq = freqs[itr];
    }

    int res = getDigitByRecursiveSums(numOfDistinctDigits, digitsArr);
    printf("%d\n", res);

    return 0;
}