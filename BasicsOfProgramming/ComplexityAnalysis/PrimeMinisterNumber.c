/**
Our Prime Minister has some secret numbers, so as in any case of emergency he
can use it to contact the Avengers to save him. But these numbers has some
special features, they are prime and sum of each individual's digit is also
prime.Like 23, it is prime number and sum of it's digits (2+3)= 5, is also a
prime number.

For your information, Avengers are Earth's Mightiest Heroes , consisting of Iron
Man, Captain America, Thor, Hulk and many more.

So your task is to print all the such numbers  in a given range, a,b (both
included), in ascending order.

Save your PM.

Input:

Single line containing two space separated integers, a and b respectively.

Output:

All the integers between a to b (including a and b), that satisfy conditions
mentioned in statement, separated by single space.

Constraints:

1<= a,b <=1000000

https://www.hackerearth.com/practice/basic-programming/complexity-analysis/time-and-space-complexity/practice-problems/algorithm/prime-ministers-number/
*/
#include <math.h>
#include <malloc.h>

int sumOfDigits(int num) {
    int sum = 0;

    while (0 != num) {
        sum = sum + num % 10;
        num = num / 10;
    }

    return sum;
}

int binarySearch(int *arr, int len, int key) {
    int low = 0, high = len - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (key < arr[mid]) {
            high = mid - 1;
        } else if (key > arr[mid]) {
            low = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;
}

int ceilSearch(int *arr, int len, int key) {
    int low = 0, high = len - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (key < arr[mid]) {
            high = mid - 1;
        } else if (key > arr[mid]) {
            low = mid + 1;
        } else {
            return mid;
        }
    }

    return low == len ? -1 : low;
}

void getPrimeNumbersTill(int limit, int *primes, int *numOfPrimes) {
    int *flags = (int *)calloc(limit + 1, sizeof(int));
    int root2 = sqrt(limit);

    for (int i = 2; i <= root2; i++) {
        if (0 == flags[i]) {
            for (int j = i * 2; j <= limit; j = j + i) {
                flags[j] = 1;
            }
        }
    }

    int j = 0;
    for (int i = 2; i < limit + 1; i++) {
        if (0 == flags[i]) {
            primes[j] = i;
            j++;
        }
    }

    *numOfPrimes = j;
    free(flags);
}