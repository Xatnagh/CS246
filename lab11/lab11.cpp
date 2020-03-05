#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Node.h"
#include "Iterator.h"
#include "Point.h"
#include "Vector.h"
#include <math.h>    
bool IsLine(ds::Vector<Point>& coors)
{   
    int slope=(coors[0].y-coors[1].y)/(coors[0].x-coors[1].x);
    std::cout<<"slope is "<<slope<<std::endl;
    for(int i=1;i<coors.Length();i++){
        if((coors[i].y-coors[i-1].y)/(coors[i].x-coors[i-1].x)!=slope)return false;
    }
    return true;
}

template<typename T>
ds::Node<T>* MiddleNode(ds::Node<T>* head)
{
    if(head==NULL || head->GetLink()==NULL){return NULL;}
    int count=0;
    ds::Node<T>* tmp=head;
    while(tmp!=NULL){
        count+=1;
        tmp=tmp->GetLink();
    }
    count=ceil(count/2);
    tmp=head;
    while(count>0){
        tmp=tmp->GetLink();
        count--;
    }
    return tmp;
}

/********************************
 * Helper Functions : Begin
 *******************************/

//Print() - prints elements of a linked list in a line
template <typename T>
void Print(ds::Node<T>* root)
{
    ds::sn::Iterator<T>* iter = new ds::sn::Iterator<T>(root);

    while(iter->HasNext())
    {
        std::cout << iter->Next() << " ";
    }
    std::cout << "\n"; 
    delete iter;
}

//Print() - prints elements of vector in a line
template <typename T>
void Print(ds::Vector<T> data)
{
    ds::da::Iterator<T>* iter = data.ToIterator();

    while(iter->HasNext())
    {
        std::cout << iter->Next() << " ";
    }
    std::cout << "\n"; 
    delete iter;
}

//GenerateList() - creates a linked list of random decimal numbers
ds::Node<int>* GenerateList(int n)
{
    int s = (n <= 0)?(10):(n);
    ds::Node<int>* root = new ds::Node<int>(0);

    for(int i = 1;i < s;i += 1)
    {
        ds::Node<int>* tmp = new ds::Node<int>(0,root);
        root = tmp;
    }

    ds::sn::Iterator<int>* iter = new ds::sn::Iterator<int>(root);
    
    while(iter->HasNext())
    {
        iter->Next() = (rand() % 100) + 1;
    }
    return root;
} 

/********************************
 * Helper Functions : End
 *******************************/

int main()
{
    Point a(0,-2);
    Point b(1,0);
    Point c(2,2);
    ds::Vector<Point> line;
    line.Insert(a);
    line.Insert(b);
    line.Insert(c);
    std::cout<<line<<std::endl;
     std::cout<<IsLine(line)<<std::endl;
    
    return 0; 
}
