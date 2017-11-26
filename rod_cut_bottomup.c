#include <stdio.h>
#include <stdlib.h>
int max(int a,int b)
{
	return (a>b)?a:b;
}
int rod_cut(int price[],int n)
{
	int dp[n+1];
	int q;
	
	for (int i = 1; i <= n; i++) {
		q = -1;
		for (int j = 0; j < i; j++) {
			q = max(q,price[j] + dp[i-j-1]);
		}
		dp[i] = q;
	}
	return dp[n];
}

int main(int argc, char **argv)
{
	int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	printf("Maximum obtainable value is %d\n",rod_cut(arr,size));
	return 0;
}
