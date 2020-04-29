//
// Created by tomek on 28.04.2020.
//

#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics.hpp> // field ‘m_mushroomTexture’ has incomplete type ‘sf::Texture’
//     sf::Texture m_mushroomTexture; bez zalaczenia nie bedzie dzialac
//#include <SFML/Window.hpp>
#include "../Window.h"


class Game{
public:
    Game();
    ~Game();

    void HandleInput();
    void Update();
    void Render();

    Window* GetWindow();

    sf::Time GetElapsed();
    void RestartClock();
private:
    void MoveMushroom();

    Window m_window;
    sf::Clock m_clock;
    sf::Time m_elapsed;

    sf::Texture m_mushroomTexture;
    sf::Sprite m_mushroom;
    sf::Vector2i m_increment;
};


#endif //GAME_GAME_H
