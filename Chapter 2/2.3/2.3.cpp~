/*Question:
 *Implement an algorithm to delete a node in the middle of a 
 *single linked list, given only access to that node.
 *EXAMPLE
 *Innput:the node 'c' from the linked list a->b->c->d->e
 *Result:nothing is returned, but the new linked list like
 *a->b->d->e
 *
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

void removenth(node* n)
{
	if (n == NULL || n->next == NULL)
	{
		cout<<"failure"<<endl;
		return;
	}
	node* p1 = n->next;
	n->str = p1->str;
	n->next = p1->next;
}
				
		
int main(int argc, char* argv[])
{
	if (argc != 3)
	{	
		cout<<"Please input one series of number and n."<<endl;
		exit(0);
	}
	string input = argv[1];
	int length = input.length();
	//argv's calss is char*, so need to change string into int
	int nth = atoi(argv[2]);
	if (nth > length)
	{
		cout<<"string's length is less than n"<<endl;
		exit(0);
	}
	if (nth < 1)
	{
		cout<<"n is less than 1"<<endl;
		exit(0);
	}
	node* head = initiate(input);
	node* target = head;
	for (int i = 1; i < nth; i++)
	{
		target = target->next;
	}
	removenth(target);
	print(head);
	return 0;
}

 
