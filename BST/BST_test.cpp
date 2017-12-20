//treetester.cpp p609
#include <iostream>
using namespace std;
#include "BST.hpp"

int main()
{
	 //测试构造函数和empty()
	BST<int> intBST;
	cout<<"构造空BST"<<endl;
	cout<<"BST "<<(intBST.empty()?"是":"不是")<<"空树"<<endl;

	//测试中序遍历
	cout<<"中序(inOrder)遍历："<<endl;
	intBST.inOrder(cout);

	//测试插入操作
    cout<<"现在开始插入(insert)测试："<<endl;
	int number;
	for(;;){
		cout<<"插入值（-999结束）";
		cin>>number;
		if(number==-999) break;
		intBST.insert(number);
	}
	intBST.graph(cout);

    //测试前序遍历
	cout<<"前序(preOrder)遍历："<<endl;
	intBST.preOrder(cout);

	//测试后序遍历
	cout<<"后序(postOrder)遍历："<<endl;
	intBST.postOrder(cout);

	//测试层次遍历
	cout<<"层次(level)遍历："<<endl;
	intBST.levelOrder(cout);

	//测试查找
    cout<<"现在开始查找(search)测试："<<endl;
	for(;;){
		cout<<"查找值（-999结束）";
		cin>>number;
		if(number==-999) break;
		cout<<(intBST.search(number))?"找到":"找不到"<<endl;;
	}

	//测试删除
    cout<<"现在开始删除(remove)测试："<<endl;
	for(;;){
		cout<<"删除值（-999结束）";
		cin>>number;
		if(number==-999) break;
		intBST.remove(number);
		intBST.graph(cout);
	}

	return 0;

}