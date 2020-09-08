#include<stdio.h>
#include<stdlib.h>
int main() {
	char* a = malloc(sizeof *a * 10);
	memset((void*)a, 1, 10);
	for(int i = 0; i < 10; i++)
		printf("%hhu\n", a[i]);
	free(a);
	return 0;
}
