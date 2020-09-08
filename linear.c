//时间复杂度O(2n)
//空间复杂度O(2n)
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void linearPrime(n) {
	//初始化两个长度为n的数组填入0表示都是素数
	unsigned long* a = malloc(sizeof *a * (n + 1));
	if(NULL==a)
	{
		printf("a.malloc...memory...error...");
	}
	memset(a, 0, sizeof *a * (n + 1));
	unsigned long* p = malloc(sizeof *p * (n + 1));
	if(NULL==p)
	{
		printf("p.malloc...memory...error...");
	}
	memset(p, 0, sizeof *p * (n + 1));
	unsigned long cnt = 0;
	clock_t start, stop;
	start = clock();
	//遍历2到n
    	for (unsigned long i = 2;i <= n; i++) {
		//cnt++;
		//如果a[i]=0则a[i]是素数，
        	if (!a[i]) {
			//p[0]+1纪录素数， p[0] 相当于 cnt，用来计数
			//把i赋值给p[1]，第一轮p[0]=1，p[1]=2
            		p[++p[0]] = i;      
        	}
		//当j小于等于已记录的素数个数且i平方小于n，j加1，也就是遍历筛选素数的所有倍数
        	for (unsigned long j = 1; j <= p[0] && i * p[j] <= n; j++) {
			//cnt++;
			//素数p[j]的倍数都不是素数，标记为1
            		a[i * p[j]] = 1;
			//如果i除以最小的素数p[j]余数为零立刻退出筛选循环
            		if (i % p[j] == 0) {
                		break;
            		}	
        	}
    	}
	stop = clock();
	double duration = (double)(stop - start) / CLOCKS_PER_SEC;
	//p[0] = 0;
	/*for(unsigned long k = 0; k <= n; k++) 
	{
		if(p[k] > 0)
			printf("%lu\n",p[k]);
	}*/
	printf("primes: %lu\n",p[0]);
	//printf("calc times: %lu\n",cnt);
	printf("duration: %f ms\n", duration * 1000);
	free(a);
	free(p);
}
int main()
{
	unsigned long n = 0;
	scanf("%lu",&n);
	linearPrime(n);
	return 0;

}
