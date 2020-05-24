#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Node.h"
#include "Queue.h"
#include "Stack.h"
#include "lab15.h"


template <typename T>
class MyStack{
    private:
        ds::da::Queue<T> data;
        public:
        MyStack() : MyStack(30) {}

        MyStack(int capacity) : data(ds::da::Queue<T>(capacity)){};
        
        void reverseddata(){
            ds::da::Stack<T> tmp;
            while(!data.IsEmpty()){
                tmp.Push(data.Peek());
                data.Dequeue();
            }
            while(!tmp.IsEmpty()){
                data.Enqueue(tmp.Top());
                tmp.Pop();
            }
        }
        void Push(const T& value){
        
            reverseddata();
            data.Enqueue(value);
            reverseddata();
        }
       void Pop(){
           if(data.IsEmpty())return;
           data.Dequeue();
       }
       T Top(){
           return data.Peek();
       }
       bool IsEmpty(){
           return data.IsEmpty();
       }
       void print(){
            ds::da::Queue<T> tmp=data;
            while(!tmp.IsEmpty()){
                 std::cout<<tmp.Peek()<<" ";
                tmp.Dequeue();
            }
       }

};


/*****************************************************
 * Remove comment line only if you completely 
 * defined all of MyStack() methods
 *****************************************************/
bool TestStackClass()
{
    using namespace std;
    ds::sn::Stack<int> a;
    MyStack<int> b;
    int value;
    int n = 5;

    for(int i = 0;i < n;i += 1)
    {
        value = rand() % 100 + 1;
        a.Push(value);
        b.Push(value);
    }
    while(!a.IsEmpty() && !b.IsEmpty())
    {
        
        cout<<a.Top()<<"   "<<b.Top();
        if(a.Top() != b.Top())
        {
            std::cout << "TOP not equal\n\n";
            return false;
        }
        a.Pop();
        b.Pop();
    }


    if(a.IsEmpty() == b.IsEmpty())
    {
        std::cout << "MyStack is valid\n\n";
        return true;
    }
    else
    {
        std::cout << "MyStack is invalid\n\n";
        return false;
    }
}
/*****************************************************
* End of comments
*****************************************************/

/*****************************************************
 * Remove comment line only if you completely 
 * defined all of MyQueue() methods
 *****************************************************
bool TestQueueClass()
{
    ds::sn::Queue<int> a;
    MyQueue<int> b;
    int value;
    int n = rand() % 41 + 10;

    for(int i = 0;i < n;i += 1)
    {
        value = rand() % 100 + 1;
        a.Enqueue(value);
        b.Enqueue(value);
    }

    while(!a.IsEmpty() && !b.IsEmpty())
    {
        if(a.Peek() != b.Peek())
        {
            std::cout << "MyQueue is invalid\n\n";
            return false;
        }
        a.Dequeue();
        b.Dequeue();
    }
    
    if(a.IsEmpty() == b.IsEmpty())
    {
        std::cout << "MyQueue is valid\n\n";
        return true;
    }
    else
    {
        std::cout << "MyQueue is invalid\n\n";
        return false;
    }
}
*****************************************************
* End of comments
*****************************************************/

int main()
{

    TestStackClass();
    srand(time(NULL));
    
    return 0; 
}
