/**

Implement a MyQueue class which implements a queue using two stacks.

Idea1: 队列是先进先出的数据结构(FIFO)，栈是先进后出的数据结构(FILO)， 用两个栈来实现队列的最简单方式是：进入队列则往第一个栈压栈， 出队列则将第一个栈的数据依次压入第二个栈，然后出栈。每次有数据进入队列， 都先将第二个栈的数据压回第一个栈，然后再压入新增的那个数据； 每次有数据出队列，都将第一个栈的数据压入第二个栈，然后第二个栈出栈。

Idea2(Based on Idea1):对于上面的实现，我们可以稍作改进来提高效率。上面的实现方法， 数据在两个栈之间移动得太频繁了，必然会导致效率下降。事实上有些移动是没有必要的。 有数据进入队列时，我们不去管第二个栈是否有数据，只管往第一个栈压栈即可。 当数据出队列时，如果第二个栈有数据，那就出栈。 因为此时第二个栈的栈顶元素即为队列的队首元素；如果第二个栈没有数据， 这才将第一个栈的数据出栈移动到第二个栈，然后第二个栈再出栈。这样一来， 逻辑上相当于将一个队列从中间切开，第一个栈从栈顶到栈底对应队列的队尾到切开处， 第二个栈从栈顶到栈底对应队列的队首到切开处。这样简单的修改， 可以减少许多不必要的数据移动，提高效率。

Author: Yuchao Zhou

**/
 
#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class MyQueue
{
public:
	MyQueue()
	{
		
	}
	~MyQueue()
	{
	
	}
	void push(T val)
	{
		move(stack2, stack1);
		stack1.push(val);
	}
	void pop()
	{
		move(stack1, stack2);
		stack2.pop();
	}
	T front()
	{
		move(stack1, stack2);
		return stack2.top();
	}
	T back()
	{
		move(stack2, stack1);
		return stack1.top();
	}
	bool empty()
	{
		// to check two stacks are empty or not
		return stack1.empty() && stack2.empty();
	}
	int size()
	{
		return stack1.size() + stack2.size();
	}
	// move stc1 into stc2
	void move(stack<T>& stc1, stack<T>& stc2)
	{
		while(!stc1.empty())
		{
			stc2.push(stc1.top());
			stc1.pop();
		}
	}
private:
	stack<T> stack1, stack2;
};
	

template <typename T>
class MyQueue1
{
public:
	MyQueue1()
	{
		
	}
	~MyQueue1()
	{
	
	}
	void push(T val)
	{
		stack1.push(val);
	}
	void pop()
	{
		if (!stack2.empty())
			stack2.pop();
		else
		{
			move(stack1, stack2);
			stack2.pop();
		}	
	}
	T front()
	{
		if (!stack2.empty())
			return stack2.top();
		else
		{
			move(stack1, stack2);
			return stack2.top();
		}	
	}
	T back()
	{
		if (!stack1.empty())
			return stack1.top();
		else
		{
			move(stack2, stack1);
			return stack1.top();
		}
	}
	bool empty()
	{
		// to check two stacks are empty or not
		return stack1.empty() && stack2.empty();
	}
	int size()
	{
		return stack1.size() + stack2.size();
	}
	// move stc1 into stc2
	void move(stack<T>& stc1, stack<T>& stc2)
	{
		while(!stc1.empty())
		{
			stc2.push(stc1.top());
			stc1.pop();
		}
	}
private:
	stack<T> stack1, stack2;
};

/**
 One better solution, just modify the move fucntion
 Add a check of empty of dst stack.
 
template <typename T>
class MyQueue1{
public:
    MyQueue1(){

    }
    ~MyQueue1(){

    }
    void push(T val){
        sin.push(val);
    }
    void pop(){
        move(sin, sout);
        sout.pop();
    }
    T front(){
        move(sin, sout);
        return sout.top();
    }
    T back(){
        move(sout, sin);
        return sin.top();
    }
    int size(){
        return sin.size()+sout.size();
    }
    bool empty(){
        return sin.empty()&&sout.empty();
    }
    void move(stack<T> &src, stack<T> &dst){
        if(dst.empty()){
            while(!src.empty()){
                dst.push(src.top());
                src.pop();
            }
        }
    }

private:
    stack<T> sin, sout;    
};
**/

int main(){
    MyQueue<int> q;
    MyQueue1<int> q1;
    for(int i=0; i<10; ++i){
        q.push(i);
        q1.push(i);
    }

    cout<<"q  "<<q.front()<<" "<<q.back()<<endl;
    cout<<"q1  "<<q1.front()<<" "<<q1.back()<<endl;
    cout<<endl;
    q.pop();
    q1.pop();
    q.push(10);
    q1.push(10);
    cout<<q.front()<<" "<<q.back()<<endl;
    cout<<q1.front()<<" "<<q1.back()<<endl;
    cout<<endl;
    cout<<q.size()<<" "<<q.empty()<<endl;
    cout<<q1.size()<<" "<<q1.empty()<<endl;        
    return 0;
}

 
