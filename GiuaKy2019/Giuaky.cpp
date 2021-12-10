#include<iostream>
using namespace std;

#define  MAX  300 

class CharArray { 

    char a[MAX]; 
    int size; 

public: 

    CharArray();//khởi tạo mảng ban đầu có kích thước bằng 0 
    CharArray(CharArray & ar);//Hàm tạo copy 
    //khởi tạo mảng ban đầu có giá trị và kích thước bằng mảng b 
    CharArray(char  b[],int  bSize); 
    void add(char ch, int p);//bổ sung ch vào vị trí p của mảng nếu kích thước mảng 
    // còn < MAX, (ký tự đầu ở vị trí 0) 
    void remove(int p);//loại bỏ ký tự ở vị trí p của mảng nếu kích thước mảng còn > 0 
                        //(ký tự đầu ở vị trí 0) 
    friend CharArray operator+(char ch, CharArray ar);//trả về mảng có thêm ký tự ch ở đầu (vai trò giống hàm addFirst) 
    friend ostream & operator<<(ostream & os, CharArray  ar); 
    CharArray operator*(int k);//trả về mảng kích thước gấp k lần mảng ban đầu 
}; 

CharArray::CharArray(){
    size = 0;
}

CharArray::CharArray(CharArray & ar){
    size = ar.size;
    for(int i = 0; i < size ; i++){
        a[i] = ar.a[i];
    }
}

CharArray::CharArray(char  b[],int  bSize){
    size = bSize;
    for(int i = 0; i < size ; i++){
        a[i] = b[i];
    }
}

void CharArray::add(char ch, int p){
    if(size < MAX){
        size ++;
        for(int i = size; i > p; i--){
            a[i] = a[i-1];
        }
        a[p] = ch;
    }
}

void CharArray::remove(int p){
    if(size > 0){
        size--;
        for(int i = p; i < size ; i++){
            a[i] = a[i+1];
        }
    }
}

CharArray operator+(char ch, CharArray ar){
    ar.size++;
    for(int i = ar.size; i > 0; i--){
            ar.a[i] = ar.a[i-1];
    }
    ar.a[0] = ch;
    return ar;
}

ostream & operator<<(ostream & os, CharArray  ar){
    for(int i = 0; i < ar.size; i++){
        os << ar.a[i] << " ";
    }
    os << endl;
    return os;
}

CharArray CharArray::operator*(int k){
    CharArray b;
    b.size = size*k;
    for(int i = 0 ; i < k; i++){
        for(int j = 0 ; j < size; j++){
            b.a[i*size + j] = a[j]; 
        }
    }
    return b;
}

int main(){

    char a[ ] = {'X', 'Y', 'Z'}; 
    CharArray ar(a,3); 
    CharArray ar2(ar); 
    cout<<"Kiem tra cac ham thanh vien:"<<endl; 
    cout<<ar<<ar2; 
    ar.add('a',0); 
    ar.add('b',4); 
    ar.add('c',1); 
    cout<<ar; 

    ar = 'd' + ar;
    cout << ar;

    CharArray b;

    b = ar*5;
    cout << b;

    
}