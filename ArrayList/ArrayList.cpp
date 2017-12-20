#include "ArrayList.h"
#include <cassert>
using namespace std;

ArrayList::ArrayList(int maxSize)//����
{
    myCapacity=maxSize;
	mySize=0;
	myArray=new ElementType[myCapacity];
	assert(myArray!=0);
}

ArrayList::~ArrayList()//����
{
	delete [] myArray;
}

ArrayList::ArrayList(const ArrayList& origList)//��������
{
     myCapacity=origList.myCapacity;
	 myArray=new ElementType[myCapacity];
	 assert(myArray!=0);
	 mySize=origList.mySize;
	 for(int i=0;i<mySize;i++) myArray[i]=origList.myArray[i];
}


ArrayList& ArrayList::operator=(const ArrayList& right)//��ֵ����
{ //�벹��
	if (this != &right)//ȷ�ϲ������Ҹ�ֵ
	{
		if (myCapacity != right.myCapacity)//��������� ���·����ڴ�
		{
			delete []  myArray;
			myArray = new ElementType[right.myCapacity];
			if (myArray == 0)
			{
				cerr << "Inadequate memory to allocate stack ***\n";
				exit(1);
			}		
		}
		mySize = right.mySize;
		for (int i = 0;i < mySize;++i)
			myArray[i] = right.myArray[i];
	}
	return *this;
}


bool ArrayList::empty() const //�п�
{
   return mySize==0;
}


void ArrayList::insert(ElementType item,int pos)//����
{
	if (mySize == myCapacity)
	{
		cerr << "no space for list element" << endl;
		exit(1);
	}
	if (pos<0 || pos>mySize)
	{
		cerr << "Illegal location to insert" << endl;
		return;
	}
	for (int i = mySize;i > pos;--i)
	{
		myArray[i] = myArray[i - 1];
	}
	myArray[pos] = item;
	mySize++;
}

void ArrayList::erase(int pos)//ɾ��
{//�벹��
	if (mySize == 0)
	{
		cerr << "List is empty" << endl;
		return;
	}
	if (pos < 0 || pos >= mySize)
	{
		cerr<< "Illegal location to insert" << endl;
		return;
	}
	for (int i = pos;i < mySize - 1;++i)
	{
		myArray[i] = myArray[i + 1];
	}
	mySize--;

}
void ArrayList::display(ostream& out) const//�������
{
	for(int i=0;i<mySize;i++)
		out<<i<<":"<<myArray[i]<<endl;
}

int ArrayList::find(ElementType item)//û���ҵ����-1
{//�벹��
	for (int i = 0;i < mySize;++i)
		if (myArray[i] == item)
			return i;
	return -1;

}


ostream& operator<<(ostream& out,const ArrayList& aList)//���������
{//�벹��
	aList.display(out);
	return out;

}