#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
/*
�����ͺ��붼��ͬ�����ظ��ֻ������һ��
������ͬ�绰���벻ͬ�����״γ��ֲ���������n���ظ� ����_n;
*/
struct lianxiren
{
	int flag;//��¼���
	char name[100];
	char num[100];
};
void optiBubbleSort(struct lianxiren[], int n);
char NAME[100], NUM[100];//��ʱ���������ַ���
struct lianxiren tongxunlu[200] ;
int main()
{ 
	int n ,i ,j , cnt=1,x=1;
	scanf("%d", &n);
	scanf("%s", tongxunlu[0].name);
	scanf("%s", tongxunlu[0].num);
	for (i = 1; i < n; i++)
	{
		scanf("%s", NAME);
		scanf("%s", NUM);
		int sum = 0;
		for (j = 0; j <= i - 1; j++)
		{
			if ((strcmp(NAME, tongxunlu[j].name) == 0) && (strcmp(NUM, tongxunlu[j].num) == 0))
			{
				sum++;
			}
		}
		if (sum == 0)
		{
			strcpy(tongxunlu[x].name, NAME);
			strcpy(tongxunlu[x].num, NUM);
			cnt++;
			x++;
		}
	}
	/*printf("\n");
	for (i = 0; i < cnt; i++)
	{
		printf("%s %s\n", tongxunlu[i].name, tongxunlu[i].num);
	}
	printf("\n");
	*/
	for (i = 0; i < cnt; i++)//��������ͬ�Ľ��б��
	{
		int a = 0;
		for (j = i + 1; j < cnt; j++)//����Ѱ��
		{
			if ((strcmp(tongxunlu[i].name, tongxunlu[j].name) == 0) && (tongxunlu[i].flag == 0) && (tongxunlu[j].flag == 0))//�Ѿ��б�ǵľͲ�Ҫ����
			{
				a++;
				tongxunlu[j].flag = a;
			}
		}
	}
	 optiBubbleSort(tongxunlu, cnt);//�������⣩
	 //printf("\n");
	for (i = 0; i < cnt; i++)
	{
		if (tongxunlu[i].flag == 0)
		{
			printf("%s %s", tongxunlu[i].name, tongxunlu[i].num);
		}
		else
		{
			printf("%s_%d %s", tongxunlu[i].name, tongxunlu[i].flag, tongxunlu[i].num);
		}
		printf("\n");
	}
	return 0;
	
}
	void optiBubbleSort(struct  lianxiren tongxunlu[], int cnt)
	{
		int swap_flag = 0, i, j;
		for (i = 1; i <= (cnt - 1); i++)
		{
			for (j = 0; j < (cnt - i); j++)
			{
				if (strcmp(tongxunlu[j].name, tongxunlu[j + 1].name) > 0)
				{
					swap_flag = 1;
					struct lianxiren tmp = tongxunlu[j];
					tongxunlu[j] = tongxunlu[j + 1];
					tongxunlu[j + 1] = tmp;
				}

			}
			if (swap_flag == 0)
				break;
		}
	}

/*int cnt = 0;//��¼������ͬ��֮����ʵ��¼������
	//scanf("%s", tongxunlu[0].name);
	//scanf("%s", tongxunlu[0].num);//�����һ��һ�������ظ�
	for (i = 0; i < n; i++)//��ɽṹ�����벢���ų���ȫ��ͬ��
	{
		scanf("%s", NAME);
		scanf("%s", NUM);
		//ȥ����ͬ�Ĳ���������
		for (j = 0; j < i; j++)//���Ѿ���������в���
		{
			if ((strcmp(NAME, tongxunlu[j].name) == 0) && (strcmp(NUM, tongxunlu[j].num) == 0))
			{
				flag = 1;
				break;//����ʱ�������һ���������б���
			}
			else {
				if (flag == 1)
				{
					n--;
					i--;
					flag = 0;
				}
				cnt++;
				strcpy(tongxunlu[i].name, NAME);
				strcpy(tongxunlu[i].num, NUM);
				break;//
			}
		}

	}
	*/
