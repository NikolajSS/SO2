#include "global.h"
int main()
{
    char delim[]= " ";
    char *ptr=0;
    FILE * fPointer;
    fPointer = fopen("realNews.txt", "r");
    char singleLine[150000];
    char *unsortedWords[20000];
    int numberOfWords=0;
    int k=0;
    char placeHolder[20];

while (!feof(fPointer)){
    fgets(singleLine, 150000, fPointer);

}

fclose(fPointer);
    ptr = strtok(singleLine, delim);
while (ptr!=NULL){
        unsortedWords[k]=ptr;
        //printf("%s ", unsortedWords[k]);
        ptr=strtok(NULL, delim);
        k++;
        numberOfWords++;

    }
sort_words(unsortedWords, numberOfWords);
fPointer = fopen("sortedRealNews.txt", "w");
if(fPointer==NULL)
    {
        printf("File is not created!!!");
        exit(0); /*exit from program*/
    }
    printf("%d\n", numberOfWords);
    printf("%s\n",unsortedWords[numberOfWords+1]);
for (int i = 0; i<numberOfWords; i++){
strcpy(placeHolder, unsortedWords[i]);
fprintf(fPointer, "%s", placeHolder);
fputc(' ', fPointer);
}
fclose(fPointer);
return 0;
}
