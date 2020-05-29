//
// Created by tomek on 17.05.2020.
//

#include <initializer_list>
#include <cstdio>
#include "myVectorException.h"
#ifndef MYVECTOR_MYVECTOR_H
#define MYVECTOR_MYVECTOR_H
#include <memory>


template<typename T>
class myVector {
public:
    myVector();
//    myVector(T);
    myVector(unsigned size);
    myVector(std::initializer_list<T> initializerList);
    myVector(myVector&);//coppy constructor
    myVector(myVector &&);//move constructor
    virtual ~myVector();
    T& operator[](int index);
    myVector<T>& operator=(const myVector<T>& val);
    myVector<T>& operator=(const myVector<T>&& val);
    T* begin();
    T* end();
    void pushBack(T obj);
    unsigned getlenght(void);

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
    if(maxLenght>0)
    {

        //tutaj nie do konca rozumiem co sie stalo
        //mialem dlugo problem z typami bardziej zawansowanymi np dla stringa:
        //wywolywalo sie usuniecie pojedynczego elementu
        //i rzucalo blad naruszenia pamieci ;/

            if (maxLenght > 1 || sizeof(data) > 1)
                delete[] data;
            else if(maxLenght==1)
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

template<typename T>
myVector<T>::myVector(myVector &l)
:data{new T[l.maxLenght]}, lenght{l.lenght}, maxLenght{l.maxLenght}
{
    for(int i=0;i<l.lenght;i++)
        data[i]=l.data[i];

}

template<typename T>
myVector<T>::myVector(myVector &&l)
:data{l.data}, lenght{l.lenght}, maxLenght{l.maxLenght}
{
    l.data = nullptr;
    l.maxLenght = 0;
    l.lenght = 0;
}

template<typename T>
void myVector<T>::pushBack(T obj)
{
    if(lenght<maxLenght){
        data[lenght++] = obj;
    }else{
        //ok nie mamy juz miejsca w pamieci wolnej na nowe obiekty wiec trzeba przelokowac zasoby
            T *dataTEMP = data;
            unsigned maxLengtTemp = maxLenght;
            maxLenght += 20;
            try{data = new T[maxLenght];} catch (std::bad_alloc) { throw std::bad_alloc{};}
            for (int i = 0; i < lenght; i++)
                data[i] = dataTEMP[i];
            data[lenght++] = obj;
            delete[] dataTEMP;
    }
}


template<typename T>
unsigned myVector<T>::getlenght(void) {
    return lenght;
}

template<typename T>
myVector<T> &myVector<T>::operator=(const myVector<T> &val)
{
    delete[] data;
    data = new T[val.maxLenght];
    maxLenght = val.maxLenght;
    for(int i=0;i<val.lenght;i++)
        data[i]=val.data[i];
    lenght=val.lenght;
    return *this;
}

template<typename T>
myVector<T>& myVector<T>::operator=(const myVector<T> &&val) {
    delete[] data;
    data = val.data;
    lenght=val.lenght;
    maxLenght=val.maxLenght;
    val.data= nullptr;
    val.maxLenght=0;
    val.lenght=0;
}




#endif //MYVECTOR_MYVECTOR_H
