//
// Created by tomek on 01.05.2020.
//

#ifndef GAME_CELL_H
#define GAME_CELL_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "abstractCell.h"

class cell :public sf::RectangleShape, public abstractCell
{
public:
    cell();
    bool isFloorCell() override ;
    bool isLifeCell()override ;
    bool isObstacleCell() override;
    bool isDeathCell() override;
    void setAsLifeCell()override ;
    void setAsObstacleCell() override;
    void setAsDeathCell() override;
    void setAsFloorCell() override;
    void changePointsForLifeForm(int val)override ;
    void ChangePointsForDeath(int val)override ;
    std::pair<int,int> getChanceForLife()override ;
    std::pair<int,int> getChanceForDeath();
    bool random_life_event()override ;
    bool random_death_event()override ;
    void cycle()override ;
    unsigned int nOfCycle() const;


private:
    const sf::Color podloze{0,194,255};
    const sf::Color zywa{67,255,0};
    const sf::Color martwa{255,61,0};
    const sf::Color przeszkoda{179,0,255};

};

std::vector<std::pair<int, int>> returnNeighborhood(std::pair<int, int> point_in_space, int radius);
bool isInRadius(std::pair<int,int> x,std::pair<int,int> y, double max_distance);
int randomInBaund(int min,int max);

#endif //GAME_CELL_H
