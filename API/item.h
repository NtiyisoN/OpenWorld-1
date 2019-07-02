/* OpenWorld 1.0 
 * by Blake Cooper
 *
 * item.h 
 * created:	2019-07-01
 * updated:	2019-07-02 
 * 
 */

#include "global.h"

typedef struct item {
	bool has_type;
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

/* GETTERS: */

Item *getItemTypeOf(Item *item);

Char *getProperNameOf(Item *item);

Creature *getOwnerOf(Item *item);

Organization *getOwnerOf(Item *item);

/* SETTERS: */

void setItemTypeOf(Item *item);

void setProperNameOf(Item *item);

void setOwnerOf(Item *item, Creature *owner);

void setOwnerOf(Item *item, Organization *owner);
