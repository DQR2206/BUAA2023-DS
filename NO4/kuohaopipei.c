#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
/*
����ļ���{} ����
�����һ����⵽�Ĳ�ƥ������ż��к�
�ַ����� ��ch='('���ַ������� �� str[]="((("����ע�������Ų�Ӧ������
ע�Ͱ�������ע��\\  ����ע��
�ַ��������ַ��������в����������ź�˫����,���ڶ�������ʱ��˵���ַ�������
����Ϊת���ַ� ʹ��ʱ��\
*/

/*
ע������ⷨȱʧ�˶���ע�͵Ŀ����ԣ�������һ��ʼ�Ľⷨ�и����˶���ע�͵Ŀ��ǣ�
ͨ������һ������flag=0;�������'/*'��flag=1,������Ĳ������жϣ�ֱ����ĳһ�����ҵ��˺�һ���־
���Ҫ���ڽ����ַ����������ʱ����&&flag==0������
*/
#define M 200
struct node
{
	int top;
	char sign[2000];
	int row[2000];
};
struct node stack1, rem;//rem��¼�Ѿ������ķ���,���۶Է��Ž��к��ֲ������ȴ���,�����ƥ��Ļ��������ڴ���ʱ�պ�ƥ��
char str[2000];//�����ļ��ж������
char* p1, * p2, ch;
int row = 0;
int flag = 0;//����Ƿ���ֲ�ƥ��
int main()
{
	FILE* fp = fopen("example.c", "r");
	stack1.top = 0, rem.top = 0;
	//�ִ���������top,topָ��ջ��Ԫ�ص��Ϸ�
	while (fgets(str, 2000, fp) != NULL)
	{
		row++;
		int length = 0;//��¼ÿһ��������Ҫ���м��ĳ���
		p1= strstr(str, "//");
		p2 = strstr(str, "/*");
		/*
		����ע�͵Ĳ��ҷ�ʽֵ��ѧϰ����һ��ʼʹ�õķ�ʽΪ��ͷ��β������'\'�����ж���һ���ַ����ж�
		��// ��  '/*'��Ϊ�ַ���������ƥ�����Ч
		*/
		if ((p1 == NULL) && (p2 == NULL))
		{
			length = strlen(str);
		}
		else if ((p1 == NULL) && (p2 != NULL))
		{
			length = p2 - str;
		}
		else if ((p1 != NULL) && (p2 == NULL))
		{
			length = p1 - str;
		}
		else
		{
			int a = p1 - str;
			int b = p2 - str;
			if (a < b)
			{
				length = a;
			}
			else
			{
				length = b;
			}
		}
		int i;
		for (i = 0; i < length; i++)//ע�⣡i<length,һ��ʼ��bug����Ϊд����i<strlen(str);��Ͷ�ע���е����ݽ����˼��
		{
			if (str[i] == '(')//������ֱ����ջ
			{
				stack1.sign[stack1.top] = '(';
				rem.sign[rem.top] = '(';
				stack1.row[stack1.top] = row;
				stack1.top++, rem.top++;
			}
			else if (str[i] == ')')
			{
				rem.sign[rem.top] = ')';
				rem.top++;
				if (stack1.sign[stack1.top - 1] == '(')
				{
					stack1.top--;//���ƥ����г�ջ
				}
				else
				{
					ch = ')';
					flag = 1;
					break;
				}
			}
			else if (str[i] == '{')
			{
				rem.sign[rem.top] = '{';
				rem.top++;
				if (stack1.sign[stack1.top - 1] != '(')
				{
					stack1.sign[stack1.top] = '{';
					stack1.row[stack1.top] = row;
					stack1.top++;
				}
				else
				{
					ch = '(';
					flag = 1;
					break;
				}
			}
			else if (str[i] == '}')
			{
				rem.sign[rem.top] = '}';
				rem.top++;
				if (stack1.sign[stack1.top - 1] == '{')
				{
					stack1.top--;
				}
				else
				{
					ch = '}';
					flag = 1;
					break;
				}
			}
			else if (str[i] == '\'')
			{
				char *p = strchr(str + i + 1, '\'');
				if (p != NULL)
				{
					i = p - str;
				}
				else
					continue;
			}
			else if (str[i] == '\"')
			{
				char* p = strchr(str + i + 1, '\"');
				if (p != NULL)
				{
					i = p - str;
				}
				else
					continue;
			}
		}
		if (flag == 1)
		{
			if (ch == '(')
			{
				printf("without maching '%c' at line %d", ch, stack1.row[stack1.top - 1]);

			}
			else//  '{'  ')'  '}'
			{
				printf("without maching '%c' at line %d", ch, row);
			}
			break;
		}
	}
	if (flag == 0)
	{
		if (stack1.top == 0)
		{
			printf("%s", rem.sign);
		}
		else
		{
			printf("without maching '%c' at line %d", stack1.sign[stack1.top - 1], stack1.row[stack1.top - 1]);
		}
	}
	fclose(fp);
	return 0;
}
