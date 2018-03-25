// C program for implementation of selection sort
#include <stdio.h>

static inline void swap(int *xp, int *yp)
{
    __asm__ ( ""
        : "=a" (*xp), "=b" (*yp)
        : "a" (*yp), "b" (*xp) );
}

static inline void selectionSort(int arr[], int n)
{
    if(n<=0) {
        return;
    }
	int i=0, j, min_idx;

		// Find the minimum element in unsorted array
		min_idx = i;
		for (j = i; j < n; j++)
		if (arr[j] < arr[min_idx])
			min_idx = j;

		// Swap the found minimum element with the first element
		swap(&arr[min_idx], &arr[0]);
	    selectionSort(&arr[1],n-1);
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Driver program to test above functions
int main()
{
	int arr[] = {64, 25, 12, 22, 11,3,4,2,65,54,76,73};
	int n = sizeof(arr)/sizeof(arr[0]);
	selectionSort(arr, n);
	printf("Sorted array: \n");
	printArray(arr, n);
	return 0;
}

