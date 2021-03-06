// shipfee.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	ifstream input("input.txt");
	ofstream output("output.txt");
	int n;
	int m[200][200] = { 0 };                           //初始化数组
	input >> n;                                        //读取文件
	for (int i = 1; i <= n - 1; i++)                  //初始化，将所有r(i,j)都先存在数组m中
	{
		for (int j = i + 1; j <= n; j++)
		{
			input >> m[i][j];
		}
	}
	input.close();
	for (int r = 2; r <= n; r++)                 //从长度为 2 的开始找最优解（比如说从 1 到 2 就是长度为 2的），直到找到长度为 n 的
	{
		for (int i = 1; i <= n - r + 1; i++)
		{
			int j = i + r - 1;                  // 遭到对应的j；
			for (int k = i; k <= j; k++)        //循环找k，使得r（i，k）+r(k,j)最小;
			{
				int z = m[i][k] + m[k][j];
				if (z < m[i][j])
				{
					m[i][j] = z;                //用较优的解替换原来的r(i,j)
				}
			}
		}
	}
	output << m[1][n] << endl;
	cout << m[1][n] << endl;
	output.close();
	return 0;
}
