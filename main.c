#include <stdlib.h>
#include <stdio.h>
#include "lfsr.h"
#include "util.h"

#define A_LEN 93
#define A_FB 69
#define A_FF 66
#define A_AND_L 91
#define A_AND_R 92

#define B_LEN 84
#define B_FB 78
#define B_FF 69
#define B_AND_L 82
#define B_AND_R 83

#define C_LEN 111
#define C_FB 87
#define C_FF 66
#define C_AND_L 109
#define C_AND_R 110

#define WARMUP_CYCLES 1152

void usage(char* name);
int cycle(lfsrPtr A, lfsrPtr B, lfsrPtr C);

int main(int argc, char** argv) {
	int i;
	char* input;
	char* iv;
	char* key;
	char* msg;
	int* vals;
	lfsrPtr A;
	lfsrPtr B;
	lfsrPtr C;


	/* ARGUMENT HANDLING */
	utilLog("processing arguments");

	/* Check for necessary number of arguments */
	if (argc != 4) {
		utilWarning("invalid arguments");
		usage(argv[0]);
		exit(0);
	}

	/* Capture arguments */
	key = argv[1];
	iv = argv[2];
	input = argv[3];


	/* INITIALIZATION */

	utilLog("initializing trivium");

	utilLog("initilizing register A");

	/* Allocate value array */
	vals = malloc(A_LEN * sizeof(int));
	if (vals == NULL) {
		utilError("allocation failure");
	}

	/* The first 80 bits of A are the initilization vector */
	for (i = 0; i < 80; i++) {
		vals[i] =  iv[i] - '0';
	}
	for (i = 80; i < A_LEN; i++) {
		vals[i] = 0;
	}

	/* Initialize register A */
	A = lfsrInit(A_LEN, A_FB, A_FF, A_AND_L, A_AND_R, vals);

	utilLog("initilizing register B");

	/* Allocate value array */
	vals = malloc(B_LEN * sizeof(int));
	if (vals == NULL) {
		utilError("allocation failure");
	}

	/* The first 80 bits of B are the key */
	for (i = 0; i < 80; i++) {
		vals[i] =  key[i] - '0';
	}
	for (i = 80; i < B_LEN; i++) {
		vals[i] = 0;
	}

	/* Initialize register B */
	B = lfsrInit(B_LEN, B_FB, B_FF, B_AND_L, B_AND_R, vals);

	utilLog("initilizing register C");

	/* Allocate value array */
	vals = malloc(C_LEN * sizeof(int));
	if (vals == NULL) {
		utilError("allocation failure");
	}

	/* The last 3 bits of C are 1 */
	for (i = 0; i < C_LEN; i++) {
		vals[i] = 0;
	}
	vals[C_LEN - 1] = 1;
	vals[C_LEN - 2] = 1;
	vals[C_LEN - 3] = 1;

	/* Initialize register C */
	C = lfsrInit(C_LEN, C_FB, C_FF, C_AND_L, C_AND_R, vals);


	/* WARM UP */

	utilLog("warming up trivium");

	for (i = 0 ; i < WARMUP_CYCLES ; i++) {
		msg = malloc(MSG_BUFF * sizeof(char));
		if (msg != NULL) {
			sprintf(msg, "cycle %i", i + 1);
			utilTrace(msg);
		} else {
			utilWarning("unable to allocage message");
		}

		cycle(A, B, C);
	}


	/* ENCRYPTION */

	utilLog("encrypting plaintext");


	/* DECRYPTION */

	utilLog("decrypting cyphertext");

	exit(0);
}

void usage(char* name) {
	/* Print usage information */
	fprintf(stdout, "Usage: %s <KEY> <VECTOR> <TEXT>\n", name);
	fprintf(stdout, "Generate a key stream using the Trivium cipher.\n\n");
	fprintf(stdout, "  KEY\t\tAn 80 bit key, with the first bit to be used on");
	fprintf(stdout, " the left\n");
	fprintf(stdout, "  VECTOR\tAn 80 bit initialization vector, with the");
	fprintf(stdout, " first bit to be used on the left.\n");
	fprintf(stdout, "  TEXT\t\tThe plaintext to be encrypted.\n");
}

int cycle(lfsrPtr A, lfsrPtr B, lfsrPtr C) {
	int a;
	int b;
	int c;

	/* Capture register output */
	a = lfsrOutput(A);
	b = lfsrOutput(B);
	c = lfsrOutput(C);

	/* Update registers */
	lfsrShift(A, c);
	lfsrShift(B, a);
	lfsrShift(C, b);

	/* Compute resultant output bit */
	return (a + b + c) % 2;
}
