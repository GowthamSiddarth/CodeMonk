/**
Watson gives a date to Sherlock and asks him what is the date on the previous
day. Help Sherlock. You are given date in DD MM YYYY format. DD is an integer
without leading zeroes. MM is one of the "January", "February", "March",
"April", "May", "June", "July", "August", "September", "October", "November" and
"December" (all quotes for clarity). YYYY is also an integer between 1600 and
2000 without leading zeroes. You have to print the date of the previous day in
same format.

Input and Output
First line, T (≤ 100), the number of testcases. Each testcase consists of date
in specified format. For each testcase, print the required answer in one line.
Given date will be a valid date.

https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/sherlock-and-date/
*/
#include <string.h>
#include <stdio.h>

enum Boolean {FALSE, TRUE};

struct Month {
    char name[10];
    int days;
};

struct Month months[] = {{"January", 31}, {"February", 28}, {"March", 31}, {"April", 31}, {"May", 31},
                            {"June", 30}, {"July", 31}, {"August", 31}, {"September", 30}, 
                            {"October", 31}, {"November", 30}, {"December", 31}};

struct Date {
    int date;
    struct Month month;
    int year;
};

enum Boolean isLeapYear(int year) {
    return (0 == (year % 4)) || ((0 == (year % 400)) && (0 != (year % 100)));
}

struct Date getPreviousDate(struct Date date) {
    struct Date previousDate;
    if (date.date > 1) {
        previousDate.date = date.date - 1;
        previousDate.month = date.month;
        previousDate.year = date.year;
    } else if (0 == strcmp(date.month.name, "March")) {
        previousDate.date = isLeapYear(date.year) ? 29 : 28;
        previousDate.month = months[1];
        previousDate.year = date.year;
    } else if (0 != strcmp(date.month.name, "January")) {
        int idx = 1;
        while (idx < 12 && 0 != strcmp(months[idx].name, date.month.name)) idx++;
        previousDate.date = months[idx - 1].days;
        previousDate.month = months[idx - 1];
        previousDate.year = date.year;
    } else {
        previousDate.date = 31;
        previousDate.month = months[11];
        previousDate.year = date.year - 1;
    }

    return previousDate;
}

int main() {
    struct Date date = {1, months[0], 1996};
    struct Date previousDate = getPreviousDate(date);
    printf("%d %s %d\n", previousDate.date, previousDate.month.name, previousDate.year);

    return 0;
}   