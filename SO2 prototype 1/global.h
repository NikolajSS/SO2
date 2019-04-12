#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///Nøgleord

char *bigKeyword[];

char *mediumKeyword[];

char *smallKeyword[];

char *antiWord[]; ///Ord der opstår oftere i rigtige artikler end i falske, giver -1 point.


/// Point der skal sige brugeren, hvor stor sandsynligheden er for at det er fake news
int fakeNewsPoints=0;

///FILES
FILE * fPointer;

    char singleLine[6000];
    int k;
    int numberOfBigWords;
    int numberOfMediumWords;
    int numberOfSmallWords;
    int numberOfAntiWords;


///SPLITTING
char delim[] = " ";
char *word4Word[20]; ///Artikeltitlen, men opdelt i ord
int i;
char *ptr;
int numberOfWords; ///Bliver også brugt som antal ord i strengen der skal analyseres
