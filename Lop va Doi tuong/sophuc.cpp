#include<iostream>
#include<math.h>
using namespace std;

class sophuc
{
private:
    /* data */
    float phanthuc, phanao;
public:
    sophuc(/* args */){
        phanthuc = 1;
        phanao = 1;
    }

    sophuc(int a, int b){
        phanthuc = a;
        phanao = b;
    }

    sophuc operator+(sophuc p){
        sophuc q;
        q.phanthuc = phanthuc + p.phanthuc;
        q.phanao = phanao + p.phanao;
        return q;
    }

    sophuc operator-(sophuc p){
        sophuc q;
        q.phanthuc = phanthuc - p.phanthuc;
        q.phanao = phanao - p.phanao;
        return q;
    }

    sophuc operator*(sophuc p){
        sophuc q;
        q.phanthuc = phanthuc * p.phanthuc - phanao * p.phanao;
        q.phanao = phanthuc * p.phanao  + phanao * p.phanthuc;
        return q;
    }

    sophuc operator/(sophuc p){
        sophuc q;
        float mau = pow(p.phanao, 2) + pow(p.phanthuc, 2);
        q.phanthuc = (phanthuc * p.phanthuc + phanao * p.phanao) / mau;
        q.phanao = (phanthuc * p.phanao  - phanao * p.phanthuc) / mau;
        return q;
    }

    ~sophuc(){
        phanthuc = 1;
        phanao = 1;
    }

    friend ostream& operator<<(ostream & os, sophuc p);
};

ostream& operator<<(ostream & os, sophuc p){
    os << p.phanthuc << " + " << p.phanao <<"i";
    return os;
}

int main(){

    sophuc a;
    cout << "Ham tao khong tham so: " << a << endl;
    sophuc b(2,2);
    cout << "Ham tao co tham so: " << b << endl;
    cout << a << " + " << b << " = " << a + b << endl;
    cout << b << " - " << a << " = "<< b - a << endl;
    cout << a << " * " << b << " = "<< a * b << endl;
    cout << b << " / " << a << " = "<< b / a << endl;

    return 0;
}