#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
struct ListNode
{
    int val;
    struct ListNode* next;
};
int hasCycle(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return 0;
    }
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
    while (slow != fast) {
        if (fast == NULL || fast->next == NULL) {
            return 0;
        }
        slow = slow->next;//��һ��
        fast = fast->next->next;//������
    }
    return 1;
}
/*
�����л��������õ��˿���ָ���˼�룬�������ܷ�(flyod��Ȧ��)
��ָ�������Ȧ������׷����ָ��
*/
