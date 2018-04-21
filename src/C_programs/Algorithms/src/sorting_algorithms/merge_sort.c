#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "utils.h"


void merge(int *a, int left, int mid, int right)
{
	int i,j,k;
	int n1,n2;

	n1 = mid - left+1;
	n2 = right - mid;

	int left_arr[n1],right_arr[n2];
	i = 0;
	j = 0;

	for (i=0; i<n1; i++) {
		left_arr[i] = a[left+i];
	}
	for (j=0; j<n2; j++) {
		right_arr[j] = a[mid+1+j];
	}

	i = 0;
	j = 0;
	k = left;

	while (i < n1 && j < n2) {

		if (left_arr[i] <= right_arr[j]) {
			a[k] = left_arr[i];
			i++;
		} else {
			a[k] = right_arr[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		a[k] = left_arr[i];
		k++;
		i++;
	}

	while (j < n2) {
		a[k] = right_arr[j];
		k++;
		j++;
	}	

	return;
}

void merge_sort(int *a, int left, int right)
{
	int mid;

	if (!a || left < 0 || right < 0) {
		printf("\n ERROR: Invalid inputs to merge sort");
		return;
	}

	if (left >= right) {
		return;
	}

	mid = left+ (right-left)/2;

	merge_sort(a, left, mid);
	merge_sort(a, mid+1, right);

	/* Now merge both the parts */
	merge(a, left, mid, right);
	
}

void main() 
{
	int a[] = {100,99,98,97,96,95};

	print_array(a, 6);

	printf("\n Array contents after sorting ...");

	merge_sort(a, 0, 5);

	print_array(a, 6);
}
