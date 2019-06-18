/* OpenWorld 1.0 
 * by Blake Cooper
 *
 * language.c 
 * created:	2019-05-10 
 * updated:	2019-06-05 
 * 
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

Language *makeRandomLanguage() {
	Language *new_lang = malloc(sizeof(Language));

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

	return new_lang;
}

Language *makeLanguageCalled(char *name) {
	Language *new_lang = makeRandomLanguage();
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

	char *new_word = calloc(MAX_CHARS_IN_NAME, sizeof(char));
	int cursor_count = 0;

	for (int i = 0; i < syllables_in_word; i++) {
		if (cursor_count < MAX_CHARS_IN_NAME) {
			new_word = getSyllable();
			while (*new_word != '\0') {
				new_word++;
				cursor_count++;
				if (cursor_count == MAX_CHARS_IN_NAME) {
					break;
				}
			}
		}
	}

	return new_word;
}

char *getNameOfLanguage(Language *lang) {
	return lang->name;
}

int isMutuallyIntelligibleWith(char *other_language) {
	//TODO: Figure out how to calculate this
}

char *translateInto(Language *lang, char *source) {
	//TODO: Allow for looking up words to see if they already exist (ie., load source word into fixed space, use it for dictionary lookup
	//TODO: Strip punctuation, ignore case (might need pareser lib)
	char *translation;
	int non_whitespace = 0;

	char *cursor_source = source;
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
