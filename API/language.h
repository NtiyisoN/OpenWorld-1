/* OpenWorld 1.0 
 * by Blake Cooper
 *
 * language.h 
 * created:	2019-05-10 
 * updated:	2019-05-24 
 * 
 */

#include "Dictionary.c"

/* Default array size for language name, number of syllables, number of word initial and final syllables (any elements not used will be 0) */
#define WORD_SIZE 16
#define NUMBER_SYLLABLES 32
#define NUMBER_SYLLABLES_INITIAL 12
#define NUMBER_SYLLABLES_FINAL 12

typedef struct language {
	char name[WORD_SIZE];
	
	/* How long is the longest word, in terms of syllables? */
	int max_syllables_per_word;

	/* Does the written language have spaces? */
	int spaces;

	/* Store all the possible syllables that can occur in the beginning, midle and end of words */
	char *syllables[NUMBER_SYLLABLES];
	char *syllables_wordinitial[NUMBER_SYLLABLES_INITIAL];
	char *syllables_wordfinal[NUMBER_SYLLABLES_FINAL];

	Dictionary *dictionary[HASHSIZE];

} Language;

/* Create new, completely random language */
Language randomLanguage();

/* Create new language with a specific name */
Language makeLanguageCalled(char *name);

/* Load a language from the database */
Language loadLanguage();

/* Save a language to the database */
void saveLanguage();

/* Free allocated Language structs */
void freeLanguage(Language *lang);

/* Function for producing (random) syllables */
char *getSyllable();

/* Similar to the getSyllable() function, this returns a short syllable (either a vowel or a single consonant onset with a vowel) to be used as a grammatical marker*/
char *getMarker();

/* Check for mutual inteligibility */
int isMutuallyIntelligibleWith(char *other_language);


/* GETTERS: */
/* Get a translation of a word or phrase*/
char *getTranslation(char *literal);


/* SETTERS: */
int changeName(Language *language, char *new_name);

int changeMaxSyllablesPerWord(Language *lang, unsigned int syllables);

int changeSpacesInSentences(Language *lang, unsigned int spaces);

int changeConjugationPerson(Language *lang, unsigned int person_conjugation);

int changeConjugationTense(Language *lang, unsigned int tense_conjugation);

int changeWhereConjugationMarkerGoes(Language *lang, unsigned int where_conjugation_marker_goes);

int changeHasFormalRegister(Language *lang, unsigned int has_formal_register);
