/* OpenWorld 1.0 
 * by Blake Cooper
 *
 * organization.h 
 * created:	2019-07-01 
 * updated:	2019-07-11 
 * 
 */

#include "global.h"
#include "language.c"

typedef struct organization {

	char[MAX_CHARS_IN_NAME] name;
	int type;

	Organization[MAX_ASSOCIATIONS] associated_organizations;

	Language *associated_language;
} Organization;

/* CONSTRUCTORS: */

Organization *makeRandomOrganization();

Organization *makeOrganizationCalled(char *name);

Organization *makeOrganizationOfType(int type);

Organization *makeOrganizationWithAssociatedOrganization(Organization *org);

Organization *makeRandomOrganizationInContext(World *world);

Organization *loadOrganizationFromFile(char *filename);

/* GETTERS: */

char *getNameOf(Organization *organization);

int getTypeOfOrganizationOf(Organization *organization);

Language *getAssociatedLanguageOf(Organization *organization);

/* SETTERS: */

void setNameOf(Organization *organization, char *name);

void setTypeOfOrganizationOf(Organization *organization, int type);

void setAssociatedLangaugeOf(Organization *organization, Language *language);
