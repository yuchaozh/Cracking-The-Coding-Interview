/*Question:
 *Describe how you could use a single array to implement three
 *stacks
 *
 *Tricky: divide the array into three equal space and using 
 *points to record the index
 *
 *Author: Yuchao Zhou
 */
 
#include <string>
#include <iostream>
#include <stdlib.h> //exit(0);

using namespace std;

int stackSize = 300;
//initate a int array with parameter;
int* stack;
int points[3] = {0, 300, 600};

void push(int stackNumber, int value)
{
	int index = stackNumber * stackSize + points[stackNumber] + 1;
	points[stackNumber]++;
	stack[index] = value;
}

int pop(int stackNumber)
{
	int index = stackNumber * stackSize + points[stackNumber];
	points[stackNumber]--;
	int content = stack[index];
	stack[index] = 0;
	return content;
}

int top(int stackNumber)
{
	int index = stackNumber * stackSize + points[stackNumber];
	return stack[index];
}

bool isEmpty(int stackNumber)
{
	return points[stackNumber] == stackNumber * stackSize;
}
		
int main ()
{
	stack = new int[stackSize * 3];
	for (int i = 0; i <900; i++)
	{
		cout<<i<<":  "<<stack[i]<<endl;
	}
	push(0, 2);
	push(0, 222);
	push(1, 3);
	push(2, 4);
	pop(1);
	pop(0);
	pop(1);
	push(1, 999);
	cout<<top(0)<<"  "<<top(1)<<"  "<<top(2)<<endl;
	return 0;
}

 
