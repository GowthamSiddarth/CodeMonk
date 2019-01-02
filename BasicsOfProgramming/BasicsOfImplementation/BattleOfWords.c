/**
Alice and Bob are fighting over who is a superior debater. However they wish to
decide this in a dignified manner. So they decide to fight in the Battle of
Words.

In each game both get to speak a sentence. Because this is a dignified battle,
they do not fight physically, the alphabets in their words do so for them.
Whenever an alphabet spoken by one finds a match (same alphabet) spoken by the
other, they kill each other. These alphabets fight till the last man standing.

A person wins if he has some alphabets alive while the other does not have any
alphabet left.

Alice is worried about the outcome of this fight. She wants your help to
evaluate the result. So kindly tell her if she wins, loses or draws.

Input:
First line contains an integer T denoting the number of games played.
Each test case consists of two lines. First line of each test case contains a
string spoken by Alice. Second line of each test case contains a string spoken
by Bob.

Note:
Each sentence can have multiple words but the size of sentence shall not exceed
105.

Output:
For each game, output consists of one line each containing "You win some." if
she wins ,"You lose some." if she loses or "You draw some." otherwise.

Constraints:
1 ≤ T ≤ 10
1≤ |A|,| B| ≤ 105
'a' ≤ alphabet ≤ 'z'
Each string contains atleast one alphabet.
Scoring:
Length of |A|,|B| in each test case does not exceed 104 : ( 30 pts )
Original Constraints : ( 70 pts )

https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/battle-of-words/
*/
#define WIN 1
#define LOSE -1
#define DRAW 0

int getAliceStatus(char *aliceSentence, char *bobSentence) {
    int letters[26] = {0};
    
    int idx = 0;
    while ('\0' != aliceSentence[idx]) {
        letters[aliceSentence[idx] - 'a']++;
    }

    idx = 0;
    while ('\0' != bobSentence[idx]) {
        letters[bobSentence[idx] - 'a']--;
    }

    int numOfAliceLettersLeft = 0, numOfBobLettersLeft = 0;
    for (int itr = 0; itr < 26; itr++) {
        if (letters[itr] > 0) {
            numOfAliceLettersLeft++;
        } else if (letters[itr] < 0) {
            numOfBobLettersLeft++;
        }
    }

    if (numOfAliceLettersLeft > 0 && 0 == numOfBobLettersLeft) {
        return WIN;
    } else if (0 == numOfAliceLettersLeft && numOfBobLettersLeft > 0) {
        return LOSE;
    } else {
        return DRAW;
    }

}


