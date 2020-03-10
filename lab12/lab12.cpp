#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Node.h"
#include "Iterator.h"
#include "Set.h"

template <typename T>
ds::sn::Set<T> Intersection(const ds::sn::Set<T>& A,const ds::sn::Set<T>& B)
{
    ds::sn::Set<T> combined;
    ds::sn::Iterator<T>* iter = A.ToIterator();
    while(iter ->HasNext()){
        T item = iter->Next();
        if(B.Contains(item)){
            combined.Insert(item);
        }
    }
    std::cout<<combined;
    return combined;
}

template <typename T>
ds::sn::Set<T> Union(const ds::sn::Set<T>& A,const ds::sn::Set<T>& B)
{
    return ds::sn::Set<T>();
}

/********************************
 * Helper Functions : Begin
 *******************************/

//GenerateList() - creates a linked list of random decimal numbers
ds::sn::Set<int> GenerateSet(int n)
{
    int s = (n <= 0)?(10):(n);
    ds::sn::Set<int> S;

    while(S.Size() < s)
    {
        S.Insert((rand() % 1000 + 1));
    }
    return S;
} 

/********************************
 * Helper Functions : End
 *******************************/

int main()
{
    ds::sn::Set<int> a;
    ds::sn::Set<int>b;
    a.Insert(1);
    a.Insert(12);
    a.Insert(13);
    b.Insert(12);
    b.Insert(16);
    Intersection(a,b);
    return 0; 
}
