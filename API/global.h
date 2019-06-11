/* OpenWorld 1.0 
 * by Blake Cooper
 *
 * global.h 
 * created:	2019-05-10 
 * updated:	2019-06-11 
 * 
 * "Ever tried. Ever failed. No matter. Try again. Fail again. Fail better."
 * ~Samuel Beckett
 */

/* CUSTOMIZEABLE VARIABLES: */

/* Global: */

typedef unsigned short int bool

#define FALSE 0
#define TRUE 1

#define MAX_CHARS_FOR_DESCRIPTION 2048
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

/* Type of site: */
#define UNIVERSE 0
#define GALAXY 1
#define SYSTEM 2
#define PLANET 3
#define ANOMALY 4
#define REGION 5
#define COUNTRY 6
#define SETTLEMENT 7
#define SITE 8
#define STRUCTURE 9
#define ROOM 10

/* Types of biomes: */
#define GRASS 0
#define SAVANA 1
#define DESERT 2
#define TUNDRA 3
#define TAIGA 4
#define FOREST 5
#define SWAMP 6
#define BEACH 7
#define OCEAN 8
