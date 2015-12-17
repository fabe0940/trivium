#include <stdlib.h>
#include "util.h"
#include "varArray.h"

varArrayPtr varArrayInit(int len, int* vals) {
	int i;
	struct varArray* ptr;

	utilTrace("--- varArrayInit() ---");

	/* Allocate varArray */
	utilTrace("allocating varArray");
	ptr = malloc(sizeof(struct varArray));
	if (ptr == NULL) {
		utilError("unable to allocate varArray");
	}

	/* Allocate internal array */
	utilTrace("initializing varArray");
	ptr->len = len;
	ptr->vals = malloc(sizeof(int) * len);
	if (ptr->vals == NULL) {
		utilError("unable to allocate internal array");
	}

	/* Initialize internal array */
	for (i = 0 ; i < len ; i++) {
		(ptr->vals)[i] = vals[i];
	}

	return ptr;
}
