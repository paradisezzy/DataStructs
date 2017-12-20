#include "ArrayList.h"
#include <cassert>
using namespace std;

ArrayList::ArrayList(int maxSize)//构造
{
    myCapacity=maxSize;
	mySize=0;
	myArray=new ElementType[myCapacity];
	assert(myArray!=0);
}

ArrayList::~ArrayList()//析构
{
	delete [] myArray;
}

ArrayList::ArrayList(const ArrayList& origList)//拷贝构造
{
     myCapacity=origList.myCapacity;
	 myArray=new ElementType[myCapacity];
	 assert(myArray!=0);
	 mySize=origList.mySize;
	 for(int i=0;i<mySize;i++) myArray[i]=origList.myArray[i];
}


ArrayList& ArrayList::operator=(const ArrayList& right)//赋值重载
{ //请补充
	if (this != &right)//确认不是自我赋值
	{
		if (myCapacity != right.myCapacity)//容量不相等 重新分配内存
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


bool ArrayList::empty() const //判空
{
   return mySize==0;
}


void ArrayList::insert(ElementType item,int pos)//插入
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

void ArrayList::erase(int pos)//删除
{//请补充
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
void ArrayList::display(ostream& out) const//遍历输出
{
	for(int i=0;i<mySize;i++)
		out<<i<<":"<<myArray[i]<<endl;
}

int ArrayList::find(ElementType item)//没有找到输出-1
{//请补充
	for (int i = 0;i < mySize;++i)
		if (myArray[i] == item)
			return i;
	return -1;

}


ostream& operator<<(ostream& out,const ArrayList& aList)//输出流重载
{//请补充
	aList.display(out);
	return out;

}