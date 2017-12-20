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
	Linked_List();//������б�mySize:0
	Linked_List(const Linked_List& origList); //P268 
	~Linked_List();//P268
	const Linked_List& operator=(const Linked_List & origList);
	bool empty() const;//�п�
	void insert(ElementType item, NodePointer preptr);
	//���� p268
	void erase(NodePointer preptr);//ɾ�� p268
	void display(ostream& out)const;//����б�Ԫ�أ�������
	NodePointer find(ElementType item, int& success);
private:
	int mySize;//�б�Ĵ�С
	NodePointer first; //����ָ��
};

ostream& operator<<(ostream & out, const Linked_List& aList);

#endif