//12.1 �����������BST������ģ��  P590-P611
//ע�⣺ģ����������ʵ�ֲ��ּҡ�1������һ��; 2����������ʽ�Ϸ��룬ʹ�� .template
#include <iostream>
#include <iomanip>
#ifndef BST_HPP
#define BST_HPP

//��������㶨��
template<typename DataType>
class BinNode{
public:
	DataType data;
	BinNode *left;
	BinNode *right;
	BinNode():left(0),right(0){}
	BinNode(DataType item):data(item),left(0),right(0){}
};

template<typename DataType>
class BST{
public:
	BST();//�޲ι���
	bool empty() const; //�п�
	void inOrder(ostream & out) const; //�������
    void preOrder(ostream& out) const;//ǰ�����-���в���
	void postOrder(ostream& out) const;//�������-���в���
	void levelOrder(ostream& out) const;//��α���-���в���
    void graph(ostream& out) const;//�������

	bool search(const DataType& item) const;//����
	void insert(const DataType& item);//����
	void remove(const DataType& item);//ɾ��
    
private:
	//��������ϵ��
	//�����������
	void inOrderAux(ostream& out,BinNode<DataType>* subtreePtr) const;
    //ǰ���������-���в���
	void preOrderAux(ostream& out,BinNode<DataType>* subtreePtr) const;
	//�����������-���в���
	void postOrderAux(ostream& out,BinNode<DataType>* subtreePtr) const;
    //��α�������-���в���
	void levelOrderAux(ostream& out,BinNode<DataType>* subtreePtr) const;
	//ͼ���������
	void graphAux(ostream& out,int indent,BinNode<DataType>* subtreeRoot) const;
    //����ɾ���Ĳ���
	void search2(const DataType& item,bool& found,BinNode<DataType>* & locptr,BinNode<DataType>* & parent) const;

	BinNode<DataType>* myRoot;//����
};

//p592
template<typename DataType>
inline BST<DataType>::BST():myRoot(0) {}

//p592
template<typename DataType>
inline bool BST<DataType>::empty() const {return myRoot==0; }

//p594
template<typename DataType>
inline void BST<DataType>::inOrder(ostream& out) const
{  inOrderAux(out,myRoot);  }

//p594
template<typename DataType>
void BST<DataType>::inOrderAux(ostream& out,BinNode<DataType>* subtreeRoot) const
{
	if(subtreeRoot!=0)
	{
		inOrderAux(out,subtreeRoot->left);
		out<<subtreeRoot->data<<" ";
		inOrderAux(out,subtreeRoot->right);
	}
}

//p596
template<typename DataType>
inline void BST<DataType>::graph(ostream& out) const
{ graphAux(out,0,myRoot);}

//p596
template<typename DataType>
void BST<DataType>::graphAux(ostream& out,int indent,BinNode<DataType>* subtreeRoot) const
{
	if(subtreeRoot!=0)
	{
		graphAux(out,indent+8,subtreeRoot->right);
		out<<setw(indent)<<" "<<subtreeRoot->data<<endl;
		graphAux(out,indent-8,subtreeRoot->left);
	}
}


/*//p597 �ݹ�汾
template<typename DataType>
inline bool BST<DataType>::search(const DataType& item) const
{ return searchAux(myRoot,item);}

template<typename DataType>
bool BST<DataType>::searchAux(BST<DataType>::BinNodePointer subtreeRoot,const DataType& item) const
{
	if(subtreeRoot==0) return false;
	if(item<subtreeRoot->data) return searchAux(subtreeRoot->left,item);
	else if(subtreeRoot0->data<item) return searchAux(subtreeRoot->right,item);
	else return true;
}
*/

//p598
template<typename DataType>
bool BST<DataType>::search(const DataType& item) const
{
	BinNode<DataType>* locptr=myRoot;
	bool found=false;
	while(!found&&locptr!=0)
	{
		if(item<locptr->data) locptr=locptr->left;
		else if(locptr->data<item) locptr=locptr->right;
		else found =true;
	}
	return found;
}

//p600,ע��p601�еݹ�汾
template<typename DataType>
void BST<DataType>::insert(const DataType& item)
{
	BinNode<DataType>* locptr=myRoot,*parent=0;
	bool found=false;
	while(!found&&locptr!=0)
	{
		parent=locptr;
		if(item<locptr->data) locptr=locptr->left;
		else if(locptr->data<item) locptr=locptr->right;
		else found=true;
	}
	if(!found){
		locptr=new BinNode<DataType>(item);
	    if (parent==0) myRoot=locptr;
		else if(item<parent->data) parent->left=locptr;
		else parent->right=locptr;
	}
	else
		cout<<"Item already in the tree!"<<endl;
}

//p605
template<typename DataType>
void BST<typename DataType>::remove(const DataType& item)
{
	bool found;
	BinNode<DataType>* x,*parent;
	search2(item,found,x,parent);

	if(!found){
		cout<<"Item not in the BST"<<endl;
		return ;
	}
	//else
	if(x->left!=0 && x->right!=0)
	{
		BinNode<DataType>* xSucc=x->right;
		parent=x;
		while(xSucc->left!=0){
			parent=xSucc;
			xSucc=xSucc->left;
		}
		x->data=xSucc->data;
		x=xSucc;

		BinNode<DataType>* subtree=x->left;
		if(subtree==0) subtree=x->right;
		else if(parent->left ==x) subtree=x->right;
		if(parent==0) myRoot=subtree;
		else if(parent->left==x) parent->left=subtree;
		else parent->right=subtree;
		delete x;
	}
}

//p606
template<typename DataType>
void BST<DataType>::search2(const DataType & item,bool& found,BinNode<DataType>* & locptr,
                                    BinNode<DataType>* & parent) const
{
	locptr=myRoot;
	parent=0;
	found=false;
	while(!found&&locptr!=0)
	{
		if(item<locptr->data){
			parent=locptr;
			locptr=locptr->left;
		}
		else if(locptr->data<item){
			parent=locptr;
			locptr=locptr->right;
		}
		else
			found=true;
	}
}

#endif