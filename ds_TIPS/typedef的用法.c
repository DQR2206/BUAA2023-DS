#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
int main()
{
 typedef int dqr;
 dqr a;
 scanf("%d",&a);
 printf("%d",a);
return 0;
}
/*
 typedef��C���ԵĹؼ��֣�����ΪΪ���ӵ���������򵥵ı���
�÷����ڴ�ͳ�ı����������ʽ�У����µ������滻������
�ٰѹؼ���typedef���ڸ����Ŀ�ͷ����
 1.typedefΪ������������ȡ���� 
 ��typedef int dqr;
  dqr a;
  2.typedefΪ�Զ�����������ȡ����
   �Զ��������������ṹ��
    struct students
    {
       char sex;
       char name[120];
       int ages;
    };
    �ṹ�����¶���������
	struct students
	{
	   char sex;
	   char name[20];
	   int ages;
    }std;
    std.name[20]="duqirong";
    
    ����stryct students 
	{
	   char sex;
	   char name[20];
	   int ages;
     };
     typedef struct students std;
     std.name[20]="duqirong"
*/

