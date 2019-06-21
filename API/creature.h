/* OpenWorld 1.0 
 * by Blake Cooper
 *
 * creature.h 
 * created:	2019-06-21 
 * updated:	2019-06-21 
 * 
 */

#include "global.h"

typedef struct creature {
	char species[MAX_CHARS_IN_NAME];
	
	bool has_proper_name;
	char *proper_name[MAX_CHARS_IN_NAME];

	bool has_description;
	char *description[MAX_CHARS_IN_DESCRIPTION];

	bool is_hostile;
	bool is_friendly;

	bool is_hungry;
	bool is_thirsty;
	bool is_angry;
	bool is_lonely;
	bool is_tired;

	int moves_on;

	int height;
	int weight;
	int capacity;

	bool has_hair;
	int hair_color;
	bool has_eyes;
	int eye_color;

	bool has_legs;
	int number_legs;
	bool has_arms;
	int number_arms;

	bool employed_by_person;
	Creature *employer;

	bool employed_by_organization;
	Organization *employer;


	/* TODO: this assumes two parents for every creature. In the future, this should be user-determined? */
	Creature parent_1;
	Creature parent_2;

	bool is_hybrid;

	bool is_sentient;
	bool is_civilized;

	bool can_speak_language;
	Language language;

	bool can_read;

	bool uses_money;

	/* TODO: still to come: inventory, levels for hunger/thirst etc./ways of tracking entites the creature is friendly/hostile toward */

} Creature;
