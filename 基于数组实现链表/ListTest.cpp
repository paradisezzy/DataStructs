//#include "ArrayList.h"
#include "Linked_List.h"
#include <iostream>
using namespace std;
extern NodeType node[];

void iniStoragePool();
int main()
{
	iniStoragePool();
	//ArrayList a;
	Linked_List a; //����ע���ͷ�ͬʱ��ע����һ������
	a.insert(5, -1);
	a.insert(7, -1);
	a.insert(9, -1);
	a.insert(11,-1);
	a.display(cout);
	cout << endl;

	
	//ArrayList b(a),c;
	Linked_List b(a),c;
	b.display(cout);
	cout << "display b"<<endl;
	c=a;
	cout<<c;
	cout <<"coutc"<< endl;

	cerr << "cout pool" << endl;
	for (int i = 0;i < 100;++i)
	{
		cout << node[i].data << " " << node[i].next << endl;
	}

	a.erase(-1);
	cout<<a;
	cout << "couta" << endl;
	
	
	
	//ArrayList�β��Դ���
	/*int re=a.find(item);
	if(re==-1) cout<<item<<"������!"<<endl;
	item=7;
	re=find(item);
	if(re!=-1){
		a.erase(re);
		a.display();
	}*/
	//ArrayList�β��Դ������

	
	int item = 10;
	int success=0;
   NodePointer re=a.find(item,success);
	if(success==-1) cout<<item<<"�����ڣ�"<<endl;
	item=9;
	re=a.find(item,success);
	if (success == 1) {//Ϊʲô���ﲻʹ��re!=NULL�������жϣ�  
		a.erase(re);
		a.display(cout);
	}
	
   return 0;

}