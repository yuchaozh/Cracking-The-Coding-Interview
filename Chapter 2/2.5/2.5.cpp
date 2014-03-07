/*Question:
 *Given a circular linked list, implement an algorithm which 
 *returns node at the beginning of the loop.
 *Circular linked list: A (corrupt) linked list in which a 
 *node's next pointer points to an earlier node, so as to make
 *a loop in the linked list.
 *EXAMPLE
 *Input:A->B->C->D->E->F->C (the same C as earlier)
 *Output:C
 *Trick:
 *Head is k nodes from loopstarts
 *meetingpoint for n1 and n2 is k nodes from loopstart
 *Author: Yuchao Zhou
 */
 
#include <string>
#include <iostream>
#include <stdlib.h> //exit(0);
#include <cstdlib>

using namespace std;
 
class node
{
public:
	string str;
	node* next;
	node()
	{
		str = "";
		next = NULL;
	}
	node(string s)
	{
		str = s;
		next = NULL;
	}
};

void print(node* head)
{
	while(head)
	{
		cout<<head->str<<"  ";
		head = head->next;
	}
	cout<<endl;
}

/** there is no need to implement a list class**/
node* initiate()
{
	node* head;
	node* A = new node("A");
	node* B = new node("B");
	node* C = new node("C");
	node* D = new node("D");
	node* E = new node("E");
	node* F = new node("F");
	head = A;
	A->next = B;
	B->next = C;
	C->next = D;
	D->next = E;
	E->next = F;
	F->next = E;
	return head;
}

/**
node* findLoop(node* n)
{
	if (n == NULL || n->next == NULL)
	{
		cout<<"no loop"<<endl;
		return NULL;
	}
	node* n1 = n;
	node* n2 = n;
       //while (n2->next != NULL) is wrong when only has two nodes (1, 2)
        while (n2->next && n2->next->next)
	{
		n1 = n1->next;
		n2 = n2->next->next;
		if (n1 == n2)
			break;
	}
	
	if (n2->next == NULL)
	{
		cout<<"no loop"<<endl;
		return NULL;
	}
	
	n1 = n;
	while (n1 != n2)
	{
		n1 = n1->next;
		n2 = n2->next;
	}
	return n1;
}		
**/

class Solution 
{
public:
    ListNode *detectCycle(ListNode *head) 
    {
    	bool hasCycle = false;
		if (head == NULL || head->next == NULL)
			return NULL;
		ListNode* n1 = head;
		ListNode* n2 = head;
		// while(!n2->next == NULL) is wrong.
		// only has two nodes 1, 2
		while(n2->next && n2->next->next)
		{
			n1 = n1->next;
			n2 = n2->next->next;
			if (n1 == n2)
			{
				hasCycle = true;
				break;
			}
		}
		
		// judge has cycle or not
		if (hasCycle == true)
		{
			// let n1 point to the start point, and let n1 and n2 move forward,
			// the meet point is the start of the loop
			n1 = head;
			while (n1 != n2)
			{
				n1 = n1->next;
				n2 = n2->next;
			}
			return n1;
		}
		else
			return NULL;
    }
};


int main()
{
	node* head = initiate();
	node* loop = findLoop(head);
	if (loop != NULL)
		cout<<loop->str<<endl;
	return 0;
}

 
