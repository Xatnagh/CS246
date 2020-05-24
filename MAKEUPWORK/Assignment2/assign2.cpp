#include <iostream>
#include <string>
#include "Node.h"
#include "Pair.h"
#include "Iterator.h"
#include "Stack.h"
#include "Queue.h"
#include "Deque.h"
#include "Map.h"


bool isLetterOrnumberorSpace(const char& character){
	if((character<'z'&&character>'a' )||(character<'Z'&&character>'A')||(character<='9'&&character>='0')|| character==' '){
		return true;
	}
	return false;
}
class Editor {
private:
ds::da::Deque<char> data;
public:
	Editor():data(){}
	Editor(const Editor& obj){
		data=obj.data;
	}
	Editor& operator= (const Editor& obj){
		data=obj.data;
	}
	~Editor(){}

	void read(const char& character){
		if(isLetterOrnumberorSpace(character)){
			data.InsertLast(character);
		}
		if(character=='#'){
			if(!data.IsEmpty())data.RemoveLast();
		}
	}
	std::string write(){
		std::string output="";
		while(!data.IsEmpty()){
			output+=data.Last();
			data.RemoveLast();
		}
		return output;
	}
};



class DayPlanner {
private:
	ds::da::Map<int,ds::dn::Queue<std::string>> tasks;
public:
	DayPlanner(){};
	DayPlanner(const DayPlanner& other){
		tasks=other.tasks;
	}
	DayPlanner& operator=(const DayPlanner& other){
		tasks=other.tasks;
	}
	void addTask(int num,std::string task){
		if(num>=0 && num<=23){
			if(!tasks.Contains(num)){
				ds::dn::Queue<std::string> tmp;
				tmp.Enqueue(task);
				tasks.Put(num,tmp);
			}else{
				ds::dn::Queue<std::string>& tmp= tasks.Get(num);
				tmp.Enqueue(task);
			}
		}
	}
	std::string NextTask(){
		int count=0;
		while(!tasks.Contains(count)){
			count++; //finds smallest int in map
		}
		ds::dn::Queue<std::string>& tmp=tasks.Get(count);
		std::string result=tmp.Peek();
		tmp.Dequeue();
		return result;
	} 


};
bool isNumber(const char& character){
if(character<='9'&&character>='0')return true;
return false;
}
bool islowercaseletter(const char& character){
	return (character<='z'&&character>='a');
}
std::string Decode(std::string str)
{
	std::string result="";
	for(int i=0;i<str.size();i++){
		if(isNumber(str[i])){
			int repeatcount=int(str[i])-int('0');
			std::cout<<repeatcount<< " ";
			i++;//skips the first [
			int currenti=i;
			while(repeatcount>1){ 
				if(str[i]==']'){
					i=currenti; //reset i to beginning of chat loop
					repeatcount--;
				}else{
					if(islowercaseletter(str[i])){
						result+=(str[i]);
					}
				}
				i++;
			}
		}
		if(islowercaseletter(str[i])){
			result+=(str[i]);
		}
	}

	return result;
}

int main()
{
	std::cout<<Decode("2[abc]3[cd]ef")<<'\n';
	return 0;
}
