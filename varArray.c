#include <stdlib.h>
#include "util.h"
#include "varArray.h"

struct varArray* varArrayInit(int size, int* value) {
	int i;
	struct varArray* ptr;

	utilLog("--- varArrayInit() ---");

	utilLog("allocating varArray");
	ptr = malloc(sizeof(struct varArray));
	if (ptr == NULL) {
		utilError("unable to allocate varArray");
	}

	utilLog("initializing varArray");
	ptr->size = size;
	ptr->value = malloc(sizeof(int) * size);
	if (ptr->value == NULL) {
		utilError("unable to allocate varArray");
	}

	for (i = 0 ; i < size ; i++) {
		(ptr->value)[i] = value[i];
	}

	return ptr;
}
