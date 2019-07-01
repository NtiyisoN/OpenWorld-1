/* OpenWorld 1.0 
 * by Blake Cooper
 *
 * organization.h 
 * created:	2019-07-01 
 * updated:	2019-07-01 
 * 
 */

#include "global.h"

typedef struct organization {
	int type;

	Organization[MAX_ASSOCIATIONS] associated_organizations;

	Language *associated_language;
} Organization;

