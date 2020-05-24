#include <iostream>
#include <string>
#include "BNode.h" 

template <typename T>
ds::dn::BNode<T>* TreeMinimum(ds::dn::BNode<T>* root)
{
	if(root==NULL)return NULL;
	if(root->left)return TreeMaximum(root->left); //if it has a left, then its not smallest, keep recursing;
	return root->data;
}

template <typename T>
ds::dn::BNode<T>* TreeMaximum(ds::dn::BNode<T>* root)
{

	if(root==NULL)return NULL;
	if(root->right)return TreeMaximum(root->right); //if it has a right, then its not biggest, keep recursing;
	return root->data;
}

template <typename T>
ds::dn::BNode<T>* TreeSuccessor(ds::dn::BNode<T>* x)
{
	int original = x->data;
	ds::dn::BNode<T>* tmp=x;
	while(tmp!=NULL){
		tmp=tmp->p;
	}
	return findsuccessor(tmp,original);
	
	return NULL;
}
template <typename T>
ds::dn::BNode<T>* findsuccessor(ds::dn::BNode<T>* x,T target){

	if(x->right->data>target){
		return findsuccessor(x->right,target);
	}
	else if(x->left->data>target){
		return findsuccessor(x->left);
	}else{
		return x;
	}
}



template <typename T>
ds::dn::BNode<T>* TreePredecessor(ds::dn::BNode<T>* x)
{
	return NULL;
}


int main()
{
	return 0;
}
