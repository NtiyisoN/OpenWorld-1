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

	new_lang->word_order = rand() % 7;

	int syllables_in_name = (rand() % new_lang->max_syllables_per_word) + 1;

	char *name_cursor = new_lang->name;
	int cursor_count = 0;

	for (int i = 0; i < syllables_in_name; i++) {
		if (cursor_count < NAME_SIZE) {
			name_cursor = getSyllable();
			while (*name_cursor != '\0') {
				name_cursor++;
				cursor_count++;
				if (cursor_count == NAME_SIZE) {
					break;
				}
			}
		}
	}
}

Language makeLanguageCalled(char *name) {
	Language new_lang = randomLanguage();
	new_lang->name = name;

	return new_lang;
}

Language loadLanguage() {
	//TODO: pending database setup
}

void saveLanguage(Language *lang) {
	//TODO: pending database setup
}

void freeLanguage(Language *lang) {
	free(lang);
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

int isMutuallyIntelligibleWith(char *other_language) {
	//TODO: Figure out how to calculate this
}

char *getWordOfType(int type) {
	//TODO: Figure out how to store dictionary 
}

char *getTranslation(char *literal) {
	//TODO: Figure out dictionary issue
}

int changeName(Language *lang, char *new_name) {
	int count = 0;
	while (*new_name != '\0') {
		count++;
	}

	if (count > NAME_SIZE) {
		fprintf(stderr, "%s", "Suggested name is too long! Name must be under %d characters", NAME_SIZE);
		return -1;
	} else {
		lang->name = new_name;
		return 0;
	}
}

int changeMaxSyllablesPerWord(Language *lang, unsigned int syllables) {
	if (syllables == 0) {
		fprintf(stderr, "%s", "A language cannot have zero syllables!");
		return -1;
	} else {
		lang->max_syllables_per_word = syllables;
		return 0;
	}
}

int changeSpacesInSentences(Language *lang, unsigned int spaces) {
	if (spaces > 1) {
		fprintf(stderr, "%s", "A language can either have spaces (1) or not (0).");
		return -1;
	} else {
		lang->spaces = spaces;
		return 0;
	}
}

int changeConjugationPerson(Language *lang, unsigned int person_conjugation) {
	if (person_conjugation > 1) {
		fprintf(stderr, "%s", "A language can either conjugate for person (1) or not (0).");
		return -1;
	} else {
		lang->conjugation_person = person_conjugation;
		return 0;
	}
}

int changeConjugationTense(Language *lang, unsigned int tense_conjugation) {
	if (tense_conjugation > 1) {
		fprintf(stderr, "%s", "A language can either conjugate for tense (1) or not (0).");
		return -1;
	} else {
		lang->conjugation_tense = tense_conjugation;
		return 0;
	}
}

int changeWhereConjugationMarkerGoes(Language *lang, unsigned int where_conjugation_marker_goes)
	if (where_conjugation_marker_goes > 1) {
		fprintf(stderr, "%s", "A language can either put the conjugation marker at the beginning (0) or end (1) of a word.");
		return -1;
	} else {
		lang->conjugatiion_marker_goes = where_conjugation_marker_goes;
		return 0;
	}
}

int changeHasFormalRegister(Language *lang, unsigned int has_formal_register)
	if (has_formal_register > 1) {
		fprintf(stderr, "%s", "A language either has a formal register (1) or not (0).");
		return -1;
	} else {
		lang->formal = has_formal_register;
		return 0;
	}
}
