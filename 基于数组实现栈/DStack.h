#ifndef  _DSTACK_H
#define _DSTACK_H
#include<iostream>
using namespace std;
//DStack.h p305
typedef int StackElement;
class Stack {
public:
	Stack(int numElements = 128);//构造空栈p299
	Stack(const Stack& original);//复制构造函数p303
	const Stack& operator=(const Stack& right);//赋值p304
	~Stack();//析构函数p301
	bool empty() const;//判空
	void push(const StackElement& item);//压栈
	void pop();//弹出
	StackElement top() const;//访问栈顶
	void display(ostream& out) const; //显示栈里所有元素
private:
	int myCapacity,//栈的容量 
		myTop;//栈顶
	StackElement *myArray; //动态数组
};
#endif
