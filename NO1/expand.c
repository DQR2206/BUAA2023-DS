#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
int flag[100];
int main()
{
   char str[100]="";
   
   fgets(str,100,stdin);
   int i=0;
   for(i=0;i<strlen(str);i++)
   {
   	if(str[i]!='-'&&flag[i]!=1)
   	{
   		printf("%c",str[i]);
   		flag[i]=1;
	   }
   	if(str[i]=='-')
   	{
   		int k=0;
		if(islower(str[i-1])&&islower(str[i+1])&&(str[i+1]-str[i-1]>1))//����Сд���ҿ���չ 
		{
		flag[i]=1;//���б��
			int front = str[i-1]-'a',behind = str[i+1]-'a';
			for(k=front+1;k<=behind-1;k++)
			{
				printf("%c",'a'+k);//��ӡչ���ַ���δ�����ַ������� 
			}
		 } 
		else if(isupper(str[i-1])&&isupper(str[i+1])&&(str[i+1]-str[i-1]>1))//���Ǵ�д���ҿ���չ 
		{
			flag[i]=1;//�ѽ��ڵ�����Ԫ�ؽ��б�ǣ�����-���ص� 
			int front = str[i-1]-'A',behind = str[i+1]-'A';
			for(k=front+1;k<=behind-1;k++)
			{
				printf("%c",'A'+k);//��ӡչ���ַ���δ�����ַ������� 
			}
		 }  
		else  if(isdigit(str[i-1])&&isdigit(str[i+1])&&(str[i+1]-str[i-1]>1))//�������ֲ��ҿ���չ 
		{
			flag[i]=1;//�ѽ��ڵ�����Ԫ�ؽ��б�ǣ�����-���ص� 
			int front = str[i-1]-'0',behind = str[i+1]-'0';
			for(k=front+1;k<=behind-1;k++)
			{
				printf("%c",'0'+k);//��ӡչ���ַ���δ�����ַ������� 
			}
		 } 
		 else
		 {
		 	printf("-");
		 	flag[i]=1;
		 }
   	
    } 
   }
   return 0;
}


