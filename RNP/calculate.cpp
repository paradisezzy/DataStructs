#include<iostream>
#include<string>
#include<stack>
#include<cassert>
#include<cctype>
using namespace std;
int Operator(int num1, int num2, char op)
{
	switch (op)
	{
	case'+':return num1 + num2;
	case'-':return num1 - num2; 
	case'*':return num1*num2;
	case'/':return num1 / num2;
	case'%':return num1%num2;
	default:
	{
		cout << "���������" << endl;
		exit(0);
	}
	}
}

int calculate(string exp)
{
	stack<int>numStack;
	int num=0;//���ڴ洢�ַ���ת������������
	int num1, num2;//�����������������
	char token;
	for (int i = 0;i < exp.length();++i)
	{
		token = exp[i];
		switch (token)
		{
		case'\0':
			break;
		case '+':
		case'-':
		case'*':
		case'/':
		case'%':
		{
			if (numStack.empty())
			{
				cout << "***expression error!**" << endl;
				exit(0);
			}
			else
			{
				num2 = numStack.top();
				numStack.pop();
			}
			if (numStack.empty())
			{
				cout << "***expression error!**" << endl;
				exit(0);
			}
			else
			{
				num1 = numStack.top();
				numStack.pop();
			}
			numStack.push(Operator(num1, num2, token));
			break;

		}
		default://���������
		{
			while (true)
			{
				if (!isalnum(exp[i]))
					break;
				num = num * 10 + (exp[i] - '0');
				i++;
			}
			numStack.push(num);
			num = 0;
		}
			
		}
	}
	return numStack.top();
}
