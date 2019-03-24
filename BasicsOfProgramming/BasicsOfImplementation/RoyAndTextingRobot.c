/**
Roy frequently needs to use his old Nokia cell phone for texting whose keypad
looks exactly as shown below.

http://he-s3.s3-website-ap-southeast-1.amazonaws.com/media/uploads/8d7b093.png

You may be already familiar with the working of the keypad, however if you're
not we shall see a few examples.

To type "b", we need to press "2" twice. To type "?" we need to press "1"
thrice. To type "5" we need to press "5" four times. To type "0" we need to
press "0" twice.

I hope that it's clear how the keypad is being used.

Now Roy has lot of text messages and they are pretty lengthy. So he devised a
mechanical-hand-robot (with only 1 finger) which does the typing job. One
drawback of this robot is its typing speed. It takes 1 second for single press
of any button. Also it takes 1 second to move from one key to another. Initial
position of the hand-robot is at key 1.

So if its supposed to type "hack" it will take 1 second to move from key 1 to
key 4 and then 2 seconds to type "h". Now again 1 second to move from key 4 to
key 2 and then 1 second to type "a". Since "c" is present at the same key as "a"
movement time is 0. So it simply takes 3 seconds to type "c". Finally it moves
from key 2 to key 5 in 1 second and then 2 seconds to type "k". So in total it
took 1+2+1+1+3+1+2= 11 seconds to type "hack".

Input:
First line contains T - number of test cases.
Each of next T lines contain a string S - the message Roy needs to send.
Each string is terminated by a newline escape sequence \n.

Output:
For each test case output the time taken by the hand-robot to type down the
message.

Constraints:
1 ≤ T ≤ 50
1 ≤ |S| ≤ 1000 , where |S| denotes the length of string S
String is made of all the characters shown in the image above which are as
follows:
"." (period), "," (comma), "?" (question mark), "!" (exclamation mark), [a-z]
(small case english alphabets), "_" (underscore) and [0-9] (digits)

Note: We are using "_" underscore instead of " " empty space to avoid confusion

https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/roy-and-texting-robot-2/
*/
#include <stdio.h>
#include <string.h>

int getTimeTakenByRobot(char *text) {
    int buttons[256];
    int positions[256];

    buttons['a'] = 2;
    positions['a'] = 1;

    buttons['a'] = 2;
    positions['a'] = 1;

    buttons['b'] = 2;
    positions['b'] = 2;

    buttons['c'] = 2;
    positions['c'] = 3;

    buttons['d'] = 3;
    positions['d'] = 1;

    buttons['e'] = 3;
    positions['e'] = 2;

    buttons['f'] = 3;
    positions['f'] = 3;

    buttons['g'] = 4;
    positions['g'] = 1;

    buttons['h'] = 4;
    positions['h'] = 2;

    buttons['i'] = 4;
    positions['i'] = 3;

    buttons['j'] = 5;
    positions['j'] = 1;

    buttons['k'] = 5;
    positions['k'] = 2;

    buttons['l'] = 5;
    positions['l'] = 3;

    buttons['m'] = 6;
    positions['m'] = 1;

    buttons['n'] = 6;
    positions['n'] = 2;

    buttons['o'] = 6;
    positions['o'] = 3;

    buttons['p'] = 7;
    positions['p'] = 1;

    buttons['q'] = 7;
    positions['q'] = 2;

    buttons['r'] = 7;
    positions['r'] = 3;

    buttons['s'] = 7;
    positions['s'] = 4;

    buttons['t'] = 8;
    positions['t'] = 1;

    buttons['u'] = 8;
    positions['u'] = 2;

    buttons['v'] = 8;
    positions['v'] = 3;

    buttons['w'] = 9;
    positions['w'] = 1;

    buttons['x'] = 9;
    positions['x'] = 2;

    buttons['y'] = 9;
    positions['y'] = 3;

    buttons['z'] = 9;
    positions['z'] = 4;

    buttons['.'] = 1;
    positions['.'] = 1;

    buttons[','] = 1;
    positions[','] = 2;

    buttons['?'] = 1;
    positions['?'] = 3;

    buttons['!'] = 1;
    positions['!'] = 4;

    buttons['_'] = 0;
    positions['_'] = 1;

    buttons['0'] = 0;
    positions['0'] = 2;

    buttons['1'] = 1;
    positions['1'] = 5;

    buttons['2'] = 2;
    positions['2'] = 4;

    buttons['3'] = 3;
    positions['3'] = 4;

    buttons['4'] = 4;
    positions['4'] = 4;

    buttons['5'] = 5;
    positions['5'] = 4;

    buttons['6'] = 6;
    positions['6'] = 4;

    buttons['7'] = 7;
    positions['7'] = 5;

    buttons['8'] = 8;
    positions['8'] = 4;

    buttons['9'] = 9;
    positions['9'] = 5;

    int idx = 0, prevButton = 1, count = 0;
    while ('\0' != text[idx]) {
        if (prevButton != buttons[text[idx]]) {
            count++;
            prevButton = buttons[text[idx]];
        }

        count = count + positions[text[idx]];
        idx++;
    }

    return count;
}

int main() {
    char text[1001];
    memcpy(text, "i_?_u", 6);

    int res = getTimeTakenByRobot(text);
    printf("%d\n", res);

    return 0;
}