#include "LinkedList.h"
#include <cassert>
using namespace std;

LinkedList::LinkedList()//����
{  mySize=0;
   first=NULL;
}

LinkedList::~LinkedList()//����
{
	node*ptr = first;
	while (first)
	{
		first = first->next;
		delete ptr;
		ptr = first;
	}
}

LinkedList::LinkedList(const LinkedList& origList)//��������
{
	mySize=origList.mySize;
	if(origList.first!=NULL)
	{
		node* p=origList.first;
		first=new node(p->data);
		p=p->next;
		node* pp=first;
		while(p){
			pp->next=new node(p->data);
			p=p->next;
            pp=pp->next;
		}
    }
	else
		first=NULL;
}

LinkedList& LinkedList::operator=(const LinkedList& right)//��ֵ����
{//�벹��
	if (this != &right)
	{
		this->~LinkedList();
		mySize = right.mySize;
		if (right.first == NULL)//�ձ���ʱ�����
		{
			first = NULL;
		}
		else
		{
			node* p = right.first;
			first = new node(p->data);
			p = p->next;
			node* pp = first;
			while (p) {
				pp->next = new node(p->data);
				p = p->next;
				pp = pp->next;
			}
		}
	}
	return *this;
}
    
bool LinkedList::empty() const//�п�
{
	return first==NULL;
}

void LinkedList::insert(ElementType item,node* pre)//��pre����룬preΪ�����������
{//�벹��

	if (pre == NULL)
	{
		node*p = new node(item);
		p->next = first;
		first = p;
	}
	else
	{
		node*p = new node(item);
		p->next = pre->next;
		pre->next = p;
	}

}

void LinkedList::erase(node* pre)//ɾ��pre��ģ�preΪ����ɾ����
{//�벹��
	if (pre == NULL)
	{
		node*p = first;
		first = first->next;
		delete p;
	}
	else
	{
		node*p = pre->next;
		pre->next = p->next;
		delete p;
	}
}

void LinkedList::display(ostream& out) const//�������
{
    for(node* p=first;p;p=p->next)
		out<<p->data<<endl;
}


node* LinkedList::find(ElementType item, int& success)
//�����ض���ֵitem,���ڷ��ذ�����ֵ����ǰ���Ͳ��ҳɹ��ı��1�������ڷ��ز���ʧ�ܱ��-1��NULL
{   node* pre=NULL,*p=first;
	while(p&&p->data!=item)
	{
		pre=p;
		p=p->next;
	}
	if(p!=NULL) 
	{
		success=1;
		return pre;
	}
	else
	{
		success=-1;
		return NULL;
	}

}


ostream& operator<<(ostream& out,const LinkedList& aList)//���������
{//�벹��
	aList.display(out);
	return out;
}