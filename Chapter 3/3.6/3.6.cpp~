/**

Write a program to sort a stack in ascending order. You should not make any assumptions about how the stack is implemented. The following are the only functions that should be used to write this program: push | pop | peek | isEmpty.

Idea1: 使用一个附加的栈来模拟插入排序。将原栈中的数据依次出栈与附加栈中的栈顶元素比较， 如果附加栈为空，则直接将数据压栈。否则， 如果附加栈的栈顶元素大于从原栈中弹出的元素，则将附加栈的栈顶元素压入原栈。 一直这样查找直到附加栈为空或栈顶元素已经不大于该元素， 则将该元素压入附加栈。

Idea2: 使用一个优先队列来为出栈的元素排序，原栈中的元素不断出栈然后插入优先队列， 直到原栈为空。然后再将优先队列中的元素不断压回原栈，这样操作后， 栈中的元素便有序化了。

Author: Yuchao Zhou

**/
 
#include <iostream>
#include <stack>
#include <cstdlib> // rand()
#include <queue>

using namespace std;

// ascending 100, 99, 98, 97....
stack<int> SsortAsc(stack<int> src)
{
	stack<int> tmp;
	while(!src.empty())
	{
		int data = src.top();
		src.pop();
		while(!tmp.empty() && tmp.top() > data)
		{
			src.push(tmp.top());
			tmp.pop();
		}
		tmp.push(data);
	}
	return tmp;
}

//descending 1, 2, 3...
stack<int> SsortDes(stack<int> src)
{
	stack<int> tmp;
	while(!src.empty())
	{
		int data = src.top();
		src.pop();
		while(!tmp.empty() && tmp.top() < data)
		{
			src.push(tmp.top());
			tmp.pop();
		}
		tmp.push(data);
	}
	return tmp;
}

stack<int> SsortQueue(stack<int> src)
{
	//priority_queue<int, vector<int>, greater<int>> is wrong.
	//>> should be > >
	priority_queue<int, vector<int>, greater<int> > q;
	while (!src.empty())
	{
		q.push(src.top());
		src.pop();
	}
	while (!q.empty())
	{
		src.push(q.top());
		q.pop();
	}
	return src;
}

int main(){
    stack<int> s;

	cout<<"before sort: "<<endl;
    for(int i=0; i<10; ++i)
    {
    	// get random number 0~100, not contain 100
        s.push((rand()%100));
        cout<<s.top()<<" ";
    }
    cout<<endl;
    cout<<"after sort: "<<endl;
    //s = SsortAsc(s);
    //s = SsortDes(s);
    s = SsortQueue(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    return 0;
}
 
