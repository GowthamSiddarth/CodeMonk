/**
Prateek wants to give a party to his N friends on his birthday, where each
friend is numbered from 1 to N. His friends are asking for a gift to come to the
party, instead of giving him one. The cost of the gifts are given in the array
Value where ith friend asks for a gift which has a cost Costi.

But, Prateek has only X amount of money to spend on gifts and he wants to invite
his friends which are in continuous range such that currCost of the cost of the gifts
of those friends will be exactly equal to X.

If he can invite his friends, who can satisfy the above condition then, print
YES otherwise print NO.

Input:
The first line contains a single integer T, denoting the number of test cases.
In each test case, the following input will be present: - The next line contains
two space-separated integers N and X, where N represents the number of friends
and X represents amount of money which Prateek can spend on gifts.
- Next N line contains N integers, where ith line contains ith integer, which
represents the Costi .

Ouput
Output exactly T lines, each containing the answer to the corresponding test
case .

Constraints:
1 <= T <= 10
1 <= N , Cost[i] <= 10^6
1 <= X <= 10^12

https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/prateek-and-his-friends/description/
*/
#define TRUE 1

int canPrateekPurchaseGifts(int *costs, int numOfFriends, int targetCost) {
    int currCost = costs[0];
    int start = 0, itr;

    for (itr = 1; itr <= numOfFriends; itr++) {
        while (currCost > targetCost && start < itr - 1) {
            currCost = currCost - costs[start];
            start++;
        }

        if (currCost == targetCost) {
            return TRUE;
        }

        if (itr < numOfFriends) {
            currCost = currCost + costs[itr];
        }
    }

    return !TRUE;
}