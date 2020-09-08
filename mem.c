#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main() {
	unsigned long lu = 18446744073709551615lu;
	long l = 9223372036854775807l;
	printf("%lu\n", lu);
	printf("%ld\n", l);
	printf("%lu\n",sizeof(long));
	unsigned long* a = malloc(sizeof *a * 10);
	memset(a, 0, sizeof(unsigned long) * 10);
	for(int i = 0; i < 10; i++)
	{
		if(i > 4) a[i] = 1;
		printf("%lu\n", a[i]);
	}
	free(a);
	return 0;
}
