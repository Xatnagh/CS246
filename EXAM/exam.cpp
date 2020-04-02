#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.h"
#include "Node.h"
#include "Iterator.h"
#include "List.h"
#include "Stack.h"
#include "Queue.h"
#include "Set.h"
#include "Deque.h"
#include "Helper.h" //Helper Functions for Testing Your Functions

template <typename T>
int LastOccurrence(ds::da::Vector<T>& data,const T& value)
{
    int last=-1;
    for(int i=0;i<data.Size();i++){
        if (data[i]==value) last== i;
    }
    if(last!=-1)return last;
    return -1;
}

template <typename T>
void BubbleSort(ds::dn::Node<T>* root)
{
    ds::dn::Node<T>* tmp=root;
    bool loopagain=true;
    while (loopagain){
        
        loopagain=false; //idea here is that if there was a need to swap, then the system will go all over again, else it is sorted 

        while(tmp->GetNext()!=NULL){
            if(tmp->GetData()>tmp->GetNext()->GetData()){
                loopagain=true;
                T swaptmp=tmp->GetData();
                tmp.setData(tmp->GetNext()->GetData());
                tmp->GetNext()->setData(swaptmp);
            }
            tmp=tmp->GetNext();
                if(tmp->GetNext()!=NULL){
                    while(tmp->GetPrev!=NULL){
                        tmp=tmp->GetPrev(); //resets nodes
                    }
                }
                
        }
    
    
    }
    return;
}

template <typename T>
bool HasCycle(ds::sn::Node<T>* root)
{
    if(root==NULL || root->GetLink()==NULL)return false;
    ds::sn::Node<T>* tmpprev=root;
    ds::sn::Node<T>* tmp =root->getLink();
    while(tmp.GetLink()!=NULL ){
        tmpprev=tmp;
        tmp=tmp->GetLink();
        if(tmp->GetLink()==tmpprev)return true;
    }
    return false;
}

std::string AdjacentDuplicatesRemoval(std::string str)
{
    std::string tmp=str;
    bool loopagain=true;
    while(loopagain){
        loopagain=false;
        for(int i=1;i<tmp.length();i++){
            if(tmp[i] == tmp[i-1]){
                tmp.erase(i-1,2);
                loopagain=true;
            }
        }
    }
    
    return tmp;
}

int MaxKSum(ds::da::Vector<int>& data,int k) //what is this interview question
{
    int maxsum=0;
    int currentsum=0;
    if(data.Size()==0)return 0;
    if(k<0 || k>=data.Size()){
        for(int i=0;i<data.Size();i++){
            maxsum+=data[i];
        }
        return maxsum;
    }
    for(int i=0;i<data.Size()-k;i++){
        currentsum=0;
        for(int j=0;j<k;j++){
            currentsum+=data[j+i];
        }
        if(currentsum>maxsum) maxsum=currentsum;
        
    }

    return maxsum;
}

int main()
{
    srand(time(NULL));
    //Test Your Functions Here
    std::cout<<AdjacentDuplicatesRemoval("abbaca")<<'\n'; // returns ca
    ds::da::Vector<int> test;
    test.InsertLast(3); // 3 9 1 8 2 7
    test.InsertLast(9);
    test.InsertLast(1);
    test.InsertLast(8);
    test.InsertLast(100);
    test.InsertLast(7);
    std::cout<<"test before:"<<std::endl<<test.ToString()<<std::endl;
    std::cout<<MaxKSum(test,3)<<'\n';
    return 0;
}
