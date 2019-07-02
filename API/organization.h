/* OpenWorld 1.0 
 * by Blake Cooper
 *
 * organization.h 
 * created:	2019-07-01 
 * updated:	2019-07-02 
 * 
 */

#include "global.h"

typedef struct organization {

	char[MAX_CHARS_IN_NAME];
	int type;

	Organization[MAX_ASSOCIATIONS] associated_organizations;

	Language *associated_language;
} Organization;

/* GETTERS: */

char *getNameOf(Organization *organization);

int getTypeOfOrganizationOf(Organization *organization);

Language *getAssociatedLanguageOf(Organization *organization);

/* SETTERS: */

void setNameOf(Organization *organization, char *name);

void setTypeOfOrganizationOf(Organization *organization, int type);

void setAssociatedLangaugeOf(Organization *organization, Language *language);
