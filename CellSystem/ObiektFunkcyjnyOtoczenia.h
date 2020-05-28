//
// Created by tomek on 28.05.2020.
//

#ifndef GAME_OBIEKTFUNKCYJNYOTOCZENIA_H
#define GAME_OBIEKTFUNKCYJNYOTOCZENIA_H
#include <vector>
#include <math.h>

class ObiektFunkcyjnyOtoczenia {
    private:
        double radius;
        bool isInRadius(std::pair<int, int> x, std::pair<int, int> y, double max_distance);
    public:
        ObiektFunkcyjnyOtoczenia(int radius) : radius(radius) {}
        std::vector<std::pair<int, int>> operator()(std::pair<int, int>);
};

bool ObiektFunkcyjnyOtoczenia::isInRadius(std::pair<int, int> x, std::pair<int, int> y, double max_distance)
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

std::vector<std::pair<int, int>> ObiektFunkcyjnyOtoczenia::operator()(std::pair<int, int> pkt) {

    //liczba komorek powinna byc zliczona dyskretnie.
    //wiec tutaj nie bedzie to optymalne rozwiazanie na 100%
    double n_f_cell = M_PI * pow(radius, 2);
    int intnofcell = n_f_cell;
    //nie moglem tego skastowac bezposrednio w konstruktorze ;-;
    //i ostatecznie takie o to brzydkie dzielo :D zeby tylko uniknac nowego alokowania pamieci
    std::vector<std::pair<int, int>> to_return{size_t{static_cast<size_t>(intnofcell)}};

    for(int i=pkt.first-radius;i<=pkt.first+radius;i++)
    {
        for(int j=pkt.second-radius;j<=pkt.second+radius;j++)
        {

            std::pair<int,int> tmp{i,j};
            if(isInRadius(pkt,tmp,radius)) // && !(i==pkt.first && j==pkt.second)
            {
                to_return.push_back(std::move(tmp));
            }
        }
    }


    return to_return;
}


#endif //GAME_OBIEKTFUNKCYJNYOTOCZENIA_H
