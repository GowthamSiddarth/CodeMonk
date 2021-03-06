/**
For a number X, let its "Coolness" be defined as the number of "101"s occurring
in its binary representation. For example, the number 21 has Coolness 2, since
its binary representation is 101012, and the string "101" occurs twice in this
representation.

A number is defined as Very Cool if its Coolness is greater than or equal to K.
Please, output the number of Very Cool integers between 1 and R.

Input:
The first line contains an integer T, the number of test cases.
The next T lines contains two space-separated integers, R and K.

Output:
Output T lines, the answer for each test case.

Constraints:
1<=T<=100
1<=R<=10^5
1<=K<=100

https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/very-cool-numbers/description/
*/
#include <stdio.h>

enum Boolean {FALSE, TRUE};

int count101(int number) {
    int count = 0;
    while (number) {
        count = count + (5 == (number & 5));
        number = number >> 1;
    }

    return count;
}

enum Boolean isVeryCoolNumber(int number, int threshold) {
    return count101(number) >= threshold ? TRUE : FALSE;
}

int getNumberOfVeryCoolNumbers(int range, int threshold) {
    int itr, count = 0;
    for (itr = 1; itr <= range; itr++) 
        count = count + isVeryCoolNumber(itr, threshold);
    
    return count;
}

int main() {
    int range = 5;
    int threshold = 1;

    int res = getNumberOfVeryCoolNumbers(range, threshold);
    printf("%d\n", res);

    return 0;
}