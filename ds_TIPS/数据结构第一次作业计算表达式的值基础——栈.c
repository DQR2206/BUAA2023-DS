#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
//������������ݽṹ ջ
/*
ջ�����ݽṹ�����������������򵯼���ѹ���ӵ�
FILO:first in last out��ȡԪ��ֻ��ȡջ��Ԫ�أ���������ջ��Ԫ������ȡ 
����������ɾ��Ԫ��ֻ���������β������
���ݷ����ջ������ջ
ɾ�����ݳ�Ϊ��ջ����ջ����ջ����ջ������
��ʼʱջΪ��ջ��ջ��λ��top==0,λ�������׶ˣ�����ѹ��Ԫ�أ�ջ��������β���ƶ�
ջ��λ�ñ�ջ��Ԫ�ش�һ   
λ��ջ����Ԫ�س�Ϊջ��Ԫ�� 
 ջ�����Ų����ɾ��Ԫ�ظı�λ�� 
 ��ջǰ�ж�ջ�Ƿ�����
 ��ջ����ȡջ��Ԫ��ʱ�ж�ջ�Ƿ��ѿ� 
*/ 
#define maxsize 100
int stack[maxsize];//����������Ϊ��ջ�Ĵ洢�ṹ 
int top;//���ñ���top��¼ջ��λ��  top==0��ջ   top==maxsize ջ�� 
int isStackEmpty();//�ж�ջ�Ƿ�Ϊ�� 
int isStackFull();//�ж�ջ�Ƿ����� 
void push(int );//��ջ 
void pop();//��ջ 
int getTop();//ȡջ��Ԫ�� 

int main()
{
	int i;
   for( i=1;i<=8;i++)
   {
   	if(!isStackFull())
   	 push(i);
	  }  
	while(!isStackEmpty())
	{
		printf("%d ",getTop());//ȡ��ջ��Ԫ�� 
		pop();//��ջ������ 
	 } 
	 return 0;
}
//�ж�ջ��
int isStackEmpty()
{
	return (0==top);
 } 
//�ж�ջ��
int isStackFull()
{
	return maxsize==top;
 } 
//��ջ
void push(int e)
{
	if(top<maxsize)
	stack[top++]=e;//ջ����λ�÷����µ�Ԫ�أ�ջ������
	else
	printf("StackFull!"); 
 } 
//��ջ
void pop()
{
	if(top>0)//��Ԫ��
	--top;//��ջΪʲôֻҪ�ƶ�ջ���Ϳ����ˣ� ��ջ��ԭ�������ݻ���ջ������Ѿ���Ϊ���� 
	else
	printf("StackEmpty!"); 
 } 
//ȡջ��Ԫ��
int getTop()
{
	if(top>0)
	return stack[top-1];//˵��ջ��λ��ջ��Ԫ�غ�
	else
	{
		printf("StackEmpty!");
		return -1;//����ֵ������
		/*
		ע�⣺return 0  һ����������������ʱ����ʾ�������ɹ����
		      return -1  һ�������Ӻ�����β����ʾ�ú���ʧ�� 
		*/ 
	 } 
 } 
