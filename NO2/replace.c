#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
//ָ���ļ���ĳһ�ַ����滻Ϊ��һ���ַ���
//ָ���ı��滻�ַ�����Сд�޹�
char src[100] = "";
char sub[100] = "";
char str[100] = "";
int my_strstr(char[], char[]);
int main()
{
	gets(src);
	gets(sub);
	FILE* Rstream = fopen("filein.txt", "r");
	FILE* Wstream = fopen("fileout.txt", "w");
	while (fgets(str, 100, Rstream) != NULL)//��������ʽ�����ļ�
	{
		int i = 0, j = 0;
		for (i = 0; i < strlen(str); i++)
		{
			if (my_strstr(str + i, src) == 0)//��λ���бȶԷ���ֵΪ0ʱ˵���պ���ͷ������
			{
				fputs(sub, Wstream);
				i = i + strlen(src) - 1;
			}
			else//����ͷ������������ǰ����ַ�
			{
				fputc(str[i], Wstream);
			}
		}
	}

	fclose(Rstream);
	fclose(Wstream);
	return 0;
}
int my_strstr(char str[], char src[])//�ڶ����ļ���ÿһ���в����Ƿ�����Ҫ�滻���ַ��������س��ֵ�λ��
{
	//�Ƚ��ַ���ת��Ϊ��д
	int i = 0,j=0;
	char temp1[100] = "";
	char temp2[100] = "";
	strcpy(temp1, str);
	strcpy(temp2, src);
	for (i = 0; i < strlen(temp1); i++)
	{
		temp1[i] = toupper(temp1[i]);
	}
	for (i = 0; i < strlen(temp2); i++)
	{
		temp2[i] = toupper(temp2[i]);
	}
	i = 0, j = 0;
	while (temp1[i] != '\0' && temp2[i] != '\0')
	{
		if (temp1[i] == temp2[j])
		{
			i++;
			j++;
		}
		else//�ַ�������s���˻ص��ϴβ��ҵ���һ��λ��
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (temp2[j] == '\0')
		return i - j;
	else
		return -1;
}

