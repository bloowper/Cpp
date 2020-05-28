//
// Created by tomek on 17.05.2020.
//

#include <initializer_list>
#include "myVectorException.h"
#ifndef MYVECTOR_MYVECTOR_H
#define MYVECTOR_MYVECTOR_H



template<typename T>
class myVector {
public:
    myVector();
    myVector(unsigned size);
    myVector(std::initializer_list<T> initializerList);
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
    if(maxLenght>0||sizeof(data)>0)
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


#endif //MYVECTOR_MYVECTOR_H
