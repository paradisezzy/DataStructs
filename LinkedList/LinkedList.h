#include <iostream>
using namespace std;
#ifndef LINKEDLIST
#define LINKEDLIST

typedef int ElementType;

class node{
public:
	node(ElementType d,node* n=NULL):data(d),next(n){ }
	ElementType data;
	node* next;
};

class LinkedList{
public:
	LinkedList();//����
    ~LinkedList();//����
	LinkedList(const LinkedList& origList);//��������
	LinkedList& operator=(const LinkedList& right);//��ֵ����
    
	bool empty() const; //�п�
    void insert(ElementType item,node* pre);//��pre����룬preΪ�����������
	void erase(node* pre);//ɾ��pre��ģ�preΪ����ɾ����
	void display(ostream& out=cout) const;//�������

	node* find(ElementType item,int& success);//�����ض���ֵitem,���ذ�����ֵ����ǰ����������success-1,��ǰ������NULL
private:
	int mySize;
	node *first;
};
ostream& operator<<(ostream& out,const LinkedList& aList);//���������

#endif