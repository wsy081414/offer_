
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
void revolve_left1(char str[], int k)//第一种方法
{
	assert(str);
	int len = strlen(str);//求得字符串的长度
	char tmp = 0;//用来保存你要移位的字符
	if (k < len)
	{
		for (int i = 0; i < k; i++)
		{
			tmp = str[0];
			for (int j = 0; j < len - 1; j++)
			{
				str[j] = str[j + 1];//对后面的字符串向前移位，
			}
			str[len - 1] = tmp;//把第一个字符放到最后的位置
		}
	}
	else
	{
		exit(1);
	}
}
void reverse(char *left,char *right)
{
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;

	}
}
void revolve_left(char *str, int k)//第二种方法
{
	int len = strlen(str);
	assert(str);
	if (k<len&&k>0 && len > 0)
	{
		reverse(str, str + k - 1);
		reverse(str + k, str + len - 1);
		reverse(str, str + len - 1);
	}
}
int main()
{
	char str[] = "abcdefg";
	int k = 0;
	printf("输入你所需要旋转的字符个数：");
	scanf("%d", &k);
	revolve_left(str, k);
	printf("%s\n", str);
	system("pause");
	return 0;
}