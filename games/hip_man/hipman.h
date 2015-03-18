#define SPACE  0
#define CHIP   1
#define DOT    2
#define WALL   3

#define RED    0
#define PINK   1
#define GREEN  2
#define WEAK   3
#define FAINT  4

struct enemy {
    int  st;
    int  x;
    int  y;
    int  tx;
    int  ty;
    int  wt;
};
