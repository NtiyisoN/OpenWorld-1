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

	for (int i = 0; i < NUMBER_SYLLABLES; i++) {
		new_lang->syllables[i] = getSyllable();
	}

	for (int i = 0; i < NUMBER_SYLLABLES_INITIAL; i++) {
		new_lang->syllables_wordinitial[i] = new_lang->syllables[rand() % NUMBER_SYLLABLES];
	}

	for (int i = 0; i < NUMBER_SYLLABLES_FINAL; i++) {
		new_lang->syllables_wordfinal[i] = new_lang->syllables[rand() % NUMBER_SYLLABLES];
	}

	new_lang->name = makeWord(new_lang);

	Dictionary *dictionary[HASHSIZE];
}

Language makeLanguageCalled(char *name) {
	Language new_lang = randomLanguage();
	new_lang->name = name;

	return new_lang;
}

Language loadLanguage() {
	//TODO: pending database setup
	//TODO: see below
}

void saveLanguage(Language *lang) {
	//TODO: pending database setup
	//TODO: ...actually, consider using hashtables to start from, which can then be loaded into and retrieved from the database
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

char *makeWord(Language *lang) {
	int syllables_in_word = (rand() % new_lang->max_syllables_per_word) + 1;

	char *new_word = calloc(WORD_SIZE, sizeof(char));
	int cursor_count = 0;

	for (int i = 0; i < syllables_in_word; i++) {
		if (cursor_count < WORD_SIZE) {
			new_word = getSyllable();
			while (*new_word != '\0') {
				new_word++;
				cursor_count++;
				if (cursor_count == WORD_SIZE) {
					break;
				}
			}
		}
	}

	return new_word;
}

int isMutuallyIntelligibleWith(char *other_language) {
	//TODO: Figure out how to calculate this
}

char *getTranslation(Language *lang, char *literal) {
	//TODO: Allow for looking up words to see if they already exist (ie., load literal word into fixed space, use it for dictionary lookup
	char *translation;
	int non_whitespace = 0;

	char *cursor_literal = literal;
	char *cursor_translation = translation;
	
	for (cursor; cursor != '\0'; cursor++) {
		if (non_whitespace && *cursor = ' ') {
			cursor_translation = makeWord(lang);
			
			while (*cursor_translation != '\0') {
				cursor_translation++;
			}
			
			if (lang->spaces) {
				*cursor_translation = ' ';
				cursor_translation++;
			}
		} else {
			non_whitespace = 1;
		}
	}

	return translation;
}

int changeName(Language *lang, char *new_name) {
	int count = 0;
	while (*new_name != '\0') {
		count++;
	}

	if (count > WORD_SIZE) {
		fprintf(stderr, "%s", "Suggested name is too long! Name must be under %d characters", WORD_SIZE);
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
