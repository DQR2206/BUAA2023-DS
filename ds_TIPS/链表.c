#define _CRT_SECURE_NO_WARNINGS 1
/*
������һ������洢��Ԫ�Ϸ���������˳��Ĵ洢�ṹ
���Ա��ȱ������ÿһ�β����ɾ��Ԫ�أ�����Ԫ�ص��ƶ�����ʱ��Ч�ʵ���
��ʽ�ṹ�洢���ص�����һ������Ĵ洢��Ԫ���洢���Ա��е�Ԫ�أ��ڲ����ɾ��Ԫ��ʱ��ͨ���޸�ָ����ɲ���
������Ϊ��ʽ�洢�ṹ�Ĵ洢��Ԫ����������Ҫָ�������ʺ��Ԫ��
�洢Ԫ����Ϣ�����Ϊ�����򣬴洢���λ�õ����Ϊָ�������������ֹ���һ���ڵ�
n���ڵ㹹��һ��������Ϊ���Ա����ʽ�洢�ṹ
������ÿ���ڵ�ֻ��һ��ָ���� 
һ.����Ĵ���
������Ĵ����У����ָ����һ���ڵ��ָ�룬���ָ�뱣����һ�����ĵ�ַ
typedef struct node* LinkList;
struct Node
{
	Elemtype data;
	struct Node* next;
};
��.����ĳ�ʼ��
1.�����Ĵ��룺�漰�ı����������ͳͳ��ָ�봫����
2.����ͷ�ڵ㣬Ϊͷ�ڵ�����ڴ�
3.ͷ���ָ���ʼ��Ϊ��ָ��
void InitList(LinkList* L)
{
	*L = (LinkList)malloc(sizeof(struct Node));
	(*L) ->next = NULL;
}
��.�ж������Ƿ�Ϊ��
����ͷ�ڵ�ָ����Ϊ��֤������Ϊ�գ���֮����Ϊ��
*/
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define Elemtype int
typedef struct node
{
	Elemtype data;
	struct node* link;//ָ����һ��������ָ��
}LNode,*LinkList;
//1.����һ����������
/*
list ��Ϊͷ���ָ�����ָ�룬��������������׵�ַ(��һ�������ĵ�ַ)
������Ϊ��ʱ��  list = NULL; ����ͨ��list��������б���
*/
LinkList CREAT(int n)
{
	LinkList p, r, list = NULL;//��������ָ��ṹ�����͵�ָ��
	Elemtype a;
	int i;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a);//��ȡһ������Ԫ��
		p = (LinkList)malloc(sizeof(LNode));//����һ���µ������
		p->data = a;
		p->link = NULL;//����ĩβָ�����ÿ�
		if (list == NULL)//�������Ϊ��
		{
			list = p;//�׵�ַ��ֵ��ͷ���ָ��
		}
		else
			r->link = p;//�½������������β��
		r = p;//ָ��r����ָ������ĩβ
	}
	return list;
}
//���㷨ʱ�临�Ӷ�ΪO(n),nΪ���Ա���

//2.�����Ա�ĳ���(O(n))
int LENGTH(LinkList list)
{
	LinkList p = list;
	int n = 0;
	while (p != NULL)
	{
		n++;
		p = p->link;//��p���Ϻ���;  p->link pָ���������ָ�������ݣ������һ��������ַ
	}
	return n;
}
//�󳤶ȵݹ�ⷨ
int LENGTH(LinkList list)//�������Ϊͷ�ڵ��ַ
{
	if (list != NULL)
	{
		return 1 + LENGTH(list->link);//��һ�������λ��
	}
	else
		return 0;
}

//3.���������Ƿ�Ϊ��
int ISEMPTY(LinkList list)
{
	return (list == NULL);
}
//���жϴ���ͷ�ڵ�������Ƿ�Ϊ��ʱ(�ж�ͷ����ָ�����Ƿ�Ϊ��)
int ISEMPTY(LinkList list)
{
	return (list->link == NULL);
}


//4.ȷ��Ԫ��item�������е�λ��
/*
������ĵ�һ��λ�ÿ�ʼ������αȶԵ�ǰ����������������Ƿ���itemƥ��
���ҳɹ�����������ַ������ʧ�ܷ���NULL
*/
LinkList FIND(LinkList list, Elemtype item)
{
	LinkList p = list;
	while (p != NULL && p->data != item)
	{
		p = p->link;
	}
	return p;
}

//�����￪ʼ���еĺ������������ڴ���������ָ�봫���ββ�����ı���ʵ���������в�ȡ��& LinkList &list��ʽ������C���Ա�����������
// ����취Ϊ�������ָ�룬�Զ���ָ�����һ������ã��õ�ʵ�ʲ����ĵ�ַ,�Ӷ����Զ�ԭ��������޸�
// �Ե�һ��Ϊ���������޸ķ�ʽ����
//5.�ڷǿ���������ĵ�һ�������ǰ����һ��������ϢΪitem�������
void INSERTLINK1(LinkList list, Elemtype item)
{
	LinkList p;
	p = (LinkList)malloc(sizeof(LNode));
	p->data = item;
	p->link = list;//�½ڵ�ָ����ָ��ԭ��ĵ�һ��Ԫ��
	list = p;//ͷ���ָ�����
}
//�޸ĺ�
void INSERTLINK1(struct node** list, Elemtype item)//(LinkList * list , Elemtype item);Ҳ����
{
	LinkList p;
	p = (LinkList)malloc(sizeof(LNode));
	p->data = item;
	p->link = *list;
	*list = p;
}

//6.�ڷǿ����������ĩβ����һ��������ϢΪitem�������
void INSERTLINK2(LinkList list, Elemtype item)
{
	LinkList p,r;
	r = list;
	while (r->link != NULL)//��ͷ��β����
	{
		r = r->link;
	}
	p = (LinkList)malloc(sizeof(LNode));
	p->data = item;
	p->link = NULL;
	r->link = p;
}

//7.����ָ��qָ���������������һ��������ϢΪitem�������
void INSERTLINK3(LinkList list,LinkList q, Elemtype item)
{
	LinkList p;
	p = (LinkList)malloc(sizeof(LNode));
	p->data = item;
	if (list == NULL)
	{
		list = p;
		p->link = NULL;
	}
	else
	{
		p->link = q->link;
		q->link = p;
	}
}

//8.�����Ա��i���ڵ�������һ��������ϢΪitem�������
int INSERTLINK4(LinkList list, int i, Elemtype item)
{
	LinkList p, q = list;
	int j = 1;
	while (j < i && q != NULL)
	{
		q = q->link;
		j++;
	}
	if (j != i || q == NULL)
	{
		printf("�����в����ڵ�%d�����\n", i);
		return -1;
	}
	p = (LinkList)malloc(sizeof(LNode));
	p->data = item;
	p->link = q->link;
	q->link = p;
	return 1;
}
//9.�ڰ�ֵ������������������в���һ��������ϢΪitem�������
/*
��������㰴����ֵ����Ϣ��С��������
�������Ԫ�غ���ȻҪ����Ϊ��������
*/
void INSERTLINK5(LinkList list, Elemtype item)
{
	LinkList p, q, r;
	p = (LinkList)malloc(sizeof(LNode));
	p->data = item;
	if (list == NULL || item < list->data)//����Ϊ�ջ�����С�ڵ�һ�����������򣬷��ڵ�һ��
	{
		p ->link = list;
		list = p;
	}
	else
	{
		q = list;
		while (q != NULL && item >= q->data)//Ѱ�Ҳ���λ��
		{
			q = q->link;
			r = q;//rָ��ĵ�ַ��ͬ��qָ��ĵ�ַ����ָ��ͬһ�������
		}
		p->link = q->link;
		r->link = p;
	}
}

//10.�ӷǿ����Ա���ɾ��q��ָ�������
/*(1).ɾ���ڵ�������ĵ�һ���ڵ�
   ʹ��ָ��listָ��ڶ���Ԫ�ؼ���
   (2).ɾ����q���ǵ�һ����㲢����֪ɾ���ڵ�q��ǰ��r
   r->link=q->link;
   (3).ɾ����q���ǵ�һ���ڵ㲢�Ҳ�֪��ǰ��
   ������ǰ����ҵ�q,
   ֹͣ����������Ϊ x->link=q;
*/
//���(1)��(2)
void DELETELINK1(LinkList list, LinkList q, LinkList r)
{
	if (q == list)
	{
		list = q->link;
	}
	else
	{
		r->link = q->link;
	}
	free(q);//�Ѿ����������һ���֣������ͷ�
}
//���(3)
void DELETELINK2(LinkList list, LinkList q)
{
	if (q == list)
	{
		list = q->link;
	}
	else
	{
		LinkList tmp = list;
		while (tmp->link!= NULL && tmp->link != q)//�������д��tmp!=NULL�����ˣ�tmp�Ѿ�Խ������,��������ı�־Ϊָ�����е�֮��λ��
		{
			tmp = tmp->link;
		}
		if (tmp->link != NULL)//�ų��˳�ѭ���ĵ�һ��������ֻ����Ϊ��һ��Ԫ����q�˳�ѭ��
		{
			tmp->link = q->link;
		}
	}
	free(q);
}

//11.����һ������
//�����������������ɾ��(�����������ɾ��)
void DELETELIST(LinkList *list)
{
	LinkList p = *list;//�õ�ָ��ͷ����ָ��
	while (p != NULL)
	{
		*list = p->link;
		free(p);
		p = *list;
	}
}

//12.ɾ����������������ֵ��Ϊitem�����������
//�ӵڶ�����ʼ�����жϣ�����жϵ�һ��
void DELETELIST(struct node** list, int item)
{
	struct node* LIST = *(list);//�Զ���ָ�������,�õ���ָ��
	struct node* p, *q = LIST;
	p = LIST->link;//ָ��ڶ����ڵ�
	while (p != NULL)
	{
		if (p->data == item)//��������
		{
			q->link = p->link;//����p��һ�����
			free(p);//�ͷ�
			p = q->link;
		}
		else
		{
			q = p;
			p = p->link;
		}
		if (LIST->data == item)
		{
			p = LIST;
			LIST = LIST->link;
			free(p);
		}
	}
}
//13.��תһ�����Ա�
//�ı��������ָ����ָ��ķ�ʽ
void INVERT(struct node** list)
{
	struct node* LIST = *list;
	struct node* p, * q, * r;
	p = LIST;
	q = NULL;
	while (p != NULL)
	{
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	LIST = q;
}

//14.�������ǿ����Ա����ӳ�һ�����Ա�
void CONNECT(struct node* lista, struct node* listb)
{
	struct node* p;
	for (p = lista; p->link != NULL; p = p->link);
	p->link = listb;
}

//15.��������ֵ�������ӵķǿ����Ա�ϲ�Ϊһ����ֵ���ӵ����Ա���С�������У�
//��ϲ����������ָ��listc
struct node* MERGELIST(struct node* lista, struct node* listb)
{
	struct node* listc,*p=lista,*q=listb,*r;
	//ȷ��c����ͷ�ڵ�
	if (lista->data <= listb->data)
	{
		listc = lista;
		r = lista;
		p = lista->link;//ͷ�ڵ�ѡ��a��ͷ�ڵ㣬p����һλ
	}
	else
	{
		listc = listb;
		r = listb;
		q = listb->link;//ͷ�ڵ�ѡ��b��ͷ�ڵ㣬q����һλ
	}
	//r��ʲô���ã�rָ��listc�����һ���ڵ�
	while (p != NULL && q != NULL)
	{
		if (p->data <= q->data)//ѡȡp��ָ���
		{
			r->link = p;     //��p��ָ������ӵ�r֮��
			r = p;           //rָ��listc�����һ���ڵ�
			p = p->link;
		}
		else
		{
			r->link = q;
			r = q;           
			q = q->link;
		}
	}
	//�˳�����ʱ˵��lista��listb��ͷ
	//��ʱr->link�д洢�������p,��˵����lista��ͷ����qͬ��
	(r->link = p) ? p : q;//����ʣ��ڵ�
	//���ڸ�ֵ����ж���٣���ֵ������ֵ��Ϊ��ֵ���������pΪ��ָ�룬�ж����Ϊ�٣�r->link=q;
	//���p���ǿ�ָ�룬˵��p��û�ж��꣬r->link=p;
	return listc;//���غϲ��������һ������ֵ
}

//16.����һ����������
struct node* COPY(struct node* lista)
{
	struct node* listb;
	if (!lista)
	{
		return NULL;
	}
	else
	{
		listb = (struct node*)malloc(sizeof(struct node));
		listb->data = lista->data;
		listb->link = COPY(lista->link);
	}
	return listb;
}

//.17�����������������������
void linksort(Elemtype A[], int n)
{
	struct node* p, * list = NULL;
	int i;
	for (i = 0; i < n; i++)
	{
		INSERTLINK5(list, A[i]);//������������
	}
	p = list;
	i = 0;
	while (p != NULL)
	{
		A[i++] = p->data;
		p = p->link;
	}
}
/*
ѭ������
���������ָ�����ٴ��NULL,����ָ������ĵ�һ�������
ͷ�ڵ������������������Ĺ�����ͬ��������������Բ������Ϣ��Ҳ���Դ��һЩ���Ա���֮�����Ϣ��
ָ�����ŵ�һ��Ԫ�ص������
*/