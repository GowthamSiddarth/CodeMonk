/**
The great Kian is looking for a smart prime minister. He's looking for a guy who
can solve the OLP (Old Legendary Problem). OLP is an old problem (obviously)
that no one was able to solve it yet (like P=NP).

But still, you want to be the prime minister really bad. So here's the problem:

Given the sequence a1, a2, ..., an find the three values a1 + a4 + a7 + ..., a2
+ a5 + a8 + ... and a3 + a6 + a9 + ... (these summations go on while the indexes
are valid).

Input
The first line of input contains a single integer n (1 ≤ n ≤ 105).

The second line contains n integers a1, a2, ..., an separated by space (1 ≤ ai ≤
109).

Output
Print three values in one line (the answers).

https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/the-great-kian/
*/

struct GreatKian {
    int sum1, sum2, sum3;
};

struct GreatKian getGreatKianSums(int *arr, int len) {
    int sum1 = 0, sum2 = 0, sum3 = 0, idx;

    for (idx = 0; idx < len; idx = idx + 3) {
        sum1 = sum1 + arr[idx];
        sum2 = idx + 1 < len ? sum2 + arr[idx + 1] : sum2;
        sum3 = idx + 2 < len ? sum3 + arr[idx + 2] : sum3;
    }
    
    struct GreatKian greatKian = {sum1, sum2, sum3};
    return greatKian;
}