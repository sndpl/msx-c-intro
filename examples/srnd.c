#include <stdio.h>
#include <msxalib.h>
#include <msxclib.h>


VOID main()
{
	int i, r;

    srnd();
	for (i = 0; i < 10; ++i) {
		r = rnd(1000);
		printf("%3d ", r);
	}
}