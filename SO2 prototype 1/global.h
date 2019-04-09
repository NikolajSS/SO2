#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUMBEROFMEDIUMWORDS 8
#define NUMBEROFSMALLWORDS 5
///Nøgleord
char *bigKeyword[];

char *mediumKeyword[] = {"FEMINIST", "ASSAULT", "MAN", "ANTI", "DEMOCRAT", "RALLY", "INFORMATION", "CLINTON"};

char *smallKeyword[] = {"POPE","FLORIDA", "FAIL", "ULTIMATE"};

char *antiWord[] = {"KOREA", "CHINA", "BARACK", "G20", "JERUSALEM", "SAD", "COURT"}; ///Ord der opstår oftere i rigtige artikler
                                                                                    /// end i falske, giver -1 point.


/// Point der skal sige brugeren, hvor stor sandsynligheden er for at det er fake news
int fakeNewsPoints=0;
