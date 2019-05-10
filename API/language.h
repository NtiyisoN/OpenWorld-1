/* Word order definitions (subject (S), object (O) and verb (V)) */
#define SOV 0
#define SVO 1
#define VSO 2
#define VOS 3
#define OVS 4
#define OSV 5
#define NO_ORDER 6

/* Default array size for initializing structs */
#define DEFAULT_ARRAY_SIZE 16

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
	char name[DEFAULT_ARRAY_SIZE];
	
	char syllables[DEFAULT_ARRAY_SIZE * 2];
	char syllables_wordinitial[DEFAULT_ARRAY_SIZE];
	char syllables_wordfinal[DEFAULT_ARRAY_SIZE];
	int max_syllables_per_word;

	int word_order;
	int spaces;

	int conjugation_person;
	int conjugation_tense;
	int conjugation_marker_goes
	char *markers_person[3];
	char *markers_tense[3];

	int formal;
	char *formal_marker;

} Language;

/* Get a word of a certain type */
char *getWord(int type);

/* Get a translation of a word */
char *getWord(char *literal);

/* Get a sentence translation */
char *getSentence(char *literal);

/* Check for mutual inteligibility */
int isMutuallyIntelligibleWith(char *other_language);
