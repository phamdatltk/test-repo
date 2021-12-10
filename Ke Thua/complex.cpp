#include<iostream>
using namespace std;

class Real{

protected:
    float r;

public:
    Real(){
        r = 0;
    }

    Real(float a){
        r = a;
    }

    ~Real(){
        r = 0;
    }

    Real Add(Real x){
        Real z ;
        z.r = r + x.r;

        return z;
    }

    void Print(){
        cout << r;
    }

};

class Complex: public Real
{
    /* data */
    float i;
public:
    Complex(/* args */){
        r = 0;
        i = 0;
    }
    Complex(float a, float b){
        r = a;
        i = b;
    }

    ~Complex(){
        r = 0;
        i = 0;
    }

    Complex Add(Complex a){
        Complex z ;
        z.r = r + a.r;
        z.i = i + a.i;
        return z;
    }

    void Print(){
        Real::Print();
        cout << "+j" << i;
    }
};



int main(){


   Real x, y(10.5),z(25.5);
   x = y.Add(z);
   cout<<"x="; x.Print();
   cout<<endl;   
   
   Complex c, d(5,6), e(6,9);
   c = d.Add(e);
   cout<<"c="; c.Print();
   cout<<endl;   
   
   return 0;
}
