#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Node.h"
#include "Iterator.h"
template<typename T>
void traverse(ds::Node<T>* root){
    ds::Node<T>* tmp=root;
    while (tmp!=NULL){
        std::cout<<tmp->GetData()<<" ";
        tmp=tmp->GetLink();
    }
    std::cout<<std::endl;
}
template <typename T>
void SwapNodes(ds::Node<T>* root,ds::Node<T>* nptr1,ds::Node<T>* nptr2)
{
    ds::Node<T>* tmp = nptr2->GetLink();
    nptr2->SetLink(nptr1->GetLink());
    nptr1->SetLink(tmp);
   
}//this function, by the way it is worded sounds like unlinking everything between nptr1 and nptr2

double SecondLargest(ds::Node<double>* root)
{
    if(root->GetLink()==NULL)throw "list not big enough";
    ds::Node<double>* tmp = root->GetLink();
    double largest= (root->GetData()>tmp->GetData())? root->GetData() : tmp->GetData();
    double secondlargest=(root->GetData()<tmp->GetData())? root->GetData() : tmp->GetData();;
    while(tmp!=NULL){
        if(tmp->GetData()<largest && tmp->GetData()>secondlargest){
            secondlargest=tmp->GetData();
        }
        if(tmp->GetData()>largest){
            secondlargest=largest;
            largest = tmp->GetData();
        }
        tmp=tmp->GetLink();
    }
    return secondlargest;
}

template <typename T>
void RemoveAll(ds::Node<T>* root,const T& target)
{
    if(root==NULL)return; 
    while(root->GetData()==target){
        root=root->GetLink();
    }
    ds::Node<T>* tmp=root->GetLink();
    ds::Node<T>* prev=root;
    while(tmp!=NULL){
        if(tmp->GetData()==target){
            prev->SetLink(tmp->GetLink());
        }
        prev=tmp;
        tmp=tmp->GetLink();
        
    }
}





int main()
{    
    ds::Node<int>* c=new ds::Node<int>(3);
    ds::Node<int>* b=new ds::Node<int>(2,c);
    ds::Node<int>* root=new ds::Node<int>(1,b);
    traverse(root);
    RemoveAll(root,1);
    traverse(root);
    return 0; 
}
