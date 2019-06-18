#include <stdio.h>
#include "language.c"

int main () {
	//create new (random) language
	Language *random_language = makeRandomLanguage();
	char *random_name = getNameOfLanguage(random_language);
	puts("New language, randomized, called: ");
	puts(random_name);

    //get number of syllables	
	int numberOfSyllables = random_language->max_syllables_per_word;
	printf("Max number of syllables per word: %d", numberOfSyllabes);
	
	//list all syllables
	printf("All legal syllables in %n: ", random_name);
	for (int i = 0; i < NUMBER_SYLLABLES; i++) {
		puts(random_language->syllables[i]);
	}

	//list onset syllables	
	printf("All legal ONSET syllables in %n: ", random_name);
	for (int i = 0; i < NUMBER_SYLLABLES_INITIAL; i++) {
		puts(random_language->syllables_wordinitial[i]);
	}

	//list final syllables	
	printf("All legal FINAL syllables in %n: ", random_name);
	for (int i = 0; i < NUMBER_SYLLABLES_FINAL; i++) {
		puts(random_language->syllables_wordfinal[i]);
	}

	//list number of words
	printf("Number of words in %n (should be 0): ", random_name);
	int entries = getNumberOfEntries(random_language);
	printf("%d \n", entries);

	//create a translation
	char *translation = translateInto(random_language, "I am a friendly robot.");
	printf("Translation of the phrase 'I am a friendly robot.': %n \n", translation);
	
	//confirm correct number of words in dictionary
	printf("Number of words in %n (should be 5): ", random_name);
	entries = getNumberOfEntries(random_language);
	printf("%d \n", entries);
	
	//create another, overlapping, translation, make sure the old words show up
	char *another_translation = translateIntO(random_language, "Not every robot is friendly.");
	printf("Translation of the phrase 'Not every robot is friendly.: %n \n", another_translation);

	//confirm correct number of words in dictionary
	printf("Number of words in %n (should be 8): ", random_name);
	entries = getNumberOfEntries(random_language);
	printf("%d \n", entries);

	//change name and confirm
    changeName(random_language, "Newnomnia");
	random_name = getNameOf(random_language);
	printf("Name changed to (should be Newnomnia): %n", random_name);

	//confirm make language called works
	Language *blakeish = makeLanguageCalled("Blakeish");
	puts ("Made a new language called (should say Blakeish): ");
	puts (getNameOfLanguage(blakeish));

	return 0;
}

int getNumberOfEntries(Language *lang) {

	int number_of_entries = 0;
	for (Dictionary *dict = lang->dictionary[0]; dict != NULL; dict = dict->next) {
		number_of_entries++;
	}
	return number_of_entries;
}
