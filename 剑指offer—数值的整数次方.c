#define _CRT_SECURE_NO_WARNINGS 1
//面试题10：二进制中1的个数 
//题目：请实现一个函数，输入一个整数，输出该数二进制表示1的个数。例如把9表示成二进制是1001，有2位是1。因此如果输入9，该函数输出2。

//第一种，最简单的思路，不考虑边界问题。。。
#include<stdio.h>
#include<stdlib.h>
double Power(double base, int exponent)
{
	double ret = 1;
	if (exponent > 0)
	{
		while (exponent)
		{
			ret *= base;
			exponent--;
		}
	}
	else if (exponent < 0)
	{
		exponent = (unsigned int)(-exponent);
		while (exponent)
		{
			ret *= base;
			exponent--;
		}
		ret = 1 / ret;
	}
	else
		ret = 1;
	return ret;
}
int main()
{
	double base = 0;
	int exponent = 0;
	double ret = 0;
	printf("please enter a base number:");
	scanf("%lf", &base);
	printf("please enter a exponent number:");
	scanf("%d",&exponent);
	ret=Power(base, exponent);
	printf("%lf", ret);
	system("pause");
	return 0;
}
//考虑所有边界问题，优化一：
#include<stdio.h>
#include<stdlib.h>
#define EPSINON 0.0000000001
double Power(double base, int exponent)
{
	double ret = 1;
	if (((base -0.0)>-EPSINON)&&(base-0.0)<EPSINON)
	{
		if (exponent >= 0)
		{
			ret = 0;
			return ret;
		}
		else
			return -1; 
	}
	if (exponent > 0)
	{
		while (exponent)
		{
			ret *= base;
			exponent--;
		}
	}
	else if (exponent < 0)
	{
		exponent = (unsigned int)(-exponent);
		while (exponent)
		{
			ret *= base;
			exponent--;
		}
		ret = 1.0 / ret;
	}
	else
		ret = 1;
	return ret;
}
int main()
{
	double base = 0;
	int exponent = 0;
	double ret = 0;
	printf("please enter a base number:");
	scanf("%lf", &base);
	printf("please enter a exponent number:");
	scanf("%d", &exponent);
	ret = Power(base, exponent);
	printf("%lf", ret);
	system("pause");
	return 0;
}



//最终版本：注重效率的方法。优化二：
#include<stdlib.h>
#include<stdio.h>
#define EPSINON 0.0000000001

double PowerWithUnsignedExponent(double base, int exponent)
{
	if (exponent == 0)
		return 0;
	if (exponent == 1)
		return base;
	double result = PowerWithUnsignedExponent(base, (exponent >> 1));
	result *= result;
	if ((exponent & 0x1) == 1)
	{
		result *= base;
	}

	return result;
}
double Power(double base, int exponent)
{
	double ret = 1;
	if (((base - 0.0)>-EPSINON) && (base - 0.0)<EPSINON)
	{
		if (exponent >= 0)
		{
			ret = 0.0;
			return ret;
		}
		else
			return -1;
	}
	unsigned int absexponent = (unsigned int)(exponent);
	if (exponent < 0)
	{
		absexponent = (unsigned int)(-exponent);
	}
	ret = PowerWithUnsignedExponent(base, absexponent);
	if (exponent < 0)
	{
		ret = 1.0 / ret;
	}
	
	return ret;
}

int main()
{
	double base = 0;
	int exponent = 0;
	double ret = 0;
	printf("please enter a base number:");
	scanf("%lf", &base);
	printf("please enter a exponent number:");
	scanf("%d", &exponent);
	ret = Power(base, exponent);
	printf("%lf", ret);
	system("pause");
	return 0;
}