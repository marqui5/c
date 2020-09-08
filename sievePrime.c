//时间复杂度O(nln(ln(n)))
//空间复杂度O(n)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

int main ()
{
	unsigned long cnt = 0;
	unsigned long n;
	scanf("%lu",&n);
	char* p;
	unsigned long i,j;
	
	
	n=n+1;
	p=(char*)malloc(n);
	if(NULL==p)
	{
		printf("malloc...memory...error...");
		return 1;	
	}
	memset((void*)p,1,n);

	clock_t start, stop;                                              start = clock();
	for(i=4;i<n;i=i+2)
	{
		p[i]=0;
		//cnt++;
	}
	
	for(i=3;i<n;i=i+2)
	{
		if(!p[i])
		{
			continue;
		}
		for(j=2*i;j<n;j=j+i)
		{
			//printf("%hhu\n",p[j]);
			p[j]=0;
			//cnt++;
		}
	}
	stop = clock();                                                   double duration = (double)(stop - start) / CLOCKS_PER_SEC;
	
	printf("2\n");
	/*for(i=3;i<n;i=i+2)
	{
		if(p[i])
		{
			printf("%lu\n",i);
		}
	}*/
	//printf("calc times: %lu\n", cnt);
	printf("duration: %f ms\n", duration * 1000);
	free(p);
	
	return 0;
}
