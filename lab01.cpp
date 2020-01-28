#include <iostream>
#include<string>

bool IsLower(char c){
  return c>='a' && c<='z';
}
bool isUpper(char c){
  return c>='A' && c<='Z';
}

int letterCount(std::string str){
    int count=0;
    for(int i=0;i<str.length();i++){
      if(IsLower(str[i])||isUpper(str[i])){
            count++;
        }
    }
  return count;
}
std::string toLower(std::string str){
  for(int i=0;i<str.length();i++){
    if(isUpper(str[i])){
      str[i]=32+int(str[i]);
    }
  }
  return str;
}
std::string toUpper(std::string str){
  for(int i=0;i<str.length();i++){
    if(IsLower(str[i])){
      str[i]=int(str[i])-32;
    }
  }
  return str;
}

std::string Substr(std::string str,char s,char e){
  std::string substring="";
  int startindex=-1;
  int endindex;
  for(int i=0;i<str.length();i++){
    if(str[i]==s){
      startindex=i;
    }
    if(startindex!=-1 && str[i]==e){
      return str.substr(startindex, i-1);
    }
  }
  return "";
}
int main() {
  using namespace std;
  cout<<IsLower('d')<<endl;
  cout<<letterCount("abc;[;[;[;B")<<endl;
  cout<<toLower("DHAb")<<endl;
  cout<<toUpper("bdsahdbsadT")<<endl;
cout<<Substr("abcdefg", 'c', 'f');
}