/*Question:
 *Write code to remove deplicates from an unsorted linked list.
 *FOLLOW UP
 *How would you solve this problem if a temporary buffer is not
 *allowed?
 *Author: Yuchao Zhou
 */
 
#include <string>
#include <iostream>
#include <stdlib.h> //exit(0);

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
};

/** there is no need to implement a list class**/
node* initiate(string str)
{
	node* head, *p;
	for (int i = 0; i < str.length(); i++)
	{
		node* nd = new node();
		nd->str = str[i]; 
		nd->next = NULL;
		if (i == 0)
		{
			head = p = nd;
			continue;
		}
		p->next = nd;
		p = nd;
	}
	return head;
}

void print(node* head)
{
	while(head)
	{
		cout<<head->str<<"  ";
		head = head->next;
	}
	cout<<endl;
}

void deleteDups(node* head)
{
	if (head == NULL)
	{	
		cout<<"NULL"<<endl;
		return;
	}
	node *p = head;
	node *c = head;
	node *q = head;
	while(c)
	{
		p = c;
		q = c->next;
		string target = c->str;
		while(q)
		{
			if (target == q->str)
			{	
				p->next = q->next;
				q = q->next;
			}
			else
			{	
				q = q->next;
				p = p->next;
			}
		}
		c = c->next;
	}
	print(head);
}
				
		
int main(int argc, char* argv[])
{
	if (argc != 2)
	{	
		cout<<"Please input a string."<<endl;
		exit(0);
	}
	string input = argv[1];
	node* head = initiate(input);
	deleteDups(head);
	return 0;
}

 
