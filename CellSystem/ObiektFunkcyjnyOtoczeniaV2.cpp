//
// Created by tomek on 30.05.2020.
//

//
// Created by tomek on 28.05.2020.
//

#ifndef FUNC_OBJECT
#define FUNC_OBJECT
#include <vector>
#include <math.h>
#include "myVector.h"

class ObiektFunkcyjnyOtoczeniav2 {
private:
    double radius;
    bool isInRadius(std::pair<int, int> x, std::pair<int, int> y, double max_distance);
public:
    ObiektFunkcyjnyOtoczeniav2(int radius) : radius(radius) {}
    myVector<std::pair<int,int>> operator()(std::pair<int, int>);
};

bool ObiektFunkcyjnyOtoczeniav2::isInRadius(std::pair<int, int> x, std::pair<int, int> y, double max_distance)
{

    double  xf=x.first,
            xs=x.second,
            yf=y.first,
            ys=y.second,
            distance;
    distance = sqrt(pow(xf-yf,2)+pow(xs-ys,2));
    if(distance<=max_distance)
        return true;
    else
        return false;

}




#endif //GAME_OBIEKTFUNKCYJNYOTOCZENIA_H


