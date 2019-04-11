#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZEOFARTICLES 150000
#define NUMBEROFARTICLEWORDS 12000

char fakeString[SIZEOFARTICLES];
char realString[SIZEOFARTICLES];
char * fakeStringArray[NUMBEROFARTICLEWORDS];
char * realStringArray[NUMBEROFARTICLEWORDS];
char * fakePtr;
char * realPtr;
int numberOfFakeWords;
int numberOfRealWords;
char delim[]=" ";
int counter=0;
char * wordsUsed[NUMBEROFARTICLEWORDS];
int i;
char wordToCmp[10000];
int returnValue;
    FILE *fFakePointer;
    FILE *fRealPointer;

    FILE *fBigPointer;
    FILE *fMediumPointer;
    FILE *fSmallPointer;
    FILE *fAntiPointer;
int placeHolder1;
int placeHolder2;

///Tjekker om ordet er blevet brugt
int isThisWordUsed(char _word[], char * _stringArray[], int numberThing){
   printf("seeing if %s has been used, repeating %d times\n", _word, counter+1);
    for (int i=0; i<counter+1; i++){
            printf("DEBUG: %s, %s\n", _word, wordsUsed[i]);
        if (strcmp(_word, wordsUsed[i])==0){
            printf("Word '%s' has been used\n", _word);
            return 1; /// returnerer 1 hvis ordet er blevet talt før
        } else {
            printf("Puttin %s into wordsused[%d]\n", _word, i);
            wordsUsed[i]=_stringArray[numberThing];
            counter++;
            return 0; ///Returnerer nul hvis det ikke er blevet brugt før
        }
    }
}

int splitIt(int _delim, char * _ptr, char * _output[], char _input[], int _numberOfWords){
    _ptr = strtok(_input, _delim);
    i=0;
    while(_ptr!=NULL){
        _output[i]=_ptr;
        _ptr=strtok(NULL, _delim);
        i++;
        _numberOfWords++;
    }
    return _numberOfWords;
}

int countIt(char _wordToCount, char * _stringToCount[], int _lengthOfArray, char nameOfArray[]){
    printf("Counting for %s... %d, \n", nameOfArray, _lengthOfArray);
    returnValue=0;
    for (int i = 0; i<_lengthOfArray; i++){
        if (strcmp(("%s",wordToCmp), _stringToCount[i])==0){
            returnValue++;
            printf("DEBUG: %s, is at %d, value is now %d\n", wordToCmp, i, returnValue);
        }
    }
    return returnValue;
}
void determineKeyword(int _numberOfFakeWords, int _numberOfRealWords, char _keyWord[], FILE *_bigFile, FILE *_mediumFile, FILE *_smallFile, FILE *_antiFile ){
    printf("asdasd\n");
    if(_numberOfFakeWords+_numberOfRealWords>3){
        if (_numberOfRealWords==0){
            fprintf(_bigFile, "%s", _keyWord);
            fputc(' ', _bigFile);
            printf("%s has been put into bigkeywords\n", _keyWord);
        } else if (_numberOfFakeWords/_numberOfRealWords>=2){
            fprintf(_bigFile, "%s", _keyWord);
            fputc(' ', _bigFile);
            printf("%s has been put into bigkeywords\n", _keyWord);
        } else if (_numberOfFakeWords/_numberOfRealWords>=3/2){
            fprintf(_mediumFile, "%s", _keyWord);
            fputc(' ', _mediumFile);
            printf("%d/%d %s has been put into mediumkeywords\n", numberOfFakeWords, numberOfRealWords, _keyWord);
        } else if (_numberOfFakeWords/_numberOfRealWords>=18/13){
            fprintf(_smallFile, "%s", _keyWord);
            fputc(' ', _smallFile);
            printf("%s has been put into smallkeywords\n", _keyWord);
        }else if (_numberOfFakeWords/_numberOfRealWords<=2/3){
            fprintf(_antiFile, "%s", _keyWord);
            fputc(' ', _antiFile);
            printf("%s has been put into Antikeywords\n", _keyWord);
        }else {
        printf("There weren't enugh occurrences or it was too close of the word %s, to be put as a keyword\n");
        }
    }
}

void compareThem(char * _firstStringArray[], char * _secondStringArray[]){
    for (int i=0; i<numberOfFakeWords; i++){
        strcpy(wordToCmp, _firstStringArray[i]);
        if (isThisWordUsed(wordToCmp, fakeStringArray, i)==0){
                printf("SUCCES\n");
            placeHolder1=countIt(wordToCmp, _firstStringArray, numberOfFakeWords, "FakeWords");
            placeHolder2=countIt(wordToCmp, _secondStringArray, numberOfRealWords,"Realwords");
            determineKeyword(placeHolder1, placeHolder2, wordToCmp, fBigPointer, fMediumPointer, fSmallPointer, fAntiPointer);
        }

    }
}
