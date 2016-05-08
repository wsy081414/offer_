

#include<stdio.h>
#include<stdlib.h>

//递归算法
long long fib(unsigned int n)
{
	if (n == 1)
		return 1;
	else if (n <= 0)
		return 0;
	else
		return fib(n - 1) + fib(n - 2);	//递归，
}
//非递归算法
long long fib_2(unsigned int n)
{

	long long fib1 = 1;
	long long fib2 = 0;
	unsigned int i = 0;
	for (i = 0; i < n ; i++)
	{
		fib1 = fib1 + fib2;//在这里进行一个算法，首先fib1成了你给的前两个的和。并且赋给了第一个数，这里的第一项数就是下一次计算中的fib1。
		fib2 = fib1 - fib2;//这里是对你所需要的数进行计算，在这里更新的fib1减去fib2就是新的第二项数
	}
	return fib2;

}
int main()
{
	unsigned int n = 0;
	long long ret = 0;
	printf("Please give the first few items:\n");
	scanf("%u", &n);
	ret = fib(n);
	printf("%lld\n", ret);
	system("pause");
	return 0;
}
