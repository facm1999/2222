#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
#include <stdlib.h>
//定义栈结构；
typedef struct stack 
{
	int top;               //栈顶的位置
	int cap;         //栈的容量
	int* arr;
}*Stack;
//初始化栈
Stack init(int cap) 
{
	Stack S = (Stack)malloc(sizeof(struct stack));
	if (!S)return NULL;
	S->top = -1;                           //栈空为-1，有一个元素为0，符合数组的定义
	S->cap = cap;
	int* array = (int*)malloc(cap * sizeof(int));
	if (!array)return NULL;
	S->arr = array;
}
//栈的一些函数
int isEmpty(Stack S) 
{
	return S->top == -1;
}
int getTOP(Stack S) 
{
	return S->arr[S->top];
}
int pop(Stack S) 
{
	if (isEmpty(S))return 0;
	return S->arr[S->top--];
}
void push(Stack S,int m) 
{
	if (S->top == S->cap - 1)exit(-1);
	S->arr[++S->top] = m;
}
//中缀表达式转化为后缀表达式
char res[100];                         //定义一个存储长度不大于100的算式表达式的数组
char* shift(char* exp) 
{
	int i, j;
	Stack S = init(strlen(exp));
	for (i=0,j = 0;i<strlen(exp); i++) 
	{
		if (isdigit(exp[i]))            //如果读取的数字就直接输出到res中；
		{
			res[j++] = exp[i];
		}
		else if (exp[i] == '(')      //如果是‘（’，就入栈
		{
			push(S, exp[i]);
		}
		else if (exp[i] == ')')      //如果是‘）’，就出栈
		{
			while (!isEmpty(S) && getTOP(S) != '(') 
			{
				res[j++] = ' ';    //空格避免对两个数字的影响
				res[j++] = pop(S);
			}
			if (isEmpty(S)) 
			{
				return -1;
			}
			else 
			{
				pop(S);         //把‘（’也出栈
			}
		}
		else                 //对操作符的操作
		{
			while (!isEmpty(S) && Pri(exp[i]) <= Pri(getTOP(S))) 
			{
				res[j++] = pop(S);
			}
			push(S, exp[i]);
			res[j++] = ' ';            //避免将两个操作数弄混
		}
	}
	while (!isEmpty(S))               //将栈中剩余操作符输出
	{
		res[j++] = ' ';
		res[j++] = pop(S);
	}
	res[j++] = '\0';
	return res;
}
//判断各种运算符符号的优先级
int Pri(char op)            
{
	switch (op)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	}
	return -1;
}
//计算后缀表达式
int evaluate(char* res)
{
	Stack S= init(strlen(res));                 // 创建栈
	int i;
	for (i = 0; i<strlen(res); i++)
	{
		if (res[i] == ' ')continue;           // 如果是空格就继续扫描	
		else if (isdigit(res[i]))             // 如果是数就入栈
		{ 
			int num = 0;	
			while (isdigit(res[i]))         // 将字符串转成可运算的数
			{
				num = num*10 + (int)(res[i] - '0'); //字符转数字
				i++;
			}
			i--;                          //如果这一位不是数字，返回上一位，将数字入栈
			push(S, num); 
		}	
		else                               // 如果是操作符，就连续出栈进行运算
		{
			int val1 = pop(S);
			int val2 = pop(S);
			switch (res[i])
			{
			case '+': push(S, val2 + val1); break;
			case '-': push(S, val2 - val1); break;
			case '*': push(S, val2 * val1); break;
			case '/': push(S, val2 / val1); break;
			}
		}
	}
	return pop(S);
}
//用户输入表达式求值
void main() 
{
	fflush(stdin);
	char exp[50];
	printf("请输入表达式：\n");
	scanf("%s",&exp);
	int res=evaluate(shift(exp));
	printf("%s", "结果为:");
	printf("%d",res);
}
