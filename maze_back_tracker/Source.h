#pragma once
#include "cell.h"

#include <vector>
using namespace std;

void print_maze(int size, cell** maze);
int random(int min, int max);
bool check_for_any_unvisited_neighbors(cell** maze, pair<int, int> wsp);
cell& return_cell(cell** maze,pair<int, int>& wsp);
pair<int, int> zwroc_pair_dla_sasiada(int kierunek, pair<int, int> para);
void print_maze_path(int size, cell** maze);
bool check_for_any_connected_unvisited_neighbors(cell** maze, pair<int, int> wsp);