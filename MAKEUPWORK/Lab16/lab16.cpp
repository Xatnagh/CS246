#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Node.h"
template <class T>
void swapData(ds::dn::Node<T>* a,ds::dn::Node<T>* b){
    T tmp =a->GetData();
    a->SetData(b->GetData());
    b->SetData(tmp);
}

template <class T>
void InsertionSort(ds::dn::Node<T>* root)
{
    ds::dn::Node<T>* tmp=root;
    ds::dn::Node<T>* backtracker=tmp;
    while(current!=NULL){
        while(backtracker->GetData()<backtracker->GetPrev()->GetData() && backtracker->GetPrev()!=NULL){
            swap(backtracker, backtracker->GetPrev());
            backtracker=backtracker->GetPrev();
        }
        tmp=tmp->GetNext();
        backtracker=tmp;
    }
    return;
}


/********************************
 * Helper Functions : Begin
 *******************************/

//GenerateList() - converts Point object to a one dimension chess board index
ds::dn::Node<int>* GenerateList(int n)
{
    int nc = (n <= 0)?(10):(n);
    ds::dn::Node<int>* root = new ds::dn::Node<int>(rand() % 99 + 1);
    ds::dn::Node<int>* tmp = root;
    for(int i = 1;i < nc;i += 1)
    {
        tmp->SetNext(new ds::dn::Node<int>(rand() % 99 + 1));
        tmp->GetNext()->SetPrev(tmp);
        tmp = tmp->GetNext();
    }

    return root;
}

template <class T>
void Print(ds::dn::Node<T>* root)
{
    for(ds::dn::Node<T>* t = root;t != NULL;t = t->GetNext())
    {
        std::cout << t->GetData() << " ";
    }
}

/********************************
 * Helper Functions : End
 *******************************/

int main()
{
    srand(time(NULL));
    ds::dn::Node<int>* root = GenerateList(15);
    Print(root);
    std::cout << "\n";
    ds::dn::Clear(root);
        
    return 0; 
}
