
#include<stdio.h>
#include<stdlib.h>

long long transform(char *str)
{
	int flag = 1;
	int num = 0;
	int radix = 0;
	//判断空字符串
	if (str == NULL)
	{
		return 0;
	}
	//判断空格问题
	while (*str==' '||*str=='\t')
	{
		str++;
	}

	//-情况
	if (*str == '-')
	{
		flag = -1;
		str++;
	}
	//+情况
	else if (*str=='+')
	{
		str++;
	}

	//考虑进制的问题
	if (*str == '0' && (*(str + 1) == 'X' || *(str + 1) == 'x'))//十六进制
	{
		radix = 16;
		str += 2;
	}else if(*str == '0')//八进制
	{
		radix  = 8;
		str++;
	}else //十进制
	{
		radix = 10;
	}
	while (*str)
	{
		if (radix == 16)
		{
			if (*str >= '0' && *str < '9')
			{
				num = num*radix + (*str - '0');//处理十六进制0-9
			}
			else
			{
				num = num*radix + (*str - 'a' + 10);//处理a-f
			}
		}
		else
		{
			num = num*radix + (*str - '0');
		}
		str++;
	}
	return num*flag;
}
int main()
{

	char *str = "45678";
	long long ret = 0;
	ret=transform(str);
	printf("%ld", ret);
	system("pause");
	return 0;
}