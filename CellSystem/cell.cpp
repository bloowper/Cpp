//
// Created by tomek on 01.05.2020.
//

#include "cell.h"
#include <math.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/random.hpp>
using namespace boost::multiprecision;
using namespace boost::random;




std::vector<std::pair<int, int>> returnNeighborhood(std::pair<int, int> point_in_space, int radius)
{
    int x = point_in_space.first;
    int y = point_in_space.second;
    std::vector<std::pair<int, int>> to_return;
    for(int i=point_in_space.first-radius;i<=point_in_space.first+radius;i++)
    {
        for(int j=point_in_space.second-radius;j<=point_in_space.second+radius;j++)
        {
            if(isInRadius(point_in_space,std::make_pair(i,j),radius))
            {
                if(!(i==point_in_space.first && j==point_in_space.second))
                to_return.push_back(std::make_pair(i,j));
            }
        }
    }
    return to_return;

}

bool isInRadius(std::pair<int, int> x, std::pair<int, int> y, double max_distance) {

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

int randomInBaund(int min, int max)
{
        int  output = min + (rand() % static_cast<int>(max - min + 1));
        return output;
}



bool cell::isFloorCell()
{
    return floorCell;
}

bool cell::isLifeCell() {
    return lifeCell;
}

bool cell::isObstacleCell() {
    return obstacleCell;
}

bool cell::isDeathCell() {
    return deathCell;
}


cell::cell():sf::RectangleShape()
{
    obstacleCell = false;
    lifeCell = false;
    deathCell = false;
    pointsForDie = 0;
    pointsForLife = 0;
    maxPoints = 100;
    cycles = 0;
    setOutlineThickness(1);
    setOutlineColor(sf::Color::Black);
    setFillColor(sf::Color::Magenta);
}

void cell::changePointsForLifeForm(int val)
{
    pointsForLife+=val;
    if(pointsForLife > maxPoints)
    {
        pointsForLife = maxPoints;
    }
    else if(pointsForLife < 0)
    {
        pointsForLife = 0;
    }
}

void cell::ChangePointsForDeath(int val)
{
    pointsForDie+=val;
    if(pointsForDie > maxPoints)
    { pointsForLife = maxPoints; }
    else if(pointsForDie < 0)
    {
        pointsForDie = 0;
    }

}

std::pair<int, int> cell::getChanceForLife() {
    return std::pair<int, int>(pointsForLife, maxPoints);
}

std::pair<int, int> cell::getChanceForDeath()
{
    return std::pair<int, int>(pointsForDie,maxPoints);
}

bool cell::random_life_event() {
    if(pointsForLife == 0)
        return false;
    int randomInBaund1 = randomInBaund(pointsForLife, maxPoints);
    if(randomInBaund1 == maxPoints)
        return true;
    else
        return false;
}

bool cell::random_death_event() {
    if(pointsForDie==0)
    {
        return false;
    }
    int random = randomInBaund(pointsForDie,maxPoints);
    if(random == maxPoints)
    {
        return true;
    } else
        return false;
}

void cell::cycle()
{
    cycles++;
}

unsigned int cell::nOfCycle() const {
    return cycles;
}

void cell::setAsLifeCell() {
     lifeCell = true;
     deathCell = false;
     obstacleCell = false;
     floorCell = false;
    pointsForDie = 0;
    pointsForLife = 0;
    cycles=0;
    this->setFillColor(zywa);
}

void cell::setAsDeathCell() {
    lifeCell = false;
    deathCell = true ;
    obstacleCell = false;
    floorCell = false;
    pointsForDie = 0;
    pointsForLife = 0;
    cycles=0;
    this->setFillColor(martwa);
}

void cell::setAsObstacleCell() {
    lifeCell = false;
    deathCell = false ;
    obstacleCell = true;
    floorCell = false;
    pointsForDie = 0;
    pointsForLife = 0;
    cycles=0;
    this->setFillColor(przeszkoda);
}


void cell::setAsFloorCell()
{
    lifeCell = false;
    deathCell = false ;
    obstacleCell = false;
    floorCell = true;
    pointsForDie = 0;
    pointsForLife = 0;
    cycles=0;
    this->setFillColor(podloze);
}











