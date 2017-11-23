#include <stdio.h>
#include <stdlib.h>

void heapsort(int arr[],int n);

int main(int argc, char **argv)
{
	
	int a[] = {11,2,22,3,33,8,5,3,7,1};
	int len = sizeof(a)/sizeof(a[0]);
	int i;
	
	printf("The elements of the array before heap sort.\n");
	for (i = 0; i < len; i++) {
		printf("%d\n",a[i]);
	}
	
	printf("Initiating heap sort on array\n");
	heapsort(a,len);
	
	printf("The elements of the array after heap sort.\n");
	for (i = 0; i < len; i++) {
		printf("%d\n",a[i]);
	}
	
	return 0;
}

void max_heapify(int arr[],int n,int i);
void swap(int arr[],int i,int j); // helper function for swapping 
								  // of elements of array.

void heapsort(int arr[],int n)
{
	// Building max heap
	for (int i = (n-1)/2; i >= 0; i--) {
		max_heapify(arr,n,i);
	}
	
	for (int i = n-1; i > 0; i--) {
		swap(arr,i,0);
		max_heapify(arr,i,0);
	}
}

void max_heapify(int arr[],int n, int i)
{
	int largest;
	int l,r;
	while (i < n) {
		l = (i<<1) + 1;
		r = (i+1) << 1;
	
		if ( l < n && arr[l] > arr[i]) {
			largest = l;
		} else {
			largest = i;
		}
	
		if ( r < n && arr[r] > arr[largest]) {
			largest = r;
		}
	
		if (largest != i) {
			swap(arr,largest,i);
			i = largest;
		} else {
			break;
		}
	}
}

void swap(int arr[],int i,int j)
{
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
	
	
