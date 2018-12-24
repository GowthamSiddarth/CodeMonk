/**
Goki recently had a breakup, so he wants to have some more friends in his life.
Goki has N people who he can be friends with, so he decides to choose among them
according to their skillsOfFriends set Yi(1<=i<=n). He wants atleast X skillsOfFriends in his
friends. Help Goki find his friends.

INPUT
First line of the input contains an integer N denoting the number of people.

Next line contains a single integer X - denoting the minimum skill required to
be Goki's friend.

Next n lines contain one integer Y - denoting the skill of ith person.

OUTPUT
For each person print if he can be friend with Goki. 'YES' (without quotes) if
he can be friends with Goki else 'NO' (without quotes).

CONSTRAINTS

1<=N<=1000000
1<=X,Y<=1000000

https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/tds-and-his-breakup/
*/
#include <stdio.h>

int isFriendOfGoki(int skillsOfFriend, int threshold) {
    return skillsOfFriend >= threshold;
}

int main() {
    int threshold = 100;
    int skillsOfFriends[] = {110, 130, 90, 100, 45};
    int numOfFriends = sizeof(skillsOfFriends) / sizeof(skillsOfFriends[0]);

    for (int idx = 0; idx < numOfFriends; idx++) {
        printf("%s\n", isFriendOfGoki(skillsOfFriends[idx], threshold) ? "YES" : "NO");
    }

    return 0;
}