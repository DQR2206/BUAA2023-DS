#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<malloc.h>
#include<stdlib.h>
#include<math.h>
/*
����һ�������ͷ�ڵ� head ��һ���ض�ֵ x �������������зָ���ʹ������ С�� x �Ľڵ㶼������ ���ڻ���� x �Ľڵ�֮ǰ��
��Ӧ�� ���� ����������ÿ���ڵ�ĳ�ʼ���λ�á�

˼·:ֱ��������ֻ��Ҫά���������� small��large 
small����˳��洢����С��x�Ľ��
large����˳��洢���д��ڵ���x�Ľڵ�
������ԭ����֮��small��largeβ������ 
*/
typedef struct ListNode
{
	int val;
	struct ListNode *next;
}list,listptr;
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode* small = malloc(sizeof(struct ListNode));
    struct ListNode* smallHead = small;
    struct ListNode* large = malloc(sizeof(struct ListNode));
    struct ListNode* largeHead = large;
    while (head != NULL) {
        if (head->val < x) {
            small->next = head;
            small = small->next;
        } else {
            large->next = head;
            large = large->next;
        }
        head = head->next;
    }
    large->next = NULL;//��Ϊlarge��һ�����ӵĿ�����һ��С��x�Ľ�� 
    small->next = largeHead->next;
    return smallHead->next;
}

