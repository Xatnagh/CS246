#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.h"

/**********************************
 * Question 1: Swap Counts [2,4,6,1,3,5]
 * a. 4 swap
 * b. 6 swap
 * c. 6 swap
 **********************************/


template <typename T>
bool Monotonic(const ds::Array<T>& data)
{
    if(data.Length()<=2)return true;
    bool sign = (data[1]-data[0]>0)? true : false; // if sign is true, it is increasing, else decreasing
    for(int i =2; i<data.Length();i++){
        if(data[i]-data[i-1]>0!=sign){ 
            return false;
        }
    }
    return true;
}

int main()
{
    srand(time(NULL));
    ds::Array<int> a(3);
    a[0]=1;
    a[1]=2;
    a[2]=-2;
    std::cout<<Monotonic(a);
    return 0; 
}
