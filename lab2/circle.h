#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
#include <string>
#include <sstream>
class Circle{
  private: 
  double radius;
   static const double pi;
  public:

  Circle(){
    radius=1;
  }

  Circle(double r){
    (r>0)?radius=r:radius=1;
  }

  Circle(Circle& cir){
    radius=cir.radius;
  }

  ~Circle();

  Circle& operator=(const Circle& cir){
    if(this!=&cir)
    radius=cir.radius;
    return *this;
    }
  double getRadius(){
    return radius;
  }
  double getRadius ()const{
    return radius;
  }
  void setRadius(double r){
    radius=r;
  }
  double diameter(){
    return radius*2;
  }
  double circumference(){
    return 2*pi*radius;
  }
  double area(){
    return pi*radius*radius;
  }
  std::string toString() const{

    std::stringstream out;

    out<<((double )((int)(radius * 10)));
    return out.str();
  }
 friend std::ostream& operator<<(std::ostream& out,const Circle& obj)
    {
        out << obj.toString();
        return out;
    }



};

const double Circle::pi=3.141592; 


#endif 