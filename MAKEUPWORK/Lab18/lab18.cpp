#include <iostream>
#include <string>
#include "Array.h"
#include "Node.h"
#include "Iterator.h"
#include "List.h"
#include "Queue.h"
#include "Set.h"
#include "Stack.h"
#include "Deque.h"

int ToInteger(std::string num)
{
	bool negative;
	int start=0;
	if(num.size()<=1)return -2147483647;
	ds::Array<int> characters(num.size());
	if(num[0]=='-'){
		negative=true;
		start=1; //to check to negatives if tehre are negatives skip the first index;
	}
	for(int i=start;i<num.size();i++){
		if((num[i]<='9' && num[i]>='0') ){
		characters[i]=int(num[i])-int('0');	
		}else{
			return -2147483647;
		}
	}
	int result=characters[0];
	for(int i=1;i<characters.Size();i++){
		result*=10;
		result+=characters[i];
	}
	if(result>2147483647 || result<-2147483647)return -2147483647;
	return negative ? result*-1:result;
}

int main()
{
	std::cout<<ToInteger("189732");
	return 0;
}
