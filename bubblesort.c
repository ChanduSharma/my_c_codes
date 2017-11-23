#include <stdio.h>
#include <stdlib.h>

void swap(int arr[],int i,int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void bubblesort(int arr[],int n)
{
	int i,j;
	
	for (i = 0; i < n ; i++) {
		for (j = 0 ; j < n-i-1; j++) {
			if (arr[j] > arr[j+1]) {
				swap(arr,j,j+1);
			}
		}
	} 
}
int main(int argc, char **argv)
{
	int a[] = {11,2,22,3,33,8,5,3,7,1};
	int len = sizeof(a)/sizeof(a[0]);
	int i;
	
	printf("The elements of the array before bubblesort.\n");
	for (i = 0; i < len; i++) {
		printf("%d\n",a[i]);
	}
	
	printf("Initiating bubblesort on array\n");
	bubblesort(a,len);
	
	printf("The elements of the array after bubblesort.\n");
	for (i = 0; i < len; i++) {
		printf("%d\n",a[i]);
	}
	
	return 0;
}

