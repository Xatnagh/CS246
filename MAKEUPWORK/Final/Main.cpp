#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Array.h"
#include "Node.h"
#include "Pair.h"
#include "Iterator.h"
#include "List.h"
#include "Set.h"
#include "Stack.h"
#include "Queue.h"
#include "Deque.h"
#include "BNode.h"
using namespace ds;

//Question 1

template <typename T>
bool IsBST(sn::BNode<T>* root)
{
	if(root==NULL|| !(root->left &&root->right))return true; //null or reached end
	if(root->right){
		if(root->right->data<root->data)return false;
		return IsBST(root,root->right);
	}
	if(root->left){
		if(root->left->data>root->data)return false;
		return IsBST(root,root->left);
	}
	return false;
}
template <typename T>



//Question 2
void printlist(sn::Node<int>* root){
	sn::Node<int>* tmp=root;
	while(tmp!=NULL){
		std::cout<<tmp->GetData()<< "  ";
		tmp=tmp->GetLink();
	}
}
sn::Node<int>* MergeSortedLists(sn::Node<int>* a,sn::Node<int>* b)
{
	if(a==NULL)return b;
	if(b==NULL)return a;
	sn::Node<int>* mergedlist=new sn::Node<int>(1);
	sn::Node<int>* mergedlisttraverse= mergedlist;
	sn::Node<int>* tmp1 = a;
	sn::Node<int>* tmp2 = b;
	 if(tmp1->GetData()<=tmp2->GetData()){
		mergedlist->SetData(a->GetData());
		tmp1=tmp1->GetLink();
	 }else{
		mergedlist->SetData(tmp2->GetData());
		tmp2=tmp2->GetLink();
	}

	while(tmp1!=NULL && tmp2!=NULL){
		if(tmp1->GetData()<=tmp2->GetData()){
			sn::Node<int>* temp=new sn::Node<int>(tmp1->GetData());
			mergedlisttraverse->SetLink(temp);
			mergedlisttraverse=mergedlisttraverse->GetLink();
			tmp1=tmp1->GetLink();
		}else{
			sn::Node<int>* temp=new sn::Node<int>(tmp2->GetData());
			mergedlisttraverse->SetLink(temp);
			mergedlisttraverse=mergedlisttraverse->GetLink();
			tmp2=tmp2->GetLink();
		}
	}
	while(tmp2!=NULL){
		sn::Node<int>* temp=new sn::Node<int>(tmp2->GetData());
			mergedlisttraverse->SetLink(temp);
			mergedlisttraverse=mergedlisttraverse->GetLink();
			tmp2=tmp2->GetLink();
	}
	while(tmp1!=NULL){
		sn::Node<int>* temp=new sn::Node<int>(tmp1->GetData());
			mergedlisttraverse->SetLink(temp);
			mergedlisttraverse=mergedlisttraverse->GetLink();
			tmp1=tmp1->GetLink();
	}

	return mergedlist; //really scuffed but its works
}
//Question 3

bool withinrange(const char& c){
	return (c>='a' && c<='c');
}
bool IsValidWord(std::string wrd)
{
	ds::dn::Stack<char> tracker;
	for(char c:wrd){
		if(withinrange(c)){
			if(c=='a'){
				if(!tracker.IsEmpty())if(tracker.Top()=='c') tracker.Pop();
				tracker.Push(c);
			}
			if(c=='b'){
				if(tracker.IsEmpty())return false;
				if(tracker.Top()=='a')tracker.Pop();
				tracker.Push(c);
			}
			if(c=='c'){
				if(tracker.IsEmpty())return false;
				if(tracker.Top()=='b')tracker.Pop();
			}
		}
	}return tracker.IsEmpty();
}
// aabcabcbc

// a c

//Question 4
/******************************************************************************************
InFix: (12 40 13) 43 (23 11 39) 21 (38 47 36) 14 (26 5 3)

Postfix: 2 13 40 23 39 11 43 38 36 47 26 3 5 14 21
 
Prefix: 21 43 14 40 11 47 5 2 13 23 39 38 36 26 3

******************************************************************************************/

int main()
{	 
	std::cout<<IsValidWord("ababcc");
	return 0;
}
