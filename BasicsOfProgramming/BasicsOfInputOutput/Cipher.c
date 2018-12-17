/**
 *
Indian army is going to do a surprise attack on one of its enemies country. The
President of India, the Supreme Commander of the Indian Army will be sending an
alert message to all its commanding centers. As enemy would be monitoring the
message, Indian army is going to encrypt(cipher) the message using basic
encryption technique. A decoding key 'K' (number) would be sent secretly.

You are assigned to develop a cipher program to encrypt the message. Your cipher
must rotate every character in the message by a fixed number making it
unreadable by enemies.

Given a single line of string 'S' containing alpha, numeric and symbols,
followed by a number '0<=N<=1000'. Encrypt and print the resulting string.

Note: The cipher only encrypts Alpha and Numeric. (A-Z, a-z, and 0-9) . All
Symbols, such as - , ; %, remain unencrypted.

https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/cipher-1/

*/
#include <stdio.h>
#include <string.h>

#define UPPER 1
#define LOWER 2
#define NUMERIC 3
#define NONE 0

int isUpper(char c) { return c >= 'A' && c <= 'Z'; }

int isLower(char c) { return c >= 'a' && c <= 'z'; }

int isAlpha(char c) { return isUpper(c) ? UPPER : isLower(c) ? LOWER : NONE; }

int isNumeric(char c) { return c >= '0' && c <= '9' ? NUMERIC : NONE; }

int isAlphaNumeric(char c) {
  int alpha = isAlpha(c);
  return (NONE != alpha) ? alpha : isNumeric(c);
}

void encrypt(char *statement, int key) {
  int idx = 0, currCharType;
  while ('\0' != statement[idx]) {
    if (NONE != (currCharType = isAlphaNumeric(statement[idx]))) {
      switch (currCharType) {
        case UPPER:
          statement[idx] = (statement[idx] - 'A' + key) % 26 + 'A';
          break;
        case LOWER:
          statement[idx] = (statement[idx] - 'a' + key) % 26 + 'a';
          break;
        case NUMERIC:
          statement[idx] = (statement[idx] - '0' + key) % 10 + '0';
          break;
      }
    }

    idx++;
  }
}

int main() {
  char statement[10001];
  memcpy(statement, "All-convoYs-9-be:Alert1.", 25);
  int key = 4;

  printf("%s\n", statement);
  printf("%d\n", key);
  encrypt(statement, key);
  printf("%s\n", statement);

  return 0;
}