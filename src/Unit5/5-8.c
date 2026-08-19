//
// Created by XyZ3r7 on 8/18/26.
//
//They should add this as a constant somewhere!
static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day) {
    int i, leap;
    if (month <= 0 || month > 12) return -1;
    if (year < 0) {
        leap = year%4 == 1;
    }else {
        leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    }
    if (day < 1 || day > daytab[leap][month])
        return -1;

    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;

    if (year < 0) {
        leap = year%4 == 1;
    }else {
        leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    }
    if (yearday <= 0) {
        return;
    }
    if (yearday > (leap ? 366 : 365)) return;

    for (i = 1; yearday > daytab[leap][i]; i++) {
        if (i >= 13) {
            return;
        }
        yearday -= daytab[leap][i];
    }
    *pmonth = i;
    *pday = yearday;
}