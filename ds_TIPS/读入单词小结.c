#define _CRT_SECURE_NO_WARNINGS 1
//1.���ö�ά���鷽ʽͳ�Ƶ���
/*
������Ҫע����ǣ����ڶ�ȡ��ʽ��fgetc(ch);
ÿ����һ���ַ����ļ�ָ����Զ�����һλ��
ע�ⲻҪ����
ע�⣺fgetc��fgets ����ֵΪ�ɹ���ȡ���ֽ����������ļ�ĩβʱ����EOF
*/
char word[500][50];
int main()
{
	int cnt = 0;//��¼���ʸ���
	int place = 0;//��¼ÿ�������ж�������ĸλ��
	int flag = 1;//��ǵ���
	FILE* RSTREAM = fopen("article.txt","r");
	char ch = fgetc(RSTREAM);
	while (ch != EOF)
	{
		if (isalpha(ch))
		{
			flag = 0;
			word[cnt][place] = tolower(ch);//ת����Сд��ĸ
			place++;//���ж�ȡλ�ú���
		}
		else//����Ĳ�����ĸ��
		{
			if (flag != 1)//˵����һ������Ļ�����ĸ������һ��������ĸ���������е�¼��
			{
				word[cnt][place] = '\0';
				cnt++;//������һ��
				flag = 1;
				place = 0;
			}
			//��ʱ������ж�flag==1
			// ��˵����һ����ȡ��Ҳ������ĸ��������һ�У�ͨ��flagһֱ����1���������м�������ַ�
		}
		ch = fgetc(RSTREAM);//������һ���ַ�
	}
	fclose(RSTREAM);
}


/*
ʹ������ʽʵ��
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct node
{
	char s[100];
	int num;
	struct node* next;
}Node,*Nodeptr;
Nodeptr list;
char s[1010];
char aaa[1010], * fro, * p;
char* read(char* ch, char* t, char* end)//��ȡ���ʺ���
{
	while (!isalpha(*ch))//��������ĸ�ַ�
	{
		ch++;
	}
	if (ch >= end)//��Ч��
	{
		return NULL;
	}
	while (isalpha(*ch))
	{
		*t = *ch;
		ch++;
		t++;
	}
	*t = 0;
	return ch;
}
Nodeptr insert(char* t)//���뺯�����ڲ���Ĺ����о�����������ȥ��
{
	Nodeptr pre = list, now = list->next;
	if (now == NULL)//���ʱ��л�û�е���
	{
		Nodeptr tmp = (Nodeptr)malloc(sizeof(Node));
		strcpy(tmp->s, t);//ֱ�Ӳ���
		tmp->num = 1;
		tmp->next = NULL;
		list->next = tmp;
		return tmp;
	}
	//��ʱnow�ĳ�ʼֵΪlist->next;list��Ϊͷ�ڵ㲻���Ԫ��
	for (; now != NULL; pre = now, now = now->next)//now=list->next!=NULL˵����ʱ�����Ѿ���Ԫ��
	{
		int fl = strcmp(t, now->s);
		if (fl < 0)//�²���ĵ��ʵ��ֵ���ȵ�ǰָ��ĵ���ҪС�����뵽ǰ�ˣ�����
		{
			Nodeptr tmp = (Nodeptr)malloc(sizeof(Node));
			strcpy(tmp->s, t);
			tmp->num = 1;
			tmp->next = now;//���뵽ǰ��
			pre->next = tmp;
			return tmp;
		}
		else if (fl == 0)//����ͬ�ĵ��ʣ�ȥ�أ�
		{
			now->num++;
			return now;
		}
	}
	//�˳�ѭ��ʱ��û����˵���ֵ�������е����κ�һ�����󣬲��뵽���
	Nodeptr tmp = (Nodeptr)malloc(sizeof(Node));
	strcpy(tmp->s, t);
	tmp->num = 1;
	tmp->next = NULL;
	pre->next = tmp;//��ǰpre->nowָ�����һ����Ϊ�յĽ�㣬now�Ѿ�ָ��NULL��
	return tmp;
}
int main()
{
	freopen("article.txt", "r", stdin);
	list = (Nodeptr)malloc(sizeof(Node));//����ͷ�ڵ�
	list->next = NULL; fro = aaa;
	while (gets(s) != NULL)//���ж���
	{
		int i;
		for (i = 0; i < strlen(s); i++)
		{
			if (isalpha(s[i]))
			{
				s[i] = tolower(s[i]);
			}
		}
		p = s;
		while (1)
		{
			p = read(p, fro, s + strlen(s));
			if (p == NULL)
			{
				break;
			}
			insert(fro);
		}
	}
	Nodeptr now = list->next;
	//���
	while (now != NULL)
	{
		printf("%s %d\n", now->s, now->num);
		now = now->next;
	}
	return 0;
}


int getword(FILE* fp,char *w)
{
  int c;//�����c����Ϊint���ͱȽ��ȶ� ��Ϊc���ܷ���ֵ������EOF��Ϊ-1����char����û��-1��˵��
  while(!isalpha(c=fgetc(fp)))
  if(c==EOF)return c;
  else continue;
  do
{
  *w++=tolower(c);
}while(isalpha(c=fgetc(fp)));
 *w='\0';//������
 return 1;
}
