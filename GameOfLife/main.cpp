//
// Created by tomek on 28.04.2020.
//

#include "main.h"

#include "Game.h"


int main(int argc, char* argv[]){
// Program entry point.
    Game game; // Creating our game object.
    while(!game.GetWindow()->IsDone()){
        game.HandleInput();
        game.Update();
        game.Render();
        game.RestartClock();
    }
}