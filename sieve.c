//时间复杂度O(nln(ln(n)))
//空间复杂度O(n)
//termux 最大可以计算 2^32 ÷ 2 - 2 = 2147483646 以内的素数
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
void sievePrime(n) {
	unsigned long cnt = 0;
	char* a = malloc(sizeof *a * (n + 1));
	memset((void*)a, 1, (n + 1));
	unsigned long rt = sqrt(n);
	clock_t start, stop;
        start = clock();
	for(unsigned long i = 2; i <= rt; i++) {
		//cnt++;
		if(!a[i]) continue;
		for(unsigned long j = i * i; j <= n; j += i) 
		{
			//输出多少个零则有多少个数被重复筛选，需要进一步优化，保证每个数只被筛选一
			//printf("%hhu\n",a[j]);
			a[j] = 0;
			//cnt++;
		}
	}
	stop = clock();
	double duration = (double)(stop - start) / CLOCKS_PER_SEC;
	//printf("%d\n",2);
	for(unsigned long k = 3; k <= n; k += 2)
	{
		//if(a[k])
		if(k > n - 100 && a[k])
			printf("%lu\n",k);
	}
	//printf("calc times: %lu\n", cnt);
        printf("duration: %f ms\n", duration * 1000);
	free(a);
}
int main()
{
	unsigned long n = 0;
	scanf("%lu",&n);
	sievePrime(n);
	return 0;
}
