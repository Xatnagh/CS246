#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Vector.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Vector.h"

//Maximum Function Version 1
template <typename T>
T Maximum1(const ds::Vector<T>& data)
{
    T m = data[0];
    int n = data.Length();

    for(int i = 1;i < n;i += 1)
    {
        if(m < data[i])
        {
            m = data[i];
        }
    }

    return m;
}

//Maximum Function Version 2
template <typename T>
T Maximum2(const ds::Vector<T>& data)
{
    int n = data.Length();
    T m = (data[0] >= data[n-1])?(data[0]):(data[n-1]);
    T p;

    for(int i = 1;i < n/2;i += 1)
    {
        if(data[i] >= data[n-i-1])
        {
            p = data[i];
        }
        else
        {
            p = data[n-i-1];
        }

        if(m < p)
        {
            m = p;
        }
    }

    return m;
}

//Consecutive Integers Version 1
int ConsecInt1(int n)
{
    int s = 0;

    for(int i = 1;i <= n;i += 1)
    {
        s += i;
    }

    return s;
}

//Consecutive Integers Version 2
int ConsecInt2(int n)
{
    if(n <= 0)
    {
        return 0;
    }
    else
    {
        return n * (n + 1) / 2;
    }
}

//Is Positive Prime Version 1
bool IsPosPrime1(int n)
{
    if(n <= 1)
    {
        return false;
    }
    
    for(int i = 2;i < n;i += 1)
    {
        if(n % i != 0)
        {
            return false;
        }
    }
    return true;
} 

//Is Positive Prime Version 2
bool IsPosPrime2(int n)
{
    if(n <= 1)
    {
        return false;
    }
    
    for(int i = 2;i * i < n;i += 1)
    {
        if(n % i != 0)
        {
            return false;
        }
    }
    return true;
} 

int main()
{
    srand(time(NULL));

    ds::Vector<int> a(10);
    int arr[10];

    for(int i = 0;i < 10;i += 1)
    {
        arr[i] = rand() % 50 + 1;
    }

    a.Assign(12,10);
    ds::it::Iterator<int>* iter = new ds::it::Iterator<int>(arr,10);
    a.Insert(iter);
    delete iter;

    std::cout << a << "\n";

    return 0; 
}