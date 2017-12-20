//treetester.cpp p609
#include <iostream>
using namespace std;
#include "BST.hpp"

int main()
{
	 //���Թ��캯����empty()
	BST<int> intBST;
	cout<<"�����BST"<<endl;
	cout<<"BST "<<(intBST.empty()?"��":"����")<<"����"<<endl;

	//�����������
	cout<<"����(inOrder)������"<<endl;
	intBST.inOrder(cout);

	//���Բ������
    cout<<"���ڿ�ʼ����(insert)���ԣ�"<<endl;
	int number;
	for(;;){
		cout<<"����ֵ��-999������";
		cin>>number;
		if(number==-999) break;
		intBST.insert(number);
	}
	intBST.graph(cout);

    //����ǰ�����
	cout<<"ǰ��(preOrder)������"<<endl;
	intBST.preOrder(cout);

	//���Ժ������
	cout<<"����(postOrder)������"<<endl;
	intBST.postOrder(cout);

	//���Բ�α���
	cout<<"���(level)������"<<endl;
	intBST.levelOrder(cout);

	//���Բ���
    cout<<"���ڿ�ʼ����(search)���ԣ�"<<endl;
	for(;;){
		cout<<"����ֵ��-999������";
		cin>>number;
		if(number==-999) break;
		cout<<(intBST.search(number))?"�ҵ�":"�Ҳ���"<<endl;;
	}

	//����ɾ��
    cout<<"���ڿ�ʼɾ��(remove)���ԣ�"<<endl;
	for(;;){
		cout<<"ɾ��ֵ��-999������";
		cin>>number;
		if(number==-999) break;
		intBST.remove(number);
		intBST.graph(cout);
	}

	return 0;

}