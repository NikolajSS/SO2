#include "global.h"


void openReadAndClose(FILE * _file, char _location[], char _stringOutput[]){
    _file = fopen(_location, "r");
    while (!feof(_file)){
        fgets(_stringOutput, JUSTABIGNUMBER, _file);
    }
    fclose(_file);
}

int splitIt(char * _delim, char * _ptr, char * _output[], char _input[], int _numberOfWords){
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
int compareStingray(char * _stingray1[], char * _stingray2[], int _stingray1Size, int _stingray2Size,int factor){
    returnValue=0;
    printf("size1:%d - size2:%d\n", _stingray1Size, _stingray2Size);
    for (int i = 0; i<_stingray1Size; i++){
        for (int j = 0; j<_stingray2Size; j++){
            if (strcmp(_stingray1[i], _stingray2[j])==0){
                returnValue+=factor;
                printf("%s and %s is a match\n", _stingray1[i], _stingray2[j]);
            }
        }
    }
    return returnValue;
}

void cleanItUp(char _string[]){
    _string=strlwr(_string);
    int i, j;
    for (i=0; _string[i] !='\0'; ++i){
        while (!( (_string[i] >= 'a' && _string[i] <= 'z') || _string[i] == '\0' || _string[i]==' ' ||(_string[i] >= '0' && _string[i] <= '9')) ){
                for(j = i; _string[j] != '\0'; ++j){
                    _string[j] = _string[j+1];
                }
            _string[j] = '\0';
        }
    }
}
