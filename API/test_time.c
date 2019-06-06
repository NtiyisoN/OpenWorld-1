#include "time.h"
#include "time.c"

int main() {

	Calendar random_calendar = loadRandomCalendar();

	//should be 0000-00-00
	char *date_time = getDatetime("YYYY-MM-DD");
	
	puts(date_time);

	setDateTimeRandomly(random_calendar);

	TIME_COUNT date_time_counter = parseDateTime(random_calendar);

	if(dateTimeIsBefore(random_calendar, 0)) {
					puts("Fail! random time is earlier than the dawn of time!");
	}

	TIME_COUNT date_time_old_counter = date_time_counter;

	advance(random_calendar, YEAR);

	if(dateTimeIsAfter(random_calendar, date_time_old_counter)){
					puts("Fail! advance (or associated checks) isn't working");
	}

	rewind(random_calendar, YEAR);

	if(parseDateTime(random_calendar) != date_time_old_counter) {
			puts("Fail! rewind isn't working.");
	}

	return 0;
}
