/**
Roy's friends has been spying on his text messages, so Roy thought of an
algorithm to encrypt text messages.

Encryption Algorithm is as follows:
We say message to be encrypted as Plain Text and encrypted form of message as
Cipher. Plain Text consists of lower case alphabets only. Consider the Cipher
Disk as shown in figure.

http://he-s3.s3-website-ap-southeast-1.amazonaws.com/media/uploads/525661d.png

Initially, we start with 0 (zero). For each character in Plain Text, we move
either clockwise or anti-clockwise on the disk depending on which way is closest
from where we are currently standing. If both clockwise and anti-clockwise
distances are equal, we give priority to clockwise movement. Clockwise movements
are represented using positive numbers while Anti-clockwise movements are
represented as negative numbers.

Roy needs your help in implementing this algorithm. Given a Plain Text message,
your task is to encrypt it using above algorithm and print the Cipher Text.

Input:
First line contains integer T - number of test cases.
Each of next T lines contains a string representing Plain Text message.

Output:
For each test case, print the encrypted form of given string in new line.
Each line should consist of space separated integers in the range [-12,13].
See the sample test case for more clarification.

Constraints:
1 <= T <= 100
1 <= Length of Plain Text string <= 100

https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/roy-and-cipher-disk/
*/

int getClockwiseDistance(char from, char to) {
    return to >= from ? to - from : to - from + 25 - 2 *'a';
}

int getAntiClockwiseDistance(char from, char to) {
    return to >= from ? to - from + 25 - 2 *'a' : to - from;
}