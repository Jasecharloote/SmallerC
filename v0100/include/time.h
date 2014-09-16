/*
  Copyright (c) 2014, Alexey Frunze
  2-clause BSD license.
*/
#ifndef __TIME_H
#define __TIME_H

#ifndef NULL
#define NULL 0
#endif

#ifndef __SIZE_T_DEF
#define __SIZE_T_DEF
typedef unsigned size_t;
#endif

#ifdef __SMALLER_C_32__
#ifndef __TIME_T_DEF
#define __TIME_T_DEF
typedef unsigned long time_t;
#endif
#endif

#ifdef __SMALLER_C_32__
typedef unsigned long clock_t;
#endif

#ifdef _DOS
#define CLOCKS_PER_SEC 18 // clock() will recalculate result to 18 Hz instead of to 18.2 Hz
#endif

struct tm
{
  int tm_sec;   // seconds after the minute - [0, 60]
  int tm_min;   // minutes after the hour - [0, 59]
  int tm_hour;  // hours since midnight - [0, 23]
  int tm_mday;  // day of the month - [1, 31]
  int tm_mon;   // months since January - [0, 11]
  int tm_year;  // years since 1900
  int tm_wday;  // days since Sunday - [0, 6]
  int tm_yday;  // days since January 1 - [0, 365]
  int tm_isdst; // Daylight Saving Time flag
};

#ifdef __SMALLER_C_32__
clock_t clock(void);
time_t time(time_t*);
struct tm* gmtime(time_t*);
struct tm* localtime(time_t*);
time_t mktime(struct tm*);
char* ctime(time_t*);
#endif
char* asctime(struct tm*);

#endif