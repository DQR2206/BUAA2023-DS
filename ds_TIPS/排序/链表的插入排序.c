#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<malloc.h>
#include<stdlib.h>
#include<math.h>
typedef struct ListNode
{
   int val;
   struct ListNode * next;	
}ListNode;
struct ListNode* insertionSortList(struct ListNode* head){
    //�ջ���ֻ��һ���ڵ�
    if(!head || !(head->next))
        return head;

    //�����ڱ�λ
    ListNode* dummy = (ListNode*)malloc(sizeof(ListNode));
    dummy->next = head;
    //���������β�ڵ�
    ListNode* lastSorted = head;
    //������Ľڵ�
    ListNode* cur = head->next;
    while(cur)
    {
        //������Ľڵ����ú���������β�ڵ㹹������
        if(lastSorted->val <= cur->val)
        {
            lastSorted = cur;
            cur = cur->next;
        }
        else  // cur->val < lastSorted->val
        {
            ListNode* pre = dummy;
            //Ѱ�Һ��ʵĲ���λ��
            while(pre->next->val <= cur->val)  // ȡ��ȡ�Ⱦ���
                pre = pre->next;
            //���������Ľڵ�
            lastSorted->next = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            
            cur = lastSorted->next;
        }
    }

    head = dummy->next;
    free(dummy);
    dummy = NULL;
    return head;
}

int main()
{

  return 0;
}

