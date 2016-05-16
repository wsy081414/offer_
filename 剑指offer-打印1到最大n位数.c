#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int Increment(char *num)
{
	int isOverflow = 0;
	int len = strlen(num);
	int i;

	
	for (i = 0; i<len; i++)
		num[i] = num[i] - '0';

	num[len - 1]++;
	for (i = len - 1; i >= 0; i--)
	{
		if (num[i] >= 10)
		{
			if (i == 0)
			{	
				isOverflow = 1;
				num[i]--;
			}
			else
			{
				num[i] -= 10;
				num[i - 1] += 1;
			}
		}
		else
			break;
	}


	for (i = 0; i<len; i++)
		num[i] = num[i] + '0';

	return isOverflow;

}
void Print_n(int n)
{
	if (n <= 0)
		return;

	char *num = (char *)malloc((n + 1)*sizeof(char));
	if (num == NULL)
		exit(EXIT_FAILURE);
	memset(num, '0', n*sizeof(char));
	num[n] = '\0';
	while (!Increment(num))
	{
		int i = 0;
		while (num[i] == '0')
			i++;
		printf("%s\n", num + i);

	}

	free(num);
	num = NULL;
}

int main()
{
	int n;
	printf("ÇëÊäÈën£º");
	scanf("%d", &n);
	Print_n(n);
	system("pause");
	return 0;
}