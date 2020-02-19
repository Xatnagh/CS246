#include <iostream>
#include "shape.h"

int main(){
    Square b(10.4);
    std::cout<<b.ToString();
    delete b;
    std::cout<<b.ToString();
}