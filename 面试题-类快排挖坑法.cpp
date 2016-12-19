/*对一个数组按照给定的下标进行排序，仅仅使用两两交换的方式，要求不能对数组进行扩容，尽可能少的额外空间。

如：原数组为A,B,C,D,E，现在给定的新位置为3，0，1，4，2，那么排序后为D,A,B,E,C,*/





//这道题采用一种类似快速排序的挖坑的方法进行。


void SwapSort(int *pArr, int *pPos, int n)
{
	assert(pArr);
	assert(pPos);
	int tmp = pArr[0];
	int i = 0;
	for (int j = 0; j < n; )
	{
		if (pPos[i] != i)
		{
			tmp = pArr[i];
			int prevpos = i;
			while (1)
			{
				pArr[i] = pArr[pPos[i]];
				i = pPos[i];
				j++;
				if (prevpos == pPos[i])
				{
					pArr[i] = tmp;
					i = prevpos + 1;
					j++;
					break;
				}
			}		
		}
		else
		{
			i++;
			j++;
		}
	}

}



void swapsort(int *parr, int *ppos, int n)
{
	assert(parr);
	assert(ppos);
	int tmp = parr[0];
	int i = 0;
	for (int j = 0; j < n;)
	{

		while (i == ppos[i])
		{
			i++;							//相等，说明就在正确的位置上，这个时候，只需要调整向后，知道找到下一个非正确位置。
			j++;
		}
		//当全部填充后，可以考虑跳出
		if (i >= n)
			break;

		if (ppos[i] != i)
		{
			tmp = parr[i];				//选坑
			int prevpos = i;			//记录前面的i
			while (1)
			{
				parr[i] = parr[ppos[i]];		//填坑
				int newpos = ppos[i];			//寻找下一个pos
				ppos[i] = i;							//修正原来的pos
				i = newpos;						//调整至新节点
				j++;
				if (prevpos == ppos[i])		//查看新点的pos是否和前一个点的i相同，如果相同，就出现了循环的问题。
				{
					parr[i] = tmp;
					ppos[i] = i;						//修正pos
					i = prevpos + 1;				//移动至前一个的下一个
					j++;
					break;
				}
			}
		}
		
	}

}
void test1()
{
	int pArr[] = { 'A', 'B', 'C', 'D', 'E' };
	int pPos[] = { 3, 0, 1, 4, 2 };
	SwapSort(pArr, pPos, sizeof(pArr) / sizeof(pArr[0]));
	for (int i = 0; i<sizeof(pArr) / sizeof(pArr[0]); ++i)
	{
		printf("%c  ",pArr[i]);
	}
	cout << endl;
}

int main()
{
	test1();
	system("pause");
	return 0;
}