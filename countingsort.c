#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void countingsort(char arr[]) 
// for sorting string with lower case character.
{
	char output[strlen(arr)];
	
	int count[256] = {0};
	int i;
	
	for (i = 0; arr[i]; i++) {
		count[(int)arr[i]]++;
		//calculating the frequency of each element.
		// for any character x subracting 'a' will bring it in range 
		// of [0,25].
	}
	
	//calculating the cummulative frequency of each element.
	for (i = 1; i < 256; i++) {
		count[i] += count[i-1];
	}
	
	//building the output array
	for(i = 0; arr[i]; i++) {
		output[count[(int)arr[i]]-1] = arr[i];
		count[(int)arr[i]]--;
	}
	//copying back the sorted string to array.
	for (i = 0; arr[i]; i++) {
		arr[i] = output[i];
	}
	
}

int main(int argc, char **argv)
{
	char arr[] = "chandrakantsharma";
	printf("Before applying counting sort on string.\n%s",arr);
	countingsort(arr);
	printf("\nAfter counting sort, the string is\n%s",arr);
	return 0;
}

