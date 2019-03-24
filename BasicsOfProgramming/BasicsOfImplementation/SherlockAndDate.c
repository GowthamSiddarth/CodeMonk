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

enum Boolean {FALSE, TRUE};

struct Month {
    char name[10];
    int days;
};

struct Month months[] = {{"January", 31}, {"February", 28}, {"March", 31}, {"April", 31}, {"May", 31},
                            {"June", 30}, {"July", 31}, {"August", 31}, {"September", 30}, 
                            {"October", 31}, {"November", 30}, {"December", 31}};

enum Boolean isLeapYear(int year) {
    return (0 == (year % 4)) || ((0 == (year % 400)) && (0 != (year % 100)));
}