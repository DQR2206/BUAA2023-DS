#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<malloc.h>
#include<stdlib.h>
#include<math.h>
//������������ͷ�ڵ㣬��һ���ڵ㲻������� 
typedef struct node
{
  int data;
  struct node * link;	
}NODE ,*PNODE;
void BubbleSort(PNODE L)
{
	int i ,count = 0, num;//count��¼������ĸ�����num�����ڲ�ѭ����
	NODE *p, *q, *tail;//��������ָ�룬����ð������
	p = L;
	while(p->link != NULL)//��������ĸ���
	{
		count++;//ע�͢�
		p = p->link;
	}
	for(i = 0; i < count - 1; i++)//���ѭ����������ð������һ��
	{
		num = count - i - 1;//��¼�ڲ�ѭ����Ҫ�Ĵ�����������ð������һ����
		q = L->link;//��qָ���һ�����
		p = q->link;//��pָ���һ�����
		tail = L;//��tailʼ��ָ��qǰһ����㣬���㽻����Ҳ�����������һ������
		while(num--)//�ڲ�ѭ�� ����������ð������һ��
		{
			if(q->data > p->data)//����ý���ֵ���ں�һ����㣬�򽻻�
			{
				q->link = p->link;
				p->link = q;
				tail->link = p;
			}
			tail = tail->link;//ע�͢�
			q = tail->link;//ע�͢�
			p = q->link;//ע�͢�
		 } 
	} 
}

int main()
{
  int i,n;
  scanf("%d",&n);
 
  PNODE list=(PNODE)malloc(sizeof(NODE));//����ͷָ�� 
  PNODE now=(PNODE)malloc(sizeof(NODE));
  list->link=NULL;
  for(i=1;i<=n;i++)
  {
  	PNODE p=(PNODE)malloc(sizeof(NODE));
  	scanf("%d",&p->data);
  	p->link=NULL;
  	if(list->link==NULL)
  	{
  		list->link=p;
	  }
	  else
	  {
	  	now->link=p;
	  }
	  now = p;
  }
  BubbleSort(list);
  PNODE q=(PNODE)malloc(sizeof(NODE));
  q=list->link;
  while(q!=NULL)
  {
  	printf("%d\n",q->data);
  	q=q->link;
  }
  return 0;
}

