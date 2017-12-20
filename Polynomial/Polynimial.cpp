#include"Polynomial.h"
#include<iostream>
using namespace std;
template<typename CoefType>
Polynomial<CoefType> Polynomial<CoefType>::operator=(const Polynomial<CoefType>&rhs)
{
	if (this != &rhs)
	{
		this->~Polynomial();
		myTerms = new Polynomial<CoefType>::Node();
		Polynomial<CoefType>::Node*ptra = myTerms;
		Polynomial<CoefType>::Node*ptrb = rhs.myTerms->next;
		while (ptrb)
		{
			ptra->next = new Polynomial<CoefType>::Node(ptrb->data.coef, ptrb->data.expo);
			ptra = ptra->next;
			ptrb = ptrb->next;
		}
	}
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
Polynomial<CoefType> Polynomial<CoefType>::operator+(const Polynomial<CoefType>&rhs)
{
	Polynomial<CoefType> result;//会调用类的默认构造函数
	Polynomial<CoefType>::Node*ptra = Myterms->next;
	Polynomial<CoefType>::Node*ptrb = rhs.Myterm->next;
	Polynomial<CoefType>::Node*ptrc = result.Myterms;
	int degree = 0;
	while (ptra&&ptrb)
	{
		if (ptra->expo < ptrb->expo)
		{
			ptrc->next = new Polynomial<CoefType>::Node(ptra->data.coef, ptra->data.expo);
			ptra = ptra->next;
			ptrc = ptrc->next;
			degree++;
		}
		else if (ptra->expo > ptrb->expo)
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
Polynomial<CoefType> Polynomial<CoefType>::operator*(const Polynomial<CoefType>&rhs)
{
	Polynomial<CoefType>arr[myDegree];
	Polynomial<CoefType>::Node*ptra = myTerms->next;
	Polynomial<CoefType>::Node*ptrb = rhs.myTrms->next;
	for (int i = 0;i < myDegree;++i)
	{
		Polynomial<CoefType>::Node*ptrc = arr[i].mhyTerms;
		while (ptrb)
		{
			ptrc->next = new Node(ptra->data.coef*ptrb->data.coef, ptra->data.expo + ptrb->data.expo);
			ptrb = ptrb->next;
		}
		ptra = ptra->next;
		ptrb = rhs.myTerms->next;
	}

	Polynomial<CoefType> result;
	for (int i = 0;i < myDegree;++i)
	{
		result = result + arr[i];
	}
	return result;
}