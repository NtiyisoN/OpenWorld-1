/* OpenWorld 1.0 
 * by Blake Cooper
 *
 * global.h 
 * created:	2019-05-10 
 * updated:	2019-07-11 
 * 
 * "Ever tried. Ever failed. No matter. Try again. Fail again. Fail better."
 * ~Samuel Beckett
 */

/* CUSTOMIZEABLE VARIABLES: */

/* Global: */

typedef unsigned short int bool;

#define FALSE 0
#define TRUE 1

#define MAX_CHARS_IN_DESCRIPTION 2048
#define FILENAME_MAX_LENGTH 32
#define MAX_CHARS_IN_NAME 32

#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3

/* Language: */
//TODO

/* Time: */

//How many historical eras have there been?
#define NUMBER_OF_HISTORICAL_ERAS 5

//How long do historical eras last?
#define YEARS_PER_HISTORICAL_ERA 2000

/* Space: */

/* Generation parameters: */

/* Astronomical: */

/* If you don't need to involve astronomical space in your world, consider turning this off (0)... it'll save a lot of memory! */
#define GENERATE_UNIVERSE 1

/* The numbers here are used, along with rand(), to produce sites in roughly these quantities. */
#define GALAXIES_IN_UNIVERSE 1000
#define SYSTEMS_IN_GALAXY 1000
#define PERCENT_SYSTEMS_WITH_PLANETS 10
#define PLANETS_PER_SYSTEM 16

/* Planetary: */ 
#define REGIONS_PER_PLANET 12

/* Civilized settlements: */

/* If a space is created in context of a world, civilization numbers will influence these also. */
#define COUNTRIES_PER_REGION 5
#define SETTLEMENTS_PER_COUNTRY 32
#define STRUCTURES_PER_SETTLEMENT 32
#define ROOMS_PER_STRUCTURE 4

/* This is a catch-all if, for some reason, the program doesn't know what kind of map it's making. In that case, if fills in the map with this number of sites */
#define DEFAULT_NUMBER_SITES_ON_GENERIC_MAP 5

/* Type of site: */
/* These are hierarchical, generated by default. */
#define NUMBER_OF_SITE_TYPES 9
#define UNIVERSE 0
#define GALAXY 1
#define SYSTEM 2
#define PLANET 3
#define REGION 4
#define COUNTRY 5
#define SETTLEMENT 6
#define STRUCTURE 7
#define ROOM 8

/* These are NOT hierarchical, and user-generated only: */
#define ANOMALY 9
#define SITE 10
#define CAVE 11
#define VOLCANO 12
#define ASTEROIDS 13

/* Types of biomes (program generates 9 by default): */
#define NUMBER_OF_BIOME_TYPES;
#define GRASS 0
#define SAVANA 1
#define DESERT 2
#define TUNDRA 3
#define TAIGA 4
#define FOREST 5
#define SWAMP 6
#define BEACH 7
#define OCEAN 8

/* ORGANIZATIONS: */
/* Types of organizations: */
#define NUMBER_OF_ORGANIZATION_TYPES 8
#define RELIGIOUS 0
#define POLITICAL 1
#define FACTION 2
#define GUILD 3
#define FAMILY 4
#define MILITARY 5
#define INDUSTRIAL 6
#define EDUCATIONAL 7

/* Number of associations as association can have with other associations:*/
#define MAX_ASSOCIATIONS 32
