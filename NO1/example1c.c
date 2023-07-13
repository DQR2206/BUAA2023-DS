#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#define maxsize 100
char sign[maxsize];//�洢�������ջ 
int num[maxsize];//�洢���ֵ�ջ 
int topnum,topsign;
char line[maxsize],sub[maxsize];
int isStackFullNum( );
int isStackEmptyNum( );
int isStackFullSign( );
int isStackEmptySign( );
void pushnum(int );
void pushsign(char );
void popnum( );
void popsign();
int getTopNum( );
char getTopSign();
int compare(char );//�Ƚ���������ȼ� 
int calculate(char rela,int num1,int num2)
{
	if(rela=='*')
	{
		return num1*num2;
	}
	else if(rela=='/')
	{
		return num1/num2;
	}
	else if(rela=='+')
	{
		return num1+num2;
	}
	else 
	{
		return num1-num2;
	}
}
int main()
{
   int i,j=0,k;
   gets(line);//����ʱǧ����Ŵ��ȥ�Ⱥ� 
   //ɾ�����ʽ�еĿո� 
   for(i = 0; line[i]!='=' ;i++)
   {
   	if(line[i]!=' ')
   	{
   		sub[j++]= line[i];
	   }
   }
   sub[j]='\0';
  // printf("%s\n",sub); 
   for(i = 0;sub[i]!='\0';i++)
   {
   	if(isdigit(sub[i]))
   	{
   		int cnt=0,sum=0,rem=i;
   		if(isdigit(sub[i+1]))
   		{
   			while(isdigit(sub[i+1]))
   			{
   			i=i+1;
   			cnt=cnt+1;
   		    }
   		    for(j=0;j<=cnt;j++)
		{
			sum=sum+(int)pow(10,cnt-j)*(sub[rem+j]-'0');
		}
		pushnum(sum);
		}
	    else{
	          pushnum(sub[i]-'0');
        	}
	
	   }
   //��ȡ�ַ����е���   �Ѿ��ɹ��� �����12��ȡ������ 
	//���з��Ŵ���   �ҵ�sub�ִ�����û��'='�� 
	else if(sub[i]=='*'||sub[i]=='/'||sub[i]=='-'||sub[i]=='+')
	{
		if(isStackEmptySign())//����ջΪ��ֱ�Ӳ��� 
		{
			pushsign(sub[i]);
			//printf("%c",sign[0]);//�����Ѿ���ȷ�����˰� 
		}
		else   //������ ,��Ҫ�о������ 
		{
			//ѹ����Ź��� 
			if(compare(sub[i]))
			{
				pushsign(sub[i]);
			//	printf("%c",sign[1]);
			}
			else
			{
			  //�����������ȼ�������
			 /*
			 ���ó�signջ��Ԫ�غ�num������ջ��Ԫ��
			 ������ѹ��num��Ϊ�µ�ջ��Ԫ�أ����ϼ���ֱ��Ҫ����ķ������ȼ�����
			 �˳����Ӽ����Ӽ�����ջ,�Ƚ���ѭ��ģ����� 
			 */ 
			 while(!compare(sub[i]))
			 {
			 	char op=getTopSign();
			 	popsign();
			 	int num2=getTopNum();
			 	popnum();
			 	int num1=getTopNum();
			 	popnum();
			 	//ȡ��һ������������,ջ����Ӧ�����ƶ� 
				pushnum(calculate(op,num1,num2)); 
				
			 }
			 pushsign(sub[i]);
			}
		}
	}
   }
  
   for(i=0;i<3;i++)
   {
   	//printf("%c",sign[i]);
   }
   //sign����ѹ����ȷ 
   
   //���ʽɨ�����
   if(isStackEmptySign())//sign����Ϊ�� 
   {
   	for(j=0;j<topnum;j++)
   	{
   		printf("%d",num[j]);
	   }
   }     //500 = ������ ������ջΪ�յ��������� 
   else{
   	while(!isStackEmptySign())
   	{
   		 char op=getTopSign();
   		 popsign();
   		 int num2=getTopNum();
   		 popnum();
   		 int num1=getTopNum();
   		 popnum();
   		 pushnum(calculate(op,num1,num2));
	   }
    printf("%d",num[0]);
} 
   return 0;
}
int isStackEmptyNum()
{
	return (0==topnum);
}
int isStackFullNum()
{
	return (maxsize==topnum);
}
int isStackEmptySign()
{
	return (0==topsign);
}
int isStackFullSign()
{
	return (maxsize==topsign);
}
void pushnum(int e)
{
	if(topnum<maxsize)
	{
		num[topnum++] = e;
	}
}
void pushsign(char ch)
{
	if(topsign<maxsize)
	{
		sign[topsign++] = ch;
	}
}
void popnum()
{
	if(topnum>0)
	topnum--;
}
void popsign()
{
	if(topsign>0)
	topsign--;
}
int getTopNum()
{
	if(topnum>0)
	return num[topnum-1];
	else
	return -1;
 } 
char getTopSign()
{
	if(topsign>0)
	return sign[topsign-1];
	else
	return -1;
}
int compare(char now)//��ѹס�ļ�������� 
{
	if(now=='*'&&sign[topsign-1]=='+'||now=='*'&&sign[topsign-1]=='-'||now=='/'&&sign[topsign-1]=='+'||now=='/'&&sign[topsign-1]=='-')
	return 1;
	else if(topsign==0)
	return 1;
	else
	return 0;
 } 

