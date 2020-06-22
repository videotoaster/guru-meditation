#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int seg1;
int fillerPlaced;
int paddingLeft;
int halfTextWidth;
int paddingRight;
int thirdLineNumber;
int flashpos;
struct winsize w;
/* int main (int argc, char **argv)
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    while (dots<w.ws_col) { // ew
    	printf("_");
    	dots++;
    }
    return 0;
} */
void placeFiller(textLength) {
    while (fillerPlaced<paddingLeft) {
    	printf(" ");
    	fillerPlaced++;
    }
    fillerPlaced = 0;
}
void fillOneThird() {
    while (thirdLineNumber<w.ws_col / 3) {
    	printf("\n");
    	thirdLineNumber++;
    }
}
void drawCenteredTextBox(char textBox[99], char modifiers[99], char textBoxLT[99]) {
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    paddingLeft = w.ws_col / 2 - strlen(textBox) + 24;
    placeFiller(paddingLeft);
    fillerPlaced = 0;
    printf(modifiers);
    printf("┏");
    while (seg1<strlen(textBox)+6) {
    	printf("━");
    	seg1++;
    }
    seg1 = 0;
    printf("┓\n");
    placeFiller(paddingLeft);
    printf("┃   ");
    printf(textBox);
    printf("   ┃");
    printf("\n");

    if (textBoxLT!="") {	
    	placeFiller(paddingLeft);
    	printf("┃   ");
    	printf(textBoxLT);
    	while (paddingRight<strlen(textBox)-44) {
    	    printf(" ");
    	    paddingRight++;
    	}
    	printf("                ┃");
    	printf("\n");
    }
    placeFiller(paddingLeft);
    printf("┗");
    while (seg1<strlen(textBox)+6) {
    	printf("━");
    	seg1++;
    }
    seg1 = 0;
    printf("┛\e[0m\n");
}
void borderlessCenteredTextBox(char textBox[99], char modifiers[99], char textBoxLT[99]) {
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    paddingLeft = w.ws_col / 2 - strlen(textBox) + 24;
    placeFiller(paddingLeft);
    fillerPlaced = 0;
    printf(modifiers);
    printf(" ");
    while (seg1<strlen(textBox)+6) {
    	printf(" ");
    	seg1++;
    }
    seg1 = 0;
    printf(" \n");
    placeFiller(paddingLeft);
    printf("    ");
    printf(textBox);
    printf("    ");
    printf("\n");

    if (textBoxLT!="") {	
    	placeFiller(paddingLeft);
    	printf("    ");
    	printf(textBoxLT);
    	while (paddingRight<strlen(textBox)-44) {
    	    printf(" ");
    	    paddingRight++;
    	}
    	printf("    ");
    	printf("\n");
    }
    placeFiller(paddingLeft);
    printf(" ");
    while (seg1<strlen(textBox)+6) {
    	printf(" ");
    	seg1++;
    }
    seg1 = 0;
    printf(" \e[0m\n");
}
void guru() {
    sleep(1);
    system("clear");
    if (flashpos==0) {
    drawCenteredTextBox("Software Failure.    Press left mouse button to continue.","\e[31m","          Guru Meditation #00000025,65045338");
    flashpos=1;
    } else {
    borderlessCenteredTextBox("Software Failure.    Press left mouse button to continue.","\e[31m","          Guru Meditation #00000025,65045338     ");
    flashpos=0;
    }
    guru();
    
}
int main (int argc, char **argv)
{
    guru();
    return 0;
}
// DISCARDED LINES:
// printf ("lines %d\n", w.ws_row);
// printf ("columns %d\n", w.ws_col);
