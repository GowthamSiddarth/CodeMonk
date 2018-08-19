#include <stdio.h>
#include <malloc.h>
#include <math.h>

void sieveOfEratosthenes(int *flag, int n) {
    int m = sqrt(n);
    for (int i = 2; i <= m; i++) {
        if (0 == flag[i]) {
            for (int j = i * 2; j <= n; j += i) {
                flag[j] = 1;
            }
        }
    }
}

void printPrimesInRange(int n) {
    int *flag = (int *)calloc(n + 1, sizeof(int));
    
    sieveOfEratosthenes(flag, n);
    for (int i = 2; i <= n; i++) {
        if (0 == flag[i]) {
            printf("%d ", i);
        }
    }
}

int main() {
    int n = 9;
    printPrimesInRange(n);
    return 0;
}
