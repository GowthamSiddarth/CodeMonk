/**
Harry wants to find Voldemort's potion making book but he is confused about how
to get it.

The book has a special ISBN(International Standard Book Number) which is  unique
numeric book identifier only for Voldemort's book printed on it. The ISBN is
based upon a 10-digit code. The ISBN is valid if: 1xdigit1 + 2xdigit2 + 3xdigit3
+ 4xdigit4 + 5xdigit5 + 6xdigit6 + 7xdigit7 + 8xdigit8 + 9xdigit9 + 10xdigit10
is divisible by 11. Help Harry to find the book! Input: Input the ISBN code as a
10-digit integer.

Output:
If the ISBN is not a 10-digit integer, output the message “Illegal ISBN” and
terminate the program. If the number is 10-digit, extract the digits of the
number and compute the sum as explained in the explanation. If the sum is
divisible by 11, output the message, “Legal ISBN”. If the sum is not divisible
by 11, output the message, “Illegal ISBN”.

https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/sum-it-if-you-can-4867f851/
*/
#include <stdio.h>
#include <string.h>

int isDivisible(int dividend, int divisor) { return 0 == (dividend % divisor); }

char *validateISBN(char *isbn) {
  int idx = 0, total = 0;
  while ('\0' != isbn[idx]) {
    total += (idx + 1) * (isbn[idx] - '0');
    idx++;
  }

  return isDivisible(total, 11) ? "Legal ISBN" : "Illegal ISBN";
}

int main() {
  char isbn[11];
  memcpy(isbn, "1401601499", 11);

  printf("%s\n", isbn);
  char *res = validateISBN(isbn);
  printf("%s", res);

  return 0;
}