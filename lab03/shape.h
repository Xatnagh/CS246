#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <string>
#include <sstream>
class Shape{
public:
const double perimeter();
const double area();
};
class Square: public Shape{
private:
    double side;
    public:

    Square(){this->side=1;}

    Square(double side){this->side=side;}

    Square(const Square& obj){
        side=obj.side;
    }

    Square& operator= (const Square& obj){
        if(this!= &obj){
            side=obj.side;
        }
        return *this;
    }

    ~Square(){}

    void setSide(double side){this->side=side;}

    double perimeter(){return this->side*4;}

    double area(){return this->side*this->side;}

    std::string ToString()const{
        std::stringstream out;

        out<< '(' << side << ')';
        return out.str();
    }

    friend std::ostream& operator <<(std::ostream&out , const Square& obj){
        out<<obj.ToString();
        return out;
    }


    

};
// Public assignment operator.
//  Public empty destructor.
//  Public constant get method for side.
//  Public set method for side. It assigns the parameter to side only if the parameter is positive; otherwise, it does
// nothing.
//  Public overridden Perimeter() method. It returns the perimeter of the square.
//  Public overridden Area() method. It returns the area of the square.
//  Public string constant method named ToString() that takes no parameters. It returns a string of side enclosed
// in parentheses.
//  Overloaded ostream operator. It outputs the same as ToString().



#endif