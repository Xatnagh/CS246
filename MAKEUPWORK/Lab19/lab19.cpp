#include <iostream>
#include <string>

template<class K,class V>
struct Map
{
	K keys[100];
	V values[100];
	int size;
};

template<class K,class V>
void Initialize(Map<K,V>& map)
{
	map.size = 0;
}

template<class K,class V>
void Put(Map<K,V>& map,const K& key,const V& value)
{
	if() map.size()>100)return;
	for( int i =0;i<map.size();i++){
		if(map.keys[i]==key )return;
	}
	map.keys[map.size]=key;
	map.values[map.size]=value;
	return;
}

template<class K,class V>
V& Get(Map<K,V>& map,const K& key)
{
	for( int i =0;i<map.size();i++){
		if(map.keys[i]==key )return map.values[i];
	}
	throw "Key Does Not Exists";
}

template<class K,class V>
bool Contains(Map<K,V>& map,const K& key)
{
	for( int i =0;i<map.size();i++){
		if(map.keys[i]==key )return true;
	}
	return false;
}

template<class K,class V>
void Remove(Map<K,V>& map,const K& key)
{
	for( int i =0;i<map.size();i++){
		if(map.keys[i]==key){
			while(i<map.size){
				map.keys[i]=map.keys[i+1];
				map.values[i]=map.values[i+1];
				i++; //i is already the size of map so the for loop stops as well
			}
		}
	}
	return;
}

int main()
{
	return 0;
}
