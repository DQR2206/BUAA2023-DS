#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct ListNode
{
	int val;
	struct ListNode* next;
}ListNode;
struct ListNode* deleteDuplicates(struct ListNode* head) {
    //һ�������߼�
    // struct ListNode* l=head;
    // struct ListNode* temp=l;
    // int flag=0;
    // while(l!=NULL){
    //     if(l->next!=NULL && l->val==l->next->val){//ɾ���ظ�Ԫ�أ����˵�һ��
    //     l->next=l->next->next;//ɾ��l->next�ڵ�
    //     flag=1;//���
    //     }
    //     else{
    //      if(flag==1){
    //          if(l==head){//ɾ��ͷ�ڵ�
    //             head=head->next;
    //             flag=0;
    //             l=head;//��һ��ѭ��
    //          }
    //          else{//ɾ��l�ڵ�
    //             temp->next=l->next;
    //             flag=0;
    //             l=temp;
    //          }
    //      }
    //      else{
    //        temp=l;//temp��¼��һ���ڵ�
    //        l=l->next;//��һ��ѭ��
    //      }
    //     }

    // }
    // return head;
    //��������dummy head
    struct ListNode* dummy = malloc(sizeof(struct ListNode));//�൱��һֻ��վ����ͬ������ߴ�ͷ���һ��һ��������
    dummy->next = head;
    struct ListNode* l = dummy;
    while (l->next && l->next->next) {
        if (l->next->val == l->next->next->val) {
            int x = l->next->val;//��¼xΪ�ظ�ֵ��lΪǰһ���ڵ�
            while (l->next && l->next->val == x) {
                l->next = l->next->next;//ɾ��
            }
        }
        else {
            l = l->next;
        }
    }
    return dummy->next;
}