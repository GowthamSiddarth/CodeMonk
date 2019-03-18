/**
ndia is a cricket crazy nation. Chang also loves cricket and computations
related to cricket. Chang has created a Cricket app.This app analyses the
performance of a cricketer. If a cricketer under-performs, then a negative
rating is awarded. If performance is good, then positive rating is awarded to
the cricketer.Chang wants to analyse the performance of a cricketer over a
period of N matches. Chang wants to find consistency of a cricketer. So he wants
to find out the maximum consistent sum of cricket rating of a batsman or a
bowler only if his overall rating is positive over that period. Help chang in
doing so.

Input

The first line contain number of matches "N" over which the analysis is to be
done. The second line contains those ratings of a batsman/bowler in those N
matches.

Output

Print a single integer ie. the maximum consistent sum of rating of the cricketer
if it is positive otherwise output 0 (zero).

Constraint

0 <= N <= 10^5
100 <= rating <= 100

https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/cricket-rating-30/
*/

int getHighestConsistentCricketRating(int *ratings, int len) {
    int max = 0, itr, sum = 0;
    for (itr = 0; itr < len; itr++) {
        int temp = ratings[itr];
        sum = sum + temp;

        if (sum < 0) {
            sum = 0;
        }

        if (sum > max) {
            max = sum;
        }
    }

    return max;
}