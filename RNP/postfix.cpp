#include<iostream>
#include<string>
#include<cassert>
#include<cctype>
#include<stack>
using namespace std;
/*��һ����׺���ʽת��Ϊ��׺���ʽ
���صı��ʽ�ַ�����ÿ���������Ͳ�����֮�䶼���һ��
*/
string postfix(string exp)
{
	char token,//char in exp
		topToken;//top element in stack
	stack<char>opStack;//the stack to storage operator in exp
	string postfixExp;
	for (int i = 0;i < exp.length();++i)
	{
		token = exp[i];
		switch (token)
		{
		case '\0':
			break;
		case '(':
			opStack.push(token);
			break;
		case')':
		{
			while (true)
			{
				assert(!opStack.empty());
				topToken = opStack.top();
				opStack.pop();
				if (topToken == '(')
					break;
				postfixExp.append(1,topToken);
				postfixExp.append(1, '\0');
			}
			break;
		}
		case'+':
		case'-':
		case'*':
		case'/':
		case'%':
			while (true)
			{
				if (opStack.empty() ||
					opStack.top() == '(' ||
					(token == '*' || token == '/' || token == '%') &&
					(opStack.top() == '+' || opStack.top() == '-'))
				{
					opStack.push(token);
					break;
				}
				else
				{
					topToken = opStack.top();
					opStack.pop();
					postfixExp.append(1,topToken);
					postfixExp.append(1, '\0');
				}
			}
			break;
		default://������
			postfixExp.append(1, token);
			//���Ǹ�λ��
			while (true)
			{
				if (!isalnum(exp[i + 1]))
					break;
				i++;
				token = exp[i];
				postfixExp.append(1,token);
			}
			postfixExp.append(1, '\0');
		}
	}
	//����ʣ�������
	for (;;)
	{
		if (opStack.empty())
			break;
		topToken = opStack.top();
		opStack.pop();
		if (topToken != '(')
		{
			postfixExp.append(1,topToken);
			postfixExp.append(1, '\0');
		}
		else
		{
			cerr << "***error expression***" << endl;
			break;
		}
	}
	return postfixExp;
}