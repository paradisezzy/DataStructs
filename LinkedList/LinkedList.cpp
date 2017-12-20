#include "LinkedList.h"
#include <cassert>
using namespace std;

LinkedList::LinkedList()//构造
{  mySize=0;
   first=NULL;
}

LinkedList::~LinkedList()//析构
{
	node*ptr = first;
	while (first)
	{
		first = first->next;
		delete ptr;
		ptr = first;
	}
}

LinkedList::LinkedList(const LinkedList& origList)//拷贝构造
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

LinkedList& LinkedList::operator=(const LinkedList& right)//赋值重载
{//请补充
	if (this != &right)
	{
		this->~LinkedList();
		mySize = right.mySize;
		if (right.first == NULL)//空表复制时的情况
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
    
bool LinkedList::empty() const//判空
{
	return first==NULL;
}

void LinkedList::insert(ElementType item,node* pre)//在pre后插入，pre为空则插入在首
{//请补充

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

void LinkedList::erase(node* pre)//删除pre后的，pre为空则删除首
{//请补充
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

void LinkedList::display(ostream& out) const//遍历输出
{
    for(node* p=first;p;p=p->next)
		out<<p->data<<endl;
}


node* LinkedList::find(ElementType item, int& success)
//查找特定的值item,存在返回包含该值结点的前驱和查找成功的标记1，不存在返回查找失败标记-1和NULL
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


ostream& operator<<(ostream& out,const LinkedList& aList)//输出流重载
{//请补充
	aList.display(out);
	return out;
}