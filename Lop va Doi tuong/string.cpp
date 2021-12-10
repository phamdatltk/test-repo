#include<iostream>
#include<string.h>
using namespace std;

class String
{
private:
    /* data */
    char *p;
    int size;

public:
    String(){
        size = 0;
        p = new char[size];
    }
    ~String(){
        size = 0;
        delete [] p;
    }
    String(char ch){
        size = 1;
        p = new char[size];
        p[0] = ch;  
    }
    void show(){
        cout << "Size = " << size << endl ;
        for(int i = 0; i < size ; i++){
            cout << p[i];
        }
        cout << endl;
    }

    String(char * str){
        size = strlen(str);
        p = new char[size];
        for(int i = 0; i < size ; i++){
            p[i] = str[i];
        }
    }

    String operator+(String &a){
        String b;
        b.size = size + a.size;
        delete [] b.p;
        b.p = new char[b.size];

        for(int i = 0; i < size ; i++){
            b.p[i] = p[i];
        }
        for(int i = size; i < b.size ; i++){
            b.p[i] = a.p[i-size];
        }

        return b ;
    }
    
    String operator!(){
        String b;
        b.size = size;
        delete [] b.p;
        b.p = new char[size];

        for(int i = 0; i < size ; i++){
            b.p[i] = p[size- i - 1];
        }

        return b;
    }
};

int main(){

    String a;
    a.show();

    String b('t');
    b.show();

    char str[] = "VuTuyetTrinh";
    char p[] = "PhamTienDat";
    String c(str);
    c.show();

    String d = !c;
    d.show();

    String e = c + d;
    e.show();


    return 0;
}