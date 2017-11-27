#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min(int a,int b)
{
	return (a<b)?a:b;
}
int mat_mul_rec(int p[],int n)
{
	int dp[n][n];
	int j;
	for (int i = 1; i < n; i++)
		dp[i][i] = 0;
	
	for (int l = 2; l < n; l++) {
		for (int i = 1; i < n-l+1; i++) {
			
			j = i + l -1;
			dp[i][j] = INT_MAX;
			
			for (int k = i; k < j; k++) {
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j]);
			}
		}
	}
	return dp[1][n-1];
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr)/sizeof(arr[0]);
 
    printf("Minimum number of multiplications is %d\n",mat_mul_rec(arr,size));
    return 0;
}
