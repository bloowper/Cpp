//
// Created by tomek on 06.06.2020.
//

//
// Created by tomek on 06.06.2020.
//


#ifndef GAME_CELL_H
#define GAME_CELL_H
#include <SFML/Graphics/RectangleShape.hpp>

class cell : public  sf::RectangleShape
{

private:
    bool active;
public:
    cell(std::pair<int, int> cord, float size);
    void setActive(void);
    void setInactive(void);
    bool isActive();
};







#endif //GAME_CELL_H
