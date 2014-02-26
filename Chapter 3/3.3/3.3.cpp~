/**
Question:

Imagine a (literal) stack of plates. If the stack gets too high, it might topple. Therefore, in real life, we would likely start a new stack when the previous stack exceeds some threshold. Implement a data structure SetOfStacks that mimics this. SetOfStacks should be composed of several stacks, and should create a new stack once the previous one exceeds capacity. SetOfStacks.push() and SetOfStacks.pop() should behave identically to a single stack (that is, pop() should return the same values as it would if there were just a single stack).

FOLLOW UP

Implement a function popAt(int index) which performs a pop operation on a specific sub-stack.

Author: Yuchao Zhou

**/
 
#include <string>
#include <iostream>
#include <stdlib.h> //exit(0);

using namespace std;

const int STACK_SIZE = 10;
const int STACK_NUM = 3;

class stack
{
public:
	int capacity;
	int cur;
	int* buff;
	
	stack()
	{
		// initate array dynamiclly
		buff = new int [STACK_SIZE];
		capacity = STACK_SIZE;
		// use -1 to judge. because 0 has content in stack.
		cur = -1;
	}
	~stack()
	{
		delete[] buff;
	}
	void push(int value)
	{
		//due to init cur = -1 before, so use ++cur, 
		//needs to plus first, cur++ is wrong
		buff[++cur] = value;
	}
	void pop()
	{
		buff[cur]=0;
		// delete: just --cur
		--cur;
	}
	int top()
	{
		return buff[cur];
	}
	bool empty()
	{
		return cur == -1;
	}
	bool full()
	{
		return cur == capacity - 1;
	}
};

class SetOfStack
{
public:
	stack* stacks;
	int current;
	int stackCapacity;

	SetOfStack()
	{
		// similar to the initiation of int array
		stacks = new stack[STACK_NUM];
		current = 0;
		stackCapacity = STACK_NUM;
	}	
	~SetOfStack()
	{
		delete[] stacks;
	}
	void push(int value)
	{
		if(stacks[current].full())
			current++;
		stacks[current].push(value);	
	}
	void pop()
	{
		// do not use if here. there are may a lot of empty.
		while(stacks[current].empty())
			current--;
		stacks[current].pop();
	}
	void popAt(int index)
	{
		while(stacks[index].empty())
			index--;
		stacks[index].pop();	
	}
	int top()
	{
		if(stacks[current].empty())
			current--;
		return stacks[current].top();
	}
	bool stackEmpty()
	{
		if(current==0)
			return stacks[0].empty();
		else
			return false;
	}
	bool stackFull()
	{
		if(current == stackCapacity - 1)
			return stacks[current].full();
		else
			return false;
	}
};

int main()
{
	//SetOfStack* stackTest = new SetOfStack();
	cout<<"total: "<<endl;
	SetOfStack stackTest;
	for(int i=0; i<2*STACK_SIZE+5; ++i){
        stackTest.push(i);
        cout<<stackTest.top()<<endl;
    }
 
    for(int i=0; i<16; ++i)
    {
        stackTest.popAt(1);
    }
	
	// show outcome
	cout<<"stack 1: "<<endl;
    for (int i = 0; i < STACK_SIZE; i++)
    {
    	cout<<stackTest.stacks[0].buff[i]<<endl;
    }
    cout<<endl;
    cout<<"stack 2: "<<endl;
    for (int i = 0; i < STACK_SIZE; i++)
    {
    	cout<<stackTest.stacks[1].buff[i]<<endl;
    }
    cout<<endl;
    cout<<"stack 3: "<<endl;
    for (int i = 0; i < STACK_SIZE; i++)
    {
    	cout<<stackTest.stacks[2].buff[i]<<endl;
    }  
    return 0;
}
	
	

 
