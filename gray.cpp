// midnum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include<math.h> 
using namespace std;
void getGray(int **arr, int n, int row)
{
	if (n == 1)                           //结束标志  
	{
 		arr[0][n - 1] = 0;
		arr[1][n - 1] = 1;
		return;
	}

	for (int i = 0; i < row / 2; i++)
	{
		arr[i][n - 1] = 0;	             //上半部分赋值为0
		arr[row - i - 1][n - 1] = 1; 	//下半部分赋值为1
	}

	getGray(arr, n - 1, row / 2);      //递归调用

	for (int j = row / 2; j < row; j++)         //对称地补满
	{
		for (int k = 0; k < n - 1; k++)
		{
			arr[j][k] = arr[row - j - 1][k];
		}
	}
	return;
}

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n = 0;         
	in >> n;                            //文件内容
	if (n == 0 || n > 20)
	{
		cout << "输入错误" << endl;
		return 0;
	}

	int row = pow(2, n);
	int **arr = new int*[row];        //声明二维数组
	for (int m = 0; m < row; m++)
	{
		arr[m] = new int[n];
	}
	//调用递归函数 
	getGray(arr, n, row);
	//输出 
	for (int i = 0; i < row; i++) 
	{
		for (int j = n - 1; j >= 0; j--) 
		{
			cout << arr[i][j]<<' ';
			out << arr[i][j]<<' ';
		}
		cout << endl;
		out << "\n";
	}
	return 0;
}


