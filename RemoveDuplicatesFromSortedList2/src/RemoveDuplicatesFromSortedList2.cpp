#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;


struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
void output(ListNode* head)
{
    if (head==NULL)
    {
        printf("NULL\n");
        return;
    }
	ListNode* curr=head;
	while (curr!=NULL)
	{
		printf("%d",curr->val);
		if (curr->next)
		{
			printf("->");
		}
		else
		{
			printf("\n");
		}
		curr=curr->next;
	}
}
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==NULL)
        {
            return head;
        }
        ListNode* p1;
        ListNode* p2;
        ListNode* curr;
        //先处理头一段的问题
        while(head && head->next!=NULL&&head->val==head->next->val)
        {
            curr=head->next;
            while(curr && curr->val==head->val)
            {
                curr=curr->next;
            }
            head=curr;
        }
        p1=head;
        //如果后面还有元素，则继续处理
        while (p1 && p1->next)
        {
            p2=p1->next->next;
            if (p2 && p1->next->val==p2->val)
            {
                p2=p2->next;
                while(p2 && p2->val==p1->next->val )
                {
                    p2=p2->next;
                }
                p1->next=p2;
            }
            else
            {
                p1=p1->next;
            }
            
        }
        return head;
    }
};
int main()
{
    ListNode* head=NULL;
    ListNode* curr;
	int in[]={1,1};
	for (int i=0;i<sizeof(in)/sizeof(int);i++)
    {
        if (head==NULL)
        {
            head=new ListNode(in[i]);
            head->next=NULL;
            curr=head;
        }
        else
        {
            curr->next=new ListNode(in[i]);
            curr=curr->next;
            curr->next=NULL;
        }
    }
    output(head);

    //Execute
    Solution solution;
    head=solution.deleteDuplicates(head);
    output(head);
	return 0;
}
