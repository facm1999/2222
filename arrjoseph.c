#include <stdio.h>
//先初始化两个数组，一个用来存放用户密码，一个用来存放是否被遍历的状态;
int data[30];			       //因为可以假设用户数小于30；
int status[30] = {0};           //即未出列时为0，出列时数值为第几个出列；

//将密码存入数组
void credata(int n) //n为用户人数 
{
	int m;
	printf("请分别输入用户的密码：\n");
	for (int i = 0; i < n; i++) 
	{
		fflush(stdin);
		scanf_s("%d", &m);
		data[i] = m;
	}
}

//执行出列操作
void dedata(int m,int n) ///m为初始m值 ,n为用户人数
{
	int index=-1; //用来定义开始循环的下标；
	int count = 0; //记录第几个出列;
	while (count < n)
	{
		int i = 0;
		while (1)
		{	
			index = (index + 1) % n;   //让index保持在n内；
			if (status[index] == 0)
			{
				i++;                  //只有当状态为0，即为出列的数才能增加i的值。
			}
			if (i == m)
			{
				++count;
				status[index] = count;
				m = data[index];
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++)  //依次输出出列的用户的位置
	{
		for (int j = 0; j < n; j++)
			if (status[j] == i)
				printf("%d",j+1);
				printf(" ");
	}
}


//主函数
int main() 
{
	int m, n;
	printf("请输入初始m:");
	fflush(stdin);
	scanf_s("%d", &m);
	printf("请输入用户个数：");
	fflush(stdin);
	scanf_s("%d", &n);
	credata(n);
	dedata(m, n);
	return 0;
}