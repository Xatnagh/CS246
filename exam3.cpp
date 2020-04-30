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
#include "Map.h"
#include "HashTable.h"

//Question 1


int indexof(ds::da::Vector<int>& data,int value);
ds::da::Vector<int> BoundMode(ds::da::Vector<int>& data,int upb)
{
	if(upb<=1 || data.Size()==0){
		return ds::da::Vector<int>();
	}
//explanation on whats about to happen:
//I make a vector tmp, it will always be evenly indexed. Even index such as 0,2,4 will contain key, odd index will contains value or amout that each key appeared.

	ds::da::Vector<int> tmp;
	int uniquecount=0; // how many unique value is in this vector, total element of tmp will always be this value*2
	for(int i=0;i<data.Size();i++){
		if(indexof(tmp,data[i])!=-1){ 
			tmp.Insert(data[i]);
			uniquecount+=1; 
			tmp.Insert(1);
			
		}else{
			tmp[indexof(tmp,data[i])+1]+=1;
		}
	}
	ds::da::Vector<int> mode;
	int max=0;
	for(int i = 1;i<tmp.Size()-1;i+=2){   //i starts at one and increments by 2 so each value it looks at would be Value
		if(tmp[i]>max){
			max+=1;
		}
	}	
	if(max==1) return ds::da::Vector<int>(); 
	for(int i = 1;i<tmp.Size()-1;i+=2){
		if(tmp[i]==max){
			mode.Insert(tmp[i-1]); // i-1, so this is the key associated with the value.
		}
	}
	return mode;
}
//Note: THIS
int indexof(ds::da::Vector<int>& data,int value){
	for(int i=0;i<data.Size();i+=2){ // i increments by 2, so each value it looks at will be a key.
		if(data[i]==value)return i;
	}
	return -1;
}




//Question 2

struct Point
{
	int x;
	int y;
};

int PointToIndex(Point& p)
{
	return (p.x - 1) * 8 + (p.y - 1);
}

bool RookMove(ds::da::Vector<int>& bd,Point& s,Point& e)
{
	 if(s.x!=e.x && s.y!=e.y){ // if both x and y is different then  the end is diagonal, which is ILLEGAL.
        return false;
    }
    bool rowOrCol;
    (s.x==e.x)? rowOrCol=true : rowOrCol=false; // checks for whether or not the rook is going horizontally or vertically
	int unitChange;
    rowOrCol?  unitChange=1 :  unitChange=8;
    int start= PointToIndex(s);
    int end = PointToIndex(e);
    if(start>end) unitChange*=-1; // if start is greather than end, then you are not moving right or up, instead you are going in the opposite direction
    
    for(int i=start;i!=end;i+=unitChange){ 
        if(bd[i]=='x'){
            return false;
        }
    }

    return true;
}


//Question 3

bool IsValidParentheses(std::string str)
{	
	if(str[0]==')')return false;
	int opencount=0;
	int closecount=0;
	for(int i=0;i<str.length();i++){
		if(str[i]=='('){
			opencount++;
		}else{closecount++;}
	}
	if(closecount==opencount){return true;}
	return false;
}

//Question 4

template <typename T>
void Swap(ds::dn::Node<T>* a,ds::dn::Node<T>* b)
{
	if(a != NULL && b != NULL)
	{
		T t = a->GetData();
		a->SetData(b->GetData());
		b->SetData(t);
	}
}

template <typename T>
void InsertionSort(ds::dn::Node<T>* root)
{
	if(root->GetNext()==NULL)return;
	for(ds::dn::Node<T>* i=root->GetNext(); i->GetNext()!=NULL;i=i->GetNext()){
		ds::dn::Node<T>* tmp = i;
		T current=tmp->GetData();
		while(tmp->GetPrev()->GetData()>tmp->GetData()){
			tmp->SetData(tmp->GetPrev()->GetData);
			tmp=tmp->GetPrev();
		}
		tmp->SetData(current);
	}
	return;
}

//Question 5

template <typename T>
bool IsProperSubSet(ds::da::Set<T>& A,ds::da::Set<T>& B)
{
	for(int i =0;i<A.Size();i++){
		if( !B.Contains(A[i])){  // i added the [] operator myself
			return false;
		}
	}
	if(B.Size()==A.Size())return false;
	return true;
}
int main()
{
	ds::da::Vector<int> tmp;
	tmp.Insert(3);
	tmp.Insert(2);
	tmp.Insert(3);
	tmp.Insert(2);
	tmp.Insert(3);
	tmp.Insert(2);
	tmp.Insert(3);
	tmp.Insert(2);
	tmp.Insert(3);
	tmp.Insert(2);
	tmp.Insert(3);
	tmp.Insert(2);
	tmp.Insert(1);
	tmp.Insert(9);
	std::cout<<BoundMode(tmp,9);
	return 0;
}
