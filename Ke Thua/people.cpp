#include<iostream>
using namespace std;

class People
{
protected:
    /* data */
    string Name;
    int Age;
    string Address;

public:
    People(/* args */){
        Name = "";
        Age = 0;
        Address = "";
    }
    ~People(){
        Name = "";
        Age = 0;
        Address = "";
    };

    virtual void set(){
        cout << endl;
        cout << "Enter name: " ;
        getline(cin , Name);
        cout << "Enter age: " ;
        cin >> Age; 
        cin.ignore(3222, '\n');
        cout << "Enter address: " ;
        getline(cin , Address);
    }

    virtual void get(){
        cout << "Name: " << Name << endl;
        cout << "Age: " << Age << endl;
        cout << "Address: " << Address << endl;
    }
};

class Student : public People
{
private:
    /* data */
    int id;
    float math;
    float physical;
    float chemistry;

public:
    Student(/* args */){
        People();
        int id = 0;
        float math = 0;
        float physical = 0;
        float chemistry = 0;

    }
    ~Student(){
        int id = 0;
        float math = 0;
        float physical = 0;
        float chemistry = 0;
    }

    void set(){
        People::set();
        cout << "Enter ID: " ;
        cin >> id;
        cout << "Enter math: " ;
        cin >> math;
        cout << "Enter physical: " ;
        cin >> physical;
        cout << "Enter chemistry: " ;
        cin >> chemistry;
    }

    void get(){
        People::get();
        cout << "ID: " << id << endl;
        cout << "Math: " << math << endl;
        cout << "Physical: " << physical << endl;
        cout << "Chemistry: " << chemistry << endl;
    }

    void GPA(){
        cout << "GPA: " << (math + physical + chemistry) / 3 << endl;
    }
};



int main(){

    People Dat;
    Dat.set();
    Dat.get();

    Student Trinh;
    Trinh.set();
    Trinh.get();
    Trinh.GPA();

    return 0;
}