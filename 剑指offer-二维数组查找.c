//面试题3：二位数组中的查找 
//当我们需要解决一个复杂问题时，一个很有效的方法就是从具体的问题出手，通过分析具体的例子，得到规律。 
//再一个二维数组中，每一行都要按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排列。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        //得到行的size
        int row = array[0].size();
        int column = array.size();

        //给出一个边界信息
        int i = 0, j = row - 1;

        //While循环情况限制，
        while (i < column && j >= 0) {
            //如果target小于边界数组值，这个时候就在这个位置之前找
            if (target < array[i][j]) {
                j--;
            ////如果target大于边界数组值，这个时候就在这个位置下一行找
            } else if (target > array[i][j]) {
                i++;
            } else {
                return true;
            }
        }
        return false;
    }
};
#include<stdio.h>
#include<stdlib.h>
int find_arr(int arr[][3], int rows, int cols, int num)
{
    if (arr != NULL&& rows > 0 && cols > 0)
    {
        int row = 0;
        int col = cols - 1;
        while (row < rows&&col >= 0)
        {
            if (arr[row][col] == num)
            {
                return 1;
            }
            else if (arr[row][col]>num)
                row--;
            else
                col++;
        }
    }
    return 0;
}
int main()
{
    int arr[][3] = { 1, 2, 3, 2, 3, 4, 5, 6, 7 };
    int num = 0;
    printf("请输入你所要查找的元素：");
    scanf("%d", &num);
    int ret=find_arr(arr,3,3,num);
    if (ret == 0)
        printf("没有找到%d", num);
    else
        printf("存在元素%d", num);
    system("pause");
    return 0;
}