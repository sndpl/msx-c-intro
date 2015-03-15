#include <stdio.h>
#include <msxalib.h>

VOID capson()
{
	struct regs r;

	r.a = 0;
	calbio(0x0132, &r);
}

VOID capsoff()
{
	struct regs r;

	r.a = 1;
	calbio(0x0132, &r);
}

VOID main()
{
	int i, j;

	for (i = 0; i < 10; ++i) {
		capson();
		for (j = 0; j < 2000; ++j);
	    capsoff();
		for (j = 0; j < 2000; ++j);
	}
}