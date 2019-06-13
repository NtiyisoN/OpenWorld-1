/* OpenWorld 1.0 
 * by Blake Cooper
 *
 * space.c 
 * created:	2019-06-12 
 * updated:	2019-06-13 
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

	defineMap(space->map);

	return space;

}

Map *makeMap(Site *site) {
	Map *map = calloc(1, sizeof(Map));
	map->of = site;
	return map;
}

void defineMap(Map *map) {
	short maptype = map->of_site->type;
	Language *lang = map->of_site->language;
	int total_sites;
	Site *capital = makeSiteOfType(maptype)

	Site sitevisitor = capital;
	fillSpace(capital, total_sites);
}

void fillMap(Site sitevisitor, int sites_remaining) {
	//TODO: some types of maps are spherical... connecting north to south, east to west and vice v. (under the right circumstances) should happen here
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
		return;
	}
}

Site *makeRandomSite() {
	Site *site = makeSiteOfType(rand() % 9;

	return site;
}

Site *makeSiteOfType(short type) {
	
	Site *capital;

	if (type == UNIVERSE) {
		capital = makeRandomSpace();
	} else {
		capital = calloc(1, sizeof(Site));

		capital->location = map;
		capital->language = lang;

		if (maptype == UNIVERSE) {
			total_sites = GALAXIES_IN_UNIVERSE;
			
			capital->has_name = TRUE;
			capital->name = makeWord(lang);
	
			capital->has_type = TRUE;
			capital->type = GALAXY;

		} else if (maptype == GALAXY) {
			total_sites = SYSTEMS_IN_GALAXY;
		
			capital->has_name = TRUE;
			capital->name = makeWord(lang);

			capital->has_type = TRUE;
			capital->type = SYSTEM;

		} else if (maptype == SYSTEM) {
			total_sites = PLANETS_PER_SYSTEM;
		
			capital->has_name = TRUE;
			capital->name = makeWord(lang);
	
			capital->has_type = TRUE;
			capital->type = PLANET;
	
			capital->has_climate = TRUE;
			capital->climate = (rand() % 9);
	
		} else if (maptype == PLANET) {
			total_sites = REGIONS_PER_PLANET;
			
			capital->has_name = TRUE;
			capital->name = makeWord(lang);
	
			capital->has_type = TRUE;
			capital->type = REGION;
	
			capital->has_climate = TRUE;
			int chance = rand() % 10;
			if (chance < 7) {
				capital->climate = map->of_site->climate;
			} else {
				capital->climate = (rand() % 9);
			}
	
		} else if (maptype == REGION) {
			total_sites = COUNTRIES_PER_REGION;
		
			capital->has_name = TRUE;
			capital->name = makeWord(lang);
	
			capital->has_type = TRUE;
			capital->type = COUNTRY;
	
			capital->has_climate = TRUE;
			capital->inherits_climate_from_parent = TRUE;
	
		} else if (maptype == COUNTRY) {
			total_sites = SETTLEMENTS_PER_COUNTRY;
		
			capital->has_name = TRUE;
			capital->name = makeWord(lang);
	
			capital->has_type = TRUE;
			capital->type = SETTLEMENT;
	
			capital->has_climate = TRUE;
			capital->inherits_climate_from_parent = TRUE;
	
		} else if (maptype == SETTLEMENT) {
			total_sites = STRUCTURES_PER_SETTLEMENT;
		
			//TODO: types of structures? Instead of specific names?
			capital->has_type = TRUE;
			capital->type = STRUCTURE;
	
			capital->exterior_or_interior = INTERIOR;
	
		} else if (maptype == STRUCTURE) {
			total_sites = ROOMS_PER_STRUCTURE;
	
			capital->has_type = TRUE;
			capital->type = ROOM;
	
			capital->exterior_or_interior = INTERIOR;
		} else {
			total_sites = DEFAULT_NUMBER_SITES_ON_GENERIC_MAP;
		
		}
		
		map->capital = capital;

		if (maptype < 8) {
			capital->map = makeMap(capital);
			defineMap(capital->map);
		}
	}

	return capital;
}

void moveSiteTo(Site *site, Site *destination) {
	Site *sitevisitor = destination->map->capital;

	while (sitevisitor != NULL) {
		int i = 0;
		for (i; i < 4; i++) {
			if (sitevisitor->neighbor[i] == NULL) {
				sitevisitor = sitevisitor->neighbor[i];
				break;
			}
		}

		sitevisitor = sitevisitor->neighbor[i];
	}

	*sitevisitor = *site;
}

/* Getters: */
char *getSiteName(const Site site) {
	if (site->has_name) {
		return site->name;
	} else {
		return '\0';
	}
}

short getSiteType(const Site site) {
	if (site->has_type) {
		return site->type;
	} else {
		return -1;
	}
}

short getSiteClimate(const Site site) {
	if (site->has_climate) {
		return site->climate;
	} else {
		return -1;
	}
}

Creature *getSiteOwner(const Site site) {
	if (site->has_owner) {
		return site->owner;
	} else {
		return NULL;
	}
}

Creature *getSiteGovernor(const Site site) {
	if (site->has_governor) {
		return site->governor;
	} else {
		return NULL;
	}
}

Site *getSiteNorthOf(const Site site) {
	if (location->neighbor[NORTH] != NULL) {
		return location->neighbor[NORTH];
	} else {
		return location;
	}

Site *getSiteSouthOf(const Site site) {
	if (location->neighbor[SOUTH] != NULL) {
		return location->neighbor[SOUTH];
	} else {
		return location;
	}

Site *getSiteWestOf(const Site site) {
	if (location->neighbor[WEST] != NULL) {
		return location->neighbor[WEST];
	} else {
		return location;
	}

Site *getSiteEastOf(const Site site) {
	if (location->neighbor[EAST] != NULL) {
		return location->neighbor[EAST];
	} else {
		return location;
	}

/* Setters: */
void setSiteName(Site site, char name[MAX_CHARS_IN_NAME]) {
	site->name = name;
	site->has_name = TRUE;
}

void setSiteType(Site site, short type) {
	site->type = type;
	site->has_type = TRUE;
}

void setSiteClimate(Site site, short climate) {
	site->climate = climate;
	site->has_climate = TRUE;
}

void setSiteOwner(Site site, Creature *owner) {
	site->owner = owner;
	site->has_owner = TRUE;
}

void setSiteGovernor(Site site, Creature *governor) {
	site->governor = governor;
	site->has_governor = TRUE;
}
