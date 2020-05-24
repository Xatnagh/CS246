#include <iostream>
#include <string>
#include "Node.h" 
#include "List.h" 
#include "HashTable.h" 


int SingleNumber(ds::da::Vector<int>& data)
{
	ds::HashTable<int>table(30,hash);
	for(int i=0;i<data.Size();i++){
		if(!table.Search(data[i])){
			table.Insert(data[i]);
		}
	}
	for(int i=0;i<data.Size();i++){
		if(!table.Search(data[i])){
			return data[i];
		}
	}

	return 0;
}
int hash(const int& value){
	return value%30;
}
int main()
{
	return 0;
}
