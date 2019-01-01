/**
Roy is going through the dark times of his life. Recently his girl friend broke
up with him and to overcome the pain of acute misery he decided to restrict
himself to Eat-Sleep-Code life cycle. For N days he did nothing but eat, sleep
and code.

A close friend of Roy kept an eye on him for last N days. For every single
minute of the day, he kept track of Roy's actions and prepared a log file.

The log file contains exactly N lines, each line contains a string of length
1440 ( i.e. number of minutes in 24 hours of the day). The string is made of
characters E, S, and C only; representing Eat, Sleep and Code respectively. ith
character of the string represents what Roy was doing during ith minute of the
day.

Roy's friend is now interested in finding out the maximum of longest coding
streak of the day - X. He also wants to find the longest coding streak of N days
- Y. Coding streak means number of C's without any E or S in between.

See sample test case for clarification.

Input:
First line of each file contains N - number of days.
Following N lines contains a string of exactly 1440 length representing his
activity on that day.

Output:
Print X and Y separated by a space in a single line.

Constraints:
1 ≤ N ≤ 365
String consists of characters E, S, and C only.
String length is exactly 1440.

Note: The sample test case does not follow the given constraints on string
length to avoid large data. It is meant only for explanation. We assure you that
the hidden test files strictly follow the constraints.

https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/roys-life-cycle/
*/
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <stdio.h>

int getLongestCodingTime(char *activities) {    
    int maxCodingStreak = 0;
    int idx = 0;

    while ('\0' != activities[idx]) {
        while ('\0' != activities[idx] && 'C' != activities[idx]) {
            idx++;
        }

        int currCodingStreak = 0;
        while('\0' != activities[idx] && 'C' == activities[idx]) {
            currCodingStreak++;
            idx++;
        }

        if (currCodingStreak > maxCodingStreak) {
            maxCodingStreak = currCodingStreak;
        }
    }

    return maxCodingStreak;    
}

char * concat(int numOfStrings, ...) {
    va_list allDaysActivities;
    size_t length = 0;
    
    if (numOfStrings < 1) {
        return NULL;
    }

    va_start(allDaysActivities, numOfStrings);
    for (int itr = 0; itr < numOfStrings; itr++) {
        char *singleDayActivities = va_arg(allDaysActivities, char *); 
        length = length + strlen(singleDayActivities);
    }
    va_end(allDaysActivities);

    char *concatedString = (char *)malloc(length + 1);

    char *dest = concatedString;
    va_start(allDaysActivities, numOfStrings);
    for (int itr = 0; itr < numOfStrings; itr++) {
        char *singleDayActivities = va_arg(allDaysActivities, char *);
        
        while (*dest++ = *singleDayActivities++);
        dest--;
    }
    va_end(allDaysActivities);

    return concatedString;
}

int main() {
    int numOfStrings = 4;
    char codingStreaks[365][1441] = {"SSSSEEEECCCCEECCCC", "CCCCCSSSSEEECCCCSS", "SSSSSEEESSCCCCCCCS", "EESSSSCCCCCCSSEEEE"};

    int maxCodingStreakOfAllDays = 0;
    char *totalActivitiesStreak = "";
    for (int itr = 0; itr < numOfStrings; itr++) {
        int maxCodingStreakOfADay = getLongestCodingTime(codingStreaks[itr]);

        if (maxCodingStreakOfADay > maxCodingStreakOfAllDays) {
            maxCodingStreakOfAllDays = maxCodingStreakOfADay;
        }   

        totalActivitiesStreak = concat(2, totalActivitiesStreak, codingStreaks[itr]);     
    }

    int maxCodingStreamFromAllActivities = getLongestCodingTime(totalActivitiesStreak);
    printf("%d %d", maxCodingStreakOfAllDays, maxCodingStreamFromAllActivities);

    return 0;
}