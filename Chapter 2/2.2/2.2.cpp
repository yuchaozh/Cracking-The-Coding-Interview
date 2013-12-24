/*Question:
 *Implement an algorithm to find the nth to last element of a
 *singly linked list.
 *
 *Author: Yuchao Zhou
 *用string的话可以获得length，然后for循环移到nth to last处。但是调用stl的函数可能会增加O()。
 *用两个指针，一个在前，一个在后，相隔n - 1。然后一起移动即可。
 *不用先遍历一遍取得长度在移动。这样复杂度会增加。
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

void nthToLast(node* head, int n, int stringLength)
{
	if (head == NULL)
		return;
	node* p1 = head;
	node* p2 = head;
	for (int i = 0; i < n; i++)
	{
		p2 = p2->next;
	}
	while(p2)
	{
		p2 = p2->next;
		p1 = p1->next;
	}
	print(p1);
	//return p1;
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
	nthToLast(head, nth, length);
	return 0;
}

 
