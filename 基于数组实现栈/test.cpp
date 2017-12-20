#include<iostream>
#include"DStack.h"
using namespace std;
int main()
{
	Stack s;
	cout << s.empty() << endl;
	cout << endl;
	
	int num;
	cin >> num;
	for (int i = 0;i <= num;++i)
		s.push(i);
	cout << "Stack contents:" << endl;
	s.display(cout);
	cout << "top value" << s.top() <<endl;

	Stack s2 = s;
	s2.display(cout);

	while (!s.empty())
		s.pop();
	cout << "stack is empty?" << s.empty() << endl;
	cout << "top value" << s.top() << endl;
	cout << "try s.pop()" <<endl;
	s.pop();
	return 0;

}