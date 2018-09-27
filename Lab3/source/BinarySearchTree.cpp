#include "BinarySearchTree.hpp"


// Implement the functions here.

#include <iostream>

using namespace std;
typedef int DataType;

BinarySearchTree::Node::Node(DataType newVal)
{
	 left=NULL;
 	right=NULL;
 	val=newVal;
}
  
BinarySearchTree::BinarySearchTree()
{
	root_=NULL;
	size_=0;
}


void freeNode(BinarySearchTree::Node* n)
{
	if (n!=NULL){
		freeNode(n->left);
		freeNode(n->right);
		delete n; 
	}
		 
}

BinarySearchTree::~BinarySearchTree()
{
	freeNode(root_);
}

unsigned int BinarySearchTree::size() const
{
	return size_;
}

DataType BinarySearchTree::max() const
{
	Node * current= root_;
	while(current->right!=NULL){
		current=current->right;
	}
	return current->val;
}
 
DataType BinarySearchTree::min() const

{
	Node * current= root_;
	while(current->left!=NULL){
		current=current->left;
	}
	return current->val;
}

unsigned int MaxDepth(BinarySearchTree::Node* n)
{
	if (n==NULL){
		return 0;
	}
	else if (n->left==NULL && n->right==NULL)
	{
		return 0;
	}
	else
	{
		return 1+ max(MaxDepth(n->right) , MaxDepth(n->left));
	}	
}

unsigned int BinarySearchTree::depth() const
{
	return MaxDepth(root_);
}


bool search(BinarySearchTree::Node* T, int K)
{
	if (T==NULL){
		return false;
	}
	if(T->val==K){
		return true;
	}
	else if(K<T->val){
		search(T->left,K);
	}
	else if (K>T->val){
		search(T->right,K);
	}
	
	/**
	bool found= false;
	while(T!=NULL){
		if (T->val==K){
			found=true;
			break;
		}
		else if(K<T->val){
			T=T->left;
		}
		else{
			T=T->right;
		}
	}
	if (found==true){
		return true
	}
	else{
		return false;
	}
	*/

}

void inOrder(BinarySearchTree::Node* T)
{
	if(T==NULL){
		return;
	}
	else{ 
		inOrder(T->left);
		cout<<T->val<<endl;
		inOrder(T->right);
	}
}

void BinarySearchTree::print() const
{
	inOrder(root_);
}

bool BinarySearchTree::exists(DataType val) const
{
	return search(root_,val);
}

void insertT(BinarySearchTree::Node* T, DataType N)
{
	if (T->val>N){
		if(T->left==NULL){
			BinarySearchTree::Node * temp = new BinarySearchTree::Node(N);
			temp->val=N;
			T->left=temp;
		}
		else{
			insertT(T->left, N);
		}
	}
	else if (T->val<N){
			if(T->right==NULL){
			BinarySearchTree::Node * temp = new BinarySearchTree::Node(N);
			temp->val=N;
			T->right=temp;
		}
		else{
			insertT(T->right, N);
		}
	}
	
}
bool BinarySearchTree::insert(DataType val)
{
	if (exists(val))
	{
		return false;
	}
	
	else if(root_ == NULL)
	{
		root_ = new Node(val);
		size_++;
		return true;
	}
	
	else
	{
	insertT(root_, val);
	size_++;
	return true;
 	}
}


bool BinarySearchTree::remove(DataType val)
{
	
if ((!exists(val)) || size_ == 0)
	{
		return false;
	}

	Node* ValNode = root_;
	Node** parent = NULL;
	
	while (ValNode -> val != val)
	{
		if(ValNode -> val < val)
		{
			parent = &(ValNode -> right);
			ValNode = ValNode -> right;
			
		}
		else if (ValNode -> val > val)
		{
			parent = &(ValNode -> left );
			ValNode = ValNode -> left;
		}
	} 
	
	if (ValNode -> left == NULL  && ValNode -> right == NULL)	
	{
		if (parent != NULL)
		{
			*parent = ValNode -> right;
		}
		delete ValNode;
		parent = NULL;
	}
	
	else if (ValNode -> left == NULL && ValNode-> right != NULL)
	{
		if (parent != NULL)
		{
			*parent = ValNode -> right;
		}	
		
		if (ValNode == root_)
		{
			ValNode = ValNode -> right;
			delete root_;
			root_ = ValNode;
		}
		
		else
		{
			delete ValNode;
			ValNode = NULL;
		}
	}
	
	else if(ValNode -> left != NULL && ValNode -> right == NULL)
	{
		if (parent != NULL)
		{
			*parent = ValNode -> left;
		}
		
		if (ValNode == root_)
		{
			ValNode = ValNode -> left;
			delete root_;
			root_ = ValNode;
		}
		
		else
		{
			delete ValNode;
			ValNode = NULL;
		}
	}
	
	else if (ValNode -> left != NULL && ValNode -> right != NULL)
	{
		Node* temp =root_ -> left;
		while(temp -> right != NULL)
		{
			temp = temp -> right;
		}
		DataType tempVal = temp -> right -> val;
		remove (tempVal);
		ValNode-> val = tempVal;
	}
	
	size_--;
	return true;	
	
	
}
