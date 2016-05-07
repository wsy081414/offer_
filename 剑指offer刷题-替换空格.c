//面试题4：替换空格 
//请实现一个函数，把字符串中的每个空格替换成为“%20”.例如输入“We are happy”,则输出“We%20are%20happy”
//
//
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void Replace(char arr[])
{
	int len = strlen(arr);
	int count = 0;

	char *p = arr;
	int old_end = len;
	int new_end = 0;
	while (*p)
	{
		if (*p == ' ')
		{
			count++;
		}
		p++;
	}	
	new_end = len + 2 * count;

	while (old_end < new_end)
	{
		if (arr[old_end] == ' ')
		{
			old_end--;
			arr[new_end--] = '0';
			arr[new_end--] = '2';
			arr[new_end--] = '%';
		}
		else
		{
			arr[new_end--] = arr[old_end--];
		}
	}
}
int main()
{
	char str[20] = "we are happy";
	Replace(str);
	printf("%s\n", str);
	system("pause");
	return 0;
}