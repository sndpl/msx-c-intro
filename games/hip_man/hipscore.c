#include <stdio.h>
#include <msxalib.h>
#include <msxclib.h>
#pragma nonrec

#define MAXNUM  10

struct score {
    int  ext;
    int  sco;
    char nam[12];
};

struct score Hiscore[MAXNUM + 1];
static char ScoreFile[] = "hipman.sco";
extern unsigned Score;

static int cmp(p1, p2)
struct score *p1, *p2;
{
    int d;

    d = (p2->sco) - (p1->sco);
    if (d == 0)
	d = (p1->ext) - (p2->ext);
    return d;
}

static char *yourname()
{
    static char name[12];
    int i;
    char c;

    screen(1);
    kilbuf(); printf("Input your name:");

    for (i = 0; ;) {
	/* fflush(stdout); */
	c = getch();
	if (c == '\r') {
	    if (i > 0) {
		name[i] = '\0';
		return name;
	    }
 	}
	else if (c == '\b') {
	    if (i > 0) {
		--i;
	 	printf("\b \b");
	    }
	}
	else if (c > ' ') {
	    if (i < 11) {
		name[i++] = c;
	 	putchar(c);
	    }
	}
    }
}

VOID highscore()
{
    int i, n;
    char name[20];
    unsigned sc;
    FILE *fp;

    Hiscore[0].ext = 0;
    Hiscore[0].sco = Score;
    strcpy(Hiscore[0].nam, yourname());

    i = 0;
    if ((fp = fopen(ScoreFile, "r")) != NULL) {
	while (i < MAXNUM && fscanf(fp, "%d %s", &sc, name) != -1) {
	    ++i;
	    Hiscore[i].ext = i;
	    Hiscore[i].sco = sc;
	    strcpy(Hiscore[i].nam, name);
	}
	fclose(fp);
    }
     n = i;

    qsort(Hiscore, n+1, sizeof(struct score), cmp);
    if (n < MAXNUM)
	++n;

    printf("\n\nRank Score  Name\n");
    for (i = 0; i < n; ++i)
	printf("%2d) %6d  %s\n", i+1, Hiscore[i].sco, Hiscore[i].nam);

    if ((fp = fopen(ScoreFile, "w")) == NULL)
	puts("\nCan't make score file.\n");
    else {
	for (i = 0; i < n; ++i)
	    fprintf(fp, "%d %s\n", Hiscore[i].sco, Hiscore[i].nam);
	fclose(fp);
    }
}
