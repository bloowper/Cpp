//
// Created by tomek on 17.05.2020.
//

#include <initializer_list>
#include <cstdio>
#include "myVectorException.h"
#ifndef MYVECTOR_MYVECTOR_H
#define MYVECTOR_MYVECTOR_H



template<typename T>
class myVector {
public:
    myVector();
    myVector(unsigned size);
    myVector(std::initializer_list<T> initializerList);
    myVector(myVector&);//coppy constructor
    myVector(myVector &&);//move constructor

    virtual ~myVector();
    T& operator[](int index);
    T* begin();
    T* end();
    void pushBack(T obj);
    void pushBack(T& obj);
    void pushBack(T&& obj);
private:
    T *data;
    unsigned lenght;
    unsigned maxLenght;
};

template<typename T>
myVector<T>::myVector(unsigned int size)
:data{new T[size]},maxLenght{size},lenght{0}
{

}

template<typename T>
myVector<T>::myVector()
:myVector<T>::myVector(20)
{

}

template<typename T>
myVector<T>::myVector(std::initializer_list<T> initializerList)
:myVector<T>::myVector(initializerList.size())
{
    printf("std::initializer list constructor invoked \n");
    lenght = initializerList.size();
    int i=0;
    for( const T *initP = initializerList.begin();initP!=initializerList.end();initP++)
    {
        data[i] = *initP;
        i++;
    }
}

template<typename T>
myVector<T>::~myVector()
{
    printf("deconstructor invoked\n");
    if(maxLenght>0)
    {
        if(maxLenght>1)
        delete[] data;
        else
        delete data;
        maxLenght = 0;
        lenght = 0;
    }
}

template<typename T>
T &myVector<T>::operator[](int index) {
    printf("operator [(int)] invoked\n");
    if(index<0 || index>lenght)
    {
        throw outOfBound();
    }
    return data[index];
}

template<typename T>
T *myVector<T>::begin() {
    return data;
}

template<typename T>
T *myVector<T>::end() {
    return &data[lenght];
}

template<typename T>
myVector<T>::myVector(myVector &l)
:data{new T[l.maxLenght]}, lenght{l.lenght}, maxLenght{l.maxLenght}
{
    printf("coppy construcotr invoked\n");
    for(int i=0;i<l.lenght;i++)
        data[i]=l.data[i];

}


#endif //MYVECTOR_MYVECTOR_H
