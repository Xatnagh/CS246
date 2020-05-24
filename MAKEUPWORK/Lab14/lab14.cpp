#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Node.h"
#include "Iterator.h"
#include "Point.h"
#include "Vector.h"
#include "Queue.h"

std::string ToTernary(int n)
{
    return "0";
}
//I DID ROOK MOVE

/********************************
 * Helper Functions : Begin
 *******************************/

//ToBoardIndex() - converts Point object to a one dimension chess board index
int ToBoardIndex(Point& p)
{
    if(p.x >= 0 && p.x < 8 && p.y >= 0 && p.y < 8)
    {
        return p.x * 8 + p.y;
    }
    return 0;
}

//PrintBoard() - prints chess board
void PrintBoard(ds::Vector<char>& bd)
{
    if(bd.Length() == 64)
    {
        for(int i = 0;i < 64;i += 1)
        {
            std::cout << bd[i];

            if((i + 1) % 8 == 0)
            {
                std::cout << "\n";
            } 
            else 
            {
                std::cout << " ";
            }
        }
    }
}

//GenerateBoard() - generate a chess board of spaces
ds::Vector<char> GenerateBoard()
{
    ds::Vector<char> bd(64);
    bd.Assign(64,'o');
    int n = rand() % 12 + 4;

    for(int i = 0;i < n;i += 1)
    {
        bd[rand() % 64] = 'x';
    }
    return bd;
} 

/********************************
 * Helper Functions : End
 *******************************/
bool RookMove(ds::Vector<char>& bd,Point& s,Point& e)
{
        ds::Vector<char>& tmp=bd; // made a temp board so original board doesn't get modified
        ds::da::Queue<int> possiblemoves;
        addtopossibemoves(possiblemoves,tmp,s);
        
        int goal = ToBoardIndex(e);
        for(int i=possiblemoves.Peek(); !possiblemoves.IsEmpty(); i=possiblemoves.Peek()){
            if(i==goal){                                            
              return true;
            }
             possiblemoves.Dequeue(); 
        }
        return false;
}
void addtopossibemoves(ds::da::Queue<int>& moves,ds::Vector<char>& bd,Point& s){
    moves.Enqueue(ToBoardIndex(s));
    
    bd[ToBoardIndex(s)]='x'; //if a block is checked is might as well be blocked off
    
    int index=ToBoardIndex(s);
    
    if(index+8<64 && bd[index+8]!='x'){
        Point tmp=s;
        tmp.y+=1;
         addtopossibemoves(moves,bd,tmp);
    }
    if(index-8>0 && bd[index-8]!='x'){
        Point tmp=s;
        tmp.y-=1;
         addtopossibemoves(moves,bd,tmp);
    }
    if(index+1<64 && bd[index+1]!='x'){
        Point tmp=s;
        tmp.x+=1;
         addtopossibemoves(moves,bd,tmp);
    }
    if(index-1>0 && bd[index-1]!='x'){
        Point tmp=s;
        tmp.x-=1;
         addtopossibemoves(moves,bd,tmp);
    }
}

int main()
{
    srand(time(NULL));
    
    return 0; 
}
