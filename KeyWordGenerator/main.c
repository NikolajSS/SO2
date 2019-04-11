#include "global.h"
int main()
{

    fFakePointer = fopen("sortedFakeNewsKeywords.txt", "r");
    fRealPointer = fopen("sortedRealNewsKeywords.txt", "r");

    fBigPointer = fopen("bigKeywords.txt", "w");
    fMediumPointer = fopen("mediumKeywords.txt", "w");
    fSmallPointer = fopen("smallKeywords.txt", "w");
    fAntiPointer = fopen("AntiKeywords.txt", "w");

    while (!feof(fFakePointer)){
        fgets(fakeString,SIZEOFARTICLES , fFakePointer);
    }
    fclose(fFakePointer);

    numberOfFakeWords=splitIt(delim, fakePtr, fakeStringArray, fakeString, numberOfFakeWords);
    printf("%d", numberOfFakeWords);
    while (!feof(fRealPointer)){
        fgets(realString,SIZEOFARTICLES ,fRealPointer);
    }
    fclose(fRealPointer);

    numberOfRealWords=splitIt(delim, realPtr, realStringArray, realString, numberOfRealWords);
    for (int i = 0; i<NUMBEROFARTICLEWORDS; i++){
        wordsUsed[i]=" ";
    }
    compareThem(fakeStringArray, realStringArray);
    return 0;
}
