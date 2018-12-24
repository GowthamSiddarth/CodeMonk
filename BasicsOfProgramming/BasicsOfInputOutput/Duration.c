/**
Rahul is a very busy persion he dont wan't to waste his time . He keeps account
of duration of each and every work. Now he don't even get time to calculate
duration of works, So your job is to count the durations for each work and give
it to rahul.

Input:

First line will be given by N number of works
Next N line will be given SH,SM,EH and EM  each separated by space(SH=starting
hr, SM=starting min, EH=ending hr, EM=ending min) 

Output:

N lines with duration HH MM(hours and minutes separated by space)

https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/duration/description/
*/

void convertMinutesToHoursAndMinutes(int totalMinutes, int *hours, int *minutes) {
    *hours = totalMinutes / 60;
    *minutes = totalMinutes % 60;
}

void getDuration(int startHours, int startMinutes, int endHours, int endMinutes, int *totalHours, int *totalMinutes) {
    int totalDurationInMinutes = (endHours * 60 + endMinutes) - (startHours * 60 + startMinutes);
    convertMinutesToHoursAndMinutes(totalDurationInMinutes, totalHours, totalMinutes);
}