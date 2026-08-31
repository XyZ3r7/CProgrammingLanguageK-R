//
// Created by XyZ3r7 on 8/18/26.
//
static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_yearP(int year, int month, int day) {
    int leap;
    char *p;
    if (month <= 0 || month > 12) return -1;

    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

    if (day < 1 || day > *(*(daytab + leap) + month))
        return -1;

    for (p = *(daytab + leap) + 1; p < *(daytab + leap) + month; p++) {
        day += *p;
    }

    return day;
}

void month_dayP(int year, int yearday, int *pmonth, int *pday) {
    int leap;
    char *p;

    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    if (yearday <= 0) {
        return;
    }

    for (p = *(daytab + leap) + 1; yearday > *p; p++) {
        if (p >= (*(daytab + leap) + 13)) {
            return;
        }
        yearday -= *p;
    }
    *pmonth = p - *(daytab + leap);
    *pday = yearday;
}
