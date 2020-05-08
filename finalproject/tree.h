#ifndef tree_h
#define tree_h
#include "branch.h"
using namespace std;
class tree{
    public:
    branch* root;
    branch* current;
    tree(branch* root):root(root),current(root){};
void cd( std::string filename){
    if(current->contains(filename)!=-1){
        current=current->getFolders()[current->contains(filename)]; 
    }else{
        cout<<"destination not found";
    }
}
void mkdir(std::string foldername){
    current->addfolder(foldername);
}
void ls(){
    current->ls();
}
void touch(std::string filename){
    current->addfile(filename);
}
void pwd(){
    current->pwd();
}
void rm(std::string filename){
    current->rm(filename);
}
};

#endif
