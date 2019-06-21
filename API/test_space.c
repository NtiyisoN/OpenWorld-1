#include "space.c"

int main() {

	Site *blakecosmotopia = makeRandomSpace();
	setSiteName(blakecosmotopia, "blakecosmotopia");
	printf("'Let there be light!' The universe, henceforth known as %s, is born!", getSiteName(blakecosmotopia));

	return 0;
}
