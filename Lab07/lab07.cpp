#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Vector.h"

/*********************************************************
 * Function A 
 * Description: it will find the difference between the highest number and lowest number on the vector
 * Runtime: 3n+3
 *********************************************************/
int A(ds::Vector<int>& data)
{
    if(data.Length() <= 1)
    {
        return 0;
    }
    int mn = (data[0] <= data[1])?(data[0]):(data[1]);
    int mx = data[0] + data[1] - mn; 
    int n = data.Length();
    int i = 0;

    while(i < n)
    {
        if(mx < data[i])
        {
            mx = data[i];
        }
        else if(mn > data[i])
        {
            mn = data[i];
        }
        i += 1;
    }
    return (mx - mn);
}

/*********************************************************
 * Function B 
 * Description:  enter a day of a month and it will tell u what week day it is
 * Runtime:1 
 *********************************************************/
std::string B(int dy)
{
    int os = 5;
    std::string wkdy[7] = {"Sunday"};
    wkdy[1] = "Monday";
    wkdy[2] = "Tuesday";
    wkdy[3] = "Wednesday";
    wkdy[4] = "Thursday";
    wkdy[5] = "Friday";
    wkdy[6] = "Saturday";

    if(dy <= 0 || dy > 29)
    {
        return "Not a valid day";
    }
    return wkdy[(os + dy) % 7];
}

/*********************************************************
 * Function C 
 * Description:  check if absolute value of n is greather than 1
 * Runtime:2sqrt(n)+2
 *********************************************************/
bool C(int n)
{
    int p = (n < 0)?(-1 * n):(n);     //1      

    for(int i = 2;i * i <= p;i += 1)   //sqrt(n)+1
    {
        if(p % 1 != 0)   / //sqrt(n)
        {
            return false;  //this is useless code cus (int)%1 will always be 0
        }
    }
    return (p > 1); //1
}

/*********************************************************
 * Function D 
 * Description: populate the data vector with nested for loop of i * j where the limit of i and j is n and they both start at and increment by 1.
 * Runtime:n^2+1
 *********************************************************/
void D(ds::Vector<int>& data,int n)
{
    if(n >= 1) //1
    {
        for(int i = 1;i <= n;i += 1) //n
        {
            for(int j = 1;j <= n;j += 1) //n
            {
                data.Insert(i * j);
            }
        }
    }
}

/*********************************************************
 * Function E 
 * Description: sumation of i^2 where start i=1 and end = n 
 * Runtime: 1
 *********************************************************/
int E(int n)
{
    return (n > 0)?(n * (n + 1) * (2 * n + 1)/6):(0);//1
}

/*********************************************************
 * Function F
 * Description: it just turns n into a string, if n is less than 0, it will return '0' 
 * Runtime:n+1
 *********************************************************/
std::string F(int n)
{
    if(n <= 0)//1
    {
        return "0";
    }
    std::string cur = "";
    char dc;
    int di;

    while(n > 0) //n
    {
        di = n % 10;
        dc = (char)('0' + di);
        cur = dc + cur;
        n /= 10;
    }
    return cur;
}

int main()
{
    std::cout << F(7);
    return 0; 
}
