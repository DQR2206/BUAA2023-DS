
/*
C�����ļ��Ķ��壬��ζ��ļ��������ļ�ָ�룬ͨ��ָ����ļ����в���

�ļ��Ķ��壺�ļ��������Ϣ�ļ���
C������ļ��Ĳ���
1.�����������ļ�������ļ�������ȡ���������������Ļ������ı��ļ������ݣ�
2.д��������һЩ�������ļ�����д�루��ı��ļ������ݣ�

C����ͨ���ļ���ָ�벢����һЩ����Ȼ����ļ����в���
�ļ�ָ�룺����ļ����׵�ַ�����ָ������ר��ָ���ļ�

�����ļ�ָ��
��ʽ��FILE *ָ����
��  FILE *pf;������һ��ֻ��ָ���ļ���ָ�룬֮��Ҫ���ļ����׵�ַ��ֵ����ָ��

���ļ�ָ�븳���ֵ
��θ�ֵ:ͨ��fopen������ָ����и�ֵ
fopen����
A.���ļ�
B.ͬʱ���������ļ����׵�ַ
C.�ú���ʵ���Ͼ��ǵ�ַ
��ʽ��fopen("Ҫ�򿪵��ļ���"�����򿪷�ʽ��)��
˵����
1.�򿪷�ʽ�Ǳ������ļ�֮����Ҫ������Ҫд
2.�򿪷�ʽ��
r:���ļ�֮��Ҫread
w:���ļ�֮��Ҫwrite���µ����ݸ��ǵ��ɵ�����
a:���ļ�֮��׷���ļ�append ���µ����ݼӵ�ĩβ
r+:��д��ʽ����дλ�����ļ���ͷ��
w+:��д��ʽ�����ļ�����ʱ��ո��ļ�
a+������׷�ӷ�ʽ��������д���ļ�ĩβ���ļ�������ʱ�������ļ�
rb:�򿪶������ļ����ж�
wb:�򿪶������ļ�����д

�򿪵��ļ���·���к���\��ʱ���Ҫ��\\
fopen("c:\\duqirong\\my.txt","r");
Ҫ�򿪵��ļ����������ļ�����·��(�Ҽ��ļ��������ļ���ַ����)

�ر��ļ�
A��ͨ��fopen�ܹ����ļ���֮����ļ����в���
B��������֮��ͨ�� fclose(�ļ�ָ��)���ر��ļ�

int main()
{
	FILE* fp;//�����ļ�ָ��
	fp = fopen("C:\\Users\\86132\\Desktop\\��һ�����ݽṹ��ҵ\\example1c.c", "w");//ָ������ļ�
	//���ļ����в���
	fclose(fp);
	return 0;
}

4.���ļ������ĺ���
1��fgetc
  ���ܣ���fp��ָ����ļ��ж�ȡ��һ���ַ�(r)
  ��ʽ���ַ��ͱ���=fgetc(fp);//fpΪ�ļ�ָ��
  �ļ�һ��Ҫ�Զ��ķ�ʽ�򿪣�֮��ָ����Զ�����ƶ�һ��λ��!!!!�����������ʵ�ֶ�ȡ�����ļ�
2)fputc
  ���ܣ���fp��ָ����ļ�����д��һ���ַ�
  ��ʽ��fputc(Ҫд����ַ���fp);
  �ļ�һ��Ҫ��д�ķ�ʽ�򿪣�֮��ָ����Զ�����ƶ�һ��λ��
3��fgets
  ���ܣ���fp��ָ����ļ������ȡ����һ���ַ���
  ��ʽ��fgets(str,n,fp);�������n-1���ַ�����һ���ַ�Ϊ\0
  str:����ַ���������  �ļ��򿪷�ʽΪr;
  ����ʵ�鷢�֣���ȡ����ʱ������򿪷�ʽд����"w",���򿪵��ļ��ᱻ���
4��fputs
  ���ܣ����ַ���д�뵽fpָ����ļ�����
  ��ʽ��fputs(str,fp);

  �ܽ᣺�����йض�ȡ�Ĳ�������> "r"
  �й�д��Ĳ�������> "w"
  ���"r"����Ϊ"w"�ᵼ�´򿪵��ļ������
  "w"����Ϊ"r"��Դ�ļ���Ӱ��

5)ר�ŶԶ������ļ����в���
  A)fwrite
  ���ܣ���һ���ṹ������е���Ϣ�Զ����Ƶ���ʽд�뵽ָ�����ļ�����
  ��ʽ��fwrite(&�ṹ���������sizeof(�ṹ������)��1��fp)
  B)fread
  ���ܣ���fp��ָ����ļ����ж���һ����Ϣ�������һ���ṹ�������
  ��ʽ��fread(&�ṹ���������sizeof(�ṹ������)��1��fp)
6)feof( EOF ?)
 ���ܣ��ж�ָ���ļ���ָ���Ƿ�ָ���ļ���ĩβ
 ��ʽ��feof(�ļ�ָ��)������1����ָ��ĩβ������0����û��ָ��ĩβ
 һ����÷���
 while(!feof(fp));

 fscanf(FILE* stream, const char* format, ...);
fprintf(FILE* stream, const char* format, ...);
��һ������ָ�ļ���
fscanf(stdin,"%d%d",%a,%b);// FILE* stdin:��׼�����ļ������̣�
fprintf(srdout,"%d",a+b);// FILE* stdout :��׼����ļ�(��ʾ��)
C�����ڿ�ʼʱ�Զ��򿪵ı�׼�ļ���stdin,stdout,stderr,Ҳ������FILE*�͵�ָ��

freopen����,�ض����׼��������ĺ���
�ض����������ԭ������ڿ���̨���ַ������ָ���ļ�·������
�ض������룺��ָ�����ļ��ж�ȡ�������Ƕ�ȡ�ڿ���̨�е�����
��׼������FILE *freopen(const char *path,const char *mode,FILE *stream)
freopen����������stdio.h��
path:�ļ��������ڴ洢����������Զ����ļ���
mode:�ļ��򿪵�ģʽ����freopen�е�ģʽ��ͬ
streamһ���ļ������ñ�׼���ļ�
����ֵ���ɹ�������path��ָ���ļ���ָ�룻ʧ�ܷ���NULL
ֻ����������ĵط���һ��������������д
freopen("in.txt", "r",stdin);
	freopen("out.txt", "w", stdout);
	int a, b;
	scanf("%d%d", &a, &b);
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	printf("a+b=%d", a + b);
	fclose(stdin);
	fclose(stdout);
	return 0;

�������е�Сд��ĸ��дΪ��д���洢Ϊ��һ���ļ�
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<ctype.h>
int main()
{
	char ch;
	FILE* Rstream = fopen("in.txt", "r");
	if (Rstream != NULL)
	{
		FILE* Wstream = fopen("out.txt", "w");
		if (Wstream != NULL)
		{
			ch = getc(Rstream);
			while (!feof(Rstream))
			{
				fputc(isalpha(ch) ? toupper(ch) : ch, Wstream);
				ch = fgetc(Rstream);
			}
		}
		fclose(Rstream);
	}
	return 0;
}

while (fgets(line[input], N, stream)!=NULL)
	{
		len = strlen(line[input]);
		if (len > 0 && line[input][len - 1] == '\n')
		{
			line[input][len - 1] = '\0';
			len--;
		}
�����ڿռ����ʱfgets����������ַ���ĩβ�Ļ��з�\n;
��Ҫ�����⴦���\n����\0

*/
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100
int main1()
{
	FILE* stream;
	char* filename = "in.txt";
	char line[2][N] = { {""} };
	int input = 1, longest = 0, tmp;
	int max_len = 0, len;
	stream = fopen(filename, "r");
	if (stream == NULL)
	{
		perror("can not open file.\n");
		exit(-1);
	}
	while (fgets(line[input], N, stream)!=NULL)
	{
		len = strlen(line[input]);
		if (len > 0 && line[input][len - 1] == '\n')
		{
			line[input][len - 1] = '\0';
			len--;
		}
		if (len > max_len)
		{
			max_len = len;
			tmp = input;
			input = longest;
			longest = tmp;
		}
	}
	printf("longest line : %s\n", line[longest]);
	printf("line characters : %d\n", max_len);
	fclose(stream);
	return 0;
}