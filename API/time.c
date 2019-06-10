/* OpenWorld 1.0 
 * by Blake Cooper
 *
 * time.c 
 * created:	2019-06-06 
 * updated:	2019-06-10 
 * 
 */

#include <stdlib.h>
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
	for (int i = 0; i < NUMBER UNITS; i++) {
		cal->calendar[i] = malloc(sizeof(Unit));

		if (i < 5) {
			cal->calendar[i]->hasName = 0;
			cal->calendar[i]->name = '\0';

			cal->calendar[i]->hasCount = 1;
			cal->calendar[i]->count = 0;

		} else {
			cal->calendar[i]->hasName = 1;
			cal->calendar[i]->name = makeWord(lang, NAME_SIZE);
			
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
	
	//Now, link the named units together in a string
	for (int i = MONTH; i < NUMBER_UNITS; i++) {
		int count = 1;
		Unit previous_unit = cal->calendar[i];
		while (count < cal->calendar[i]->units_in_higher_unit) {
			Unit *next = malloc(sizeof(Unit));
			next->name = makeWord(lang, NAME_SIZE);
			name->hasName = 1;
			if (cal->calendar[i]->hasCount) {
				hasCount = 1;
			} else { 
				hasCount = 2; 
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

void destroyCalendar(Calendar cal) {
	free(cal);
}

void advance(Calendar cal, int unit) {
	cal->current_datetime = 
			cal->current_datetime + cal->calendar[unit]->count_in_ms;
}

void rewind (Calendar cal, int unit) {
	//Note: there cannot be negative time, if the unit to be rewound is greater than the amount of elapsed time, time will reset to 0.
	if (cal->calendar[unit]->count_in_ms > cal->current_datetime) {
		cal->current_datetime = 0;
	} else {
		cal->current_datetime = 
				cal->current_datetime - cal->calendar[unit]->count_in_ms;
	}
}

void setDateTimeRandomly (Calendar cal) {
	cal->current_datetime = rand() % (NUMBER_OF_HISTORICAL_ERAS * YEARS_PER_HISTORICAL_ERA * cal->calendar[YEAR]->count_in_ms);
}

char *getDateTime (const Calendar cal, char *format) {
	char dateTime[MAX_CHARS_FOR_DESCRIPTION];
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
	char *write_cursor = dateTime;
	char *read_cursor = format;

    while (read_cursor != '\0') {
		switch (*read_cursor) {
				case 'D':
					char *next = read_cursor + 1;
					if (*next == 'A') {
						next++;
						if (*next == 'T') {
							next++;
							if (*next == 'E') {
								//TODO: return date string
								break;
							}
						}
					} else if (*next == 'D') {
						//TODO: return day
						break;
					} else {
						*write_cursor = *read_cursor;
						break;
					}
					break;
				case 'E':
					char *next = read_cursor + 1;
					if (*next == 'R') {
						next++;
						if (*next == 'A') {
							//TODO: return era name
							break;
						}
					} else {
						*write_cursor = *read_cursor;
						break;
					}
					break;
				case 'H':
					char *next = read_cursor + 1;
					if (*next == 'H') {
						//TODO: return hour number
						break;
					} else {
						*write_cursor = *read_cursor;
						break;
					}
					break;
				case 'M':
					char *next = read_cursor + 1;
					if (*next == 'M') {
						//TODO: return month number
						break;
					} else if (*next == 'N') {
						next++;
						if (*next == 'T') {
							next++;
							if (*next == 'H') {
								//TODO: return month name
								break;
							}
						}
					} else if (*next == 'T') {
						//TODO: return minute
						break;
					} else {
						*write_cursor = *read_cursor;
						break;
					}
					break;
				case 'S':
					char *next = read_cursor + 1;
					if (*next == 'S') {
						//TODO: return seconds number
						break;
					} else {
						*write_cursor = *read_cursor;
						break;
					}
					break;
				case 'T':
					char *next = read_cursor + 1;
					if (*next == 'I') {
						next++;
						if (*next == 'M') {
							next++;
							if (*next == 'E') {
								//TODO: return time string
								break;
							}
						}
					} else {
						*write_cursor = *read_cursor;
						break;
					}
					break;
				case 'Y':
					char *next = read_cursor + 1;
					if (*next == 'Y') {
						next++;
						if (*next == 'Y') {
							next++;
							if (*next == 'Y') {
								//TODO: return year number
								break;
							}
						}
					} else {
						*write_cursor = *read_cursor;
						break;
					}
					break;
				default:
						*write_cursor = *read_cursor;
		}

		read_cursor++;
	}

	return dateTime;
}

long long getDateTimeAsCounter (Calendar cal) {
		return cal->current_datetime;
}

short dateTimeIsBefore (Calendar cal, long long datetime) {
	return cal->current_datetime < datetime;
}


short dateTimeIsAfter (Calendar cal, long long datetime) {
	return datetime < cal->current_datetime;
}
