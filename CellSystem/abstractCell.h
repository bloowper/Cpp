//
// Created by tomek on 10.05.2020.
//

#ifndef GAME_ABSTRACTCELL_H
#define GAME_ABSTRACTCELL_H
#include <utility>


//ZAGADNIENIE
//FUNKCJE CZUSTO WIRTUALNE
//nazwal bym to interfacem
class abstractCell {

public:
    virtual bool isFloorCell() = 0;
    virtual bool isLifeCell() = 0;
    virtual bool isObstacleCell()=0;
    virtual bool isDeathCell()=0;
    virtual void setAsLifeCell()= 0;
    virtual void setAsObstacleCell() = 0;
    virtual void setAsDeathCell() = 0;
    virtual void setAsFloorCell()=0;
    virtual void changePointsForLifeForm(int val)= 0;
    virtual void ChangePointsForDeath(int val)= 0;
    virtual std::pair<int,int> getChanceForLife()= 0;
    virtual bool random_life_event()= 0;
    virtual bool random_death_event()= 0;
    virtual void cycle()= 0;
    enum unitTypes{floor,life,death,obstacle};
protected:
    int type;
    bool lifeCell;
    bool deathCell;
    bool obstacleCell;
    bool floorCell;
    int pointsForDie;
    int pointsForLife;
    int maxPoints;
    unsigned cycles;

};



#endif //GAME_ABSTRACTCELL_H
