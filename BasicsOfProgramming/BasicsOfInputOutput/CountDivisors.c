/**
You have been given 3 integers - l, r and k. Find how many numbers between l and
r (both inclusive) are divisible by k. You do not need to print these numbers,
you just have to find their count.

Input Format
The first and only line of input contains 3 space separated integers l, r and k.

Output Format
Print the required answer on a single line.

Constraints
1 <= l <= r <= 1000
1 <= k <= 1000
*/
#include <stdio.h>

int countDivisors(int l, int r, int k) {
    return r / k - ((0 == (l % k)) ? l / k : l / k + 1) + 1;
}

int main() {
    int l = 1, r = 10, k = 5;
    int res = countDivisors(l, r, k);
    printf("%d", res);

    return 0;    
}