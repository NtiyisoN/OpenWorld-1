#include <stdio.h>
#include "language.c"

int main () {

	srand(time(NULL));

	for (int i = 0; i < 100; i++) {
		char *syllable = getSyllable();
			puts (syllable);
	}

	return 0;
}
