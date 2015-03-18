#include <stdio.h>
#include <msxalib.h>
#include <msxclib.h>
#include "hipman.h"
#pragma nonrec

extern TINY Maze[23][25];
extern int  Hx;
extern int  Hy;
extern int  Ecl[5];
extern struct enemy E[3];

static VOID rndmvenemy(ep)
struct enemy *ep;
{
    static int  movex[7] = {  0, 1, 0, -1,  0, 1, 0 };
    static int  movey[7] = { -1, 0, 1,  0, -1, 0, 1 };
    int  tx, ty, i, count;

    for (count = 0, i = rnd(4); count < 4; ++count, ++i) {
	tx = movex[i];
	ty = movey[i];
	if (Maze[ep->y + ty][ep->x + tx] != WALL
		&& (ep->tx != -tx || ep->ty != -ty)) {
	    ep->tx = tx;
	    ep->ty = ty;
	    return;
	}
    }
    ep->tx = 0;
    ep->ty = 0;
}

static TINY chasex(ep)
struct enemy *ep;
{
    int tx;

    tx = sgn(Hx - ep->x);

    if (tx == 0)
	return 0;

    if (tx == -(ep->tx))
	return 0;

    if (Maze[ep->y][ep->x + tx] == WALL)
	return 0;

    ep->tx = tx;
    ep->ty = 0;
    return 1;
}

static TINY chasey(ep)
struct enemy *ep;
{
    int ty;

    ty = sgn(Hy - ep->y);

    if (ty == 0)
	return 0;

    if (ty == -(ep->y))
	return 0;

    if (Maze[ep->y + ty][ep->x] == WALL)
	return 0;

    ep->tx = 0;
    ep->ty = ty;
    return 1;
}

static VOID refresh(ep)
struct enemy *ep;
{
    ep->tx = 0;
    ep->ty = 0;
    ep->st = (ep - &E[0]);
}

static VOID red(ep)
struct enemy *ep;
{
    if (!chasex(ep) && !chasey(ep))
	rndmvenemy(ep);
}

static VOID pink(ep)
struct enemy *ep;
{
    if (!chasey(ep) && !chasex(ep))
	rndmvenemy(ep);
}

static VOID green(ep)
struct enemy *ep;
{
    rndmvenemy(ep);
}

static VOID weaking(ep)
struct enemy *ep;
{
    if (--(ep->wt) == 0)
	refresh(ep);
    else
	rndmvenemy(ep);
}

static VOID fainting(ep)
struct enemy *ep;
{
    if (--(ep->wt) == 0)
	refresh(ep);
}

VOID putenemy(ep)
struct enemy *ep;
{
    int col, i;

    i= ep - &E[0];

    if ((ep->wt & 1) != 0 || ep->wt >= 10)
	col = Ecl[ep->st];
    else
	col = Ecl[i];
    putspr(i+1, (ep->x) * 8, (ep->y) * 8, col, 0);
}

VOID mvenemy()
{
    static VOID (*adr[5])() = {red,pink,green,weaking,fainting};
    struct enemy *ep;

    for (ep = &E[0]; ep <= &E[2]; ++ep) {
	(*adr[ep->st])(ep);
	ep->x += ep->tx;
	ep->y += ep->ty;
	putenemy(ep);
    }
}
