#include <iostream>
#include <string>
#include "Node.h" //Node()
#include "Pair.h" //Pair()
#include "Iterator.h" //Iterator(), PairIterator()
#include "Set.h" //Set()
#include "List.h" //Vector(), LinkedList()
#include "Map.h" //Map()

int DuplicatesSum(ds::da::Vector<int>& data)
{
	ds::da::Map<int,int> numbercount;
	for(int i=0;i<data.Size();i++){
		if(!numbercount.Contains(data[i])){
			numbercount.Put(data[i],1);
		}else{
			numbercount[data[i]]+=1;
		}
	}
	
	int sum=0;
	ds::da::PairIterator<int,int>* it= numbercount.ToIterator();
	while(it->HasNext()){
		if(it->NextValue()>1){
			sum+=it->NextKey();
		}
		it->Next();
	}
	return sum;
}



int main()
{ds::da::Vector<int> data;
data.Insert(1);
data.Insert(1);
data.Insert(2);
data.Insert(3);
data.Insert(2);
data.Insert(5);
std::cout<<DuplicatesSum(data);
	return 0;
}
