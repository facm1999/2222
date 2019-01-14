#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
#include <stdlib.h>
//����ջ�ṹ��
typedef struct stack 
{
	int top;               //ջ����λ��
	int cap;         //ջ������
	int* arr;
}*Stack;
//��ʼ��ջ
Stack init(int cap) 
{
	Stack S = (Stack)malloc(sizeof(struct stack));
	if (!S)return NULL;
	S->top = -1;                           //ջ��Ϊ-1����һ��Ԫ��Ϊ0����������Ķ���
	S->cap = cap;
	int* array = (int*)malloc(cap * sizeof(int));
	if (!array)return NULL;
	S->arr = array;
}
//ջ��һЩ����
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
//��׺���ʽת��Ϊ��׺���ʽ
char res[100];                         //����һ���洢���Ȳ�����100����ʽ���ʽ������
char* shift(char* exp) 
{
	int i, j;
	Stack S = init(strlen(exp));
	for (i=0,j = 0;i<strlen(exp); i++) 
	{
		if (isdigit(exp[i]))            //�����ȡ�����־�ֱ�������res�У�
		{
			res[j++] = exp[i];
		}
		else if (exp[i] == '(')      //����ǡ�����������ջ
		{
			push(S, exp[i]);
		}
		else if (exp[i] == ')')      //����ǡ��������ͳ�ջ
		{
			while (!isEmpty(S) && getTOP(S) != '(') 
			{
				res[j++] = ' ';    //�ո������������ֵ�Ӱ��
				res[j++] = pop(S);
			}
			if (isEmpty(S)) 
			{
				return -1;
			}
			else 
			{
				pop(S);         //�ѡ�����Ҳ��ջ
			}
		}
		else                 //�Բ������Ĳ���
		{
			while (!isEmpty(S) && Pri(exp[i]) <= Pri(getTOP(S))) 
			{
				res[j++] = pop(S);
			}
			push(S, exp[i]);
			res[j++] = ' ';            //���⽫����������Ū��
		}
	}
	while (!isEmpty(S))               //��ջ��ʣ����������
	{
		res[j++] = ' ';
		res[j++] = pop(S);
	}
	res[j++] = '\0';
	return res;
}
//�жϸ�����������ŵ����ȼ�
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
//�����׺���ʽ
int evaluate(char* res)
{
	Stack S= init(strlen(res));                 // ����ջ
	int i;
	for (i = 0; i<strlen(res); i++)
	{
		if (res[i] == ' ')continue;           // ����ǿո�ͼ���ɨ��	
		else if (isdigit(res[i]))             // �����������ջ
		{ 
			int num = 0;	
			while (isdigit(res[i]))         // ���ַ���ת�ɿ��������
			{
				num = num*10 + (int)(res[i] - '0'); //�ַ�ת����
				i++;
			}
			i--;                          //�����һλ�������֣�������һλ����������ջ
			push(S, num); 
		}	
		else                               // ����ǲ���������������ջ��������
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
//�û�������ʽ��ֵ
void main() 
{
	fflush(stdin);
	char exp[50];
	printf("��������ʽ��\n");
	scanf("%s",&exp);
	int res=evaluate(shift(exp));
	printf("%s", "���Ϊ:");
	printf("%d",res);
}
