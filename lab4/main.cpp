/**********************************************************
 * Lecture 04: Non-Recursive Sorting Functions
 * Sorting the is the process of organizing content in a
 * monotonic order. When data is sorted it is possible 
 * to define more efficient algorithms to solve some 
 * problems.
 **********************************************************/ 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.h"

void RandInts(ds::Array<int>& arr,int lo,int hi)
{
    
    // int mx = (hi >= lo)?(hi):(lo);
    // int mn = (lo <= hi)?(lo):(hi);
    int count=0;
    ds::it::Iterator<int>* iter = arr.ToIterator();

    while(iter->HasNext())
    {
        iter->Next() = count++;
    }

    delete iter;
} 

bool target(ds::Array<int>& arr, int target){
    for(int i=0;i<arr.Length();i++){
        if(arr[i]+arr[arr.Length()-1-i]==target){  
            return true;
        }
    }
    return false;
}
void removeIndex(ds::Array<int>& arr, int index){
    if(index==arr.Length()){
        arr.subtractcapacity();
        
    }else{
       for(int i=index;i<arr.Length()-1;i++){
        arr[i]=arr[i+1];
        } 

        arr.subtractcapacity();
     }
}

int removeVal(ds::Array<int>& nums, int val){
    for(int i=0;i<nums.Length();i++){
        if(nums[i]==val){
            removeIndex(nums,i);
            i-=1;
        }
    }
    return nums.Length();
}

int insert(ds::Array<int>& nums, int target){
    for(int i=0;i<nums.Length();i++){
        if(nums[i]==target){
            return i;
        }else{
            if(target<nums[i]){
                return i-1;
            }
        }
    }
    return nums.Length();
}

int main()
{    
    srand(time(NULL));

    ds::Array<int> data[1] = {ds::Array<int>(15)};
    RandInts(data[0],10,99);//i populated with 0 to 15 for easy testing
    std::cout << "Data of Array " << (0 + 1) << ":\n" << data[0] << "\n\n";

    
    removeVal(data[0],6);
    std::cout<<data[0]<<std::endl<<"successfully removed 6! and length of new array is:"<<data[0].Length()<<std::endl;

    int insertvalue=3;
    std::cout<<"if I insert "<<insertvalue<<" into my array, that value would be at index: "<<insert(data[0],insertvalue)<<std::endl;//it works don't touch it




    return 0; 
}