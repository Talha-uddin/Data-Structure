#include<stdio.h>
#include<stdlib.h>

#define SIZE 20

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int array[SIZE];
    int size,n,i,j;

    printf("Enter the Size of the array: ");
    scanf("%d",&size);

    printf("Enter the element for array: ");
    for(i=0; i<size; i++)
    {
        scanf("%d",&array[i]);
    }

    quickSort(array,0,size-1);

    printf("List after sorting is: ");
    for(i=0; i<size; i++)
    {
        printf("%d\t",array[i]);
    }
}

quickSort(int array[SIZE],int first,int last)
{
    int pivot,i,j;

    if(first < last)
    {
        pivot = first;
        i = first;
        j = last;

        while(i<j)
        {
            while(array[i] <= array[pivot] && i < last)
                i++;
                while(array[j] > array[pivot])
                j--;
                
                if(i<j)
                {
                    swap(&array[i],&array[j]);
                }
                swap(&array[pivot],&array[j]);

                quickSort(array,first,j-1);
                quickSort(array,j+1,last);
        }
    }
}