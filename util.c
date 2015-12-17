#include <stdlib.h>
#include <stdio.h>
#include "util.h"

void error(char* msg) {
	fprintf(stderr, "ERROR: %s\n", msg);
	fprintf(stderr, "exiting...\n");

	exit(1);
}

void warning(char* msg) {
#ifdef DEBUG
	fprintf(stderr, "ERROR: %s\n", msg);
#endif

	return;
}

void log(char* msg) {
#ifdef DEBUG
	fprintf(stderr, "LOG: %s\n", msg);
#endif

	return;
}
