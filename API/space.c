/* OpenWorld 1.0 
 * by Blake Cooper
 *
 * space.c 
 * created:	2019-06-12 
 * updated:	2019-06-12 
 * 
 */

#include "space.c"
#include "language.c"

Site *makeSpaceFromFile(FILE filename[FILENAME_MAX_LENGTH]) {
	//TODO
	return malloc(sizeof(Site));
}

Site *makeSpaceFromContext(World world) {
	//TODO: pending API, world objects
	return malloc(sizeof(Site));
}

Site *makeRandomSpace() {
	Space *space = calloc(1, sizeof(Space));

	Language lang = makeRandomLanguage();

	space->has_name = TRUE;
	space->name = makeWord(lang);

	space->has_type = TRUE;
	space->type = 0;
	
	space->map = makeMap(space);

	//map galaxies:
	int i = GALAXIES_IN_UNIVERSE;
	
	while (i > 0) {
		
	}
	
	//hardcoded first galaxy
	//recursive function that defines the map locations by picking a random number between 0 and 3 and fills in those locations (then those locations' locations etc.)
	//connect farthest reaches from capital in every direction to the opposite side	
	
	//for each galaxy, map systems
	//for each system, map planets and anomalies
	//for each planet, create regions and (proportionately) country
	//for each country, create sites
	//for each site, create structures
	//for each structure, create rooms

	return space;

}

Map *makeMap(Site *site) {
	Map *map = calloc(1, sizeof(Map));
	map->of = site;
	return map;
}

void fillSpace(Map *map, int sites_to_build) {
	//TODO: finish this!	
	int maptype = map->of_site->type;
	int total_sites;
	Site *capital = calloc(1, sizeof(Site));

	if (maptype == UNIVERSE) {
		total_sites = GALAXIES_IN_UNIVERSE;
		capital->type = GALAXY;
		capital->map = makeMap(capital);

		fillSpace(capital);
	} else if (maptype == GALAXY) {
		total_sites = SYSTEMS_IN_GALAXY;
	} else if (maptype == SYSTEM) {
		total_sites = PLANETS_PER_SYSTEM;
	} else if (maptype == PLANET) {
		total_sites = REGIONS_PER_PLANET;
	} else if (maptype == REGION) {
		total_sites = COUNTRIES_PER_REGION;
	} else if (maptype == COUNTRY) {
		total_sites = SETTLEMENTS_PER_COUNTRY;
	} else if (maptype == SETTLEMENT) {
		total_sites = STRUCTURES_PER_SETTLEMENT;
	} else if (maptype == STRUCTURE) {
		total_sites = ROOMS_PER_STRUCTURE;
	} else {
		total_sites = DEFAULT_NUMBER_SITES_ON_GENERIC_MAP;
	}

	while (sites_to_build > 0) {
		if (sites_to_build > 4) {
		} else {
		}
	}
}	
