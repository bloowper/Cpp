//
// Created by tomek on 28.04.2020.
//

#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics.hpp> // field ‘m_mushroomTexture’ has incomplete type ‘sf::Texture’
//     sf::Texture m_mushroomTexture; bez zalaczenia nie bedzie dzialac
//#include <SFML/Window.hpp>
#include "Window.h"
#include <memory>
#include <vector>
#include "cell.h"
//#include <>

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
//
    Window m_window;
    sf::Clock m_clock;
    sf::Time m_elapsed;

    //tutaj sobie stworze swoje obiekty
    int n_of_blocks;
    float size_of_block;
    std::map<std::pair<int,int>,std::shared_ptr<cell>> blockmap;
};



template<typename TK, typename TV>
std::vector<TV> extract_values(std::map<TK, TV> const& input_map);

template<typename TK, typename TV>
std::vector<TK> extract_keys(std::map<TK, TV> const& input_map);



#endif //GAME_GAME_H
