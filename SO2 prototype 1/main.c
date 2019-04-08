#include "global.h"


int main()
{
	char str[] = "TRUMP SUPPORTER ATTACKED BY HILLARY ZOMBIES";
	int init_size = strlen(str);
	char delim[] = " ";
    char *word4Word[20];
	int i=0;
	char *ptr = strtok(str, delim);
    int numberOfWords=0;
    FILE * fPointer;
    fPointer = fopen("bigWords.txt", "r");
    char singleLine[1000];
    int k=0;
    int numberOfBigWords=0;

	///ADSKILLER STRING OP I ORD OG PUTTER DEM I word4Word
	while(ptr != NULL)	{
        word4Word[i]=ptr;
		ptr = strtok(NULL, delim);
		i++;
		numberOfWords++;
	}
	///LÆSER bigWords.txt og
while (!feof(fPointer)){
    fgets(singleLine, 150, fPointer);
    char *ptr2 = strtok(singleLine, delim);
    while (ptr2 != NULL){

        bigKeyword[k]=ptr2;
        ptr2 = strtok(NULL, delim);
        k++;
        numberOfBigWords++;
    }
}
for (int q=0; q<12; q++){
    printf("%s\n", bigKeyword[q]);
}
	fclose(fPointer);


	printf("\n");
	for (int i=0; i<numberOfWords; i++){
        printf("%s \n", word4Word[i]);
	}


	for (int i=0; i<numberOfWords; i++){
        for (int j=0; j<numberOfBigWords; j++){

            if (strcmp(word4Word[i], bigKeyword[j])==0){
                fakeNewsPoints+=3;
            }


        }
	}
	if (fakeNewsPoints<=3){
    for (int i=0; i<numberOfWords; i++){
       for (int j=0; j<NUMBEROFMEDIUMWORDS; j++){
            if (strcmp(word4Word[i], mediumKeyword[j])==0){
                fakeNewsPoints+=2;
            }
        }
	}
        if(fakeNewsPoints<=5){
            for (int i=0; i<numberOfWords; i++){
                for (int j=0; j<NUMBEROFSMALLWORDS; j++){
                    if (strcmp(word4Word[i], smallKeyword[j])==0){
                        fakeNewsPoints+=1;
                    }
                }
            }
        }
	}

	printf("%d", fakeNewsPoints);
	return 0;
}

