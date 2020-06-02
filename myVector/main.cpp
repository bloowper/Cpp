#include <iostream>
#include <vector>
#include "myVector.h"
using namespace std;


void funkcja_do_testowania_move_constructora(myVector<myVector<string>>&);

class classfordebuge{
private:
    int *variable;
public:
    classfordebuge()
    :variable{new int}
    {

    }
    classfordebuge(int var)
    :classfordebuge{}
    {
        *variable = var;
    }
    ~classfordebuge()
    {
        delete variable;
    }
    classfordebuge(const classfordebuge&  val)
    :variable{new int}
    {
        printf("debuge coppy constructor\n");
        *variable = *val.variable;
    }
    classfordebuge(classfordebuge&& val)
    {
        variable = val.variable;
        val.variable = nullptr;
        printf("debuge move constructor\n");
    }

    classfordebuge& operator=(const classfordebuge & val)
    {
        *variable=*val.variable;
        return *this;
    }

    int& getvalue()
    {
        return *variable;
    }

};

int main() {

    //tesotwanie


    myVector<int> vector{1,2,3,4,5,6};
    printf("test operatora [int] %d",vector[2]);
    std::cout<<std::endl;



    //iterowanie przy pomocy wskaznikow
    printf("iterowanie przy pomocy begin end \n");
    for(auto it = vector.begin();it!=vector.end();it++)
    {
        printf("%d ", *it);
    }printf("\n");



    //iterowanie przy pomocy petli zakresowej for
    printf("iterowanie przy pomocy zaakresowej petli for\n");
    for(auto obj:vector)
    {
        printf("%d ",obj);
    }printf("\n");



    //testy konstruktora kopiujacego
    myVector<int> vector1{vector};
    vector1[0]=66;
    printf("orginal vect\n");
    for(auto i:vector)
        printf("%d ",i);cout<<endl;
    printf("edited coppy vector\n");
    for(auto i:vector1)
        printf("%d ",i); cout<<endl;
    printf("orginal vect\n");
    for(auto i:vector)
        printf("%d ",i);cout<<endl;


    //test metody pushbac
    cout<<"metoda push back dla 30 stringow"<<endl;
    myVector<string> vector2;
    for(int i=0;i<30;i++)
    {
        string temp{"test"};
        vector2.pushBack(temp);
    }

    for(auto obj:vector2)
        cout<<obj<<" ";cout<<" nOfObj "<<vector2.getlenght()<<endl;

    //test konstruktorza przenoszacego
    cout<<"test obiektow przenoszacych\n";
    myVector<myVector<string>> vector3;
    for(int i=0;i<5;i++)
    {
        vector3.pushBack(myVector<string>{"hello"," world"," sample"});
    }

    for(auto &obj:vector3)
    {
        for(auto &ob:obj)
            cout<<ob<<" "<<"test";
        cout<<endl;
    }



    myVector<string> vector4;
    vector4.pushBack(string{"okon"});


    myVector<int> vector6{};
    for(int i=0;i<10;i++)
    {
        vector6.pushBack(i);
        cout<<vector6[vector6.getlenght()-1]<<" ";
    }


    printf("test dla obiektu do z dynamiczna pamiecia\n");
    myVector<classfordebuge> vector5{classfordebuge{1},classfordebuge{2}};
    for(auto i:{2,5,10,15,20})
    {
        vector5.pushBack(classfordebuge{i});
    }


    for(auto obj:vector5)
        cout<<obj.getvalue()<<"<value"<<" ";





}



template<typename T>
void funkcja_do_testowania_move_constructora(myVector<myVector<string>>& vect)
{

}