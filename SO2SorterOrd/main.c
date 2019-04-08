#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE * fPointer;
    fPointer = fopen("fakeNews.txt", "r");
    char singleLine[1000000];
    int k=0;
while (!feof(fPointer)){
    fgets(singleLine, 1000000, fPointer);
    printf("%s", singleLine);
}
	char delim[] = "\n";
    char *word4Word[100000];
	int i=0;
	char *ptr = strtok(singleLine, delim);
    int numberOfWords=0;
while(ptr != NULL)	{
        word4Word[i]=ptr;
        printf("%s\n",ptr);
		ptr = strtok(NULL, delim);
		i++;
		numberOfWords++;
	}
for (int i=0; i<numberOfWords; i++){
    printf("%s\n", word4Word[i]);
}
    fclose(fPointer);
    return 0;

}
