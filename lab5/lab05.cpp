#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.h"

void RandInts(ds::Array<int>& arr,int lo,int hi)
{
    int mx = (hi >= lo)?(hi):(lo);
    int mn = (lo <= hi)?(lo):(hi);
    ds::it::Iterator<int>* iter = arr.ToIterator();

    while(iter->HasNext())
    {
        iter->Next() = rand() % (mx - mn + 1) + mn;
    }

    delete iter;
} 

void SortedInts(ds::Array<int>& arr,int start,bool dup)
{
    int prev = start;
    int c = (dup)?(0):(1);
    ds::it::Iterator<int>* iter = arr.ToIterator();

    while(iter->HasNext())
    {
        prev = prev + rand() % 2;
        iter->Next() = prev; 
    }

    delete iter;
}

int mostrepeated(ds::Array<int>& arr,int end){
    //assuming that the array is sorted
    if(end<2){
     return arr[0];
    }
    int count=1;
    int largestcount=1;
    int last=arr[end-1];;
    int mostrepeatedint=arr[end-1];
    for(int i=end-2;i>=0;i--){
        if(arr[i]==last){
            count++;
            
        }else{
            if(count>=largestcount){
                mostrepeatedint=last;
                largestcount=count;
            }  
            count=1;
            last=arr[i];
        }
    }
    return mostrepeatedint;

}

int main()
{
    srand(time(NULL));
    ds::Array<int> data[2] = {ds::Array<int>(15),ds::Array<int>(15)};
    SortedInts(data[0],0,false);
    SortedInts(data[1],0,false);
    std::cout<<data[0]<<std::endl;
    std::cout<<data[1]<<std::endl;
    std::cout<<"most repeated element in array1 is: "<<mostrepeated(data[0],3)<<std::endl;
    return 0; 

}
