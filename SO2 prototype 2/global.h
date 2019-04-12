#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define JUSTABIGNUMBER 10000
#define ASMALLERNUMBER 1000

///Files and file conversion
FILE * bigKeywordFile;
FILE * mediumKeywordFile;
FILE * antiKeywordFile;
char bigString[JUSTABIGNUMBER];
char mediumString[JUSTABIGNUMBER];
char antiString[JUSTABIGNUMBER];


///splitting variables
char * ptr;
char delim[1];

int NOBigKeywords; ///NO = Number of
int NOMediumKeywords;
int NOAntikeywords;
int NOHeadlineWords;

///Output from splitting variables
char * bigStringArray[ASMALLERNUMBER];
char * mediumStringArray[ASMALLERNUMBER];
char * antiStringArray[ASMALLERNUMBER];
char * headlineStringArray[ASMALLERNUMBER];

///USERINPUT
char headLine[ASMALLERNUMBER];



///FUNCTIONS
void openReadAndClose();
int splitIt();
int compareStingray();
void cleanItUp();

///DIVERSE
int i;
int points;
int returnValue;
