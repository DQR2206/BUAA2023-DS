//�߾�������ר�� 



//�߾��ȳ˷� ��ȫ���������� 
#include<stdio.h>
#include<string.h>
char s1[1005],s2[1005];//����������������ַ�
int int1[1005],int2[1005];//����λ����λ�������������������
int result[1000005];//�˻�������� ,����λ����λ���
int main() {
int i,j;//ѭ������
int d;//��λ
int b;//��Ű�λ�˵Ľ��
int m;//���������±�
int len_result;
//��ȡ����������
scanf("%s%s",s1,s2);
//����λ����λ�������������
int len1 = strlen(s1);
int len2 = strlen(s2);
for(i=0,j=len1-1; i < len1; i++,j--) {
int1[j]=s1[i]-'0';
}
for(i=0,j=len2-1; i<len2; i++,j--) {
int2[j]=s2[i]-'0';
}
//char�ַ����鳤�ȵ��ڶ�Ӧ��int�ַ����鳤��
//ģ����ʽ���
for(i=0; i<len2; i++) {
d=0;//һ��ʼ���,��λΪ0
m=i;
for(j=0; j<len1; j++) {
b=int2[i]*int1[j]+d+result[m];
result[m]=b%10;//��λ
m++;//Ϊ��һ����׼��
d=b/10;//��λ
}
if(d>0) { //һ����ˣ����һ�εĽ�λ
result[m]=d;
}
}
//������
len_result= len1 + len2;
while(result[len_result]==0&&len_result>0) { // ɾ��ǰ����0
len_result--;
}
for(i=len_result; i>=0; i--) {
printf("%d",result[i]);
}
return 0;
}



//�߾��ȼӷ���ֻ������ȫ���������� 
#include <stdio.h>
#include <string.h>
int main()
{
	char s1[3000], s2[3000];
	scanf("%s%s", s1, s2);
	int a[3000], b[3000], c[3000];
	memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));
	int l1 = strlen(s1);
	int l2 = strlen(s2);
	int i, j;
	for (i = 0, j = l1 - 1; i < l1; i++, j--)
	{
		a[i] = s1[j] - '0';
	}
	for (i = 0, j = l2 - 1; i < l2; i++, j--)
	{
		b[i] = s2[j] - '0';
	}
	int len = 0;
	if (l1 > l2)
	{
		len = l1;
	}
	else
	{
		len = l2;
	}
	for (i = 0; i < len; i++)
	{
		c[i] = a[i] + b[i];
	}
	for (i = 0; i < len; i++)
	{
		if (c[i] >= 10)
		{
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
		}
	}
	i = 2999;
	while (c[i] == 0 && i > 0)
	{
		i--;
	}
	for (j = i; j >= 0; j--)
	{
		printf("%d", c[j]);
	}
	return 0;
} 


//�߾��ȳ�����ȫΪ��������
#include <stdio.h>  
#include <string.h>  
int len1,len2;  
char s1[905],s2[905];  
int re[905];  
void sub()  
{  
    int i=0,j;  
    while(1)  
    {
        if(s1[i]=='0')
        {
            i++;
        }  
        else  
        {
            j=i;  
            break;  
        }  
    }  
    for(;i<len2;i++)  
    {
        s1[i]=s1[i]-s2[i]+'0';  
    }
    for(i=len2-1;i>j;i--)            //��λ��ʼ����Ƿ�С��0  
    {
        if(s1[i]<'0')  
        {  
            s1[i]+=10;  
            s1[i-1]--;  
        }
    }
}  
 
int main()  
{  
    int i,p;  
    scanf("%s%s",s1,s2);   
    len1=strlen(s1);  
    len2=strlen(s2);  
    if(len1<len2 || (len1==len2 && strncmp(s1,s2,len2)<0))   //���a<b,ֱ�����0  
    {
        printf("0\n");   
    }
    p=0;  
    while(1)  
    {  
        re[p]=0;  
        while(strncmp(s1,s2,len2)>=0)      //һֱ���м�����ֱ�����ܼ�Ϊֹ  
        {  
            sub();  
            re[p]++;  
        }  
        p++;  
        if(len1==len2)  break;  
        for(i=len2-1;i>=0;i--)             //��s2ǰ�油0���Ա���м�������  
        {
            s2[i+1]=s2[i];   
        }
        s2[0]='0';  
        len2++;  
        s2[len2]='\0';  
    }  
    i=0;  
    while(1)  
    {  
        if(re[i]==0)
        {
            i++;
        }  
        else
        {
            break;  
        }
    }  
    for(;i<p;i++)
    {
        printf("%d",re[i]);  
    }
    return 0;  
} 

//�߾��ȼ���(Ҳֻ�ܶ���������) 
#include<stdio.h>
#include<string.h>
int main(void)
{
    int len_max,i;
    char m[999],n[999],temp[999];
    int a[999]={0},b[999]={0},c[999]={0};
    scanf("%s%s",m,n);
    if(strlen(m)>strlen(n))
        len_max=strlen(m);
    else
        len_max=strlen(n);
    if(strlen(n)>strlen(m)||(strlen(m)==strlen(n)&&strcmp(n,m)>0)){
       //ʹ���������ڼ�����������ͬʱ���ú���strcmp�жϴ�С
        strcpy(temp,m);
        strcpy(m,n);
        strcpy(n,temp);
       //��������
        printf("-");  //���Ϊ��
    }
    for(i=0;i<strlen(m);i++){
        a[i]=m[strlen(m)-1-i]-'0';
    }
    for(i=0;i<strlen(n);i++){
        b[i]=n[strlen(n)-1-i]-'0';
    }
    for(i=0;i<=len_max;i++){
        c[i]=a[i]-b[i];
        if(c[i]<0){
            c[i]+=10;    //���Ͻ�λ
            a[i+1]--;
        }
    }
    int flag=0;
    for(i=len_max;i>=0;i--){  //�����ӡ
        if(c[i])
            flag=1;
        if(flag)
            printf("%d",c[i]);
    }
    if(!flag) printf("0");  //���У�
    return 0;
}




//�׳� 
#include<stdio.h>
int main()
{
 int a[10000] = { 1 }, i, up, c, s,n,j;
 scanf("%d", &n);
 c = 1;
 for (i = 1; i <= n; i++)
 {
  up = 0;//��λ
  for (j = 0; j < c; j++)//��λ��i
  {
   s = a[j] * i + up;
   a[j] = s % 10;
   up = s / 10;
  }
  while (up)//λ����
  {
   a[c++] = up % 10;
   up /= 10;
  }
 }
 
 for (i = c - 1; i >=0 ;i--)
 {
  printf("%d", a[i]);
 }
 return 0;
}


//�׳˵ĺ� 
#include<stdio.h>
int main()
{
 int a[10000] = { 1 }, i, up, c, s,n,j;
 scanf("%d", &n);
 c = 1;
 for (i = 1; i <= n; i++)
 {
  up = 0;//��λ
  for (j = 0; j < c; j++)//��λ��i
  {
   s = a[j] * i + up;
   a[j] = s % 10;
   up = s / 10;
  }
  while (up)//λ����
  {
   a[c++] = up % 10;
   up /= 10;
  }
 }
 
 for (i = c - 1; i >=0 ;i--)
 {
  printf("%d", a[i]);
 }
 return 0;
}
