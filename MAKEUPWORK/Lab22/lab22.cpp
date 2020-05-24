#include <iostream>
#include <string>
#include "Node.h" 

int Tribonacci(int n)
{
	if(n==3)return 1;
	if(n==2)return 1;
	if(n==1)return 0;
	if(n>3){
		return Tribonacci(n-1)+Tribonacci(n-2)+Tribonacci(n-3);
	}
	return 0;
}


int main()
{
	std::cout<<Tribonacci(7);
	return 0;
}
