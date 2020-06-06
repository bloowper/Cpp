//
// Created by tomek on 06.06.2020.
//

#include "cell.h"


cell::cell(std::pair<int, int> cord, float size)
        :sf::RectangleShape{sf::Vector2f{size,size}},active{false}
{
    sf::RectangleShape::setOutlineThickness(1);
    sf::RectangleShape::setOutlineColor(sf::Color{116,0,35});
    sf::RectangleShape::setPosition(cord.first*size,cord.second*size);
    setInactive();
}

void cell::setActive(void)
{
    active = true;
    sf::RectangleShape::setFillColor(sf::Color{215,0,68,255});
}

void cell::setInactive(void)
{
    active = false;
    sf::RectangleShape::setFillColor(sf::Color{255,209,224});
}

bool cell::isActive()
{
    return active;
}

