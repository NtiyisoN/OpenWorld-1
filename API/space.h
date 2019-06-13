/* OpenWorld 1.0 
 * by Blake Cooper
 *
 * space.h 
 * created:	2019-06-11 
 * updated:	2019-06-13 
 * 
 */

#include "global.h"
#include "creature.c"

/* Definitions: */

/* Interior/Exterior: */
#define EXTERIOR 0
#define INTERIOR 1

/* Structs: */
typedef struct site {
	bool has_name;
	char name[MAX_CHARS_IN_NAME];
	
	bool has_type;
	short type;

	bool has_climate;
	bool inherits_climate_from_parent;
	short climate;

	bool has_creator;
	Creature *creator;

	bool has_owner;
	Creature *owner;

	bool is_governed;
	Creature *governor;

	bool exterior_or_interior;

	Site neighbor[4];

	Map *location;
	Map *map;

	Language *language;
} Site;

typedef struct map {
	Site *of;
	Site *capital;
} map;

//
//functions
Site *makeSpaceFromFile(FILE filename[FILENAME_MAX_LENGTH]);

Site *makeSpaceWithContext(OpenWorld world);

/* Note: making Space randomly will generate an entire universe, world and series of locations all without owners or cultural attachment. This will work well for some general cases, but space is better made in context */

Site *makeRandomSpace();

Site *makeRandomSite();

Site *makeSiteOfType(short type);

void moveSiteTo(Site location);

/* Getters: */
char *getSiteName(const Site site);

short getSiteType(const Site site);

short getSiteClimate(const Site site);

Creature *getSiteOwner(const Site site);

Creature *getSiteGovernor(const Site site);

Site *getSiteNorthOf(const Site site);

Site *getSiteSouthOf(const Site site);

Site *getSiteWestOf(const Site site);

Site *getSiteEastOf(const Site site);

/* Setters: */
void setSiteName(Site site, char name[MAX_CHARS_IN_NAME]);

void setSiteType(Site site, short type);

void setSiteClimate(Site site, short climate);

void setSiteOwner(Site site, Creature *owner);

void setSiteGovernor(Site site, Creature *governor);
