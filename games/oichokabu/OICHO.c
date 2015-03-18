#include <stdio.h>
#include <msxalib.h>
#include <msxclib.h>
# pragma nonrec

#define LINLEN  *((char *)0xf3b0)

int Rank[5][3];
int Chip[5];
int Card[4][10];
int Gold;

VOID locate(x, y)
int x, y;
{
    printf("\33Y%c%c", y+32, x+32);
}

VOID lclear()
{
    printf("\33K");
}

VOID dealcards(i,j)
int i, j;
{
    static char *rk[10] = {
	"10","A","2","3","4","5","6","7","8","9" };

    int s, r;

    s = rnd(4);
    r = rnd(10);
    while (Card[s][r] == 1) {
	if (++s == 4) {
	    s = 0;
	    if (++r == 10)
		r = 0;
	}
    }
    Card[s][r] = 1;
    Rank[i][j] = r;

    locate(j * 4, (i == 0) ? 3 : 4 + i);
    printf("%c%s", 128 + s, rk[r]);
}

VOID putgold()
{
    locate(0, 0); printf("GOLD:%3d", Gold);
}

VOID init()
{
    int i, j;

    printf("\f\33x5");
    putgold();
    memset(Card, 0, sizeof(Card));
    memset(Rank, 0, sizeof(Rank));
    for (i = 0; i <= 4; ++i)
	dealcards(i, 0);
}

VOID bet()
{
    int i, g;
    char buf[7];

    for (i = 1; i <= 4; ++i) {
	if (Gold == 0)
	    g = 0;
	else {
	    do {
		locate(6, 4+i);
		printf("Bet how much? ");
		lclear();
	     /* fflush(stdout); */
		fgets(buf, 7, stdin);
		locate(6, 4+i);
		lclear();
		g = atoi(buf);
	    } while (g < 0 || Gold < g);
	}
	locate(13, 4+i);
	printf("%d", g);
	Gold -= (Chip[i] = g);
	putgold();
    }
}

VOID play()
{
    char k;
    int i;

    for (i = 1; i <= 4; ++i) {
	dealcards(i, 1);
	if (Chip[i] == 0)
	    continue;
	locate(17, 4 + i);
	printf("more? (y/n)");
     /* fflush(stdout); */
	k = getch();
	if (k == 'Y' || k == 'Y')
	    dealcards(i, 2);
	locate(14, 4 + i);
lclear();
    }
}

VOID judge()
{
    int i, j;
    int p[5];

    for (i = 0; i <=4; ++i) {
	j = (Rank[i][0] + Rank[i][1] + Rank[i][2]) % 10;
	p[i] = j;
	locate(18, (i == 0) ? 3 : 4 + i);
	printf("[%d]", j);
    }

    for (i = 1; i <=4; ++i) {
	if (Chip[i] == 0)
	    continue;
	if (Rank[i][0] == Rank[i][1] && Rank[i][0] == Rank[i][2]) {
	    Gold += Chip[i] * 3;
	    locate(22, 4+i); printf("ARASHI!");
	}
	else if (p[i] > p[0]) {
	    Gold += Chip[i] * 2;
	    locate(22, 4+i); printf("WIN");
	}
	else {
	    locate(22, 4+i); printf("LOSE");
	}
    }
    putgold();
}

VOID dealer()
{
    int	 j, r0, r1;

    dealcards(0, 1);
    r0 = Rank[0][0];
    r1 = Rank[0][1];

    if ((r0==1 && r1 ==4) || (r0==4 && r1==1)) {
	locate(13, 3);
	printf("Dealer's SIPPIN");
    }
    else if ((r0==1 && r1==9) || (r0==9 && r1==1)) {
	locate(13, 3);
	printf("Dealer's KUPPIN");
    }
    else {
	j = (r0 + r1) % 10;
	if (j < 5 || (j < 7 && rnd(j) < 4))
	    dealcards(0, 2);
	judge();
    }
}

VOID main()
{
    char k;

    screen(1);
    LINLEN = 31;
    srnd();
    Gold = 10;

    do {
	init();
	bet();
	play();
	dealer();
	if (Gold == 0)
	    break;
	locate(0, 11);
	printf("One more game? (y/n)");
     /*	fflush(stdout); */
	k = getch();
    } while ( k!= 'N' && k != 'n');

    if (Gold == 0) {
	locate(0, 12);
	printf("You lost all money.\n");
    }
    else {
	locate(0,13);
	printf("You get %d golds.", Gold);
    }
}
