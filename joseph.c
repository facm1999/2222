#include <stdio.h>


//�ȶ�������ڵ�ṹ��
typedef struct node
{
	int n;
	int pwd;
	struct node* next;
}node,*nodelink;



//��������ѭ������,����ѭ�������������
node* createlink(node *h, int n, int pwd)
{
	node *p;  //�ȴ���һ��ָ��
	if (h == NULL)
	{
		p = (node *)(malloc(sizeof(node)));
		if (!p)
		{
			printf("�����ڴ�ʧ��");
			exit(0);
		}
		else
		{
			p->n = n;
			p->pwd = pwd;
			h = p;
		}

	}
	else
	{
		p = (node *)(malloc(sizeof(node)));
		if (!p)
		{
			printf("�����ڴ�ʧ��");
			exit(0);
		}
		else
		{
			p->n = n;
			p->pwd = pwd;
			h->next = p;
			h = p;
		}
	}
	return h;
}

//ִ�г��в���
void dellink(node *h, int n, int m) //��hΪβ�ڵ��ָ��,��Ҫ����ѭ����Ҫɾ���Ľڵ��ϣ�������ǰһ����bug��
{
	node *p ;
	node *tmp;
	p =tmp= h; //p�տ�ʼΪָ��β�ڵ��ָ�룬Ȼ����ͷ�ڵ㿪ʼ��������ֵ������pʼ���и�ǰֵtmp
	h = h->next;
	p = p->next;
	while (p->next != p)  
	{
		for (int i = 1; i < m; ++i)
		{
			p = p->next;
			tmp = tmp->next;
		}
			tmp->next = p->next;
			printf("%d", p->n);
			printf(" ");
			m = p->pwd;
			free(p);
			p = tmp->next;
	}
	printf("%d",p->n);
}

//������
int main()
{
	int m, n, s;
	node *h = NULL;
	node *p = NULL;
	printf("�������ʼm:");     //�����ʼm
	scanf_s("%d", &m);
	fflush(stdin);
	printf("����������:");         //��������n
	scanf_s("%d",&n);
	fflush(stdin);
	printf("���������˵�����:\n");
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d",&s);
		fflush(stdin);
		if (i == 1)
		{
			h = createlink(h, i, s);
			p = h;
		}
		else
		{
			h = createlink(h, i, s);
		}
	}
	h->next = p;   //����ѭ������
	printf("����˳�����£�\n");
	dellink(h, n, m);
	return 0;
}