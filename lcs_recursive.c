#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a,int b)
{
	return (a>b)?a:b;
}

int lcs_recursive(char *x,char *y,int m,int n)
{
	if (m == 0 || n == 0) {
		return 0;
	} else if (x[m-1] == y[n-1]) {
		return 1 + lcs_recursive(x,y,m-1,n-1);
	} else {
		return max(lcs_recursive(x,y,m-1,n),lcs_recursive(x,y,m,n-1));
	}
}
int main(int argc, char **argv)
{
	char x[] = "ABCBDAB";
	char y[] = "BDCABA";
	printf("x is %s\ny is %s\n",x,y);
	printf("Length of longest common subsequence is %d\n",lcs_recursive(x,y,strlen(x),strlen(y)));
	return 0;
}

