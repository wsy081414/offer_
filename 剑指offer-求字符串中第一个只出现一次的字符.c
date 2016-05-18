

//在一个字符串当中找出第一个只出现一次的字符。

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define MAX_SIZE 256
char check_one_arr(const char *str)
{
	assert(str);
	unsigned int hash[MAX_SIZE] = { 0 };
	const char *p = str;
	while (*p!= '\0' )
	{
		hash[*p++]++;
	}
	p = str;
	while (*p !='\0')
	{
		if (hash[*p] == 1)
			return *p;
		p++;
	}

	return *str;


}
int main()
{
	char *arr = "aabbcchddee";
	char ret=check_one_arr(arr);
	printf("%c", ret);
	system("pause");
	return 0;

}