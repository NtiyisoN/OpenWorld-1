/* OpenWorld 1.0 
 * by Blake Cooper
 *
 * time.h 
 * created:	2019-06-06 
 * updated:	2019-06-06 
 * 
 */

#include "global.h"

#define NAME_SIZE 64

/*Definitions for units of time */
#define NUMBER_UNITS 8

#define ERA 0
#define YEAR 1
#define MONTH 2
#define DAY 3
#define HOUR 4
#define MINUTE 5
#define SECOND 6
#define MILLISECOND 7

/*Definitions for time formats */
#define DD 0
#define MM 1
#define YYYY 2
#define MNTH 3
#define ERA 4
#define HH 5
#define MM 6
#define SS 7
#define TIME 8
#define DATE 9

//Struct for a unit of time
typedef struct unit {
	char name[NAME_SIZE];
	short hasName;

	int count;
	short hasCount;
	
	Unit *next;
	Unit *prev;
	
	int units_in_higher_unit;

} Unit;

//Calendar array (Unit pointers)
typedef struct calendar{
	Unit *calendar[NUMBER_UNITS];
	Unit current_datetime[NUMBER_UNITS];
} Calendar;

//Load a calendar from file
Calendar loadCalendarFromFile(char[FILENAME_MAX_LENGTH]);

//...or, create a random calendar.
Calendar loadRandomCalendar();

//Advance a unit of time
void advance (Calendar cal, int unit);

//Rewind a unit of time
void rewind (Calendar cal, int unit);

//Set the current time
char *setDateTime (Calendar cal, int format, char *date_time);

//Set the current time randomly
void setDateTimeRandomly (Calendar cal);

//Return the current time as a written statement
char *getDateTime (char *format);

//Return the current time as an int counter in seconds from 
long long *getDateTimeAsCounter ();

//Boolean: is the current time before the specified time?
short dateTimeIsBefore (char *date_time);

//Boolean: is the current time after the specified time?
short dateTimeIsAfter (char *date_time);

typedef long long TIME_COUNT;

//Convert written time format to counter
TIME_COUNT parseDateTime(Calendar cal);
