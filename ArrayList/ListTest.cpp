#include "ArrayList.h"
//#include "LinkedList.h"
#include <iostream>
using namespace std;

int main()
{
	ArrayList a;
	//LinkedList a; //����ע���ͷ�ͬʱ��ע����һ������
	a.insert(5,0);
	a.insert(7,0);
	a.insert(9,0);
	a.insert(11,0);
	a.display();
   
	ArrayList b(a),c;//LinkedList b(a),c;
	b.display();
	c=a;
	cout<<c;

	a.erase(0);
	cout<<a;
	
	
	int item=10;
	//ArrayList�β��Դ���
	int re=a.find(item);
	if(re==-1) cout<<item<<"`������!"<<endl;
	item=7;
	re=a.find(item);
	if(re!=-1){
		a.erase(re);
		a.display();
	}
	//ArrayList�β��Դ������

	/*//�ͷ���δ���ͬʱ����һ�δ���ע��
	//LinkedList�β��Դ���
	int success;
    node* re=a.find(item,success);
	if(success==-1) cout<<item<<"�����ڣ�"<<endl;
	item=9;
	re=find(item,success);
	if(success==1){//Ϊʲô���ﲻʹ��re!=NULL�������жϣ�
		a.erase(re);
		a.display();
	}
	//LinkedList�β��Դ������
   */
   return 0;

}