#include"Polynomial.h"
#include<iostream>
using namespace std;
int main()
{
	Polynomial<int> a,b;
	a.add(1, 2);
	a.add(6, 3);
	a.add(2, 4);
	a.add(5, 100);
	cout << "����a:  ";
	a.display(cout);
	cout <<endl;
	
	b.add(1, 2);
	b.add(3, 3);
	b.add(2, 4);
	b.add(2, 5);
	b.add(1, 20);
	cout << "����b:  ";
	b.display(cout);
	cout << endl;

	Polynomial<int>c, d;
	c = a + b;
	cout << "����c:  ";
	c.display(cout);
	cout << endl;


	d = a*b;
	cout << "����d:  ";
	d.display(cout);
	cout << endl;

	
}