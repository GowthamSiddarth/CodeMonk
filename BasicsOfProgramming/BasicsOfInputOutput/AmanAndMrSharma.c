/**
On a distant planet far away from Earth lives a boy named Aman.He loves to run
everyday.But his running distance is directly affected by how much horlicks his
mother mixed in his milk today.If his mother has mixed x grams of horlicks,then
Aman will be capable of running 100*x meters at most on that day.

Aman's instructor, Mr.Sharma ,is a very strict yet very caring.Everyday he asks
Aman to run around a circle of radius r once.If Aman is able to complete the
circle,he would get a toffee.

Note:Take value of pie=22/7.

CONSTRAINTS:

1<=d<105

1<=r<106

1<=x<=104

INPUT:

First line contains d,no. of days Aman goes to his instructor.Next d lines each
contain r,radius of circle and x,amount of horlicks.

OUTPUT:

Print total number of toffees Aman would finally have at the end of d days.

https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/aman-mrsharma/
*/
#define pi 22 / 7
#include <stdio.h>

int getNumOfToffeesGainedByAman(int numOfTargets, int *target, int *horlicks) {
    int count = 0;

    for (int idx = 0; idx < numOfTargets; idx++) {
        if ((100 * horlicks[idx]) >= (2.0 * target[idx] * pi)) {
            count++;
        }
    }

    return count;
}

int main() {
    int horlicks[] = {2, 2, 2};
    int target[] = {3, 5, 1};
    int numOfTargets = sizeof(target) / sizeof(target[0]);

    int res = getNumOfToffeesGainedByAman(numOfTargets, target, horlicks);
    printf("%d", res);

    return 0;
}