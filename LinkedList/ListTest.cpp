//#include "ArrayList.h"
#include "LinkedList.h"
#include <iostream>
using namespace std;

int main()
{
	//ArrayList a;
	LinkedList a; //这条注释释放同时请注释上一条声明
	a.insert(5,0);
	a.insert(7,0);
	a.insert(9,0);
	a.insert(11,0);
	a.display();
   
	//ArrayList b(a),c;
	LinkedList b(a),c;
	b.display();
	c=a;
	cout<<c;

	a.erase(0);
	cout<<a;
	
	
	
	//ArrayList段测试代码
	/*int re=a.find(item);
	if(re==-1) cout<<item<<"不存在!"<<endl;
	item=7;
	re=find(item);
	if(re!=-1){
		a.erase(re);
		a.display();
	}*/
	//ArrayList段测试代码完毕

	
	int item = 10;
	int success;
   node* re=a.find(item,success);
	if(success==-1) cout<<item<<"不存在！"<<endl;
	item=9;
	re=a.find(item,success);
	if (success == 1) {//为什么这里不使用re!=NULL的条件判断？  答：如果item位于头结点，那么re也为空
		a.erase(re);
		a.display();
	}
	
   return 0;

}