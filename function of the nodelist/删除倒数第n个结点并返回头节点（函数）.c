#include<stdio.h>
//ɾ�������е�����n����㲢����ͷָ�루һ�α�����������
struct ListNode
{
    struct ListNode* next;
};
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* ptr1 = head;
    struct ListNode* ptr2 = head;
    int i;
    for ( i = 0; i < n; i++)//ptr1���ߣ���ptr2�γ�·�̲�
    {
        ptr1 = ptr1->next;
        if (ptr1 == NULL)
        {
            head = head->next;
            return head;
        }
    }
    while (ptr1->next != NULL)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    if (ptr1 == head)
    {
        head = head->next;
        free(ptr1);
        return head;
    }
    struct ListNode* p = ptr2->next;
    ptr2->next = ptr2->next->next;
    free(p);
    return head;
}
