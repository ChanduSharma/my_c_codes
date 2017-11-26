#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define m 100
#define n 100
int dp[m][n];

int max(int a,int b)
{
	return (a>b)?a:b;
}

int lcs_aux(char *x,char *y,int i,int j)
{
	if (dp[i][j] >= 0) {
		
		return dp[i][j];
	} 
	
	if (i == 0 || j == 0) {
		
		return 0;
		
	}
	
	if (x[i-1] == y[j-1]) {
		
		dp[i][j] = 1 + lcs_aux(x,y,i-1,j-1);
	
	} else {
		
		dp[i][j] = max(lcs_aux(x,y,i-1,j),lcs_aux(x,y,i,j-1));
	}
	return dp[i][j];
}

int lcs_memoized(char x[],char y[],int a,int b)
{
	for (int i = 0; i <= a; i++) {
		for (int j = 0; j <= b; j++) {
			dp[i][j] = -1;
		}
	}
	return lcs_aux(x,y,a,b);
}


int main(int argc, char **argv)
{
	char x[] = "ABCBDABE";
	char y[] = "BDCABAEF";
	printf("x is %s\ny is %s\n",x,y);
	printf("Length of longest common subsequence is %d\n",lcs_memoized(x,y,strlen(x),strlen(y)));
	return 0;
}

