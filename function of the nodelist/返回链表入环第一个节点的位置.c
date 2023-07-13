#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
/*
��������λ��(������0��ʼ)
��һ���൱����һ��ļ�ǿ�棬����ע����ѧ�Ƶ�
��������Ƶ���
���������ͷ�ڵ㵽�뻷��ľ���Ϊa,fast��slow�����㽫Բ���ֳɵĳ��ȷֱ�Ϊb,c
���ٶȹ�ʽ a+(b+c)*n+b=2*(a+b)���������֤���ض�����ָ������һȦ֮ǰ��������
           �õ�a= (n-1)*(b+c)+c;
        ��ʱ���ǿ��Զ���һ��ָ��ptrָ�������ͷ�ڵ�
        ��fast��slow����ʱ��ptr��ʼ��slowͬʱ����ƶ�����������λ�ü�Ϊ����
*/
struct ListNode
{
    int val;
    struct ListNode* next;
};
struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* slow = head, * fast = head;
    while (fast != NULL) {
        slow = slow->next;
        if (fast->next == NULL) {
            return NULL;
        }
        fast = fast->next->next;
        if (fast == slow) {
            struct ListNode* ptr = head;
            while (ptr != slow) {
                ptr = ptr->next;
                slow = slow->next;
            }
            return ptr;
        }
    }
    return NULL;
}
