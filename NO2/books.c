#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
/*
1.¼�� 2.���� 3.ɾ�� 0.�˳�����
ִ�й����п��Զ�ν���1��2��3��ֱ������0
�������ֵ����С��������
ԭʼͼ����Ϣ����ԭʼͼ����Ϣ������500
*/
int cnt;
struct book
{
	char name[50];
	char author[20];
	char press[30];
	int year;
};
struct book bookshelf[500] = { 0 };//������һ�����
int flag[500];
void booksort(struct book[], int);//ͼ����������name�ֵ���
int main()
{
	int op, j, i = 0, cnt = 0;//cnt
	char str[120] = "";
	FILE* Rstream = fopen("books.txt", "r");
	while (fgets(str, 120, Rstream) != NULL)//����ʼ�ļ�����ṹ��
	{
		sscanf(str, "%s %s %s %d", bookshelf[cnt].name, bookshelf[cnt].author, bookshelf[cnt].press, &bookshelf[cnt].year);
		cnt++;
	}
	fclose(Rstream);

	scanf("%d", &op);
	while (op != 0)//����0�رճ���
	{
		if (1 == op)
		{
			scanf("%s %s %s %d", bookshelf[cnt].name, bookshelf[cnt].author, bookshelf[cnt].press, &bookshelf[cnt].year);
			cnt++;
			booksort(bookshelf, cnt );//�ڽṹ���������ź���
		}
		if (2 == op)
		{
			char word[50] = "";
			booksort(bookshelf, cnt);
			scanf("%s", word);
			for (j = 0; j < cnt; j++)
			{
				if (strstr(bookshelf[j].name, word) != NULL)
				{
					printf("%-50s%-20s%-30s%-10d\n", bookshelf[j].name, bookshelf[j].author, bookshelf[j].press, bookshelf[j].year);
				}
			}
		}
		if (3 == op)
		{
			char word[50] = "";
			scanf("%s", word);
			for (j = 0; j < cnt; j++)
			{
				if (strstr(bookshelf[j].name, word) != NULL)
				{
					flag[j] = 1;
				}
			}
		}
		scanf("%d", &op);
	}
	FILE* Wstream = fopen("ordered.txt", "w");
	for (i = 0; i < cnt; i++)
	{
		if (flag[i] == 0)
		{
			fprintf(Wstream,"%-50s%-20s%-30s%-10d\n", bookshelf[i].name, bookshelf[i].author, bookshelf[i].press, bookshelf[i].year);
		}
	}
		fclose(Wstream);
	return 0;
}
void booksort(struct book bookshelf[], int n)//ͼ��������
{
	int swap_flag = 0;
	struct book tmp;
	int i, j;
	for (i = 1; i <= (n - 1); i++)
	{
		for (j = 0; j < (n - i); j++)//��ʼ�����������Ϊ���ȺŴ���
		{
			if (strcmp(bookshelf[j].name, bookshelf[j + 1].name) > 0)
			{
				swap_flag = 1;
				tmp = bookshelf[j];
				bookshelf[j] = bookshelf[j + 1];
				bookshelf[j + 1] = tmp;
			}
		}
		if (swap_flag == 0)
		{
			break;
		}
	}
}
