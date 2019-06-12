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

	space->language = makeRandomLanguage();

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

void fillSpace(Map *map) {
	int maptype = map->of_site->type;
	int total_sites;
	Site *capital = calloc(1, sizeof(Site));

	if (maptype == UNIVERSE) {
		total_sites = GALAXIES_IN_UNIVERSE;
		//capital here (and in other conditionals) must be FULLY fleshed out!)
		capital->type = GALAXY;
		capital->map = makeMap(capital);
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
	
	Site sitevisitor = capital;
	
	fillSpace(capital, total_sites);
}

void fillSpace(Site sitevisitor, int sites_remaining) {
	
	if (sites_remaining > 0) {
		if (sitevisitor != NULL) {
			int neighbors = (rand() % 4) + 1;
			for (int i = 0; i < neighbors; i++) {
				sitevisitor->neighbor[i] = calloc(1, sizeof(Site));
				memcpy (sitevisitor->neighbor[i], sitevisitor, sizeof(Site));
				sitevisitor->neighbor[i]->name = makeWord(sitevisitor->language);
				fillSpace(sitevisitor->neighbor[i], (sites_remaining / neighbors));
			}

		}
	} else {
	}
}	
