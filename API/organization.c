/* OpenWorld 1.0 
 * by Blake Cooper
 *
 * organization.c 
 * created:	2019-07-11 
 * updated:	2019-07-11 
 * 
 */

#include "organization.h"

Organization *makeRandomOrganization() {
	Organization *org = calloc(1, sizeof(Organization));
	
	org->associated_language = makeRandomLanguage(); 

	org->name = makeRandomWord(org->associated_language);

	org->type = rand() % NUMBER_OF_ORGANIZATION_TYPES;

	return org;
}

Organization *makeRandomOrganizationInContext(World *world) {
	//TODO: incorporate with World object/API
	
	Organization *org = makeRandomOrganization();

	return org;
}

Organization *makeOrganizationCalled(char *name) {
	Organization *org = makeRandomOrganization();

	setNameOf(org, name);

	return org;
}

Organization *makeOrganizationOfType(int type) {
	Organization *org = makeRandomOrganization();

	setOrganizationType(org, type);

	return org;
}

Organization *loadOrganizationFromFile(char *filename) {
	//TODO
	Organization *org = makeRandomOrganization();

	return org;
}
	
Organization *makeOrganizationWithAssociatedOrganization(Organization *associated_org) {
	Organization *org = makeRandomOrganization();

	int i = 0;
	for (i; org->associated_organizations[i] != NULL; i++) {
	}

	org->associated_organizations[i] = associated_org;

	setAssociatedLanguageOf(org, associated_org->associated_language);

	setNameOf(org, makeRandomWord(org->associated_language);

	return org;
}

/* GETTERS: */

char *getNameOf(Organization *organization) {
	return organization->name;
}

int getTypeOfOrganizationOf(Organization *organization) {
	return organization->type;
}

Language *getAssociatedLanguageOf(Organization *organization) {
	return organization->associated_language;
}

/* SETTERS: */

void setNameOf(Organization *organization, char *name)
	organization->name = name;
}

void setTypeOfOrganizationOf(Organization *organization, int type) {
	organization->type = type;
}

void setAssociatedLangaugeOf(Organization *organization, Language *language) {
	organization->associated_language = language;
}
