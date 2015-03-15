#include <stdio.h>
#include <msxalib.h>
#include <msxclib.h>

int Red[14] = {1,2,3,4,5,6,7,6,5,4,3,2,1,0};
int Grn[14] = {1,0,1,2,3,4,5,6,7,6,5,4,3,2};
int Blu[14] = {3,2,1,0,1,2,3,4,5,6,7,6,5,4};

VOID main()
{
	int i, j, k;

	ginit();
    color(15, 1, 1);

    while (!kbhit()) {
    	for (i = 0; i < 14; ++i) {
    		palett(1, Red[i], Grn[i], Blu[i]);
    		for (k = 0; k < 1000; ++k);
    	}
    }

    palett(1, 0, 0, 0);
}