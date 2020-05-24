#include <iostream>
#include <string>
#include "BNode.h" 

int TreeSum(ds::dn::BNode<int>* root)
{
	int sum=0;
	if(root->left){sum+=TreeSum(root->left);}
	if(root->right){sum+=TreeSum(root->right);}
	return sum;
}
int BranchSum(ds::dn::BNode<int>* branch,int sum)
{
	if(branch->left){sum+=TreeSum(branch->left);}
	if(branch->right){sum+=TreeSum(branch->right);}
	return sum+branch->data;
	return 0;
}
template <typename T>
bool EqualTrees(ds::dn::BNode<T>* tr1,ds::dn::BNode<T>* tr2)
{
	if(tr1->data !=tr2){
		return false;
	}
	if(tr1->left && tr2->left){
		EqualTrees(tr1->left,tr2->left);
	}
	if(tr1->right && tr2->right){
		EqualTrees(tr1->right,tr2->right);
	}
	return true;
}

template <typename T>
int TreeDepth(ds::dn::BNode<T>* root)
{	if(root==NULL)return 0;
	if(!(root->left && root->right))return 1;
	return 1+std::min(TreeDepth(root->left),TreeDepth(root->right);
}

template <typename T>
ds::dn::BNode<T>* ShorterSubTree(ds::dn::BNode<T>* root)
{
	int leftBranchSum=TreeDepth(root->left);
	int rightBranchSum=TreeDepth(root->right);
	return (leftBranchSum>=rightBranchSum)? root->left: root->right;
}



int main()
{
	return 0;
}
