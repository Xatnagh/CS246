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
	if(root==NULL)return true;
	if(root->right->data > root->data && root->left->data < root->data)return true;
	return false;
}


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
	using namespace std;
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

	return mergedlist; //really scuffed but its fine
}
//Question 3

bool IsValidWord(std::string wrd)
{
	if(wrd=="")return true;
	if(wrd[0]=='b' || wrd[0]=='c')return false;
	for(int i =1;i<wrd.size()-1;i++){
		if(wrd[i]=='b' && wrd[i-1]=='b')return false;
	}//i noticed that "bb" can never be togather, and a valid word alway start with a
	return true;
}

//Question 4
/******************************************************************************************
InFix: (12 40 13) 43 (23 11 39) 21 (38 47 36) 14 (26 5 3)

Postfix: 2 13 40 23 39 11 43 38 36 47 26 3 5 14 21
 
Prefix: 21 43 14 40 11 47 5 2 13 23 39 38 36 26 3

******************************************************************************************/

int main()
{	 
	using namespace std;
	sn::Node<int>* root= new sn::Node<int>(1);
	sn::Node<int>* one= new sn::Node<int>(2);
	sn::Node<int>* tw= new sn::Node<int>(3);
	sn::Node<int>* tr= new sn::Node<int>(19);
 	root->SetLink(one);
	one->SetLink(tw);
	tw->SetLink(tr);

	sn::Node<int>* rootb= new sn::Node<int>(4);
	sn::Node<int>* oneb= new sn::Node<int>(9);
	sn::Node<int>* twob= new sn::Node<int>(12);
	rootb->SetLink(oneb);
	oneb->SetLink(twob);
printlist(root);
cout<<endl;
printlist(rootb);
cout<<endl;
printlist(MergeSortedLists(root,rootb));
	return 0;
}
