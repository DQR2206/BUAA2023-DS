/*������뽨������ C����ʵ��*/
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct linklist
{
    int data;
    struct linklist* next;
}list, * plist;
/*����С����˳�����*/
void order_insert_list(plist* head, int number)
{
    plist p_new = (plist)malloc(sizeof(list));
    plist pre = NULL;           /* preָ����Ϊtempָ��nextǰ�ı��� */
    p_new->data = number;       /* ������ֵ���½�� */
    p_new->next = NULL;
    plist temp = (plist)malloc(sizeof(list));
    temp = *head;  /*ÿ�β���ǰ������ͷ��ʼ��λ��*/
    /*��λ�ս�㸳��ֵ*/
    if (NULL == *head)
    {
        *head = p_new;
        return;
    }
    /*����data��ͷ���С��ͷ���ǰ����*/
    if (p_new->data < temp->data)
    {
        p_new->next = temp;
        *head = p_new;
        return;
    }
    else
    {
        while (NULL != temp)
        {
            if (p_new->data >= temp->data)/* �½��Ե�ǰ���data�Ƚ� */
            {
                pre = temp;
                temp = temp->next;/*��ǰ�����ƣ�ֱ��5������1 2 3 5 ����4����λ��*/
                continue;
            }
            else
            {
                p_new->next = temp;/* �����½�� */
                pre->next = p_new; /* temp��ǰһ����λ�õ�nextָ���½��p_new */
                break;
            }
        }
        if (NULL == temp)/* ��temp����Ϊβ���ʱ��˵����Ԫ��data��󣬽������Ϊβ��� */
        {
            p_new->next = NULL;
            pre->next = p_new;   /* temp��ǰһ����λ�õ�nextָ���½��p_new */
        }
    }
}
int  main()
{
    int number;
    plist head=NULL;     
    printf("input some numbers:\n");
    while (scanf("%d",&number)!=EOF)
    {
        order_insert_list(&head, number);
    }
    plist p = head;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    return 0;
}