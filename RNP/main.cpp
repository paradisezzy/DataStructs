#include<iostream>
#include<string>
using namespace std;
string postfix(string exp);
int calculate(string exp);
int main()
{
	string exp = "(2*(2-1))-3+((5+5))/2";
	string result = postfix(exp);//(2*2-1)*1-3345
	cout << result << endl;
	cout << "����ǣ�";
	cout << calculate(result) << endl;
}