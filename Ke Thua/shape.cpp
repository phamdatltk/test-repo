#include<iostream>
using namespace std;

class Shape
{
protected:
    string name;

public:
    virtual float DienTich(){ return 0; }
    virtual float ChuVi(){ return 0; }
    virtual void show(){}
};

class Retange : public Shape
{
private:
    /* data */
    float Dai;
    float Rong;
    string Name;
    
public:
    Retange(/* args */){
        Dai = 0;
        Rong = 0;
        Name = "";
    }

    Retange(string name ,float dai, float rong){
        Dai = dai;
        Rong = rong;
        Name = name;
    }
    ~Retange(){
        Dai = 0;
        Rong = 0;
        Name = "";
    }
    float DienTich(){
        return Dai*Rong;
    }
    float ChuVi(){
        return (Dai + Rong) * 2;
    }

    void show(){
        cout << "Retangle: " << Name << endl;
        cout << "Chu Vi: " << ChuVi() << endl;
        cout << "Dien Tich: " << DienTich() << endl;
    }
};

int main(){

    Retange Dat ("Dat", 10, 20.5);
    Dat.show();

    return 0;
}