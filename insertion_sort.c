#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int a[],int n);
void print_array(int a[],int n);

int main(int argc, char **argv)
{
	int dummy_array[] = {7,6,5,4,3,2,1}; 
	//A dummy array to show usage of insertion sort.
	
	int length_of_array = sizeof(dummy_array)/sizeof(dummy_array[0]);
	
	print_array(dummy_array,length_of_array);
	
	insertion_sort(dummy_array,length_of_array);
	
	print_array(dummy_array,length_of_array);
	
	return 0;
}

void print_array(int a[],int n)
{
	for (int i = 0; i < n; i++) {
		printf("%d\n",a[i]);
	}
	printf("\n");
}

void insertion_sort(int a[],int n)
{
	int i,key;
	
	for (int j = 1; j < n; j++){
		key = a[j];
		i = j-1;
		while (i >= 0 && a[i] > key) {
			a[i+1] = a[i];
			i = i-1;
		}
		a[i+1] = key;
	}
	
}	
