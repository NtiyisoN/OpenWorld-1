/* OpenWorld 1.0 
 * by Blake Cooper
 *
 * time.h 
 * created:	2019-06-06 
 * updated:	2019-06-14 
 * 
 */

#include "global.h"

#define NAME_SIZE 64

/*Definitions for units of time */
#define NUMBER_UNITS 8

#define ERA 7
#define YEAR 6
#define MONTH 5
#define DAY 4
#define HOUR 3
#define MINUTE 2
#define SECOND 1
#define MILLISECOND 0

/*Definitions for time formats */
#define DD 0
#define MM 1
#define YYYY 2
#define YR 3
#define MNTH 4
#define ER 5
#define HH 6
#define MT 7
#define SS 8
#define TIME 9:61

#define DATE 10

//Struct for a unit of time
typedef struct unit {
	char name[NAME_SIZE];
	short hasName;

	//Dichotomizing units of time here by "count" units (like seconds and minutes, which typically don't have names, and "named" units, like months, which are referred to as such. Years are both count and named units.
	short hasCount;
	long long count;

	//next and previous units in the chain (so, for example, link this month to the next and previous months.
	void *next;
	void *prev;
	
	//Number of these units to make up the next highest unit
	int units_in_higher_unit;

	//Count in ms
	int count_in_ms;

} Unit;

//Calendar array (Unit pointers)
typedef struct calendar{
	Unit *calendar[NUMBER_UNITS];
	long long current_datetime;
} Calendar;

//Load a calendar from file
Calendar *makeCalendarFromFile(char[FILENAME_MAX_LENGTH]);

//...or, create a random calendar.
Calendar *makeRandomCalendar();

//Free a calendar.
void destroyCalendar(Calendar cal);

//Advance a unit of time
void advance (Calendar cal, int unit);

//Rewind a unit of time
void rewind (Calendar cal, int unit);

//Set the current time randomly
void setDateTimeRandomly (Calendar cal);

//Return the current time as a written statement
char *getDateTime (const Calendar cal, char *format);

//Return the current time as an int counter in seconds from 
long long *getDateTimeAsCounter (Calendar cal);

//Boolean: is the current time before the specified time?
short dateTimeIsBefore (Calendar cal, long long datetime);

//Boolean: is the current time after the specified time?
short dateTimeIsAfter (Calendar cal, long long datetime);
