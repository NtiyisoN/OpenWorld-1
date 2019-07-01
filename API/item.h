/* OpenWorld 1.0 
 * by Blake Cooper
 *
 * item.h 
 * created:	2019-07-01
 * updated:	2019-06-01 
 * 
 */

#include "global.h"

typedef struct item {
	char *type;
	Item type_of;
	
	bool is_unique;
	bool has_proper_name;
	char *name;

	bool is_owned_by_creature;
	Creature owner;

	bool is_owned_by_organization;
	Organization owner;

	bool can_be_consumed;
	bool can_be_wielded;
	bool can_be_worn;
	bool can_be_carried;
	
	bool can_be_powered;
	bool is_powered;

	bool is_mobile;
	bool can_carry;

	bool can_be_destroyed;
} Item;
