#include<iostream>
#include<cassert>
#include<new>
#include"DStack.h"
using namespace std;

Stack::Stack(int numElements)
{
	assert(numElements > 0);
	myCapacity = numElements;
	myArray = new(nothrow) StackElement[myCapacity];
	if (myArray != 0)//内存足够
		myTop = -1;
	else
	{
		cerr << "**Inadequate memory to allocate stack**"<<endl;
		exit(1);
	}
}

Stack::Stack(const Stack & original):myCapacity(original.myCapacity),myTop(original.myTop)
{
	myArray = new(nothrow) StackElement[myCapacity];
	if (myArray != 0)
	{
		for (int pos = 0;pos <= myTop;pos++)
			myArray[pos] = original.myArray[pos];
	}
	else
	{
		cerr<< "**Inadequate memory to allocate stack**" << endl;
		exit(1);
	}
}

const Stack & Stack::operator=(const Stack & right)
{
	// TODO: 在此处插入 return 语句
	if (this != &right)
	{
		if (myCapacity != right.myCapacity)
		{
			delete[] myArray;
			myCapacity = right.myCapacity;
			myArray = new StackElement[myCapacity];
			if (myArray == 0)
			{
				cerr<< "**Inadequate memory to allocate stack**" << endl;
				exit(1);
			}
		}
		myTop = right.myTop;
		for (int pos = 0;pos <= myTop;++pos)
		{
			myArray[pos] = right.myArray[pos];
		}
	}
	return *this;
}

Stack::~Stack()
{
	delete[] myArray;
}

bool Stack::empty() const
{
	return (myTop == -1);
}

void Stack::push(const StackElement & item)
{
	if (myTop < myCapacity - 1)
	{
		myArray[++myTop] = item;
	}
	else
	{
		cerr << "**Stack full**" << endl;
		exit(1);
	}
}

void Stack::pop()
{
	if (!empty())
	{
		myTop--;
	}
	else
	{
		cerr << "**Stack is empty**" << endl;
	}
}

StackElement Stack::top() const
{
	if (!empty())
	{
		return myArray[myTop];
	}
	else
	{
		cout << "**stack id empty**" << endl;
		return 10086;
	}
}

void Stack::display(ostream & out) const
{
	for (int i = myTop;i >= 0;--i)
		out << myArray[i] << endl;
}


