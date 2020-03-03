#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Node.h"
#include "Iterator.h"

template <typename T>
bool similar(ds::Node<T>* root1,ds::Node<T>* root2 ){
    ds::Node<T>* tmp1=root1;
    ds::Node<T>* tmp2=root2;
    while(tmp1!=NULL||tmp2!=NULL){
        if(tmp1->GetData()!=tmp2->GetData()){
            return false;

        }
        tmp1=tmp1->GetLink();
        tmp2=tmp2->GetLink();
    }
    return false;
}
int main()
{
    return 0; 
}
