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
//一个二进制数1100，从右边数起第三位是处于最右边的一个1。减去1后，第三位变成0，它后面的两位0变成了1，
//而前面的1保持不变，因此得到的结果是1011.我们发现减1的结果是把最右边的一个1开始的所有位都取反了。
//这个时候如果我们再把原来的整数和减去1之后的结果做与运算，从原来整数最右边一个1那一位开始所有位都会变成0。
//如1100&1011=1000.也就是说，把一个整数减去1，再和原整数做与运算，会把该整数最右边一个1变成0.
//那么一个整数的二进制有多少个1，就可以进行多少次这样的操作。
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

