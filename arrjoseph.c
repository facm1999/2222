#include <stdio.h>
//�ȳ�ʼ���������飬һ����������û����룬һ����������Ƿ񱻱�����״̬;
int data[30];			       //��Ϊ���Լ����û���С��30��
int status[30] = {0};           //��δ����ʱΪ0������ʱ��ֵΪ�ڼ������У�

//�������������
void credata(int n) //nΪ�û����� 
{
	int m;
	printf("��ֱ������û������룺\n");
	for (int i = 0; i < n; i++) 
	{
		fflush(stdin);
		scanf_s("%d", &m);
		data[i] = m;
	}
}

//ִ�г��в���
void dedata(int m,int n) ///mΪ��ʼmֵ ,nΪ�û�����
{
	int index=-1; //�������忪ʼѭ�����±ꣻ
	int count = 0; //��¼�ڼ�������;
	while (count < n)
	{
		int i = 0;
		while (1)
		{	
			index = (index + 1) % n;   //��index������n�ڣ�
			if (status[index] == 0)
			{
				i++;                  //ֻ�е�״̬Ϊ0����Ϊ���е�����������i��ֵ��
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
	for (int i = 1; i <= n; i++)  //����������е��û���λ��
	{
		for (int j = 0; j < n; j++)
			if (status[j] == i)
				printf("%d",j+1);
				printf(" ");
	}
}


//������
int main() 
{
	int m, n;
	printf("�������ʼm:");
	fflush(stdin);
	scanf_s("%d", &m);
	printf("�������û�������");
	fflush(stdin);
	scanf_s("%d", &n);
	credata(n);
	dedata(m, n);
	return 0;
}