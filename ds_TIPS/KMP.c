#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#define maxsize 100
/*
����ǰ׺���׺
���ǰ��׺����󳤶�Ϊn-1;(�ַ�������Ϊn)
a b c a b |e a b c a b c m n
a b c a b |c m n
�Ѿ�ƥ��Ĳ���abcab,����ǰ��׺Ϊ"ab"
��ʱĸ��ָ��e,�Ӵ�ָ��c;
KMP�㷨ĸ��ָ���򲻱䣬���Ӵ�ָ������ƶ�
�ִ��ƶ��Ľ�������Ӵ��Ѿ�ƥ�䲿�ֵ�����ǰ׺���������Ⱥ�׺���ֶ���
a b c a b |e a b c a b c m n
      a b |c a b c m n
����next����洢�Ѿ�ƥ�䲿�ֵ�����ǰ��׺�ĳ���
next[i]=j;
������1.�±�Ϊi���ַ�ǰ����ǰ��׺�ĳ���
      2.�ô��ַ���ƥ��ʱӦ�û��ݵ����±�
      //�ô��ַ���ƥ�䣬�Ӵ��ƶ�������ǰ׺����һ���ַ�
��"abcabcmn"Ϊ��
next[0]=-1;
next[1]=0;
next[2]=0;
next[3]=0;
next[4]=1;
next[5]=2;
next[6]=3;
next[7]=0;
*/
typedef struct
{
    char data[maxsize];
    int length;
}SqString;
void  GetNext(SqString t, int next[])//���next���麯��
{
    int j, k;
    j = 0, k = -1;
    next[0] = -1;
    while (j < t.length - 1)
     //next�����±�j���Ϊt.length-1;ÿһ��next���鸳ֵ������j++֮��
    {
        if (k == -1 || t.data[j] == t.data[k])
        {
            j++; k++;
            next[j] = k;
        }
        else
        {
            k = next[k];
            // next[j] 
            //.�±�Ϊj���ַ�ǰ����ǰ��׺�ĳ���
             //   2.�ô��ַ���ƥ��ʱӦ�û��ݵ����±�
        }
    }
}
int KMPIndex(SqString s, SqString t)
{
    int next[maxsize], i = 0, j = 0;
    GetNext(t, next);
    while (i < s.length && j < t.length)
    {
        if (j == -1 || s.data[i] == t.data[j])
        {
            i++; j++;
        }
        else
        {
            j = next[j];//ĸ��ƥ��λ�ò��䣬�Ӵ�λ�û���
          
        }
    }
    if (j >= t.length)//�ߵ��Ӵ�ĩβ
        return i - t.length;//ƥ��ģʽ�������ַ��±�
    else
        return -1;//û��ƥ��
}
int main()
{
    SqString s, t;
    scanf("%s", s.data);
    scanf("%s", t.data);
    s.length = strlen(s.data);
    t.length = strlen(t.data);
    printf("%d", KMPIndex(s, t));
    return 0;
}
