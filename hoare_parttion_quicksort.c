#include <stdio.h>
#include <stdlib.h>

void quicksort(int arr[],int low,int high);

int main(int argc, char **argv)
{
	int a[] = {11,2,22,3,33,8,5,3,7,1};
	int len = sizeof(a)/sizeof(a[0]);
	int i;
	
	printf("The elements of the array before quick sort.\n");
	for (i = 0; i < len; i++) {
		printf("%d\n",a[i]);
	}
	
	printf("Initiating quicksort on array\n");
	quicksort(a,0,len-1);
	
	printf("The elements of the array after quick sort.\n");
	for (i = 0; i < len; i++) {
		printf("%d\n",a[i]);
	}
	
	return 0;
}

int hoare_partition(int arr[],int low,int high);

void quicksort(int arr[],int low,int high)
{
	int q;
	if (low < high) {
		q = hoare_partition(arr,low,high);
		quicksort(arr,low,q);
		quicksort(arr,q+1,high);
	}
}

void swap(int arr[],int i,int j);

int hoare_partition(int arr[],int low,int high)
{
	int pivot = arr[low];
	int i = low - 1;
	int j = high + 1;
	while (1) {
		
		do {
			j--;
		} while(arr[j] > pivot);
		
		do {
			i++;
		} while(arr[i] < pivot);
		
		if (i < j) {
			swap(arr,i,j);
		} else {
			return j;
		}
	}
			
}

void swap(int a[],int i,int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
		

