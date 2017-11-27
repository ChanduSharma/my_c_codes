#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min(int a,int b)
{
	return (a<b)?a:b;
}
int mat_mul_rec(int p[],int i,int j)
{
	int q = INT_MAX;
	if (i == j)
		return 0;
	
	for (int k = i; k < j; k++) {
		q = min(q,mat_mul_rec(p,i,k) + mat_mul_rec(p,k+1,j) + p[i-1]*p[k]*p[j]);
	}
	return q;
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr)/sizeof(arr[0]);
 
    printf("Minimum number of multiplications is %d\n",mat_mul_rec(arr,1,size-1));
    return 0;
}
