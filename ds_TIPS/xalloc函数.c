#define _CRT_SECURE_NO_WARNINGS 1
/*
malloc�����Ƕ�̬�ڴ���亯������������һ��������ָ����С���ڴ������
��void*���ͷ��ط�����ڴ������ַ
����ԭ�ͣ�
extern void * malloc(unsigned int num_bytes)
��Ϊ���䳤��Ϊnum_bytes�ֽڵ��ڴ��
����ͷ�ļ���stdlib.h ��malloc.h
����ɹ��򷵻�ָ�򱻷����ڴ��ָ�룬����ʧ���򷵻ؿ�ָ��NULL
�ص㣺ʹ��malloc���ٿռ�ʱ��ʹ�����һ��Ҫ�ͷſռ�
��ʹ��malloc�������ٵĿռ�ʱ����Ҫ����ָ����ƶ���һ���ƶ�֮����ܻ��������Ŀռ���ͷŵĿռ��С��ƥ��
malloc����ʹ����ʽ��
mallocֻ���ٿռ䣬���������ͼ�飬��ʹ�õ�ʱ��������͵�ǿת
malloc�������ص��������������򣬱�������ǰ�����ָ������ǿ������ת���ſ���ʹ��
���Ϊ���ҿ��ٳ�������Ҫ��С���ֽڿռ䣬������ôʹ���������
ָ������=��ָ������*��malloc(sizeof(��������)*��������)
����ʹ��malloc����֮ǰ��Ҫ����ʹ�õ����ֽ���

free����
���ã��ͷ�malloc������ָ���������Ŀռ�
ע�⣺ʹ�ú��ָ�����һ��Ҫ����ָ��NULL����ֹҰָ��
free(p);
p=NULL;

int main()
{
	int* p = NULL;
	//int n = 10;
	p = (int*)malloc(sizeof(int) * 1);
	*p = 100;
	printf("%d", *p);
	free(p);
	p = NULL;
	return 0;
}
*/
//realloc���������ڴ��С
/*
���ԭ�ռ�����㹻�Ŀռ�Ϳ���ֱ��׷�ӣ�Ȼ�󷵻ص���֮��ռ����ʼλ��
���ԭ�ռ����û���㹻�Ŀռ�����׷�ӣ�realloc�ͻ�������һ���µ��ڴ����򣬽�ԭ���ݿ�����ȥ��׷�ӣ���󷵻��¿ռ����ʼ��ַ
��һ���µ�ָ�����������realloc�����ķ���ֵ
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
int main1()
{
	int* p = (int*)calloc(10, sizeof(int));
	if (p == NULL)
	{
		printf("����ʧ��\n");
		return 0;
	}
	else
	{

	}
}