#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a,int b)
{
	return (a>b)?a:b;
}

int lcs(char *x,char *y,int m,int n)
{
	int dp[m+1][n+1];
	for (int i = 0; i <= m; i++)
		dp[i][0] = 0;
	for (int i = 0; i <= n; i++)
		dp[0][i] = 0;
	
	
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (x[i-1] == y[j-1]) {
				dp[i][j] = 1 + dp[i-1][j-1];
			} else {
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	return dp[m][n];
	
}
int main(int argc, char **argv)
{
	char x[] = "ABCBDAB";
	char y[] = "BDCABA";
	printf("x is %s\ny is %s\n",x,y);
	printf("Length of longest common subsequence is %d\n",lcs(x,y,strlen(x),strlen(y)));
	return 0;
}
