#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct jose
{
	int num;//���
	struct jose *link;
}Jose,*Joseptr;
int main()
{
	int n, k, i;
	scanf("%d%d", &n, &k);
	Joseptr list=NULL, now=NULL;
	//������ʼѭ������
	for (i = 1; i <= n; i++)
	{
		Joseptr p = (Joseptr)malloc(sizeof(Jose));
		p->num = i;
		p->link = NULL;
		if (list == NULL)
		{
			list = p;
		}
		else
		{
			now->link = p;
		}
		now = p;
	}
	now->link = list;
	Joseptr p = list,prep=p;
	int cnt = 0;
	while (n>1&&(p!=NULL))//n==1ʱ���
	{
		cnt++;
		if (cnt == k)//�ﵽ����
		{
			n--;
			prep->link = p->link;
			p = p->link;
			cnt = 0;
		}
		else
		{
			prep = p;
			p = p->link;
		}
	}
	printf("%d", p->num);
	return 0;
}
