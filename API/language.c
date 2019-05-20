/* OpenWorld 1.0 
 * language.c  
 * created 2019-05-10 by Blake Cooper
 */

#include <stdlib.h>
#include "global.h"
#include "language.h"

static char *vowels[] = {"a","e","i","o","u"};
static char *consonants[] = {
		"b","c","d","f","g","h","j","k",
		"l","m","n","p","q","r","s","t",
		"v","w","x","y","z"
	};

Language randomLanguage() {
	Language new_lang = malloc(sizeof(Language));

	new_lang->max_syllables_per_word = rand() % 5 + 5;

	new_lang->spaces_between_markers = rand() % 2;
	new_lang->conjugation_person = rand() % 2;
	new_lang->conjugation_tense = rand() % 2;
	new_lang->declension = rand() % 2;
	new_lang->plural = rand() % 2;
	new_lang->formal = rand() % 2;

	new_lang->conjugation_marker_goes = rand() % 2;
	new_lang->declension_marker_goes = rand() % 2;
	new_lang->formal_marker_goes = rand() % 2;

	new_lang->markers_person[0] = getMarker();
	new_lang->markers_person[1] = getMarker();
	new_lang->markers_person[2] = getMarker();

	new_lang->markers_tense[0] = getMarker();
	new_lang->markers_tense[1] = getMarker();
	new_lang->markers_tense[2] = getMarker();

	new_lang->markers_declension[0] = getMarker();
	new_lang->markers_declension[1] = getMarker();

	new_lang->plural_marker = getMarker();
	new_lang->formal_marker = getMarker();

	for (int i = 0; i < NUMBER_SYLLABLES; i++) {
		new_lang->syllables[i] = getSyllable();
	}

	for (int i = 0; i < NUMBER_SYLLABLES_INITIAL; i++) {
		new_lang->syllables_wordinitial[i] = new_lang->syllables[rand() % NUMBER_SYLLABLES];
	}

	for (int i = 0; i < NUMBER_SYLLABLES_FINAL; i++) {
		new_lang->syllables_wordfinal[i] = new_lang->syllables[rand() % NUMBER_SYLLABLES];
	}

	//TODO: initialize name, word order
}

char *getSyllable() {
	//determine how many characters in onset and coda
	int onset_nucleus_coda_length[3];

	for (int i = 0; i < 3; i++) {
		onset_nucleus_coda_length[i] = (rand() % 2);
		
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
	
	while (cursor < onset_nucleus_coda_length[0]) {
		syllable[cursor] = *consonants[rand() % 21];
		cursor++;
	}

	for (int i = 0; i < onset_nucleus_coda_length[1]; i++) {
		syllable[cursor] = *vowels[rand() % 5];
		cursor++;
	}

	while (cursor < chars_in_syllable) {
		syllable[cursor] = *consonants[rand() % 21];
		cursor++;
	}

	syllable[cursor] = '\0';

	return syllable;
}

char *getMarker() {

	int onset_nucleus_length[2];

	for (int i = 0; i < 2; i++) {
		onset_nucleus_length[i] = rand() % 2;
	}

	int chars_in_marker = 
		onset_nucleus_length[0] +
		onset_nucleus_length[1];

	char *marker = malloc(sizeof(char*) * (chars_in_marker + 1));

	int cursor = 0;

	while (cursor < onset_nucleus_length[0]) {
		marker[cursor] = *consonants[rand() % 21];
		cursor++;
	}

	while (cursor < chars_in_marker) {
		marker[cursor] = *vowels[rand() % 5];
		cursor++;
	}

	marker[cursor] = '\0';

	return marker;
}
