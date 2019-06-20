#include "time.c"
#include <stdio.h>

int main() {

	Calendar *random_calendar = makeRandomCalendar();

	//should be 0000-00-00
	char *date_time = getDateTime(random_calendar, "YYYY-MM-DD");
	
	puts(date_time);

	setDateTimeRandomly(random_calendar);

	TIME_COUNT date_time_counter = getDateTimeAsCounter(random_calendar);

	if(dateTimeIsBefore(random_calendar, 0)) {
					puts("Fail! random time is earlier than the dawn of time!");
	}

	TIME_COUNT date_time_old_counter = date_time_counter;

	advanceTime(random_calendar, YEAR);

	if(dateTimeIsAfter(random_calendar, date_time_old_counter)){
					puts("Fail! advance (or associated checks) isn't working");
	}

	rewindTime(random_calendar, YEAR);

	if(getDateTimeAsCounter(random_calendar) != date_time_old_counter) {
			puts("Fail! rewind isn't working.");
	}

	return 0;
}
