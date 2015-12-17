#include <stdlib.h>
#include "util.h"
#include "varArray.h"

varArrayPtr varArrayInit(int len, int* vals) {
	int i;
	struct varArray* ptr;

	utilLog("--- varArrayInit() ---");

	utilLog("allocating varArray");
	ptr = malloc(sizeof(struct varArray));
	if (ptr == NULL) {
		utilError("unable to allocate varArray");
	}

	utilLog("initializing varArray");
	ptr->len = len;
	ptr->vals = malloc(sizeof(int) * len);
	if (ptr->vals == NULL) {
		utilError("unable to allocate varArray");
	}

	for (i = 0 ; i < len ; i++) {
		(ptr->vals)[i] = vals[i];
	}

	return ptr;
}
