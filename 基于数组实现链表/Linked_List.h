#ifndef _LINKED_LIST_H
#define  _LINKED_LIST_H
typedef int ElementType;
typedef int NodePointer;
#include<iostream>
using namespace std;
class NodeType {
public:
	ElementType  data;
	int next;
};




class Linked_List {
public:
	Linked_List();//构造空列表，mySize:0
	Linked_List(const Linked_List& origList); //P268 
	~Linked_List();//P268
	const Linked_List& operator=(const Linked_List & origList);
	bool empty() const;//判空
	void insert(ElementType item, NodePointer preptr);
	//插入 p268
	void erase(NodePointer preptr);//删除 p268
	void display(ostream& out)const;//输出列表元素（遍历）
	NodePointer find(ElementType item, int& success);
private:
	int mySize;//列表的大小
	NodePointer first; //表首指针
};

ostream& operator<<(ostream & out, const Linked_List& aList);

#endif