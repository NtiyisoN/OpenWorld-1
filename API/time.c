/* OpenWorld 1.0 
 * by Blake Cooper
 *
 * time.c 
 * created:	2019-06-06 
 * updated:	2019-06-20 
 * 
 */

#ifndef TIME_H
#define TIME_H

#include <stdlib.h>
#include <stdio.h>

#include "time.h"
#include "language.c"

Calendar *makeCalendarFromFile(char *filename) {
//TODO
	return calloc(1,sizeof(Calendar));
}

Calendar *makeRandomCalendar() {
	Calendar *cal = malloc(sizeof(Calendar));

	//Generate a language to make the names of the units from. TODO: Find a way to check for existing languages and use one of them, if available.
	Language *lang = makeRandomLanguage();
	for (int i = 0; i < NUMBER_UNITS; i++) {
		cal->calendar[i] = calloc(1, sizeof(Unit));

		if (i < 5) {
			cal->calendar[i]->hasCount = 1;
			cal->calendar[i]->count = 0;

		} else {
			cal->calendar[i]->hasName = 1;
			strcpy(cal->calendar[i]->name, makeWord(lang));
			
			cal->calendar[i]->hasCount = 0;
			cal->calendar[i]->count = 0;
		}

		cal->calendar[i]->prev = NULL;
	}

	//TODO: refactor! Don't hardcode this... ideally, the number and comparison of units will be user-defined
	
	//Milliseconds
	cal->calendar[0]->count_in_ms = 1;
	cal->calendar[0]->units_in_higher_unit = 1000;

	//Seconds	
	cal->calendar[1]->count_in_ms =
			cal->calendar[0]->count_in_ms *
			cal->calendar[0]->units_in_higher_unit;
	cal->calendar[1]->units_in_higher_unit = 60;
	
	//Minutes	
	cal->calendar[2]->count_in_ms = 
			cal->calendar[1]->count_in_ms *
			cal->calendar[1]->units_in_higher_unit;
	cal->calendar[2]->units_in_higher_unit = 60;
	
	//Hours	
	cal->calendar[3]->count_in_ms = 
			cal->calendar[2]->count_in_ms *
			cal->calendar[2]->units_in_higher_unit;
	cal->calendar[3]->units_in_higher_unit = 24;
	
	//Days	
	cal->calendar[4]->count_in_ms = 
			cal->calendar[3]->count_in_ms *
			cal->calendar[3]->units_in_higher_unit;
	cal->calendar[4]->units_in_higher_unit = 30;
	
	//Months	
	cal->calendar[5]->count_in_ms = 
			cal->calendar[4]->count_in_ms *
			cal->calendar[4]->units_in_higher_unit;
	cal->calendar[5]->units_in_higher_unit = 12;
	
	//Years	
	cal->calendar[6]->count_in_ms = 
			cal->calendar[5]->count_in_ms *
			cal->calendar[5]->units_in_higher_unit;
	cal->calendar[6]->units_in_higher_unit = YEARS_PER_HISTORICAL_ERA;

	//Era
	cal->calendar[7]->count_in_ms = 
			cal->calendar[6]->count_in_ms *
			cal->calendar[6]->units_in_higher_unit;
	cal->calendar[7]->units_in_higher_unit = 0;
	
	//Now, link the named units together in an array
	for (int i = MONTH; i < NUMBER_UNITS; i++) {
		int count = 1;
		Unit *previous_unit = cal->calendar[i];
		while (count < cal->calendar[i]->units_in_higher_unit) {
			Unit *next = malloc(sizeof(Unit));
			strcpy(next->name, makeWord(lang));
			next->hasName = 1;
			if (cal->calendar[i]->hasCount) {
				cal->calendar[i]->hasCount = 1;
			} else { 
				cal->calendar[i]->hasCount = 2; 
			}

			next->prev = previous_unit;
			previous_unit->next = next;

			next->units_in_higher_unit = cal->calendar[i]->units_in_higher_unit;

			next->count_in_ms = cal->calendar[i]->count_in_ms;

			previous_unit = next;
			count++;
		}
	}
	
	cal->current_datetime = 0;

	return cal;
}

void destroyCalendar(Calendar *cal) {
	free(cal);
}

void advanceTime (Calendar *cal, int unit) {
	cal->current_datetime = cal->current_datetime + cal->calendar[unit]->count_in_ms;
}

void rewindTime (Calendar *cal, int unit) {
	//Note: there cannot be negative time, if the unit to be rewound is greater than the amount of elapsed time, time will reset to 0.
	if (cal->calendar[unit]->count_in_ms > cal->current_datetime) {
		cal->current_datetime = 0;
	} else {
		cal->current_datetime = 
				cal->current_datetime - cal->calendar[unit]->count_in_ms;
	}
}

void setDateTimeRandomly (Calendar *cal) {
	cal->current_datetime = rand() % (NUMBER_OF_HISTORICAL_ERAS * YEARS_PER_HISTORICAL_ERA * cal->calendar[YEAR]->count_in_ms);
}

char *getDateTime (const Calendar *cal, char *format) {
	char *datetime = calloc(MAX_CHARS_IN_DESCRIPTION, sizeof(char));
	int units[NUMBER_UNITS];
	
	long long remaining = cal->current_datetime;

	//get date_time as counts of each unit in an array
	for (int i = (NUMBER_UNITS -1); i > -1; i--) {
		if (remaining > cal->calendar[i]->count_in_ms) {
			units[i] = remaining / cal->calendar[i]->count_in_ms;
			remaining = remaining % cal->calendar[i]->count_in_ms;
		}
	}
	
	//parse format
	char *format_cursor = format;

	while (*format_cursor != '\0') {
		char substr_4[5];
		memcpy(substr_4, format_cursor, 4);
		substr_4[4] = '\0';

		if (strcmp(substr_4, "DATE") == 0) {
			sprintf(datetime, "%d-%d-%d", units[YEAR], units[DAY], units[MONTH]); 
			format_cursor = format_cursor + 4;
		} else if (strcmp(substr_4, "MNTH")) {
			sprintf(datetime, "%s", cal->calendar[MONTH][units[MONTH]].name);
			format_cursor = format_cursor + 4;
		} else if (strcmp(substr_4, "TIME")) {
			sprintf(datetime, "%d:%d", units[HOUR], units[MINUTE]);
			format_cursor = format_cursor + 4;
		} else if (strcmp(substr_4, "YYYY")) {
			sprintf(datetime, "%d", units[YEAR]);
			format_cursor = format_cursor + 4;
		} else {
			char substr_2[3];
			memcpy(substr_2, substr_4, 2);
			substr_2[2] = '\0';

			if (strcmp(substr_2, "DD")) {
				sprintf(datetime, "%d", units[DAY]);
				format_cursor = format_cursor + 2;
			} else if (strcmp(substr_2, "HH")) {
				sprintf(datetime, "%d", units[HOUR]);
				format_cursor = format_cursor + 2;
			} else if (strcmp(substr_2, "MM")) {
				sprintf(datetime, "%d", units[DAY]);
				format_cursor = format_cursor + 2;
			} else if (strcmp(substr_2, "MT")) {
				sprintf(datetime, "%d", units[MONTH]); 
				format_cursor = format_cursor + 2;
			} else if (strcmp(substr_2, "SS")) {
				sprintf(datetime, "%d", units[DAY]);
				format_cursor = format_cursor + 2;
			} else if (strcmp(substr_2, "YR")) {
				sprintf(datetime, "%s", cal->calendar[YEAR][units[YEAR]].name);
				format_cursor = format_cursor + 2;
			} else if (strcmp(substr_2, "ER")) {
				sprintf(datetime, "%s", cal->calendar[ERA][units[ERA]].name);
				format_cursor = format_cursor + 3;
			} else {
				sprintf(datetime, "%c", *format_cursor);
				format_cursor++;
				break;
			}
		}
	}

	return datetime;
}

long long getDateTimeAsCounter (Calendar *cal) {
	return cal->current_datetime;
}

short dateTimeIsBefore (Calendar *cal, long long datetime) {
	if (cal->current_datetime < datetime) {
        return 1;
    } else {
        return 0;
    }

    return -1;
}


short dateTimeIsAfter (Calendar *cal, long long datetime) {
    if (datetime < cal->current_datetime) {
        return 1;
    } else {
        return 0;
    }
    return -1;
}

#endif /* TIME_H */
