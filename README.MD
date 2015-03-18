# Introduction to MSX-C (second part)

*Authors*: Koji Sakurada, Tetsuto Someya  
*ISBN*: 4-7561-0057-0  
*Publisher*: ASCII Publications  
*Publication date*: December 1990  


The second book (green cover) of the Introduction to MSX-C applies the matter explained in the first book to the development of games for MSX2 computers. The authors developed a simpel C library to handle several aspects of the MSX hardware, and provide several simple example games.

The books can be found on the [Internet Archive](https://archive.org/details/texts):
* [Introduction to MSX-C (first part)](https://archive.org/details/MSX-CJoukan)
* [Introduction to MSX-C (second part)](https://archive.org/details/MSX-CGekan)


## Libraries

### MSXALIB
| Function | Description |
| ------------ | ------------ |
| VOID ginit(); | Initialize the graphic mode |
| VOID calbio(unsigned ad, regs *rg); | Call bios routines with the regs struct (see below table). |
| VOID vpoke(unsigned ad, char dt); | Write VRAM |
| VOID vpeek(unsigned ad); | Read VRAM |
| VOID ldirvm(unsigned ds, char *sr, unsigned ln); | Block transfer to VRAM from memory |
| VOID ldirmv(char *ds, unsigned sr, unsigned ln); | Block transfer to memory from VRAM |
| VOID filvrm(unsigned ad, unsigned ln, char dt); | Fill VRAM with value |
| VOID boxfil(int x1, int y1, int x2, int y2, int cl , int lg); | Draw a filled box |
| VOID line(int x1,int y1,int x2,int y2, int cl, int lg); | Draw a line |
| VOID cpym2v(char *sr, int dr, int dx, int dy, int dp, int lg); | Copy RAM to VRAM |
| VOID cpyv2v(int x1, int y1, int x2, int y2, int sp, in dex, int dy, int dp, int lg); | Copy VRAM to VRAM |
| VOID palett(int pl, int r, int g, int b);| Change color palett |
| unsigned rnd(unsigned n);| Generate random number with a max of n, n can be 1 till 65535 |

Register Structure for the calbio() function.

```
struct regs {
    char     f;
    char     a;
    unsigned bc;
    unsigned de;
    unsigned hl;
};
```

### MSXCLIB

| Function | Description |
| ------------ | ------------ |
| VOID screen(int md); | Switches to given screenmode |
| VOID color(int fg, int bg, int bd); | Changes the screencolors |
| VOID inispr(int sz); | Set sprite size |
| VOID sprite(int no, char *dt); | Define sprite |
| VOID putspr(int no, int x, int y, int cl, int pt); | Put sprite on screen |
| VOID colspr(int no, char *dt); | Define color sprite |
| TINY gtstck(int no); | Returns the joystick status (0 = cursors, 1 = port 1, 2 = port 2) |
| TINY gttrig(int no); | Returns current trigger status (0 = spacebar, 1 = port 1, button A, 2 = port 2, button A, 3 = port 1, button B, 4 = port 2, button B)|
| int  gtpad(int no); | Returns current touch pad status |
| TINY snsmat(int mt); | Returns the value of the specified line from the keyboard matrix |
| VOID kilbuf(); | Clear keyboard buffer |
| VOID gicini(); | Initialises PSG and sets initial value for the PLAY statement |
| VOID sound(int rg, int dt); | Play sound|
| int  sgn(n); | Sign function, n can be -32768 ~ +32767, returns -1, 0, 1. |
| VOID srnd(); | Seed random number generator. |

### How to create the libraries
To create the libraries the following steps are needed:  

1. Copy the following files to a directory:  
```
LIB/MSXALIB.MAC
DOS2/AMAKE.BAT
DOS2/ACHG.BAT
LIB/MSXCLIB.C
DOS2/CMAKE.BAT
DOS2/CCHG.BAT
DOS2/CC.BAT
INCLUDE/MSXALIB.H
INCLUDE/MSXCLIB.H
```  
*If you use DOS1 use the batch files from the DOS1 directory!*

2. Copy the followin files from your MSX-C disks:  
```
LIB80.COM
M80.COM
MX.COM
CF.COM
CG.COM
AREL.BAT
CREL.BAT
STUDIO.H
```
3. Create MSXALIB.REL with
```
A>AMAKE
```
4. Create MSXCLIB.REL with 
```
A>CMAKE
```

5. Use the CC.BAT command to compile the games/examples.


**TODO**: Explain ACHG and CCHG (examples: ACHG LINE, CCHG SCREEN)


## Games
The book contains 4 games which can be found in the games directory:

* Egypt (p104)  
"Egypt" is a text-based puzzle game.Your mission is to across the desert with your vehicle "@". 
Your vehicle uses 1 food to move.You can load 5 foods at point "A" and deposit foods on each point. 
You also can reload foods where foods are already deposited. 
Right and left key to move.Up and down to load/deposit foods. 
* Oicho Kabu (p112)  
"Oicho Kabu" is a Japanese traditional card game. 
Please watch the one's digit of sum of dealt cards.If your digit is greater than COM's,you will win a bet. 
When the number of three your cards are same,also you will win(It is called "Arashi",a hand of Oicho Kabu). 
But if COM has 4 and 1(Shippin) or 9 and 1(Kuppin),you'll lose. 
* Tatakare Mogura (p122)  
* Hip Man (p155)  
Pac Man Clone

## Links
* [Relearning MSX](http://www.lavandeira.net/relearning-msx/)  
Greate series of blog posts written by Javier Lavandeira to setup your MSX-C environment and start learning MSX-C.
* [Generation MSX](http://www.generation-msx.nl)  
Large MSX Software database.
* [MSX Resource Center](http://www.msx.org)  
All the MSX News you need!
* [MSX-DOS2 Tools](http://www.geocities.jp/fullmsx2/u-yan/msxdos-tools.html)  
Japanese page explaining the usages of MSX-C/MSX-DOS Tools/MSX-S BUG2
* [DownDown Game](http://fukenko.hatenablog.com/entry/2014/09/11/073327)  
Source code of DownDown game written in MSX-C with msxclib.
