#ifndef _POLYNOMIAL_H
#define _POLYNIMIAL_H
#include<iostream>
using namespace std;
template<typename CoefType>
class Polynomial
{
private:
	//Term类
	class Term
	{
	public:
		CoefType coef;
		unsigned expo;
	};

	//Node 类
	class Node
	{
	public :
		Term data;
		Node*next;
		Node(CoefType coef = 0, unsigned expo = 0, Node*next = 0)
		{
			this->data.coef =coef;
			this->data.expo = expo;
			this->next = next;
		}
	};
	//数据成员
private:
	int myDegree;
	Node* myTerms;
	//成员函数
public :
	Polynomial()
	{
		myTerms = new Node();
		myDegree = 0;
	}
	//拷贝构造函数
	Polynomial(const Polynomial<CoefType>&rhs)
	{
		myTerms = new Polynomial<CoefType>::Node();
		Polynomial<CoefType>::Node*ptra = myTerms;
		myDegree = rhs.myDegree;
		Polynomial<CoefType>::Node*ptrb = rhs.myTerms->next;
		while (ptrb)
		{
			ptra->next = new Polynomial<CoefType>::Node(ptrb->data.coef,ptrb->data.expo);
			ptra = ptra->next;
			ptrb = ptrb->next;
		}
	}


	~Polynomial();
	void add(CoefType a, CoefType b);
	void display(ostream&out);
	Polynomial<CoefType>&operator=(const Polynomial<CoefType>&rhs);	
	template<typename CoefType>
	friend Polynomial<CoefType> operator+ (const Polynomial<CoefType>&lhs,const Polynomial<CoefType>&rhs);
	template<typename CoefType>
	friend Polynomial<CoefType> operator*(const Polynomial<CoefType>&lhs,const Polynomial<CoefType>&rhs);
};


//成员函数的实现
template<typename CoefType>
Polynomial<CoefType>& Polynomial<CoefType>::operator=(const Polynomial<CoefType>&rhs)
{
	if (this != &rhs)
	{
		this->~Polynomial();
		myDegree = rhs.myDegree;
		myTerms = new Polynomial<CoefType>::Node();
		Polynomial<CoefType>::Node*ptra = myTerms;
		Polynomial<CoefType>::Node*ptrb = rhs.myTerms->next;
		ptrb;
		while (ptrb)
		{
			ptra->next = new Polynomial<CoefType>::Node(ptrb->data.coef, ptrb->data.expo);
			ptra = ptra->next;
			ptrb = ptrb->next;
		}
	}
	return*this;
}

template<typename CoefType>
Polynomial<CoefType>::~Polynomial()
{
	Polynomial<CoefType>::Node*ptra = myTerms;
	Polynomial<CoefType>::Node*ptrb = myTerms->next;
	while (ptrb)
	{
		delete ptra;
		ptra = ptrb;
		ptrb = ptrb->next;
	}
	delete ptra;
}
template<typename CoefType>
void Polynomial<CoefType>::add(CoefType a, CoefType b)//用来添加项
{
	Polynomial<CoefType>::Node*ptr = myTerms;
	while (ptr->next)
	{
		ptr = ptr->next;
	}
	ptr->next = new Polynomial<CoefType>::Node(a, b);
	myDegree++;
}

template<typename CoefType>
inline void Polynomial<CoefType>::display(ostream & out)
{
	Polynomial<CoefType>::Node*ptr = myTerms;
	while (ptr)
	{
		out << '(' << ptr->data.coef << ',' << ptr->data.expo << ')' << ' ';
		ptr = ptr->next;
	}
}

template<typename CoefType>
Polynomial<CoefType> operator+(const Polynomial<CoefType>&lhs,const Polynomial<CoefType>&rhs)
{
	Polynomial<CoefType> result;//会调用类的默认构造函数
	Polynomial<CoefType>::Node*ptra = lhs.myTerms->next;
	Polynomial<CoefType>::Node*ptrb = rhs.myTerms->next;
	Polynomial<CoefType>::Node*ptrc = result.myTerms;
	int degree = 0;
	while (ptra&&ptrb)
	{
		if (ptra->data.expo < ptrb->data.expo)
		{
			ptrc->next = new Polynomial<CoefType>::Node(ptra->data.coef, ptra->data.expo);
			ptra = ptra->next;
			ptrc = ptrc->next;
			degree++;
		}
		else if (ptra->data.expo > ptrb->data.expo)
		{
			ptrc->next = new Polynomial<CoefType>::Node(ptrb->data.coef, ptrb->data.expo);
			ptrb = ptrb->next;
			ptrc = ptrc->next;
			degree++;
		}
		else
		{
			ptrc->next = new Polynomial<CoefType>::Node(ptra->data.coef + ptrb->data.coef, ptra->data.expo);
			ptra = ptra->next;
			ptrb = ptrb->next;
			ptrc = ptrc->next;
			degree++;
		}
	}
	//把剩余的多项式挂上去

	while (ptra)
	{
		ptrc->next = new Polynomial<CoefType>::Node(ptra->data.coef, ptra->data.expo);
		ptra = ptra->next;
		ptrc = ptrc->next;
		degree++;
	}

	while (ptrb)
	{
		ptrc->next = new Polynomial<CoefType>::Node(ptrb->data.coef, ptrb->data.expo);
		ptrb = ptrb->next;
		ptrc = ptrc->next;
		degree++;
	}
	result.myDegree = degree;
	return result;
}

template<typename CoefType>
Polynomial<CoefType> operator*(const Polynomial<CoefType>&lhs,const Polynomial<CoefType>&rhs)
{
	Polynomial<CoefType>* arr=new Polynomial<CoefType>[lhs.myDegree];
	Polynomial<CoefType>::Node*ptra = lhs.myTerms->next;
	Polynomial<CoefType>::Node*ptrb = rhs.myTerms->next;
	for (int i = 0;i < lhs.myDegree;++i)
	{
		Polynomial<CoefType>::Node*ptrc = arr[i].myTerms;
		while (ptrb)
		{
			ptrc->next = new Polynomial<CoefType>::Node(ptra->data.coef*ptrb->data.coef, ptra->data.expo + ptrb->data.expo);
			ptrb = ptrb->next;
			ptrc = ptrc->next;
			arr[i].myDegree++;
		}
		ptra = ptra->next;
		ptrb = rhs.myTerms->next;
	}
	/*for (int i = 0;i < lhs.myDegree;++i)
	{
		arr[i].display(cout);
		cout << endl;
	}*/

	Polynomial<CoefType> result;
	for (int i = 0;i < lhs.myDegree;++i)
	{
		result = result + arr[i];
	}
	return result;
}

#endif

