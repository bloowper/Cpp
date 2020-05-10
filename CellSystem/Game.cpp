//
// Created by tomek on 28.04.2020.
//

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <boost/random.hpp>
#include "Game.h"
#include "Game.h"
#include <algorithm>




Game::Game(): m_window("game of live ver bieda edition", sf::Vector2u(2000,2000)){
    RestartClock();
    srand(time(NULL));

    //setting blocks
     n_of_blocks =100;
     size_of_block = m_window.GetWindowSize().x/n_of_blocks;

    for(int i=0;i<n_of_blocks;i++)
    {
        for(int j=0;j<n_of_blocks;j++)
        {
            std::shared_ptr<cell> rectangleSharedPtr{new cell};
            rectangleSharedPtr->setSize(sf::Vector2f{size_of_block,size_of_block});
            rectangleSharedPtr->setPosition(sf::Vector2f{i*size_of_block,j*size_of_block});
            rectangleSharedPtr->setAsFloorCell();
            blockmap[std::make_pair(i,j)] = rectangleSharedPtr;

        }
    }

    blockmap[std::make_pair(n_of_blocks / 2, n_of_blocks / 2)]->setAsLifeCell();
    blockmap[std::make_pair(30,30)]->setAsObstacleCell();


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

    const std::vector<std::pair<int, int>> &extractKeys = extract_keys(blockmap);
    //aktualizacja prawdopodobienstwa
    for(auto pKey=extractKeys.begin();pKey!=extractKeys.end();pKey++)
    {
        std::pair<int, int>  key= *pKey;

        if(blockmap[key]->isLifeCell())
        {
            int zasieg=4;
            const std::vector<std::pair<int, int>> &neighborhood = returnNeighborhood(key, zasieg);
            for(auto keyN:neighborhood)
            {
                const std::vector<std::pair<int, int>>::const_iterator &iterator = std::find(extractKeys.begin(),
                                                                                             extractKeys.end(), keyN);
                if(iterator!=extractKeys.end())
                {
                    int min=0,max=2;
                    blockmap[keyN]->changePointsForLifeForm(randomInBaund(min,max));
                    
                }
            }

            int minimalna_liczba_cykli = 20;
            int minD=0,maxD=4;
            if(blockmap[key]->nOfCycle()>minimalna_liczba_cykli)
            {
                blockmap[key]->ChangePointsForDeath(randomInBaund(minD,maxD));
            }

            blockmap[key]->cycle();
        }

        if(blockmap[key]->isDeathCell())
        {
            int zasieg = 3;
            const std::vector<std::pair<int, int>> &neighborhood = returnNeighborhood(key, zasieg);
            for(auto keyN:neighborhood)
            {
                const std::vector<std::pair<int, int>>::const_iterator &iterator = std::find(extractKeys.begin(),
                                                                                             extractKeys.end(), keyN);
                if(iterator!=extractKeys.end())
                {
                    int min=1,max=3;
                    if(blockmap[keyN]->isLifeCell())
                    blockmap[keyN]->ChangePointsForDeath(randomInBaund(min,max));
                }
            }
        }


    }

    //dokonywanie zdarzen
    for(auto key:extractKeys)
    {

        if(blockmap[key]->random_life_event()==true && blockmap[key]->isFloorCell()==true)
        {
            blockmap[key]->setAsLifeCell();
        }


        if(blockmap[key]->random_death_event()==true && blockmap[key]->isLifeCell()==true)
        {
            blockmap[key]->setAsDeathCell();
        }
    }

}

void Game::Render(){
    m_window.BeginDraw(); // Clear.
    for(int i=0;i<n_of_blocks;i++)
    {
        for(int j=0;j<n_of_blocks;j++)
        {
            m_window.Draw(*blockmap[std::pair<int,int>{i,j}]);
        }
    }

    m_window.EndDraw(); // Display.
}



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