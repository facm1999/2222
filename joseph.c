#include <stdio.h>


//先定义链表节点结构体
typedef struct node
{
	int n;
	int pwd;
	struct node* next;
}node,*nodelink;



//创建单向循环链表,链表循环地往里面插入
node* createlink(node *h, int n, int pwd)
{
	node *p;  //先创建一个指针
	if (h == NULL)
	{
		p = (node *)(malloc(sizeof(node)));
		if (!p)
		{
			printf("分配内存失败");
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
			printf("分配内存失败");
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

//执行出列操作
void dellink(node *h, int n, int m) //让h为尾节点的指针,主要是让循环到要删除的节点上，而不是前一个（bug）
{
	node *p ;
	node *tmp;
	p =tmp= h; //p刚开始为指向尾节点的指针，然后以头节点开始，这样赋值可以让p始终有个前值tmp
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

//主函数
int main()
{
	int m, n, s;
	node *h = NULL;
	node *p = NULL;
	printf("请输入初始m:");     //输入初始m
	scanf_s("%d", &m);
	fflush(stdin);
	printf("请输入人数:");         //输入人数n
	scanf_s("%d",&n);
	fflush(stdin);
	printf("输入所有人的密码:\n");
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
	h->next = p;   //构成循环链表
	printf("出列顺序如下：\n");
	dellink(h, n, m);
	return 0;
}