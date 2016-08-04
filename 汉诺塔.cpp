#include<cstdlib>
#include<iostream>


//汉诺塔，看错最简洁的方式进行操作，
//递归，就是看作一个和另一个，进行递归的操作就可以了
//递归的精髓就是我每一步都要依赖上面的一步

//f(n)=2^n-1
int cout = 0;
void hannuo(int m,char a,char b,char c)
{
	if (m < 1)
	{
		return;
	}
	else
	{
		hannuo(m - 1, a, c, b);
		cout++;
		std::cout << a << "->" << c << std::endl;
		hannuo(m - 1, b, a, c);	
	}	
}
int main()
{
	int m(0);
	std::cout << "输入汉诺塔层数" << std::endl;
	std::cin >> m;
	hannuo(m,'a','b','c');
	std::cout << "共移动次数："<<cout << std::endl;
	system("pause");
	return 0;
}
