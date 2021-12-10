#include<iostream>
using namespace std;

int UCLN(int a, int b){
    while(true){
        if(a>b){
            a = a - b;
        }if(a < b){
            b = b - a;
        }if(a == b){
            break;
        }
    }
    return a;
}

class Phanso
{
private:
    /* data */
    int tuso, mauso;
public:
    Phanso(/* args */){
        tuso = 0;
        mauso = 1;
    }

    Phanso(int tuso, int mauso){
        this->tuso = tuso;
        this->mauso = mauso;
    }

    ~Phanso(){
        tuso = 0;
        mauso = 1;
    }

    Phanso ToiGian(){
        Phanso p;
        p.tuso = tuso/UCLN(tuso, mauso);
        p.mauso = mauso/UCLN(tuso, mauso);
        return p;
    }

    Phanso operator+(Phanso p){
        Phanso q;
        q.tuso = tuso * p.mauso + mauso * p.tuso;
        q.mauso = mauso * p.mauso;
        q = q.ToiGian();
        return q;
    }

    Phanso operator-(Phanso p){
        Phanso q;
        q.tuso = tuso * p.mauso - mauso * p.tuso;
        q.mauso = mauso * p.mauso;
        q = q.ToiGian();
        return q;
    }

    Phanso operator!(){
        Phanso p;
        p.tuso = mauso;
        p.mauso = tuso;
        p.ToiGian();
        return p;
    }

    friend Phanso operator*(Phanso p, Phanso q);
    friend Phanso operator/(Phanso p, Phanso q);
    friend ostream& operator<<(ostream & os, Phanso p);
    
};

Phanso operator*(Phanso p, Phanso q){
    Phanso r;
    r.tuso = p.tuso * q.tuso;
    r.mauso = p.mauso * q.mauso;
    r = r.ToiGian();
    return r;
}

Phanso operator/(Phanso p, Phanso q){
    Phanso r;
    r = p * (!q);
    r.ToiGian();
    return r;
}

ostream& operator<<(ostream & os, Phanso p) {
    os << p.tuso << "/" << p.mauso ;
    return os;
}

int main(){
    
    Phanso a;
    cout << "Khoi tao khong tham so: " << a << endl ;

    Phanso b(12,60);
    cout << "Khoi tao co tham so: " << b << endl ;
    cout << "Toi gian: " << b.ToiGian() << endl ;
    cout << "Nghich dao: " << !b.ToiGian() << endl ;
    
    Phanso c(10, 153);
    cout << b << " + " << c << " = " << b+c << endl ; 
    cout << b << " - " << c << " = " << b-c << endl ; 
    cout << b << " * " << c << " = " << b*c << endl ;
    cout << b << " / " << c << " = " << b/c << endl ;  
    return 0;

}