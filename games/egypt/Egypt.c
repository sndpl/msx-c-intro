#include <stdio.h>
#pragma nonrec

#define NCAMP 10

#define RKEY '\x1C'
#define LKEY '\x1D'
#define UKEY '\x1E'
#define DKEY '\x1F'

VOID locate(x, y)
int x, y;
{
    printf("\33Y%c%c", y+32, x+32);
}

VOID plot(p, h, c)
int p, h, c;
{
    locate(4 + p * 2, 5 + h);
    printf("%c\b", c);
}

int across()
{
    int  p, q, f, step;
    int  s[NCAMP];

    for (p = 0; p < NCAMP; ++p)
	s[p] = 0;

    for (p = -1, step = 0; ;) {

	locate(7, 0);
	printf("Step: %d", step);

   	if (p == -1)
	    f = 5;

	plot(p, -1, '0' + f);
	plot(p, 0, '@');

	if (p == NCAMP)
	    return step;

	if (p >= 0 && f + s[p] == 0)
	    return -step;

	q = p;

	/* fflush(stdout); */

	switch (getch()) {

	 case LKEY:
	    if (p >= 0 && f > 0) {
		--p;
		--f;
		++step;
	    }
	    break;

	 case RKEY:
	    if (f > 0) {
		++p;
		--f;
		++step;
	    }
	    break;

	case UKEY:
	    if (p >= 0 && s[p] > 0 && f < 5) {
		++f;
		plot(p, s[p]--, ' ');
	    }
	    break;

	case DKEY:
	    if (p >= 0 && s[p] <4 && f > 0) {
		--f;
		plot(p, ++s[p], '*');
	    }
	    break;
	}

	if (q != p) {
	    plot(q, -1, ' ');
	    plot(q, 0, (q<0)? 'A': (q==NCAMP)? 'B': '-');
	}
    }
}

VOID main()
{
    int i, score;

    printf("\f\33x5");

    plot(-1, 0, 'A');
    for (i = 0; i < NCAMP; ++i)
	plot(i, 0, '-');
    plot(NCAMP, 0, 'B');

    score = across();

    locate(0, 18);
    if (score < 0) {
	printf("Sorry...\n");
	printf("You died after %d step moves.\n",-score);
    }
    else {
	printf("Congratulations!\n");
	printf("You completed your mission in %d steps.\n", score);
    }
}
