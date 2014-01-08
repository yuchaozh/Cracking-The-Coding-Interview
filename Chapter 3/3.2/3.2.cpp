/*Question:
 *How would you design a stack which, in addition to push and 
 *pop, also has a function min which returns the minimum element
 *? Push, pop and min should all operate in O(1) time
 *
 *Tricky: each node in the stack keep track of the minimum
 *beneath itself.
 *Another better solution is build two stack, if the vale <= 
 *min, then push the value into the second stack. 
 *
 *Author: Yuchao Zhou
 */
 
#include <string>
#include <iostream>
#include <stdlib.h> //exit(0);

using namespace std;

const int MAX_INT = ~(1<<31);//2147483647

class stackNode
{
public:
	int value;
	int min;
};

int stackSize = 300;
int index = -1;
//initate a stackNode array with parameter;
stackNode * stack;

void push(int val)
{
	index++;
	stack[index].value = val;
	if (index == 0)
		stack[index].min = val;
	else
	{
		if (val < stack[index-1].min)
			stack[index].min = val;
		else
			stack[index].min = stack[index-1].min;
	}
} 

int pop()
{
	int content = stack[index].value;
	stack[index].value = 0;
	stack[index].min = 0;
	index--;
	return content;
}

int top()
{
	return stack[index].value;
}

int min()
{
	return stack[index].min;
}


		
class stack2
{
public: 
	int index2;
	int* buff;
	
	stack2(int stackSize2 = 300)
	{
		buff = new int[stackSize2];
		index2 = -1;
	}
	~stack2()
	{
		delete[] buff;
	}
	void push(int val){
        buff[++index2] = val;
    }
    void pop(){
        --index2;
    }
    int top(){
        return buff[index2];
    }
    bool empty(){
        return index2==-1;
    }
};

class stackWithMin2
{
public:

	stack2 s1, s2;
	stackWithMin2()
	{
		s2.push(MAX_INT);
	}
	
	~stackWithMin2()
	{
		
	}
	
	void push(int val)
	{
		s1.push(val);
		if (val <= min())
			s2.push(val);
	}
	void pop()
	{
		if (s1.top() == min())
			s2.pop();
		s1.pop();
	}
	int top()
	{
		return s1.top();
	}
	int min()
	{
		if (s2.empty())
			return MAX_INT;
		return s2.top();
	}
};

int main ()
{
	/**
	stack = new stackNode[stackSize];
	push(3);
	push(2);
	push(-55);
	push(1);
	push(9999);
	cout<<index<<"  "<<min()<<"  "<<top()<<endl;
	**/
	stackWithMin2 stackMin;
	stackMin.push(1);
	stackMin.push(2);
	stackMin.push(-3);
	stackMin.push(4);
	stackMin.push(5);
	stackMin.pop();
	stackMin.pop();
	stackMin.pop();
	stackMin.pop();
	cout<<stackMin.top()<<"  "<<stackMin.min()<<endl;
	return 0;
}

 
