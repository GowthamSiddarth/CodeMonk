/**
W.T.H.S.E.C

Confused? Well it stands for Welcome To HackerEarth September Easy Challenge :).
It's quite amazing when long words like this get reduced to such a short string.
They sound pretty cool and often make the chat interesting. They are almost used
everywhere these days.

Our friend Harsh has been recently reducing every sentence he receives to
acronym. Since Harsh is a young lad he has his own personal likes and dislikes.
There are some words which he just does not want to see in a sentence. So
whenever he encounters such a word he simply ignores it. Harsh is thinking of
converting a book to an acronym book where each sentence of the book is reduced
to its short form. Since Harsh is quite busy in promoting his new book he wants
you to help him in doing so.

So he gives you a set of words which he dislikes and a sentence for which he
wants to abbreviate. Help him in getting the required abbreviation.

Input:

The first line contains an integer K which denotes the number of disliked words,
This is followed by k lines where each line contains a disliked word, the next
line will contain an integer donating the number of words in the given sentence,
The last line contains the sentence of which Harsh wants to abbreviate.

The sentence will consist of number of words separated by a space

All words will consist of lowercase English alphabets(a-z)

Output:

In a single line print the required acronym. The Acronym should be printed in
Upper Case English alphabets separated by "." (dots).

Note:

changing a sentence to acronym means taking first character of each word of the
sentence and changing it to upper case then writing the characters separated by
"." (dots), remember that Harsh doesn't like some words so he will not take
their first character if they appear in the sentence

If a disliked word is present as a proper substring of a word in the given
sentence then it should not be ignored.

The final Output will never be an empty string.

Constraints:

1<= K <=10

1<= length of each word <=100

1<= length of the sentence <=100

https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/acronym-2/
*/
#include <string.h>
#include <malloc.h>
#include <stdio.h>

#define MAX_LEN_WORD 100

int indexOf(char **arrOfStrings, int numOfItems, char *key) {
    for (int idx = 0; idx < numOfItems; idx++) {
        if (0 == strcmp(arrOfStrings[idx], key)) {
            return idx;
        }
    }

    return -1;
}

char * trim(char *string) {
    while ('\0' != *string && ' ' == *string) {
        string++;
    }

    int lastNonWhitespaceCharIdx = 0, idx = 0;
    while ('\0' != string[idx]) {
        while ('\0' != string[idx] && ' ' != string[idx]) {
            idx++;
        }

        lastNonWhitespaceCharIdx = idx - 1;
        while ('\0' != string[idx] && ' ' == string[idx]) {
            idx++;
        }
    }

    if ('\0' != string[lastNonWhitespaceCharIdx + 1]) {
        string[lastNonWhitespaceCharIdx + 1] = '\0';
    }

    return string;
}

int getNumOfWhitespaces(char *sentence) {
    int idx = 0, whiteSpaceCount = 0;

    while ('\0' != sentence[idx]) {
        while ('\0' != sentence[idx] && ' ' != sentence[idx]) {
            idx++;
        }

        whiteSpaceCount = whiteSpaceCount + (' ' == sentence[idx]);
        while ('\0' != sentence[idx] && ' ' == sentence[idx]) {
            idx++;
        }
    }

    return whiteSpaceCount;
}

char ** split(char *sentence, int *numOfWords) {
    sentence = trim(sentence);
    int numOfWhitespaces = getNumOfWhitespaces(sentence);
    *numOfWords = numOfWhitespaces + 1;

    char **words = (char **)malloc(sizeof(char *) * (*numOfWords));
    for (int itr = 0; itr < (*numOfWords); itr++) {
        words[itr] = (char *)calloc(MAX_LEN_WORD + 1, sizeof(char));
    }   

    int currWordIdx = 0, currCharInSentenceIdx = 0;
    while ('\0' != sentence[currCharInSentenceIdx]) {
        int currCharInWordIdx = 0;
        while ('\0' != sentence[currCharInSentenceIdx] && ' ' != sentence[currCharInSentenceIdx]) {
            words[currWordIdx][currCharInWordIdx] = sentence[currCharInSentenceIdx];
            currCharInSentenceIdx++;
            currCharInWordIdx++;
        }

        while ('\0' != sentence[currCharInSentenceIdx] && ' ' == sentence[currCharInSentenceIdx]) {
            currCharInSentenceIdx++;
        }

        currWordIdx++;
    } 

    return words;
}

char toUpper(char c) {
    return c - 'a' + 'A';
}
