#include <stdio.h>
#include <stdlib.h>

int max(int a,int b)
{
	return (a>b)?a:b;
}
int rod_cut_recursive(int price[],int n)
{
	if (n  <= 0)
		return 0;
		
	int q = -1;
	
	for (int i = 0; i < n; i++) {
		q = max(q,price[i] + rod_cut_recursive(price,n-i-1));
	}
	return q;
}

int main(int argc, char **argv)
{
	int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	printf("Maximum obtainable value is %d\n",rod_cut_recursive(arr,size));
	return 0;
}

