/**
Utkarsh's mother recently received N piles of books as a gift from someone. The
ith pile contains Bi books.

She neither wants to keep the voluminous books with herself nor she wants to
throw them away. So, she decided to distribute them to students of the nearby
school. She decided to call K students to her home and ask one of her sons
(Utkarsh or Saharsh) to distribute books.

Also, she will get happy only if the following condition is satisfied: For every
pile i there must be at least one student who receives more than one books from
pile i.

She knows that Utkarsh is very lazy. So he will randomly pick a student and give
him a book from any pile. Since he distributes randomly, he might make her sad.

On the other hand, Saharsh is smart and obedient so he will always find a way of
distribution (if possible) which will make her happy.

You need to output 2 integers : The maximum value of K

When Utkarsh is asked to distribute the books. His mother must remain happy
irrespective of the way of his distribution.

When Saharsh is asked to distribute the books.

Input format:
The first line contains an integer T, denoting the number of test cases.
The first line of each test case contains an integer N, denoting the number of
piles. The next line contains N integers, the array B.

Output format:
For each test case, print two space separated integers: The maximum value of K
if Utkarsh distributes and the maximum value of K if Saharsh distributes the
books.

Constraints:
1 ≤ T ≤ 10
1 ≤ N ≤ 1000
2 ≤ Bi ≤ 1000

https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/utkarsh-and-distributing-books-february-easy/description/
*/
#include <stdio.h>

struct UtkarshSaharshMaxStudents {
    int maxNumOfStudForUtkarsh, maxNumOfStudForSaharsh;
};

struct UtkarshSaharshMaxStudents getMaxStudsReqForUtkarshAndSaharsh(int *piles, int numOfPiles) {
    int totalBooks = 0, minBooksInAPile = 1001;
    for (int itr = 0; itr < numOfPiles; itr++) {
        if (piles[itr] < minBooksInAPile) {
            minBooksInAPile = piles[itr];
        }
        totalBooks = totalBooks + piles[itr];
    }

    struct UtkarshSaharshMaxStudents utkarshSaharshMaxStudents;
    utkarshSaharshMaxStudents.maxNumOfStudForUtkarsh = minBooksInAPile - 1;
    utkarshSaharshMaxStudents.maxNumOfStudForSaharsh = totalBooks - numOfPiles;
    return utkarshSaharshMaxStudents;
}

int main() {
    int numOfPiles = 2;
    int piles[2] = {5, 5};

    struct UtkarshSaharshMaxStudents utkarshSaharshMaxStudents = getMaxStudsReqForUtkarshAndSaharsh(piles, numOfPiles);
    printf("%d %d", utkarshSaharshMaxStudents.maxNumOfStudForUtkarsh, utkarshSaharshMaxStudents.maxNumOfStudForSaharsh);

    return 0;
}