//
// Created by tomek on 17.05.2020.
//

#ifndef MYVECTOR_MYVECTOREXCEPTION_H
#define MYVECTOR_MYVECTOREXCEPTION_H

class myVectorException{

};

class Bound :public myVectorException{

};

class outOfBound: public Bound
{

};

class AllocationProblems: public Bound
{

};






#endif //MYVECTOR_MYVECTOREXCEPTION_H
