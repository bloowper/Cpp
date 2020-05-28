#include <iostream>
#include "myVector.h"
using namespace std;

template<typename T>
void funkcja_do_testowania_move_constructora(myVector<T>& );



int main() {



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


    //testy konstruktora przenoszacego
    myVector<string> vector2{"zero"};
    string &basicString = vector2[0];
    std::cout<<basicString<<endl;



}



template<typename T>
void funkcja_do_testowania_move_constructora(myVector<T>& )
{

}