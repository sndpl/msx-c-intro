#include <stdio.h>
#include <msxalib.h>

#define SCRMOD *((char *)0xfcaf)
#define LINLEN *((char *)0xf3b0)
#define TXTNAM *((unsigned *)0xf3b3)
#define T32NAM *((unsigned *)0xf3bd)

VOID main()
{
	unsigned i, a1, a2, adtop, len;
	char ch1, ch2;

	ginit();
	if (SCRMOD == 0) {
		adtop = TXTNAM;
		len = (LINLEN > 40)? 80: 40;
	}
	else {
		adtop = T32NAM;
		len = 32;
	}
	for (i = 0; i < 24; ++i) {
		a1 = adtop + len * i;
		a2 = a1 + len -1;
		do {
			ch1 = vpeek(a1);
			ch2 = vpeek(a2);
			vpoke(a1, ch2);
			vpoke(a2, ch1);
		} while (++a1 < --a2);
	}
}