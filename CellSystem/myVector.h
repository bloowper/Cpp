//
// Created by tomek on 30.05.2020.
//

#ifndef GAME_MYVECTOR_H
#define GAME_MYVECTOR_H


//
// Created by tomek on 17.05.2020.
//

#include <initializer_list>
#include <cstdio>
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
    myVector<T>& operator=(myVector<T>&& val);
    T* begin();
    T* end();
    void pushBack(T obj);
    unsigned getlenght(void);

private:
    T *data;
    unsigned lenght;
    unsigned maxLenght;
};





#endif //MYVECTOR_MYVECTOR_H



#endif //GAME_MYVECTOR_H
