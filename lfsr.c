#include <stdlib.h>
#include <stdio.h>
#include "lfsr.h"
#include "util.h"
#include "varArray.h"

lfsrPtr lfsrInit(int len, int fb, int ff, int l, int r, int* vals) {
	lfsrPtr ptr;
	struct pair p;

	utilTrace("--- lfsrInit() ---");

	/* Allocate shift register */
	utilTrace("allocating shift register");
	ptr = malloc(sizeof(struct lfsr));
	if (ptr == NULL) {
		utilError("unable to allocate shift register");
	}

	/* Initialize shift register */
	/* Note that the arguments are for a 1-indexed array, and so we subtract
	 * 1 from the provided values to transition back into 0-indexed arrays
	 */
	utilTrace("allocating shift register contents");
	p.left = l - 1;
	p.right = r - 1;
	ptr->feedback = fb - 1;
	ptr->feedforward = ff - 1;
	ptr->and = p;
	ptr->bits = varArrayInit(len, vals);

	return ptr;
}

int lfsrOutput(lfsrPtr lfsr) {
	int out;
	char* msg;

	utilTrace("--- lfsrOutput() ---");

	/* The output bit is (feedforward + (left * right) + last) modulus 2 */
	out = lfsr->bits->vals[lfsr->feedforward];
	out += (lfsr->bits->vals[(lfsr->and).left]
		* lfsr->bits->vals[(lfsr->and).right]) % 2;
	out += lfsr->bits->vals[lfsr->bits->len - 1];
	out = out % 2;

	/* Log result */
	msg = malloc(MSG_BUFF * sizeof(char));
	if (msg != NULL) {
		sprintf(msg, "output value: %i", out);
		utilTrace(msg);
	} else {
		utilWarning("unable to allocate message");
	}

	return out;
}

void lfsrShift(lfsrPtr lfsr, int input) {
	int i;
	int new;
	char* msg;
	int* vals;

	utilTrace("--- lfsrInit() ---");

	/* The new bit is (feedback + input) modulus 2 */
	new = (lfsr->bits->vals[lfsr->feedback] + input) % 2;

	vals = malloc(lfsr->bits->len * sizeof(int));
	if (vals == NULL) {
		utilError("unable to allocate internal array");
	}

	for (i = 1; i < lfsr->bits->len; i++) {
		vals[i] = lfsr->bits->vals[i - 1];
	}
	vals[0] = new;

	lfsr->bits = varArrayInit(lfsr->bits->len, vals);

	/* Log result */
	msg = malloc(MSG_BUFF * sizeof(char));
	if (msg != NULL) {
		sprintf(msg, "new value: %i", new);
		utilTrace(msg);
	} else {
		utilWarning("unable to allocate message");
	}

	return;
}
