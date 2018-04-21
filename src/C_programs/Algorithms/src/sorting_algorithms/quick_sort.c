#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */

int partition(int *a, int left, int right)
{
	int pivot,i,j,temp;

	if (!a || left < 0 || right < 0) {
		printf("\nERROR: Incorrect inputs to partition, \
			left = %d, right = %d, arr* = %p", left, right, a);
		return;
		//assert(0);
	}

	pivot = a[right];
	i = left-1;

	for (j = left; j < right; j++) {
		
		if (a[j] <= pivot) {
			i++;
			// Swap the i and j values
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	// Now do the last swap operation i+1 to right
	temp = a[i+1];
	a[i+1] = a[right];
	a[right] = temp;
	
	return i+1;
}

/*@Desc: Recursive quick sort algorithm  
* I/P: Pointer to array to be sorted, left most index, right most valid index 
* i.e. 0 - n-1 of n array */
void quick_sort(int *a, int left, int right)
{
	int p;

	if (!a || left < 0 || right < 0) {
		printf("\nERROR: Incorrect inputs to quick sort algo, \
			left = %d, right = %d, arr* = %p", left, right, a);
		return;
		//assert(0);
	}

	if (left < right) {
		
		p = partition(a, left, right);
		quick_sort(a, left, p-1);
		quick_sort(a, p+1, right);
	}

	return;
}

void print_array(int *a, int n)
{
	int i=0;
	if (!a || n < 0) {
		printf("\nWARNING: NULL array given");
		return;
	}

	printf("\n Array contents are ...");
	for(i=0; i<n; i++) {
		printf("\n%d", a[i]);
	}
}


void main()
{
	int a [] = {100,99,98,97,96,95};

	print_array(a, 6);
	quick_sort(a, 0, 5);
	printf("\n Array after quick sort");
	print_array(a, 6);

}
