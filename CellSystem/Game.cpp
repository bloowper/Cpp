//
// Created by tomek on 28.04.2020.
//

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <boost/random.hpp>
#include "Game.h"
#include "Game.h"
#include <algorithm>
#include "myVector.h"
#include "ObiektFunkcyjnyOtoczenia.h"



//TO DO
//1 poprawic kontenery typu vector zeby mialy wstepny rozmiar przystajacy do maksymalnego w trakcie uzywania.
//zeby pozbyc sie przelokowywania pamieci i troche dzieki temu to zoptymalizowac.




Game::Game(): m_window("simple psedu cell simulation", sf::Vector2u(2000,2000)){
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

    //utworzenie szkielka zegarowego i zywej komorki
    std::pair<int,int> poczatkowa{n_of_blocks/2,n_of_blocks/2};
    blockmap[poczatkowa]->setAsLifeCell();

    ObiektFunkcyjnyOtoczenia promien15{15};
    obiektFunkcyjnyOtoczeniaV2 promien15v2{15};
    obiektFunkcyjnyOtoczeniaV2 promien20v2{20};



    myVector<std::pair<int,int>> neighborhoodv2 = promien20v2(poczatkowa);

    for(auto c:neighborhoodv2)
        if(c!=poczatkowa )blockmap[c]->setAsObstacleCell();

    const std::vector<std::pair<int, int>> &neighborhood1 = promien15(poczatkowa);
    for(auto c:neighborhood1)
        if(c!=poczatkowa)blockmap[c]->setAsFloorCell();

    for(auto c:neighborhoodv2)
    {
        if(c.first==n_of_blocks/2 && c.second>n_of_blocks/2)
        {
            blockmap[c]->setAsFloorCell();
            blockmap[std::make_pair(c.first+1,c.second)]->setAsFloorCell();
        }
    }

    ObiektFunkcyjnyOtoczenia promien3{10};
    std::vector<std::pair<int, int>> test = promien3(std::make_pair(2, 2));
    for(auto &obj:test)
    {
        try{
            this->blockmap.at(obj)->setAsObstacleCell();
        }
        catch (std::out_of_range){
            continue;
        }

    }


    //ZAGADNIENIE
    //petla for_each + funkcja lambda
    //obiekt funkcyjny z przeciazonym operatorem ()
    //wlasny wektor z konstruktorami obslugujacymi heap memory
    //+obsluga wskaznikow we wlasnym kontenerze *begin *end
    //wyrazenie lambda
    obiektFunkcyjnyOtoczeniaV2 promien8{8};
    myVector<std::pair<int,int>>  otoczeniePromien8BrzegMapy = promien8(std::make_pair(10, 10));
    try {
        std::for_each(otoczeniePromien8BrzegMapy.begin(), otoczeniePromien8BrzegMapy.end(),
                      [&](std::pair<int, int> cord) { blockmap[cord]->setAsObstacleCell(); });
    }
    catch (std::out_of_range &exception)
    {

    }



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
            int zasieg=3;
            const std::vector<std::pair<int, int>> &neighborhood = returnNeighborhood(key, zasieg);
            for(auto keyN:neighborhood)
            {
                const std::vector<std::pair<int, int>>::const_iterator &iterator = std::find(extractKeys.begin(),
                                                                                             extractKeys.end(), keyN);
                if(iterator!=extractKeys.end() && blockmap[keyN]->isFloorCell()== true)
                {
                    int min=0,max=2;
                    blockmap[keyN]->changePointsForLifeForm(randomInBaund(min,max));

                }
            }

            int minimalna_liczba_cykli = 30;
            int minD=0,maxD=10;
            if(blockmap[key]->nOfCycle()>minimalna_liczba_cykli)
            {
                blockmap[key]->ChangePointsForDeath(randomInBaund(minD,maxD));
            }
            if(blockmap[key]->nOfCycle()>minimalna_liczba_cykli+10)
            {
                blockmap[key]->ChangePointsForDeath(randomInBaund(minD,maxD));
            }
            blockmap[key]->cycle();
        }
        else if(blockmap[key]->isDeathCell())
        {
            int zasieg = 2;
            const std::vector<std::pair<int, int>> &neighborhood = returnNeighborhood(key, zasieg);
            for(auto keyN:neighborhood)
            {
                //ZAGADNIENIE
                //STL algorytmy
                const std::vector<std::pair<int, int>>::const_iterator &iterator = std::find(extractKeys.begin(),
                                                                                             extractKeys.end(), keyN);
                if(iterator!=extractKeys.end())
                {
                    int min=5,max=10;
                    if(blockmap[keyN]->isLifeCell())
                    blockmap[keyN]->ChangePointsForDeath(randomInBaund(min,max));
                }
            }
        }
        else if(blockmap[key]->isObstacleCell())
        {

        }



    }

    //dokonywanie zdarzen
    for(auto key:extractKeys)
    {

        //
        if(blockmap[key]->random_life_event()==true && blockmap[key]->isFloorCell()==true)
        {
            blockmap[key]->setAsLifeCell();
        }


        if(blockmap[key]->random_death_event()==true && blockmap[key]->isLifeCell()==true )
        {
            blockmap[key]->setAsDeathCell();
        }
    }


    //zbieranie statystyk

    int calkowita_liczba =blockmap.size();
    int liczba_zywych =0;
    int liczba_martwych=0;
    auto zliczanie = [&liczba_zywych,&liczba_martwych,this](std::pair<int,int> cord){
        if(blockmap[cord]->isLifeCell())
            liczba_zywych++;
        if(blockmap[cord]->isDeathCell())
            liczba_martwych++;
    };
    //ZAGADNIENIE STL ALGORYTMY + FUNKCJA LAMBDA
    std::for_each(extractKeys.begin(),extractKeys.end(),zliczanie);
    printf("|N %d|\t|zywe %d|\t|martwe %d|\n",calkowita_liczba,liczba_zywych,liczba_martwych);




}

void Game::Render(){
    m_window.BeginDraw(); // Clear.
    for(int i=0;i<n_of_blocks;i++)
    {
        for(int j=0;j<n_of_blocks;j++)
        {
            //ZAGADNIENIE
            //POLIMORFIZM
            m_window.Draw(*blockmap[std::pair<int,int>{i,j}]);
        }
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