#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
/*
����ʽ���  ֻ�������ϵ����(����ָ��Ϊ0)

����������������������������ʽ
ÿ��������д���ϵ������������һ�����link
*/
typedef struct list
{
	long long  xishu;
	long long  zhishu;
	struct list* link;
}LIST,*LinkList;
void LISTSORT(struct list**,int n);
void DELETE(struct list**);
int main()
{
	long long  a, b;
	char ch;
	LinkList lista = NULL;
	LinkList r=NULL;
	//�����һ������ʽ
	do{
		scanf("%lld%lld%c", &a, &b, &ch);
		LinkList p = (LinkList)malloc(sizeof(LIST));
		p->xishu = a;
		p->zhishu = b;
		p->link = NULL;
		if (lista == NULL)
		{
			lista = p;
		}
		else
		{
			r->link = p;
		}
		r = p;
		
	} while (ch != '\n');
	//����ڶ�������ʽ
	LinkList listb = NULL,t=NULL;
	do {
		scanf("%lld%lld%c", &a, &b, &ch);
		LinkList q = (LinkList)malloc(sizeof(LIST));
		q->xishu = a;
		q->zhishu = b;
		q->link = NULL;
		if (listb == NULL)
		{
			listb = q;
		}
		else
		{
			t->link = q;
		}
		t = q;
	} while (ch != '\n');
	/*
	�������鵽��Ϊֹ������������ʽ��¼������ȷ��
	ֵ��ע����ǣ�
	1.������ʽ¼��ʱ��ʹ����do while ��䣬�ж������ڸ�ֵ����֮��
	�������Ա�֤���һ���ϵ���ʹ�������¼���ֲ��½���һ���ڵ�
	2.����ֹͣ¼����ж�
	������������֮����ַ�����Ϊ�ո�ͻ��з����������
	*/
	
	//��˳���   lista listb
	//����������Ǵ�����������
	/*
	˼·���Ƚ��г˷����ٽ�������
	����ʱָ���򲻶����Ƚ������������ֵ��
	������ֵ���ֵ�������ֵ���д���ֵ��ͬ���ͽ�ϵ����ӣ���ɾ��һ�������
	����ߴ���ǰ���ʹ����
	*/
	LinkList listc = NULL;
	LinkList p = lista, q = listb,n=listb;
	r=listc;
	int cnt = 0;
	while (p != NULL)
	{
		int  i;
		while (q!= NULL)
		{
			//printf("%d\n", cnt);
			LinkList t = (LinkList)malloc(sizeof(LIST));
			cnt++;
			t->xishu = (p->xishu) * (q->xishu);
			t->zhishu = (p->zhishu) + (q->zhishu);
			//printf("\n%d %d\n",t->xishu,t->zhishu);
			t->link = NULL;
			if (listc == NULL)
			{
				listc = t;
			}
			else
			{
				r->link = t;
			}
			r = t;
			q = q->link;
		}//�˳�ѭ��ʱq�Ѿ�ָ��ڶ�������ʽ��ĩβ����Ҫ��������
		q = listb;
		p = p->link;
	}//pָ���һ������ʽ��ĩβ
	//���������µ��������ɹ�
	//��listc��������
	//printf("%d", cnt);
	LISTSORT(&listc,cnt);//����û����
	DELETE(&listc);
	LinkList d = listc;
	while(d!=NULL)
	{
		printf("%lld %lld ", d->xishu, d->zhishu);
		d = d->link;
	}
	return 0;
}
void LISTSORT(struct list** listc,int n)
{
	LinkList p = *listc;//pΪ��ָ��
	LinkList q = p->link;
	int i, j;
	for (i = 1; i <= (n - 1);i++)
	{
		for (p = *listc; p->link != NULL;p = p->link)
		{
			q = p->link;
			if (p->zhishu < q->zhishu)
			{
				long long  temp = 0;
				temp = p->zhishu;
				p->zhishu = q->zhishu;
				q->zhishu = temp;
				temp = p->xishu;
				p->xishu = q->xishu;
				q->xishu = temp;
			}
		}
	}
	return;
}
void DELETE(struct list** listc)//������ֻ������������Ч
{
	LinkList p = *listc;
	while (p->link != NULL)
	{
		LinkList q = p->link;
		if (p->zhishu == q->zhishu)
		{
			p->xishu = p->xishu + q->xishu;
			p->link = q->link;
		}
		else
		{
			p = p->link;
		}
		if (p == NULL)
		{
			return;
		}
	}
	return;
}