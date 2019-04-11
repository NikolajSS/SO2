#include "global.h"


int main()
{
	char str[] = "TRUMP SUPPORTER ATTACKED BY HILLARY ZOMBIES"; ///String to analyze

	///SPLIT STRING VARIABLES
	int init_size = strlen(str);
	char delim[] = " ";
    char *word4Word[20]; ///Artikeltitlen, men opdelt i ord
	int i=0;
	char *ptr = strtok(str, delim);
    int numberOfWords=0; ///Bliver også brugt som antal ord i strengen der skal analyseres

    ///LOOK AT txtFile (and split the string)
    FILE * fPointer;
    fPointer = fopen("bigWords.txt", "r");
    char singleLine[1000];
    int k=0;
    int numberOfBigWords=0; ///Bliver også brugt som antal ord i strengen med store nøgleord

	///ADSKILLER STRING OP I ORD OG PUTTER DEM I word4Word
	while(ptr != NULL)	{
        word4Word[i]=ptr;
		ptr = strtok(NULL, delim);
		i++;
		numberOfWords++;
	}
	///LÆSER bigWords.txt og giver dem til singleLine
    while (!feof(fPointer)){
        fgets(singleLine, 150, fPointer);
    ///tager singleLine og splitter den
        char *ptr2 = strtok(singleLine, delim);
        while (ptr2 != NULL){

            bigKeyword[k]=ptr2;
            ptr2 = strtok(NULL, delim);
            k++;
            numberOfBigWords++;
        }
    }
///Printer det splittede fra bigWords.txt
    for (int q=0; q<12; q++){
        printf("%s\n", bigKeyword[q]);
    }
    fclose(fPointer);

///Printer strengen/titlen på artiklen
	printf("\n");
	for (int i=0; i<numberOfWords; i++){
        printf("%s \n", word4Word[i]);
	}

///tjekker om bigKeyWords mathcer med strengen/titlen på artiklen
	for (int i=0; i<numberOfWords; i++){
        for (int j=0; j<numberOfBigWords; j++){
            if (strcmp(word4Word[i], bigKeyword[j])==0){
                ///Giver fakeNewsPoints 3 point, da det er store nøgleord
                fakeNewsPoints+=3;
            }


        }
	}
	///Tjekker om det er nødvendigt at tjekke de mellemstore ord
	if (fakeNewsPoints<=3){
            ///Tjekker om mediumKeyword matcher med artiklens titel
    for (int i=0; i<numberOfWords; i++){
       for (int j=0; j<NUMBEROFMEDIUMWORDS; j++){
            if (strcmp(word4Word[i], mediumKeyword[j])==0){
                fakeNewsPoints+=2;
            }
        }
	}
	///Tjekker om det er nødvendigt at tjekke de små ord
        if(fakeNewsPoints<=5){
                ///sammenligner smallKeyword med word4Word (strengen brugt)
            for (int i=0; i<numberOfWords; i++){
                for (int j=0; j<NUMBEROFSMALLWORDS; j++){
                    if (strcmp(word4Word[i], smallKeyword[j])==0){
                        fakeNewsPoints+=1;
                    }
                }
            }
        }
	}
///Printer hvor mange point der er
	printf("%d", fakeNewsPoints);
	return 0;
}

