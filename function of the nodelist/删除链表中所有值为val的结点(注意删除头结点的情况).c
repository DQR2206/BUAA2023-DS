#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<malloc.h>
#include<stdlib.h>
#include<math.h>
/*
ɾ����������������ֵΪval�Ľ�� ��������ͷָ�� 
����Ψһ��Ҫע����ǿ���ͷ�ڵ㱻ɾ���� 
*/
typedef struct ListNode
{
   int val;
   struct ListNode * next;	
}list,*listptr;
struct ListNode* removeElements(struct ListNode* head,int val)
{
	listptr dummy=(listptr)malloc(sizeof(list));
	dummy->next=head;
	listptr now=dummy;
	while(now->next)
	{
		if(now->next->val==val)
		{
			now->next=now->next->next;
		}
		else
		{
			now=now->next;
		}
	}
	return dummy->next;
}
int main()
{

  return 0;
}

