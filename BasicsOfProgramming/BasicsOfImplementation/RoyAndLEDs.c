/**
Its Diwali time and there are LED series lights everywhere. Little Roy got
curious about how LED lights work.

He noticed that in one single LED Bulb there are 3 LED lights, namely Red, Green
and Blue.

State of the bulb at any moment is the sum of Red, Green and Blue LED light.

Roy took out all the LEDs and found that Red LED stays ON for R seconds, Green
LED stays ON for G seconds and Blue LED stays ON for B seconds. Similarly they
stay OFF for same respective R, G, B number of seconds. (Initially all the LEDs
are OFF. See Sample Test Case Explanation for better understanding)

Roy has one query for you, given the total number of seconds T, find the number
of seconds Red, Green, Blue, Yellow, Cyan, Magenta, White, Black(no light)
lights are visible.

Input:

One line containing space separated integers T, R, G, B

Output:

One line containing 8 space separated integers indicating the number of seconds
Red, Green, Blue, Yellow, Cyan, Magenta, White, Black (no light) lights are
visible. (See Sample I/O for clarification)

Constraints: 1 <= T, R, G, B <= 1000000

https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/roy-and-leds-6/
*/
#include <malloc.h>
#include <stdio.h>
#include <math.h>

enum BulbState {OFF, ON};
enum LEDState {RED, GREEN, BLUE, YELLOW, CYAN, MAGENTA, WHITE, BLACK};

enum LEDState getLEDState(enum BulbState bulb1, enum BulbState bulb2, enum BulbState bulb3) {
    enum LEDState ledState;
    switch (bulb1 + 2 * bulb2 + 4 * bulb3) {
        case 0: 
            ledState = BLACK;
            break;
        case 1: 
            ledState = RED;
            break;
        case 2: 
            ledState = GREEN;
            break;
        case 3: 
            ledState = YELLOW;
            break;
        case 4: 
            ledState = BLUE;
            break;
        case 5: 
            ledState = MAGENTA;
            break;
        case 6: 
            ledState = CYAN;
            break;
        case 7: 
            ledState = WHITE;
            break;
    }
    return ledState;
}

enum BulbState toggleBulbState(enum BulbState currBulbState) {
    return ON == currBulbState ? OFF : ON;
}

enum BulbState getBulbStateAt(enum BulbState currBulbState, int now, int bulbFreq) {
    if (0 == (now % bulbFreq)) {
        currBulbState = toggleBulbState(currBulbState);
    }

    return currBulbState;
}

int * getNumOfSecsForEachLEDState(int totalSeconds, int redFreq, int greenFreq, int blueFreq, int numOfStates) {
    int * timeForEachState = (int *)calloc(numOfStates, sizeof(int));

    enum BulbState bulb1State = ON;
    enum BulbState bulb2State = ON;
    enum BulbState bulb3State = ON;
    for (int itr = 0; itr < totalSeconds; itr++) {
        bulb1State = getBulbStateAt(bulb1State, itr, redFreq);
        bulb2State = getBulbStateAt(bulb2State, itr, greenFreq);
        bulb3State = getBulbStateAt(bulb3State, itr, blueFreq);

        enum LEDState ledState = getLEDState(bulb1State, bulb2State, bulb3State);
        timeForEachState[ledState]++;
    }

    return timeForEachState;
}