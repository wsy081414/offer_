//面试题40：

//题目：一个整形数组里出了两个数字之外，其他的数字都出现了两次。请从程序中找出这两个只出现一次的数字。要求时间的复杂度为O(n)，空间复杂度是O(1)。
//
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
int judge_1(int n, int bit)
{
    n = n >> bit;
    return (n & 1);

}
void find_number( char* arr, int sz, int *num1, int* num2)
{
    int bit = 0;
    assert(arr);
    int ret = 0;

    int i = 0;
    int j = 0;
    for (i = 0; i < sz; i++)
        ret = ret^arr[i];
    while (((ret & 1) == 0)&&(bit < 32))//在这里我们来寻找最右边是1的位。
    {

            ret >>= 1;
            bit++;

    }
    *num1 = *num2 = 0;

    for (j = 0; j < sz; j++)
    {
        if (judge_1(arr[j], bit))//这里判断从右边数起你的bit那一位是不是1
        {
            *num1 ^= arr[j];//将是1的异或得出结果
        }
        else
            *num2 ^= arr[j];//将不是1的异或得出结果
    }
}


int main()
{
    int num1 = 0;
    int num2 = 0;
    char arr[] = { 0,1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    find_number(arr,sz,&num1,&num2);
    printf("%d,%d", num1, num2);
    system("pause");
    return 0;
}
