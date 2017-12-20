#include<iostream>
#include<cassert>
#include"Linked_List.h"


const int NULL_VALUE = -1; //�����ڵ�λ��
const int NUMNODES = 2048;
NodePointer freeP;//���б�ָ��
NodeType  node[NUMNODES];
void iniStoragePool()//��ʼ���洢��
{
	for (int i = 0;i < NUMNODES - 1;++i)
		node[i].next = i + 1;
	node[NUMNODES - 1].next = -1;
	freeP = 0;
}




Linked_List::Linked_List() :mySize(0), first(NULL_VALUE) {}

Linked_List::Linked_List(const Linked_List & origList)
{
	if (origList.mySize * 2 > NUMNODES)
	{
		cerr << "Iadequate memory" << endl;
		exit(1);
	}
	else
	{
		first = NULL_VALUE;
		mySize = origList.mySize;
		if (!origList.empty())
		{
			//���Ƶ�һ���ڵ�
			first = freeP;
			freeP = node[freeP].next;
			node[first].data = node[origList.first].data;
			//����ָ��
			NodePointer newPtr = first;
			NodePointer origPtr = node[origList.first].next;
			while (origPtr != NULL_VALUE)
			{
				node[newPtr].next = freeP;
				freeP = node[freeP].next;
				newPtr = node[newPtr].next;
				node[newPtr].data = node[origPtr].data;
				origPtr = node[origPtr].next;
			}
			node[newPtr].next = NULL_VALUE;
		}
	}
}

Linked_List::~Linked_List()
{
	if (!empty())
	{
		NodePointer ptr = node[first].next;
		while (ptr != NULL_VALUE)
		{
			node[freeP].next = first;
			freeP = node[freeP].next;
			first = ptr;
			ptr = node[ptr].next;
		}
	}
	
}

const Linked_List & Linked_List::operator=(const Linked_List & origList)
{
	// TODO: �ڴ˴����� return ���
	if (origList.mySize * 2 > NUMNODES)
	{
		cerr << "**Inadequate memory**" << endl;
		exit(1);
	}
	if (this != &origList)
	{
		this->~Linked_List();
		first = NULL_VALUE;
		mySize = origList.mySize;
		if (!origList.empty())
		{
			//���Ƶ�һ���ڵ�
			first = freeP;
			freeP = node[freeP].next;
			node[first].data = node[origList.first].data;
			//����ָ��
			NodePointer newPtr = first;
			NodePointer origPtr = node[origList.first].next;
			while (origPtr != NULL_VALUE)
			{
				node[newPtr].next = freeP;
				freeP = node[freeP].next;
				newPtr = node[newPtr].next;
				node[newPtr].data = node[origPtr].data;
				origPtr = node[origPtr].next;
			}
			node[newPtr].next = NULL_VALUE;
		}
	}
		return *this;
}

bool Linked_List::empty()const
{
	return (first == NULL_VALUE);
}
void Linked_List::insert(ElementType item, NodePointer preptr)
{
	if (freeP == NULL_VALUE)
	{
		cerr << "**INadequate memory**" << endl;
		exit(1);
	}
	else
	{
		NodePointer np = freeP;
		freeP = node[freeP].next;
		node[np].data = item;
		if (preptr != NULL_VALUE)
		{
			node[np].next = node[preptr].next;
			node[preptr].next = np;
		}
		else
		{
			node[np].next = first;
			first = np;
		}
		mySize++;
		
	}

}

void Linked_List::erase(NodePointer preptr)
{
	NodePointer ptr;
	if (preptr != NULL_VALUE)//���ǵ�һ���ڵ�
	{
		ptr = node[preptr].next;
		node[preptr].next = node[ptr].next;
		
	}
	else//ɾ����һ���ڵ�
	{
		ptr = first;
		first = node[ptr].next;
	}
	//������Դ
	node[ptr].next = freeP;
	freeP = ptr;
	mySize--;
}

void Linked_List::display(ostream & out) const
{
	NodePointer ptr = first;
	while (ptr != NULL_VALUE)
	{
		out << node[ptr].data<<" ";
		ptr = node[ptr].next;
	}
}
NodePointer Linked_List::find(ElementType item, int&success)
{
	 NodePointer pre = NULL_VALUE, p = first;
	while (p!=NULL_VALUE&&node[p].data != item)
	{
		pre = p;
		p = node[p].next;
	}
	if (p != NULL_VALUE)
	{
		success = 1;
		return pre;
	}
	else
	{
		success = -1;
		return NULL_VALUE;
	}

}
ostream& operator<<(ostream & out, const Linked_List& aList)
{
	aList.display(out);
	return out;
}

