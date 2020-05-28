#include <iostream>
#include "myVector.h"

int main() {

    myVector<int> vector{1,2,3,4,5,6};
    printf("%d",vector[2]);
    std::cout<<std::endl;
    for(auto it = vector.begin();it!=vector.end();it++)
    {
        std::cout<<*it<<std::endl;
    }
}
