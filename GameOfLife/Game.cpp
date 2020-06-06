//
// Created by tomek on 28.04.2020.
//

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <boost/random.hpp>
#include "Game.h"
#include "Game.h"
#include <algorithm>
using namespace std;


Game::Game(): m_window("simple psedu cell simulation", sf::Vector2u(2000,2000)){
    RestartClock();
    srand(time(NULL));

    nOfBlock = 300;
    sizeOFBlock = (float)m_window.GetWindowSize().x/(float)nOfBlock;
    Game::cordvector.resize(nOfBlock*nOfBlock);

    for(int i=0; i<nOfBlock;i++)
        for(int j=0;j<nOfBlock;j++)
        {
            std::pair<int,int> cord{i,j};
            std::shared_ptr<cell> ptr{ new cell{cord,sizeOFBlock}};
            blockmap[cord]=ptr;
            cordvector.push_back(cord);
        }


        blockmap[make_pair(30, 30)]->setActive();
        blockmap[make_pair(30, 29)]->setActive();
        blockmap[make_pair(29, 29)]->setActive();
        blockmap[make_pair(31, 29)]->setActive();
        blockmap[make_pair(31, 28)]->setActive();
        blockmap[make_pair(29, 28)]->setActive();
        blockmap[make_pair(30, 27)]->setActive();

        blockmap[make_pair(50, 50)]->setActive();
        blockmap[make_pair(50, 51)]->setActive();
        blockmap[make_pair(50, 52)]->setActive();


}

Game::~Game(){ }

sf::Time Game::GetElapsed(){ return m_elapsed; }
void Game::RestartClock(){ m_elapsed = m_clock.restart(); }
Window* Game::GetWindow(){ return &m_window; }

void Game::HandleInput(){
    // Input handling.

}

void Game::Update() {
    m_window.Update();
    sf::Event event;

    sf::Time elapsed = GetElapsed();
    sf::Time timeframe = sf::milliseconds(1000);
    if(timeframe>elapsed)
    {
        sf::sleep(timeframe-elapsed);
    }
    
    vector<pair<int,int>> actualActiveCells{};
    vector<pair<int,int>> actualInactive{};
    vector<pair<int,int>> cellsToActive{};
    vector<pair<int,int>> cellToInactive{};
    for(auto cell:blockmap)
    {
        if(cell.second->isActive())
            actualActiveCells.push_back(cell.first);
        else
            actualInactive.push_back(cell.first);
    }



    auto NeighbourVector = [=](pair<int,int> cord){
        vector<pair<int,int>> neigh;
        int x=cord.first,
            y=cord.second;
        auto isinbaund = [=](int x,int y){
            if(!(x<0 || y<0 || x>Game::nOfBlock-1 || y>Game::nOfBlock-1))
                return true;
            return false;};
        if(isinbaund(x-1,y-1)) neigh.push_back(pair<int,int>{x-1,y-1});
        if(isinbaund(x,y-1)) neigh.push_back(pair<int,int>{x,y-1});
        if(isinbaund(x+1,y-1)) neigh.push_back(pair<int,int>{x+1,y-1});
        if(isinbaund(x-1,y)) neigh.push_back(pair<int,int>{x-1,y});
        if(isinbaund(x+1,y)) neigh.push_back(pair<int,int>{x+1,y});
        if(isinbaund(x-1,y-1)) neigh.push_back(pair<int,int>{x-1,y-1});
        if(isinbaund(x,y+1)) neigh.push_back(pair<int,int>{x,y+1});
        if(isinbaund(x+1,y+1)) neigh.push_back(pair<int,int>{x+1,y+1});

        return neigh;
    };

    for(auto cord:actualActiveCells)
    {
        int nOfLiveNeighbour=0;
        vector<pair<int,int>> neighvect = NeighbourVector(cord);
        for(auto cofn:neighvect)
            if(blockmap[cofn]->isActive()) nOfLiveNeighbour++;
        if(nOfLiveNeighbour <= 1) cellToInactive.push_back(cord);
        else if(nOfLiveNeighbour == 2);
        else if(nOfLiveNeighbour == 3);
        else if(nOfLiveNeighbour == 4) cellToInactive.push_back(cord);
    }

    for(auto cord:actualInactive)
    {
        int nOfLiveNeighbour=0;
        vector<pair<int,int>> neighvector = NeighbourVector(cord);
        for(auto cofn:neighvector)
            if(blockmap[cofn]->isActive()) nOfLiveNeighbour++;
        if(nOfLiveNeighbour==3)
            cellsToActive.push_back(cord);
//        if(nOfLiveNeighbour==2)
//            cellsToActive.push_back(cord);
    }

    for(auto cord:cellsToActive)
        blockmap[cord]->setActive();
    for(auto cord:cellToInactive)
        blockmap[cord]->setInactive();




}

void Game::Render(){
    m_window.BeginDraw(); // Clear.

    for(auto pair:blockmap)
    {
        m_window.Draw(*pair.second);
    }

    m_window.EndDraw(); // Display.
}


//ZAGADNIENIE
//template
template<typename TK, typename TV>
std::vector<TK> extract_keys(std::map<TK, TV> const& input_map) {
    std::vector<TK> retval;
    for (auto const& element : input_map) {
        retval.push_back(element.first);
    }
    return retval;
}

template<typename TK, typename TV>
std::vector<TV> extract_values(std::map<TK, TV> const& input_map) {
    std::vector<TV> retval;
    for (auto const& element : input_map) {
        retval.push_back(element.second);
    }
    return retval;
}