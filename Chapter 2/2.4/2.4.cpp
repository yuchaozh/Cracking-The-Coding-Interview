/*Question:
 *You have two numbers represented by a linked list, where 
 *node contains a single digit. The digits are sorted in 
 *reverse order, such that the 1's digit is at the head of the
 *list. Write a function that adds the two numbers and returns
 *the sum as a linked list.
 *EXAMPLE
 *Input:(3->1->5) + (5->9->2)
 *Output:8->0->8
 *
 *Author: Yuchao Zhou
 */
 
#include <string>
#include <iostream>
#include <stdlib.h> //exit(0);
#include <stdio.h>
#include <cstdlib>

using namespace std;
 
class node
{
public:
	int carry;
	int number;
	node* next;
	node()
	{
		carry = 0;
		number = 0;
		next = NULL;
	}
};

void print(node* head)
{
	while(head)
	{
		cout<<head->number<<"  ";
		head = head->next;
	}
	cout<<endl;
}

/** there is no need to implement a list class**/
node* initiate(string str)
{
	node* head, *p;
	for (int i = str.length() - 1; i >= 0; i--)
	{
		node* nd = new node();
		//change char into int
		nd->number = str[i] - '0'; 
		nd->next = NULL;
		if (i == str.length() - 1)
		{
			head = p = nd;
			continue;
		}
		p->next = nd;
		p = nd;
	}
	return head;
}

node* addLists2(node* list1, node* list2, int carry)
{
	node* nd = new node();
	nd->carry = carry;
	int value = carry;
	if(list1 != NULL)
	{
		value = value + list1->number;
		cout<<value<<endl;
	}
	if(list2 != NULL)
	{
		value = value + list2->number;
		cout<<value<<endl;
	}
	int result = value % 10;
	//cout<<result<<endl;
	nd->number = value%10;
	
	node* more = addLists2(list1 == NULL ? NULL : list1->next,
						  list2 == NULL ? NULL : list2->next,
						  value > 10 ? 1 : 0);
	nd->next = more;
	//print(nd);
}

node* addLists(node* list1, node* list2, int length1, int length2)
{
	node* point1 = list1;
	node* point2 = list2;
	node* result;
	node* current;
	int carry = 0;
	int loop = 0;
	int value = 0;
	if (length1 >= length2)
	{
		loop = length1;
	}
	else
	{
		loop = length2;
	}
	for (int i = 0; i <= loop - 1; i++)
	{
		 node* nd = new node();
		if (point1 != NULL)
		{	
			carry = carry + point1->number;
			//cout<<carry<<"    ";
		}
		if (point2 != NULL)
		{
			carry = carry + point2->number;
			//cout<<carry<<endl;
		}
		nd->number = carry % 10;
		carry = carry / 10;
		//node* newNode = new node();
		if(i == 0)
		{
			result = current = nd;
		}
		if ((point1 == NULL) && (point2 != NULL))
		{
			cout<<"here1"<<endl;
			//newNode->number = carry;
			
			point2 = point2->next;
			
			current->next = nd;
			current = nd;
			//current->next = newNode;
		}
		if ((point2 == NULL) && (point1 != NULL))
		{
			cout<<"here2"<<endl;
			//newNode->number = carry;
			
			point1 = point1->next;
			current->next = nd;
			current = nd;
			//current->next = newNode;
			
		}
		if ((point2 != NULL) && (point1 != NULL))
		{
			cout<<"here3"<<endl;
			//newNode->number = carry;
			point1 = point1->next;
			point2 = point2->next;
			current->next = nd;
			current = nd;
			//current->next = newNode;
			
		}
		if ((i == loop - 1) && (carry == 1))
		{
			node* nd = new node();
			nd->number = carry;
			current->next = nd;
			current = nd;
		} 
		if ((i == loop - 1) && (carry == 0))
		{
			cout<<"here4"<<endl;
			break;
		}
		if ((point2 == NULL) && (point1 == NULL))
		{
			break;
		}
	}
		print(result);
}

				
		
int main(int argc, char* argv[])
{
	if (argc != 3)
	{	
		cout<<"Please input two numbers."<<endl;
		exit(0);
	}
	string number1 = argv[1];
	string number2 = argv[2];
	node* head1 = initiate(number1);
	node* head2 = initiate(number2);
	print(head1);
	print(head2);
	addLists(head1, head2, number1.length(), number2.length());
	//addLists2(head1, head2, 0);
	return 0;
}

 
