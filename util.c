#include <stdlib.h>
#include <stdio.h>
#include "util.h"

#ifdef DEBUG
#define DEBUG 1
#else
#define DEBUG 0
#endif

#ifdef TRACE
#define TRACE 1
#else
#define TRACE 0
#endif

void utilError(char* msg) {
	/* Print error message and exit */
	fprintf(stderr, "ERROR: %s\n", msg);
	fprintf(stderr, "exiting...\n");

	exit(1);
}

void utilWarning(char* msg) {
	/* Print warning message */
	if (DEBUG || TRACE) {
		fprintf(stderr, "WARN: %s\n", msg);
	}

	return;
}

void utilLog(char* msg) {
	/* Print log message */
	if (DEBUG || TRACE) {
		fprintf(stderr, "LOG: %s\n", msg);
	}

	return;
}

void utilTrace(char* msg) {
	/* Print trace message */
	if (TRACE) {
		fprintf(stderr, "TRACE: %s\n", msg);
	}

	return;
}
