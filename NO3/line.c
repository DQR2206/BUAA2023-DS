#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<malloc.h>
#include<stdlib.h>
#include<math.h>
struct line 
{
  int x1;
  int y1;
  int x2;
  int y2;
};
struct line a[100];
int cmp(const void *a, const void *b)
{
	return (*(struct line*)a).x1>(*(struct line* )b).x1 ? 1:-1;
}
/*
�㷨˼·���Ƚ�����������߶ν�������
��˵��������У������ڽ��б���ʱֻ��Ҫ�����������õ��Ӵ�����������Ч��
����ÿһ���߶ν��б���������ÿһ���߶Σ�����������������߶Σ������Ƿ��ܹ������� 
*/
int main()
{
  int n,i,j;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
  	scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
  }
  qsort(a,n,sizeof(struct line),cmp);//��x���� ���������� 
  int length=1;//��¼��ǰ����
  int max=1;//��¼����� 
  int max_x,max_y;
  int now=0;
  for(i=0;i<n;i++)
  {
  	now=i;
  	length=1;
  	for(j=now+1;j<n;j++)//�������� 
  	{
  		if(a[now].x2==a[j].x1&&a[now].y2==a[j].y1)
  		{
  			length++;
  			now=j;
		  }
	  }
	  if(length>max)
	  {
	  	max=length;
	  	max_x=a[i].x1;
	  	max_y=a[i].y1;
	  }
  }
  printf("%d %d %d",max,max_x,max_y);
  return 0;
}

