#include "global.h"

int main(){
    strcpy(delim, " ");
    strcpy(headLine, "Trump claims that hillary is a racist woman");
    cleanItUp(headLine);
    printf("The headline to be checked is: %s\n", headLine);

    ///open, read and close bigkeywords.txt and put them in a string array
    openReadAndClose(bigKeywordFile, "bigKeywords.txt", bigString);
    NOBigKeywords=splitIt(delim, ptr, bigStringArray, bigString, NOBigKeywords);

    ///open, read and close mediumkeywords.txt and put them in a string array
    openReadAndClose(mediumKeywordFile, "mediumKeywords.txt", mediumString);
    NOMediumKeywords=splitIt(delim, ptr, mediumStringArray, mediumString, NOMediumKeywords);

    ///open, read and close antikeywords.txt and put them in a string array
    openReadAndClose(antiKeywordFile, "antiKeywords.txt", antiString);
    NOAntikeywords=splitIt(delim, ptr, antiStringArray, antiString, NOAntikeywords);

    ///splits headline and counts the number of words in it
    NOHeadlineWords=splitIt(delim, ptr, headlineStringArray, headLine, NOHeadlineWords);

    points=0;
    points+=compareStingray(headlineStringArray, bigStringArray, NOHeadlineWords, NOBigKeywords, 3);
    points+=compareStingray(headlineStringArray, mediumStringArray, NOHeadlineWords, NOMediumKeywords, 2);
    points+=compareStingray(headlineStringArray, antiStringArray, NOHeadlineWords, NOAntikeywords, -1);

    printf("%d", points);
    return 0;
}
