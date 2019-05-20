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
	
	char syllables[NUMBER_SYLLABLES];
	char syllables_wordinitial[NUMBER_SYLLABLES_INITIAL];
	char syllables_wordfinal[NUMBER_SYLLABLES_FINAL];
	int max_syllables_per_word;

	int word_order;
	int spaces;

	int conjugation_person;
	int conjugation_tense;
	int conjugation_marker_goes;
	char *markers_person[3];
	char *markers_tense[3];

	int formal;
	char *formal_marker;

} Language;

/* Create new, completely random language */
Language randomLanguage();

/* Create new language with a specific name */
Language makeLanguageCalled(char *name);

/* Create new language from JSON(?) file */
Language makeLanguageFromFile();

/* Method for producing (random) syllables */
char *getSyllable();

/* Check for mutual inteligibility */
int isMutuallyIntelligibleWith(char *other_language);


/* GETTERS: */
/* Get a word of a certain type */
char *getWord(int type);

/* Get a translation of a word or phrase*/
char *getTranslation(char *literal);


/* SETTERS: */
int changeName(Language language, char *new_name);

int changeMaxSyllablesPerWord(Language language, int syllables);

int changeSpacesInSentences(Language language, int spaces);

int changeConjugationPerson(Language language, int person_conjugation);

int changeConjugationTense(Language language, int tense_conjugation);

int changeWhereConjugationMarkerGoes(Language language, int where_conjugation_marker_goes);

int changeHasFormalRegister(Language language, int has_formal_register);
