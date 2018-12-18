/**
 *
Dhananjay has recently learned about ASCII values.He is very fond of
experimenting. With his knowledge of ASCII values and character he has developed
a special word and named it Dhananjay's Magical word.

A word which consist of alphabets whose ASCII values is a prime number is an
Dhananjay's Magical word. An alphabet is Dhananjay's Magical alphabet if its
ASCII value is prime.

Dhananjay's nature is to boast about the things he know or have learnt about. So
just to defame his friends he gives few string to his friends and ask them to
convert it to Dhananjay's Magical word. None of his friends would like to get
insulted. Help them to convert the given strings to Dhananjay's Magical Word.

Rules for converting:

1.Each character should be replaced by the nearest Dhananjay's Magical alphabet.

2.If the character is equidistant with 2 Magical alphabets. The one with lower
ASCII value will be considered as its replacement.

Input format:

First line of input contains an integer T number of test cases. Each test case
contains an integer N (denoting the length of the string) and a string S.

Output Format:

For each test case, print Dhananjay's Magical Word in a new line.

Constraints:

1 <= T <= 100

1 <= |S| <= 500

https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/magical-word/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int primesBetween1To100[25] = {2,  3,  5,  7,  11, 13, 17, 19, 23,
                               29, 31, 37, 41, 43, 47, 53, 59, 61,
                               67, 71, 73, 79, 83, 89, 97};

char getClosestChar(char c, int primeCharBefore, int primeCharAfter) {
  int dist1 = abs(c - primeCharBefore);
  int dist2 = abs(c - primeCharAfter);
  return dist1 <= dist2 ? primeCharBefore : primeCharAfter;
}

void convertToMagicalWord(char *word) {
  int idx = 0;
  while ('\0' != word[idx]) {
    int low = 0, high = 25;

    while (low <= high) {
      int mid = low + (high - low) / 2;

      if (primesBetween1To100[mid] < word[idx]) {
        low = mid + 1;
      } else if (primesBetween1To100[mid] > word[idx]) {
        high = mid - 1;
      } else {
        break;
      }
    }

    if (low > high) {
      if (25 == low) {
        word[idx] = primesBetween1To100[high];
      } else if (-1 == high) {
        word[idx] = primesBetween1To100[low];
      } else {
        word[idx] = getClosestChar(word[idx], primesBetween1To100[high],
                                   primesBetween1To100[low]);
      }
    }

    idx++;
  }
}

int main() {
  char word[10];
  memcpy(word, "AFREEN", 7);

  printf("%s\n", word);
  convertToMagicalWord(word);
  printf("%s\n", word);

  return 0;
}