
typedef struct ListNode
{
	int val;
	struct ListNode* link;
}list,*listptr;
listptr deleteDuplicates(listptr head)
{
	listptr p = head;
	while (p != NULL)
	{
		if (p->link == NULL)//��Ӧ��һ��Ԫ�ص����
		{
			return head;
		}
		else
		{
			if (p->val == p->link->val)
			{
				p->link = p->link->link;
			}
			else
			{
				p = p->link;
			}
		}
	}
	return head;
}
