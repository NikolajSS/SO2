#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*void swap(int *x, int *y);
int Partition(int A[], int start, int end);
void QuickSort(int A[], int start, int end);


void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int Partition(int A[], int start, int end)
{
	int pivot = A[end];
	int pIndex = start;

	for(int i=start; i<end; i++)
	{
		if( A[i] <= pivot )
		{
			swap(&A[i],&A[pIndex]);
			pIndex++;
		}
	}
	swap(&A[end],&A[pIndex]);
	return pIndex;
}

void QuickSort(int A[], int start, int end)
{
	if(start<end)
	{
		int pIndex = Partition(A,start,end);
		QuickSort(A,start,pIndex-1);
		QuickSort(A,pIndex+1,end);
	}
}
*/
void sort_words(char *words[], int count)
{
    char *x;

    for (int i = 0; i<count; i++)
    {
        for (int j = i + 1; j<count; j++)
        {
            if (strcmp(words[i], words[j]) < 0)
            {
                x = words[j];
                words[j] = words[i];
                words[i] = x;
            }
        }

    }
}
