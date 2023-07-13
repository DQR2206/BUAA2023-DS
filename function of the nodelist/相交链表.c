#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<malloc.h>
#include<stdlib.h>
#include<math.h>
/*
���������������ͷ�ڵ� headA �� headB �������ҳ������������������ཻ����ʼ�ڵ㡣����������������ཻ�ڵ㣬���� null ��
*/
struct ListNode
{
   int val;
   struct ListNode *next;	
};
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL) {
        return NULL;
    }
    struct ListNode *pA = headA, *pB = headB;
    while (pA != pB) {
        pA = pA == NULL ? headB : pA->next;
        pB = pB == NULL ? headA : pB->next;
    }
    return pA;
}


//��
typedef struct ListNode ListNode;

//�ж����������Ƿ����ཻ �������ཻ��㣨�ཻ->����ַ��ʼ��ͬ��

//˫ָ�뷨��

//�뷨1�������������һ�������ǰ�Ƚϼ���-->���������޷���ǰ���� ��PASS
//�뷨2���ȱ���������������ȣ���ָ�������ָ�����ߣ����Ȳ������ʼ������ָ��
//������ͬ��㼴��

int ListSize(ListNode* head)  //�������Ⱥ���
{
    ListNode* p = head;
    int size = 0;
    while(p)
    {
        size++;
        p = p->next;
    }
    return size;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    ListNode* cur1 = headA;
    ListNode* cur2 = headB;

    int sizeA = ListSize(headA);
    int sizeB = ListSize(headB);
    int step = 0;
    if(sizeA > sizeB)
    {
        step = sizeA - sizeB;
        while(step--)
        {
            cur1 = cur1->next;
        }
    }
    else
    {
        step = sizeB - sizeA;
        while(step--)
        {
            cur2 = cur2->next;
        }
    }

    //��ʼָ�����
    while(cur1)
    {
        if(cur1 == cur2) //����ָ��ָ��ĵ�ַ��ͬ ˵��ָ��Ľ������ཻ���
        {
            return cur1;
        }
        else //����ָ��ָ��ͬ ��������
        {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
    }

    return NULL;
}

