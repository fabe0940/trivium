#ifndef _VAR_ARRAY_H_
#define _VAR_ARRAY_H_

struct varArray {
	int len;
	int* vals;
};
typedef struct varArray* varArrayPtr;

varArrayPtr varArrayInit(int len, int* vals);

#endif
