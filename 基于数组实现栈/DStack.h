#ifndef  _DSTACK_H
#define _DSTACK_H
#include<iostream>
using namespace std;
//DStack.h p305
typedef int StackElement;
class Stack {
public:
	Stack(int numElements = 128);//�����ջp299
	Stack(const Stack& original);//���ƹ��캯��p303
	const Stack& operator=(const Stack& right);//��ֵp304
	~Stack();//��������p301
	bool empty() const;//�п�
	void push(const StackElement& item);//ѹջ
	void pop();//����
	StackElement top() const;//����ջ��
	void display(ostream& out) const; //��ʾջ������Ԫ��
private:
	int myCapacity,//ջ������ 
		myTop;//ջ��
	StackElement *myArray; //��̬����
};
#endif
