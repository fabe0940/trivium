#ifndef _VAR_ARRAY_H_
#define _VAR_ARRAY_H_

struct varArray {
	int len;
	int* vals;
};

struct varArray* varArrayInit(int len, int* vals);

#endif
