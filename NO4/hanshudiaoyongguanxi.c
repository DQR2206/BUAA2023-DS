#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
int stack[200];		//����������ջ 
int s[200][200];
//�������÷�ջ�����������ű�ʾ�ú����������ڴ洢������Ǹ��кŶ�Ӧ�ĺ����ڲ����õĺ��� 
struct infor {
	char functionName[200]; //��¼����������������һ���ض���� 
}AllfunctionName[2000];
int flag = 0, top = 0, op, num = 0, fID, topp[200];//topp��ջ�����飬��Ӧ�� s (�������÷�ջ) ÿһ�� 
char fName[200];
int FindName(char* s, int len)	//���躯������ŵĺ��� 
{
	int i;
	for (i = 0; i < len; i++)
		if (strcmp(s, AllfunctionName[i].functionName) == 0)//����У����ر�� 
			return i;
	strcpy(AllfunctionName[len].functionName, s);//���û�У�����룬�������µı�� 
	return len;
}
int main()
{
	int i, j, k, t;
	while (flag == 0 && (scanf("%d", &op) == 1))	//�������������ջ���к������� 
	{
		if (op == 8)
		{
			scanf("%s", fName);	//¼�� 
			fID = FindName(fName, num);	//��ñ�� 
			stack[top] = fID;	//������ջ 
			if (top > 0)	//�����ջ���к��� 
			{
				s[stack[top - 1]][topp[stack[top - 1]]] = fID;
				//�����㷨��ʾ����һ��������ջʱ�������ǵ�ǰջ���������õ�һ�������� 
				topp[stack[top - 1]]++;	//��ջջ��+1 
			}
			top++;//��ջջ��+1 
		}
		else if (op == 0)
		{
			top--;	//��ջջ��-1 
		}
		num++;
		if (top == 0)
			flag = 1;	//��ջΪ�� 
	}
	//ȥ��
	for (i = 0; i < 200; i++)
	{
		if (topp[i] > 0)	//���ĳ���������ڵ��ù�ϵ 
		{
			for (j = 0; j < topp[i]; j++)
			{
				for (k = j + 1; k < topp[i]; k++)
				{
					if (s[i][j] == s[i][k])	//�����ظ� 
					{
						for (; k < topp[i]; k++)
						{
							s[i][k] = s[i][k + 1];	//����ȥ�� 
						}
						topp[i]--;	//ջ��-1 
						k = j;	//�ص�ԭλ׼���ٲ飨���Ե�3��4������3�����ϵ��ظ��ĵ��ã� 
					}
				}
			}
		}
	}
	for (i = 0; i < 200; i++)
	{
		if (topp[i] > 0)	//���ĳ���������ڵ��ù�ϵ 
		{
			printf("%s:", AllfunctionName[i].functionName);//��� 
			for (j = 0; j < topp[i] - 1; j++)
			{
				printf("%s,", AllfunctionName[s[i][j]].functionName);//��� 
			}
			printf("%s", AllfunctionName[s[i][j]].functionName);//��� 
			puts("");
		}
	}
	return 0;
}

