#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int arr[],int low,int high);

int main(int argc, char **argv)
{
	int a[] = {11,2,22,3,33,8,5,3,7,1};
	int len = sizeof(a)/sizeof(a[0]);
	int i;
	
	printf("The elements of the array before quicksort.\n");
	for (i = 0; i < len; i++) {
		printf("%d\n",a[i]);
	}
	
	printf("Initiating quicksort on array\n");
	quicksort(a,0,len-1);
	
	printf("The elements of the array after quicksort.\n");
	for (i = 0; i < len; i++) {
		printf("%d\n",a[i]);
	}
	
	return 0;
}


int randomized_partition(int arr[],int low,int high);

void quicksort(int arr[],int low,int high)
{
	int q;
	if (low < high) {
		q = randomized_partition(arr,low,high);
		quicksort(arr,low,q-1);
		quicksort(arr,q+1,high);
	}
}
int partition(int arr[],int low,int high);
void swap(int arr[],int i,int j);

int randomized_partition(int arr[],int low,int high)
{
	srand(time(NULL));
	int i = rand()%(high-low) + low;
	swap(arr,i,high);
	return partition(arr,low,high);
		
}

int partition(int arr[],int low,int high)
{
	int pivot = arr[high];
	int i = low - 1;
	
	for (int j = low; j < high; j++) {
		
		if (arr[j] <= pivot) {
			i++;
			swap(arr,i,j);
		}
	}
	swap(arr,i+1,high);
	return i+1;
}

void swap(int a[],int i,int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
	

