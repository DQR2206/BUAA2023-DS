#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
//ע�� n+1  n++  ++n������
/*��n==5ʱ 
n+1��Ϊ���ʽ��ֵΪ 6��n��ֵ��ȻΪ5
n++��Ϊ���ʽ��ֵΪ5������ʱn��ֵ��Ϊ6
++n��Ϊ���ʽ��ֵΪ6����ʱn��ֵҲΪ6�� 
����Ϊ����ʱ��++n��n+1����ͬ��Ч��������ʵ��nֵ������n++������bug 
*/ 
 
int result[20],flag[20];
void quanpailie(int ,int );
int main()
{
	int n,cnt=1;
	scanf("%d",&n);
//	quanpailie( n, cnt);
    printf("%d ",++n);
    printf("\n%d",n);
	return 0;
}
void quanpailie(int n,int cnt)//ʹ��cnt ��¼Ӧ������Ԫ�ص���� 
{
	int j;
	if(cnt>n)//���Ӧ������Ԫ�ص���ȴ���������ȣ���������� 
	{
		for(j=1;j<=n;j++)
		{
			printf("%d ",result[j]);//������н�� 
		}
		printf("\n");
		return;
	}
	else
	{
		for(j=1;j<=n;j++)
		{
			if(flag[j]==0)//��Ԫ�ػ�δ�������� 
			{
				result[cnt]=j;
				flag[j]=1;
				quanpailie(n,cnt+1);
				flag[j]=0;//���ݲ��� 
			}
		}
	}
}
