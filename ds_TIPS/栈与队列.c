#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
/*
ջ����ж��������Խṹ�����ڲ����������Ƶ����Ա��ֱ���Ϊ�޶������ݽṹ
һ.��ջ
ֻ�����ڱ��һ�˽��в����ɾ�����������Ա����������һ�˳�Ϊջ����ջ��Ԫ�ص�λ����һ����Ϊջ��ָ��ı���(top)����
��һ�˳�Ϊջ�ף�����û��Ԫ�ص�ʱ���Ϊ��ջ
��������ջ����ջ  �Ƚ���������Ƚ���Ԫ����ջ�ף�������Ԫ����ջ��
��ջ��һ����̬�ṹ
��ջ�Ĵ洢�ṹ��Ϊ���֣�˳��洢�ṹ����ʽ�洢�ṹ
1.˳���ջ�Ĺ���
��ջ��˳��洢�ṹ������һ������M��Ԫ�ص����� stack[0...M-1]������
��ջ��һ����̬�ṹ��������һ����̬�ṹ�����þ�̬�ṹ����������һ����̬�ṹ�Ķ�ջ�������������
ջ���Ѿ���M��Ԫ�أ���ʱ������ջ�����ᷢ�������硱���Կ�ջ����ɾ�����������硱����ע��������գ�

���ջ����ջ�գ���ջ����ջ��ȡջ��Ԫ�صȲ���ʱ�临�Ӷȶ���O(1)
*/
//��ʼ��һ����ջ
//��top���ջ��Ԫ�ص�λ��
/*
#define M 1000
typedef int elemtype;
elemtype stack[M];
int top;
//����ջΪ��ʱ top==-1;
void initial(int* top)
{
	top == -1;
}
int empty(int top)
{
	return (top == -1);
}
int full(int top)
{
	return (top == M-1);
}
int gettop(elemtype *stack, int top, int* item)//ֱ�Ӱ�ջ��Ԫ�ش���item
{
	if (empty(top))
		return 0;
	else
	{
		*item = stack[top];
		return 1;
	}
}
int push(elemtype* stack, int* top, int item)
{
	if (full(top))
		return 0;
	else
	{
		stack[++(*top)] = item;
		return 1;
	}
}

ɾ�������У�ɾ��ֻ�ǽ�ջ��ָ��������һ��λ�ã�ԭ����ջ��Ԫ����Ȼ����

int pop(elemtype* stack, int* top, int* item)
{
	if (empty(top))
		return 0;
	else
	{
		item = stack[(*top)--];
		return 1;
	}
}
/*
��ջ����ʽ�洢�ṹ ��ջ
�������Ӷ�ջ�Ĳ���ʱ�临�Ӷ�O(1)�����������ڲ�֪�������ջԪ�ظ���ʱ�����ᷢ���������

typedef struct node
{
	elemtype data;
	struct node* next;
}Node,*Nodeptr;
Nodeptr top = NULL;
int isEmpty(Nodeptr top)
{
	return (top == NULL);
}
int GetTop(Nodeptr top, int* item)
{
	if (isEmpty(top))
		return;
	else
	{
		*item = top->data;
		return 1;
	}
}
//�����൱������ǰ�����һ��Ԫ��
int Push(Nodeptr* top, int item)
{
	Nodeptr p;
	if (!(p = (Nodeptr)malloc(sizeof(Node))))
		return 0;
	else
	{
		p->data = item;
		p->next = *top;
		*top = p;
		return 1;
	}
}
//ɾ����Ϊɾ����������ĵ�һ��Ԫ��
int pop(Nodeptr* top, int* item)
{
	Nodeptr p;
	if (isEmpty(*top))
		return 0;
	else
	{
		p = *top;
		item = p->data;
		*top = (*top)->next;
		free(p);
		return 1;
	}
}

��ջ��Ӧ��
һ.����ƥ����
1.����һ���յĶ�ջ�����ζ����ַ�ֱ���ļ���ĩβ
2.���õ��ַ�Ϊ�����Ż���Բ���ţ�����ѹ���ջ
������õ��ַ�Ϊ�һ����Ż���Բ����
(1).����ʱ��ջΪ�գ����ֲ�ƥ�����󣬱������
(2).����ʱ��ջ��Ϊ�գ��˳���ǰջ��Ԫ�أ��Ƴ��Ĳ�Ϊ��Ӧ�������Ż���Բ���ţ���ƥ�䣬�������
(3).�����ļ�ĩβ����ջ�ǿգ��������
����ҵ��
��.����ת��
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct node {
	int num;
	struct node* next;
}Node,*Nodeptr;
int main()
{
	Nodeptr top = NULL;
	int n;
	scanf("%d", &n);
	while (n)
	{
		Nodeptr p = (Nodeptr)malloc(sizeof(Node));
		p->num = n%8;
		p->next = NULL;
		if (top == NULL)
		{
			top = p;
		}
		else
		{
			p->next = top;
			top = p;
		}
		n=(n-n%8)/8;
}
	while (top != NULL)
	{
		printf("%d", top->num);
		top = top->next;
	}
	return 0;
}
��.�ݹ�
�ݹ���üȲ���ʡʱ�䰡��Ҳ����ʡ�ռ䣬����Ч�ʱȽϵͣ������Ǵ�ʱ��ǶȻ��ǿռ�Ƕȶ��ȷǵݹ�����
�����ݹ飬ʱ���Ϊ��ʡ 
ע��������Ƶ��ʹ�õĲ��־��������ݹ�
�ӵݹ��㷨���ǵݹ��㷨��ת��(��ջʵ��)
int func(int m, int n)
{
	if (m == 0 || n == 0)
		return m + n + 1;
	else
		return func(m - 1, func(m - 1, func(m, n - 1)));
}

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
int reccurresive(int m, int n)
{
	int stack[100], top = -1;
	do
	{
		if (m * n != 0)
		{
			stack[++top] = m - 1;
			n--;
		}
		else
		{
			n = n + m + 1;
			if (top >= 0)
				m = stack[top];
			top--;
		}
	} while (top >= -1);
	return n;
}
int main()
{
	int n, m;
	scanf("%d %d", &m, &n);
	printf("%d", reccurresive(m, n));
	return 0;
}

��.���ʽ����
�������ʽΪ��׺���ʽ��ת��Ϊ��׺���ʽ���м���
��׺���ʽ��������������������֮��
�ص�Ϊ��1.���ʽ�������ţ�Ҳ��������������ȼ���𣬼�����̰�����������ִ������
        2.��������Ⱥ������ͬ
������ʽʱ��
������������ɨ���׺���ʽ�ĸ������ʣ�
��������ĵ���Ϊ��������ͶԸ������ǰ��������������ʩ�Ը������㣬�������������ʱ��Ԫ��
��Ϊһ���µĶ����ظ���������
���磺A+(B-C/D)*E
      ABCD/-E*+;

�����׺���ʽ��
�������������һ����ջ�������Ѿ�������������󣬶�������Ϊ�������ͽ���ѹ���ջ��
��Ϊ������ʹӶ�ջ��ȡ���������������м��㣬�õ��Ľ����Ϊ�µ��������ѹ���ջ
���ʽ���Ľ��λ��topָ���ջ��

������׺���ʽ��
��׺���ʽ��������������ȫ��ͬ��ֻ�����������ĳ��˳�����˸ı�
������������ɨ�裬ÿ����һ���������Ͱ�����Ϊ��׺���ʽһ���������
���������ʱ��ǰ���������ջ��ÿ����һ��������ͽ�����ջ��λ����������ȼ����бȽ�
�����ǰ������������ȼ��ϸߣ����ջ����������һ������
��ǰ������������ȼ��ϵͣ�ջ���������ջ����Ϊ��׺���ʽһ���ֽ�������������Ƚ�
����������ֱ����ջ����������ȼ��������
���������Ž��г�ջ�����������������ʽ�У�ֱ�����������ţ����Ų��������׺���ʽ��
*/

/*
����
һ��ֻ�����ڱ��һ�˽��в������������һ�˽���ɾ�����������Ա�
��������һ�˳�Ϊ��β����βԪ�ص�λ����һ������rear(��)ָ����
����ɾ�������γ�Ϊ��ͷ����ͷԪ�ص�λ������һ������frontָ��
û��Ԫ�صĶ��г�Ϊ�ն�
���У������ȳ���
*/
/*
����˳��洢�ṹ
�������������е�˳��洢�ṹ
һά���� QUEUE[0..M-1];front ��ͷ��rear ��β
Լ����frontָ��ʵ�ʶ�ͷλ�õ�ǰһ��λ�ã�rearָ��ʵ�ʶ�βԪ�����ڵ�λ��
��ͷԪ��Ϊ queue[front+1] ��βԪ��Ϊqueue[rear];
����һ�������Ƿ�Ϊ�� front==rear

���뿼�����磬ɾ����������
��������ڶ�β���޸Ķ�βָ�룬
ɾ�������ڶ�ͷ���޸Ķ�ͷָ��
�㷨ʱ�临�ӶȾ�ΪO(1)

//��ʼ������
#define M 1000
void initialQ(int* front, int* rear)
{
	*front = -1;
	*rear = -1;
}
//���Զ����Ƿ�Ϊ��
int isempty(int front, int rear)
{
	return (front == rear);
}
//ȡ��ǰ��ͷԪ�أ��жϵ�ǰ���Ƿ�Ϊ�գ�
int getfront(int queue[], int front, int rear, int* item)
{
	if (isempty(front, rear))
		return 0;
	else
	{
		*item = queue[front + 1];
		return 1;
	}
}
//ֱ�������Ҳ���ⷵ��ֵ��ӿ�
//����ֵ������ȡԪ�صĳɹ�����ʧ��
//��ͷԪ��ͨ��ָ�����ֱ�Ӹ�ֵ��������ض�ͷԪ��ֵ�Ļ��������жϿնӵķ���ֵ������ͻ����ͷԪ�ص�ֵҲ����Ϊ0
//���
int add(int queue[], int* rear, int item)
{
	if (rear == M - 1)
	{
		return 0;
	}
	else
	{
		*(rear)++;
		queue[*(rear)] = item;
		return 1;
	}
}
//ɾ��  ��ͷָ�����β�����ƶ�һ����
int delete(int queue[],int *front,int rear,int *item)
{
	if (isempty(front, rear))
	{
		return 0;
	}
	else
	{
		*front++;
		*item = queue[*front];
		return 1;
	}

}
*/
/*
ѭ������
���в������ڶ�ͷɾ�����ڶ�β���룬���еĶ�̬�仯����ʹ�������������ƶ�
����βָ�� rear==M-1ʱ������ǰ�˿��ܻ��п��пռ�
*/
#define M 1000
//ѭ�����в���
int addcq(int queue[], int front, int* rear, int item)
{
	if ((*rear + 1) % M == front)//ѭ����������
	{
		return 0;
	}
	else
	{
		(*rear)++;
		queue[(*rear) % M] = item;
		return 1;
	}
}

//ѭ������ɾ��
int deleteq(int queue[], int* front, int rear, int* item)
{
	if (*front == rear)//ѭ������Ϊ��
		return 0;
	else
	{
		*front = (*front + 1) % M;
		*item = queue[*front];
	}
}

/*
���Ӷ���
���Զ���Ϊ�յ�����  front == NULL;
�������ٶ���ʱ�临�Ӷ�Ϊ O(N)
����������ΪO(1)
*/
typedef struct node
{
	int data;
	struct node* next;
}Node,*Nodeptr;
//��ʼ��
void initialq(Nodeptr front, Nodeptr rear)
{
	front = rear = NULL;
}
//����Ϊ��
int EMPTY(Nodeptr front)
{
	return (front == NULL);
}
//ȡ��ͷԪ��
int gettopelem(Nodeptr front, int* item)
{
	if (EMPTY(front))
		return 0;
	else
	{
		item = front->data;
		return 1;
	}
}

//���Ӷ��еĲ���
int addlink(Nodeptr front, Nodeptr rear, int item)
{
	Nodeptr p;
	if (!(p = (Nodeptr)malloc(sizeof(Node))))
		return 0;
	p->data = item;
	p->next = NULL;
	if (front == NULL)
		front = p;
	else
	{
		rear->next = p;
	}
	rear = p;
}
//���Ӷ���ɾ��
int deletelink(Nodeptr front, int* item)
{
	Nodeptr p;
	if (front == NULL)
		return 0;
	else
	{
		p = front;//�ݴ��ͷԪ��
		*item = p->data;
		front = p->next;
		free(p);
		return 1;
	}
}
//���Ӷ��е�����   
void DELETE(Nodeptr front, Nodeptr rear)
{
	while (front)
	{
		rear = front->next;
		free(front);
		front = rear;
	}
}
