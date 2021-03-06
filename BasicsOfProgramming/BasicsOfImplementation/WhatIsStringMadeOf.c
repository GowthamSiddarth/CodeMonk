/**
You are given a string, which contains entirely of decimal digits (0-9). Each
digit is made of a certain number of dashes, as shown in the image below. For
instance 1 is made of 2 dashes, 8 is made of 7 dashes and so on.

You have to write a function that takes this string message as an input and
returns a corresponding value in terms of a number. This number is the count of
dashes in the string message.

Note:

0 consists of 6 dashes, 1 consists of 2 dashes, 2 consists of 5 dashes, 3
consists of 5 dashes, 4 consists of 4 dashes, 5 consists of 5 dashes, 6 consists
of 6 dashes, 7 consists of 3 dashes [though the figure shows that 7 consists of
4 dashes but due to minor mistake in the problem please write your solution
assuming 7 consists of 3 dashes], 8 consists of 7 dashes, 9 consists of 6
dashes.

Constraints

String message will contain at least one digit, but not more than 100
Each character in code will be a digit ('0'-'9').

https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/what-is-the-string-made-of-2/
*/
#include <stdio.h>

int dashes[] = {6, 2, 5, 5, 4, 5, 6, 4, 7, 6};

int getNumOfDashes(int digit) {
    return dashes[digit];
}

int getTotalDashes(int number) {
    int total = 0;

    while (number) {
        int digit = number % 10;
        total = total + getNumOfDashes(digit);
        number = number / 10;
    }

    return total;
}

int main() {
    int number = 12134;
    int res = getTotalDashes(number);

    printf("%d\n%d", number, res);
    return 0;
}