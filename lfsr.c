#include <stdlib.h>
#include <stdio.h>
#include "lfsr.h"
#include "util.h"
#include "varArray.h"

lfsrPtr lfsrInit(int len, int fb, int ff, int l, int r, int* vals) {
	lfsrPtr ptr;
	struct pair p;

	p.left = l;
	p.right = r;

	utilTrace("--- lfsrInit() ---");

	/* Allocate shift register */
	utilTrace("allocating shift register");
	ptr = malloc(sizeof(struct lfsr));
	if (ptr == NULL) {
		utilError("unable to allocate shift register");
	}

	/* Initialize shift register */
	utilTrace("allocating shift register contents");
	ptr->feedback = fb;
	ptr->feedforward = ff;
	ptr->and = p;
	ptr->bits = varArrayInit(len, vals);

	return ptr;
}

int lfsrOutput(lfsrPtr lfsr) {
	int out;
	char* msg;

	utilTrace("--- lfsrOutput() ---");

	/* The output bit is (feedforward + (left * right) + last) modulus 2 */
	out = 0;
	out += lfsr->bits->vals[lfsr->feedforward];
	out += lfsr->bits->vals[(lfsr->and).left] * lfsr->bits->vals[(lfsr->and).right];
	out += lfsr->bits->vals[lfsr->bits->len - 1];
	out = out % 2;

	/* Log result */
	msg = malloc(MSG_BUFF * sizeof(char));
	if (msg != NULL) {
		sprintf(msg, "value: %i", out);
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

	utilTrace("--- lfsrInit() ---");

	/* The new bit is (feedback + input) modulus 2 */
	new = (lfsr->bits->vals[lfsr->feedback] + input) % 2;

	/* Shift the bits through the register */
	for (i = 1 ; i < lfsr->bits->len ; i++) {
		lfsr->bits->vals[i] = lfsr->bits->vals[i - 1];
	}

	/* Insert the new bit */
	lfsr->bits->vals[0] = new;

	/* Log result */
	msg = malloc(MSG_BUFF * sizeof(char));
	if (msg != NULL) {
		sprintf(msg, "value: %i", new);
		utilTrace(msg);
	} else {
		utilWarning("unable to allocate message");
	}

	return;
}
