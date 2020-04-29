//
// Created by tomek on 28.04.2020.
//

#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H


#include <SFML/System.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Window{
public:
    Window();
    Window(const std::string& title, const sf::Vector2u& size);
    ~Window();

    void BeginDraw();
    void EndDraw();

    void Update();

    bool IsDone();
    bool IsFullscreen();
    sf::Vector2u GetWindowSize();

    void ToggleFullscreen();

    void Draw(sf::Drawable& l_drawable);
private:
    void Setup(const std::string title, const sf::Vector2u& size);
    void Create();
    void Destroy();

    sf::RenderWindow m_window;
    sf::Vector2u m_windowSize;
    std::string m_windowTitle;
    bool m_isDone;
    bool m_isFullscreen;
};


#endif //GAME_WINDOW_H
