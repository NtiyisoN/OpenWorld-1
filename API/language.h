/* OpenWorld 1.0 
 * language.h  
 * created 2019-05-10 by Blake Cooper
 */

/* Word order definitions (subject (S), object (O) and verb (V)) */
#define SOV 0
#define SVO 1
#define VSO 2
#define VOS 3
#define OVS 4
#define OSV 5
#define NO_ORDER 6

/* Default array size for language name, number of syllables, number of word initial and final syllables (any elements not used will be 0) */
#define NAME_SIZE 16
#define NUMBER_SYLLABLES 32
#define NUMBER_SYLLABLES_INITIAL 12
#define NUMBER_SYLLABLES_FINAL 12

/* Using a boolean to determine whether markers go before or after words */
#define BEFORE 0
#define AFTER 1

/* Define different words types */
#define NOUN 0
#define VERB 1
#define ADJECTIVE 2
#define ADVERB 3
#define CONJUNCTION 4
#define PREPOSITION 5

typedef struct language {
	char name[NAME_SIZE];
	
	/* How long is the longest word, in terms of syllables? */
	int max_syllables_per_word;
	
	/* Store all the possible syllables that can occur in the beginning, midle and end of words */
	char *syllables[NUMBER_SYLLABLES];
	char *syllables_wordinitial[NUMBER_SYLLABLES_INITIAL];
	char *syllables_wordfinal[NUMBER_SYLLABLES_FINAL];

	/* Sentence-level grammar: what order do words come in?*/
	int word_order;

	/* Grammatical markers for person, tense etc. (boolean)*/
	int spaces_between_markers;
	int conjugation_person;
	int conjugation_tense;
	int declension;
	int plural;
	int formal;

	/* Should grammatical markers go before (0) or after (1) the word they modify? */
	int conjugation_marker_goes;
	int declension_marker_goes;
	int formal_marker_goes;

	/* Person markers (0 = first, 1 = second, 3 = third) */
	/* Tense markers (0 = past, 1 = present, 2 = future) */
	/* Declension markers (0 = subject, 1 = object) */
	char *markers_person[3];
	char *markers_tense[3];
	char *markers_declension[2];
	char *plural_marker;
	char *formal_marker;

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
/* Get a word of a certain type */
char *getWordOfType(int type);

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
