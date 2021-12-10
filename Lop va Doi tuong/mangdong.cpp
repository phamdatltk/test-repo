#include<iostream>
using namespace std;

class Mangdong
{
private:
    /* data */
    unsigned int size;
    int *p;

public:
    Mangdong(/* args */){
        size = 0;
        p = new int[size];
    }

    Mangdong(int size){
        this->size = size;
        p = new int[size];
    }

    ~Mangdong(){
        size = 0;
        delete [] p;
    }

    Mangdong operator++(){
        if(size > 0){
            delete [] p;
        }
        ++size;
        p = new int[size];
        return Mangdong(size);
    }

    Mangdong operator--(){
        if(size > 0){
            delete [] p;
        }
        --size;
        p = new int[size];
        return Mangdong(size);
    }

    Mangdong operator+=(int n){
        if(size > 0){
            delete [] p;
        }
        p = new int[size+n];
        size += n;
        return Mangdong(size);
    }

    void init(){
        if(size > 0){
            for(int i = 0 ; i < size ; i++){
                p[i] = rand();
            }
        }
    }

    void show(){
        if(size > 0){
            cout << "Size: " << size<< endl ;
            for(int i = 0; i < size ; i++){
                cout << p[i] << "  " ;
            }
            cout << endl;
        }
    }

};

int main(){

    Mangdong a(5);
    a.init();
    a.show();

    Mangdong b = a+=5;
    b.init();
    b.show();

    return 0;
}