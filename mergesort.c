#include <stdio.h>
#include <stdlib.h>

void merge_sort(int arr[],int p,int r);
int main(int argc, char **argv)
{
	int a[] = {11,2,22,3,33,8,5,3,7,1};
	int len = sizeof(a)/sizeof(a[0]);
	int i;
	
	printf("The elements of the array before merge sort.\n");
	for (i = 0; i < len; i++) {
		printf("%d\n",a[i]);
	}
	
	printf("Initiating merge sort on array\n");
	merge_sort(a,0,len-1);
	
	printf("The elements of the array after merge sort.\n");
	for (i = 0; i < len; i++) {
		printf("%d\n",a[i]);
	}
	
	return 0;
}

void merge(int a[],int p,int q,int r);

void merge_sort(int arr[],int p,int r)
{
	if (p < r) {
		int q = (int)((p+r)/2);
		merge_sort(arr,p,q);
		merge_sort(arr,q+1,r);
		merge(arr,p,q,r);
	}
}

void merge(int a[],int p,int q,int r)
{
	int n1,n2;
	
	n1 = q - p + 1;
	n2 = r - q;
	
	int L[n1];
	int R[n2];
	
	for (int i = 0; i < n1; i++)
		L[i] = a[p+i];
	
	for (int j = 0; j < n2; j++)
		R[j] = a[q+j+1];
		
	int i = 0;
	int j = 0;
	int k = p;
	
	while ( i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			a[k] = L[i];
			i++;
		} else {
			a[k] = R[j];
			j++;
		}
		k++;
	}
	
	while ( i < n1 ) {
		a[k] = L[i];
		i++;
		k++;
	}
	
	while (j < n2) {
		a[k] = R[j];
		j++;
		k++;
	}
} 
			
			
			
			
			
			
			
			
			
			























