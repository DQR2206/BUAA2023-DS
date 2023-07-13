#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
/*
�Բ����ĳ���Ҫͨ��ջ��ʵ��
1 pos str �����ַ���
2 pos n ɾ��n���ַ�
3 ���������ɾ�����������ܳ���������������
����ͬһ��ʱ��εĳ�������ѡ����ջ�����ǽ���ʱ��ջ��Ԫ����ջ
*/
#define M 502
char s[3000];
typedef struct node1//��¼�Ѿ�����������ջ
{
	int op;//�洢����
	int pos;//���в�����λ��
	char add[520];//1->������ַ���
	char delete[520];//2->ɾ�����ַ���
	struct node1* link;
}stacked,*stackedptr;
typedef struct node2//��¼��Ҫ����������ջ
{
	int op;
	int pos;
	char add[520];
	int length;//ɾ������
	struct node2* pre;
	struct node2* link;
}stacking,*stackingptr;
stackedptr stackedtop;
stackingptr stackingtop;
int flag = 0;//��¼��Ҫ��������ջ���ж���1��2
int main()
{
	int n, i, op;
	gets(s);
	scanf("%d", &n);
	//��ջ�ṹ
	for (i = 1; i <= n; i++)//�Ѿ��������Ĳ���,����op==2ʱ¼�뱻ɾ�����ַ���
	{
		scanf("%d", &op);
		if (op == 1)
		{
			stackedptr p = (stackedptr)malloc(sizeof(stacked));
			if (p == NULL) {
				scanf("%d %s", &(p->pos), p->add);
				continue;
			}
			p->op = op;
			p->link = NULL;
			if (stackedtop == NULL)
			{
				stackedtop = p;
			}
			else
			{
				p->link = stackedtop;
				stackedtop = p;
			}
			scanf("%d %s",&(p->pos),p->add);
		}
		else if (op == 2)
		{
			stackedptr p = (stackedptr)malloc(sizeof(stacked));
			if (p == NULL) {
				scanf("%d %s", &(p->pos), p->delete);
				continue;
			}
			p->op = op;
			p->link = NULL;
			if (stackedtop == NULL)
			{
				stackedtop = p;
			}
			else
			{
				p->link = stackedtop;
				stackedtop = p;
			}
			scanf("%d %s", &(p->pos), p->delete);
		}
		else   //������ֳ��������͵�ǰһ������û����������ջ��Ԫ����ջ
		{
			if (stackedtop == NULL)
			{
				continue;
			}
			else
			{
				stackedtop = stackedtop->link;
			}
		}
	}
	int cnt = n;
	//��Ҫ�����Ĳ���  2�洢ɾ������
	scanf("%d", &op);
	stackingptr now = (stackingptr)malloc(sizeof(stacking));
	now=stackingtop;
	while (op != -1)
	{
		if (op == 1)
		{
			flag++;
			stackingptr q = (stackingptr)malloc(sizeof(stacking));
			q->op = op;
			q->link = NULL;
			if (stackingtop == NULL)
			{
				stackingtop = q;
			}
			else
			{
				q->pre = now;
				now->link = q;
			}
			now = q;
			scanf("%d %s", &(q->pos), q->add);

		}
		else if (op == 2)
		{
			flag++;
			stackingptr q = (stackingptr)malloc(sizeof(stacking));
			if (q == NULL) {
				scanf("%d %d", &(q->pos), &(q->length));
				continue;
			}
			q->op = op;
			q->link = NULL;
			if (stackingtop == NULL)
			{
				stackingtop = q;
			}
			else
			{
				q->pre = now;
				now->link = q;
			}
			now = q;
			scanf("%d %d", &(q->pos), &(q->length));
		}
		else  //�������� ��������Ĳ�����ǰһ���������Ѿ��������Ĳ�������Ҫ���ַ������иı䣬�������һ���о��Ƚ��е���
		{
			
			if (flag>0)
			{
				flag--;
				if (flag == 0)
				{
					stackingtop = NULL;
					now = stackingtop;
				}
				else
				{
					stackingptr tmp;
					tmp = now->pre;
					now->pre->link = NULL;
					now = tmp;
				}
			}
			else//���������Ѿ���ɵĲ���
			{
				if (cnt == 0)
				{
					scanf("%d", &op);
					continue;
				}
				else
				{
					if (stackedtop->op == 1)
					{
						char sub[5000];
						int len = strlen(stackedtop->add);
						strcpy(sub, s + stackedtop->pos + len);
						strcpy(s + stackedtop->pos, sub);
						stackedtop = stackedtop->link;
					}
					else if (stackedtop->op == 2)
					{
						char sub[5000];
						strcpy(sub, s + stackedtop->pos);
						strcpy(s + stackedtop->pos, stackedtop->delete);
						int len = strlen(stackedtop->delete);
						strcpy(s + stackedtop->pos + len, sub);
						stackedtop = stackedtop->link;
					}
					cnt--;
				}
			}
		}
		scanf("%d", &op);
	}
	stackingptr q = stackingtop;
	while (q != NULL)
	{
		if (q->op == 1)
		{
			if (q->pos == strlen(s)-1)
			{
				strcat(s, q->add);
			}
			else
			{
				char sub[5000];
				strcpy(sub, s + q->pos);
				strcpy(s + q->pos, q->add);
				strcpy(s + q->pos + strlen(q->add), sub);
			}
		}
		else
		{
			if (q->pos + q->length > strlen(s))
			{
				int i;
				for (i = q->pos; i < strlen(s); i++)
				{
					s[i] = 0;
				}
			}
			else
			{
				char sub[5000];
				strcpy(sub, s + q->length + q->pos);
				strcpy(s + q->pos, sub);
			}
		}
		q = q->link;
	}
	printf("%s", s);
	return 0;
}