#define _CRT_SECURE_NO_WARNINGS 1
/*Interview questions 10: the number of binary in 1
Title: please implement a function, enter an integer, the output of the number of binary representation of the number of 1. 
For example, 9 is represented as binary is 1001, there are 2 is 1, so if you enter 9, the function output 2*/


//The first method, when the input negative number, will appear dead circulation problem

#include<stdio.h>
#include<stdlib.h>
int count_one_bits(int value)
{
	int count = 0;
	while (value)
	{
		if (value &1)
		{
			count++;
		}
		value = value >> 1;
	}
	return count;
}
int main()
{
	int num;
	int ret;
	printf("Please enter a number greater than 0\n");
	scanf("%d", &num);
	ret = count_one_bits(num);
	printf("%d", ret);
	system("pause");
	return 0;
}

/*The second method, the a integer minus 1, and original integer and operation, 
to the integer is the rightmost a 1 to a 0. So a integer binary number 1, you can many times this operation. 
Finally, the counter to determine the number of operations, the counter outputs.*/

#include<stdio.h>
#include<stdlib.h>
int count_one_bits(unsigned int value)
{
    int count = 0;
    while (value)
    {
        value = value&(value - 1);
        count++;

    }
    return count;
}
int main()
{
    int num;
    int ret;
    printf("Please enter a number greater than 0\n");
    scanf("%d", &num);
    ret = count_one_bits(num);
    printf("%d", ret);
    system("pause");
    return 0;
}

