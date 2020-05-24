#include <iostream>
#include <string>
#include "BNode.h" 

bool HasPathSum(ds::sn::BNode<int>* root,int value)
{
	int currentsum=value-root->data;
	if(currentsum==0)return true;
	if( root->left){
		if( PathSum(root,currentsum))
		return true;
	}  
	if(root->right){
		if( PathSum(root,currentsum))
		return true;
	}
	return false;	
}
bool PathSum(ds::sn::BNode<int>* stem,int currentSum)
{	
	currentSum-=stem->data;
	if(currentSum==0)return true;
	if(currentSum<0)return false;
	if( stem->left){
		return PathSum(stem,currentSum);
	}  
	if(stem->right){
		return PathSum(stem,currentSum);
	}
		
}

template <typename T>
int TreeDepth(ds::dn::BNode<T>* root)
{
	if(root==NULL)return 0;
	if(!(root->left && root->right))return 1;
	return 1+std::max(TreeDepth(root->left),TreeDepth(root->right);
}

template <typename T>
bool IsFull(ds::sn::BNode<T>* root)
{
	if(root->right==NULL || root->left==NULL){
		return true;
	}else{
		return (IsFull(root->left)&&IsFull(root->left));
	}
	return 0;
}

int main()
{
	return 0;
}
