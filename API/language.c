/* OpenWorld 1.0 
 * language.c  
 * created 2019-05-10 by Blake Cooper
 */

#include <stdlib.h>
#include "global.h"
#include "language.h"

char *getSyllable(){
	//Establish the possible vowel/nucleii for syllables
	char vowels[] = {"a","e","i","o","u"};
	char consonants[] = {
		"b","c","d","f","g","h","j","k",
		"l","m","n","p","q","r","s","t",
		"v","w","x","y","z"
	};

	//determine how many characters in onset and coda
	int onset_nucleus_coda_length[3];

	for (int i = 0; i < 3; i++) {
		onset_nucleus_coda_length[i] = (rand() % 3);
		
		//Nucleus must be present!
		if (i == 1 && onset_nucleus_coda_length[1] < 1) {
			onset_nucleus_coda_length[1] = 1;
		}
	}

	int chars_in_syllable = 
		onset_nucleus_coda_length[0] +
		onset_nucleus_coda_length[1] +
		onset_nucleus_coda_length[2];

	char *syllable = malloc(sizeof(char*) * (chars_in_syllable + 1));

	int cursor = 0;

	for (cursor; cursor < chars_in_syllable; cursor++)+{
		if (cursor < onset_nucleus_coda_length[0]) {
			syllable[cursor] = consonants[rand() % 21];
		} else if (cursor > onset_nucleus_coda_length[0] && cursor < (onset_nucleus_coda_length[0] + onset_nucleus_coda_length[1])) {
			syllable[cursor] = vowels[rand() % 5];
		} else {
			syllable[cursor] = consonants[rand() % 21];
		}
	}

	syllable[cursor] = '\0';
}
