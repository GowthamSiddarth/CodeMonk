/**
Bob and Khatu are brave soldiers in World War 3. They have spotted an enemy
troop which is planting bombs. They sent message to the command centre
containing characters W and B where W represents a wall and B represents a Bomb.
They asked command to tell them how many walls will be destroyed if all bombs
explode at once. One bomb can destroy 2 walls on both sides.

Input:

First line of input contains number of test cases T. Each test case contains a
single string which contains two type of chars 'W' and 'B'.

Output:

For each test case print the total number of destroyed wall.

Constraints:

1 ≤ T ≤ 10
1 ≤ |S| ≤ 10^5

https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/bob-and-bombs-cake-walk/
*/

int getNumOfWallsDestroyed(char *axis) {
    int count = 0, idx = 0;
    while ('\0' != axis[idx]) {        
        if ('B' == axis[idx]) {
            if (idx >= 1 && 'W' == axis[idx - 1]) {                
                count++;
                axis[idx - 1] = ' ';
            }
            if (idx >= 2 && 'W' == axis[idx - 2]) {                
                count++;
                axis[idx - 2] = ' ';
            }
            if ('\0' != axis[idx + 1] && 'W' == axis[idx + 1]) {                
                count++;
                axis[idx + 1] = ' ';
            }
            if ('\0' != axis[idx + 2] && 'W' == axis[idx + 2]) {                
                count++;
                axis[idx + 2] = ' ';
            }
        }

        idx++;
    }

    return count;
}
