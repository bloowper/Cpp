#include "cell.h"
#include "Source.h"
#include <iostream>
#include <stack>
#include <utility> 
#include <time.h>
#include <vector>
/*
Tomasz Orchowski
u¿ywana jest funkcja powi¹zana z systemem windows
System("cls");

pasowa³o by poprawiæ klasê cell bo na pocz¹tku chcia³em zachowaæ kapsulizacjê danych 
potem z niej zrezygnowa³em, st¹d ten ba³agan
*/
using namespace std;
int GLOBAL_SIZE = 10;

enum SASIAD
{
	LEWO = 0,
	PRAWO =1,
	GORA =2,
	DOL = 3,
};





int main()
{

	getchar();
	cell** maze = new cell * [GLOBAL_SIZE];
	for (int i = 0; i < GLOBAL_SIZE; i++)
	{
		maze[i] = new cell[GLOBAL_SIZE];
	}

	for (int w = 0; w < GLOBAL_SIZE; w++)
	{
		for (int k = 0; k < GLOBAL_SIZE; k++)
		{
			maze[w][k] = cell(w, k);
		}
	}
	print_maze(GLOBAL_SIZE, maze);

	pair<int, int> startowy{ 0,0 };
	pair<int, int> koncowy{ GLOBAL_SIZE - 1,GLOBAL_SIZE - 1 };
	maze[startowy.first][startowy.second].is_start = true;
	maze[koncowy.first][koncowy.second].is_end = true;

	int NumberOfAllCells = GLOBAL_SIZE * GLOBAL_SIZE;
	int ActualNumberOfCells = 0;
	stack< pair<int, int>> STACK;
	STACK.push(make_pair(0, 0));
	ActualNumberOfCells++;

	cell *Current = &maze[startowy.first][startowy.second];
	pair<int, int> wsp = startowy;

	//tworzenie labiryntu nad tablica
	while (true)
	{
		Current->set_as_visited();
		if (check_for_any_unvisited_neighbors(maze,wsp)==false)
		{
			STACK.pop();
			wsp = STACK.top();
			Current = &maze[wsp.first][wsp.second];
			continue;
		}


		
			int losowy_kierunek = random(LEWO, DOL);
			if(losowy_kierunek==LEWO)
			{
				pair<int, int> lewy = zwroc_pair_dla_sasiada(LEWO, wsp);
				if (lewy.first == -1 || lewy.second==-1) continue;//zabezpieczenie zeby nie wylosowac wsp po za tablica
				cell& potencjalnie_nastepna_komorka = maze[lewy.first][lewy.second];
				if (potencjalnie_nastepna_komorka.get_was_visited() == false)
				{
					Current->set_left(potencjalnie_nastepna_komorka);
					potencjalnie_nastepna_komorka.set_right(*Current);
					//automatycznie lewa laczy z prawa a prawa z lewa
					potencjalnie_nastepna_komorka.set_as_visited();
					Current = &potencjalnie_nastepna_komorka;
					STACK.push(lewy);
					ActualNumberOfCells++;
					wsp = STACK.top();
				}
				else continue;

			}

			else if(losowy_kierunek == PRAWO)
			{
				pair<int, int> prawy = zwroc_pair_dla_sasiada(PRAWO, wsp);
				if (prawy.first == -1 || prawy.second== -1) continue;
				cell& potencjalnie_nastepna_komorka = return_cell(maze,prawy);
				if (potencjalnie_nastepna_komorka.get_was_visited() == false)
				{
					Current->set_right(potencjalnie_nastepna_komorka);
					potencjalnie_nastepna_komorka.set_left(*Current);
					potencjalnie_nastepna_komorka.set_as_visited();
					Current = &potencjalnie_nastepna_komorka;
					STACK.push(prawy);
					ActualNumberOfCells++;
					wsp = STACK.top();
				}
				else continue;

			}
			else if(losowy_kierunek == GORA)
			{
				pair<int, int> gora = zwroc_pair_dla_sasiada(GORA, wsp);
				if (gora.first == -1 || gora.second==-1) continue;
				cell& potencjalnie_nastepna_komorka = return_cell(maze, gora);
				if (potencjalnie_nastepna_komorka.get_was_visited() == false)
				{
					Current->set_top(potencjalnie_nastepna_komorka);
					potencjalnie_nastepna_komorka.set_bottom(*Current);
					potencjalnie_nastepna_komorka.set_as_visited();
					Current = &potencjalnie_nastepna_komorka;
					STACK.push(gora);
					ActualNumberOfCells++;
					wsp = STACK.top();
				}
				else continue;
				
			}
			else if(losowy_kierunek == DOL)
			{
				pair<int, int> dol = zwroc_pair_dla_sasiada(DOL, wsp);
				if (dol.first == -1 || dol.second==-1) continue;
				cell& potencjalnie_nastepna_komorka = return_cell(maze, dol);
				if (potencjalnie_nastepna_komorka.get_was_visited()==false)
				{
					Current->set_bottom(potencjalnie_nastepna_komorka);
					potencjalnie_nastepna_komorka.set_top(*Current);
					potencjalnie_nastepna_komorka.set_as_visited();
					Current = &potencjalnie_nastepna_komorka;
					STACK.push(dol);
					ActualNumberOfCells++;
					wsp = STACK.top();
				}
				else continue;
			}

			system("cls");
			print_maze(GLOBAL_SIZE, maze);

			if (ActualNumberOfCells == GLOBAL_SIZE * GLOBAL_SIZE) break;
	}
	
//LABIRYNT*********************************
//PRZECHODZENIE****************************

	cout << "Teraz przechodzenie";
	getchar();
	system("cls");
	maze[GLOBAL_SIZE - 1][GLOBAL_SIZE - 1].is_end = true;
	for (int w = 0; w < GLOBAL_SIZE; w++)
	{
		for (int k = 0; k < GLOBAL_SIZE; k++)
		{
			maze[w][k].visited = false;
		}
	}

	stack < pair<int, int>> Stack;
	Stack.push(make_pair(0, 0));
	maze[0][0].isPath = true;
	pair<int, int> cord{ Stack.top() };
	cell* aktualna = &maze[cord.first][cord.second];

	while (aktualna->is_end==false)
	{

		if (check_for_any_connected_unvisited_neighbors(maze,cord)==false)
		{
			aktualna->isPath = false;
			Stack.pop();
			cord = Stack.top();
			aktualna = &maze[cord.first][cord.second];
		}

		int kierunek = random(0, 3);
		pair<int, int> lewo = zwroc_pair_dla_sasiada(LEWO, cord);
		pair<int, int> prawo = zwroc_pair_dla_sasiada(PRAWO, cord);
		pair<int, int> gora = zwroc_pair_dla_sasiada(GORA, cord);
		pair<int, int> dol = zwroc_pair_dla_sasiada(DOL, cord);

		if(kierunek == LEWO)
		{ 
			if (lewo.first == -1 || lewo.second == -1)
				continue;
			if (maze[cord.first][cord.second].left!=nullptr &&
				maze[lewo.first][lewo.second].visited == false)
			{
				cord = lewo;
				Stack.push(cord);
				aktualna = &maze[cord.first][cord.second];
				aktualna->visited = true;
				aktualna->isPath = true;
			}
			else continue;
		}
		else if(kierunek == PRAWO)
		{ 
			if (prawo.first == -1 || prawo.second == -1)
				continue;
			if (maze[cord.first][cord.second].right != nullptr &&
				maze[prawo.first][prawo.second].visited == false)
			{
				cord = prawo;
				Stack.push(cord);
				aktualna = &maze[cord.first][cord.second];
				aktualna->visited = true;
				aktualna->isPath = true;
			}
			else continue;
		}
		else if(kierunek == GORA)
		{
			if (gora.first == -1 || gora.second == -1)
				continue;
			if (maze[cord.first][cord.second].top != nullptr &&
				maze[gora.first][gora.second].visited == false)
			{
				cord = gora;
				Stack.push(cord);
				aktualna = &maze[cord.first][cord.second];
				aktualna->visited = true;
				aktualna->isPath = true;
			}
			else continue;
		}	
		else if (kierunek == DOL)
		{
			if (dol.first == -1 || dol.second == -1)
				continue;
			if (maze[cord.first][cord.second].bottom != nullptr &&
				maze[dol.first][dol.second].visited == false)
			{
				cord = dol;
				Stack.push(cord);
				aktualna = &maze[cord.first][cord.second];
				aktualna->visited = true;
				aktualna->isPath = true;
			}
			else continue;
		}

		system("cls");
		print_maze_path(GLOBAL_SIZE, maze);
	}


	




}


int random(int min, int max) //range : [min, max)
{
	static bool first = true;
	if (first)
	{
		srand(time(NULL)); //seeding for the first time only!
		first = false;
	}

	return min + rand() % ((max + 1) - min);


}

bool check_for_any_unvisited_neighbors(cell** maze, pair<int,int> wsp)
{//return true jezeli zostal jakis sasiad
	
	pair<int, int> lewo = zwroc_pair_dla_sasiada(LEWO,wsp);
	pair<int, int> prawo = zwroc_pair_dla_sasiada(PRAWO, wsp);
	pair<int, int> gora = zwroc_pair_dla_sasiada(GORA, wsp);
	pair<int, int> dol = zwroc_pair_dla_sasiada(DOL, wsp);

	if (lewo.first != -1 && lewo.second !=-1)
	{
		if (return_cell(maze, lewo).visited == false)
			return true;
	}
	if (prawo.first != -1 && prawo.second!=-1)
	{
		if (return_cell(maze, prawo).visited == false)
			return true;
	}
	if (gora.first != -1 && gora.second!=-1)
	{
		if (return_cell(maze, gora).visited == false)
			return true;
	}
	if (dol.first != -1 && dol.second!=-1)
	{ 
		if (return_cell(maze, dol).visited==false)
			return true;
	}

	return false;
}

bool check_for_any_connected_unvisited_neighbors(cell** maze, pair<int, int> wsp)
{//return true jezeli zostal jakis sasiad

	pair<int, int> lewo = zwroc_pair_dla_sasiada(LEWO, wsp);
	pair<int, int> prawo = zwroc_pair_dla_sasiada(PRAWO, wsp);
	pair<int, int> gora = zwroc_pair_dla_sasiada(GORA, wsp);
	pair<int, int> dol = zwroc_pair_dla_sasiada(DOL, wsp);

	if (lewo.first != -1 && lewo.second != -1)
	{
		if (return_cell(maze, lewo).visited == false && return_cell(maze,wsp).is_left_available()==true)
			return true;
	}
	if (prawo.first != -1 && prawo.second != -1 && return_cell(maze,wsp).is_right_available()==true)
	{
		if (return_cell(maze, prawo).visited == false)
			return true;
	}
	if (gora.first != -1 && gora.second != -1 && return_cell(maze,wsp).is_top_available()==true)
	{
		if (return_cell(maze, gora).visited == false )
			return true;
	}
	if (dol.first != -1 && dol.second != -1 && return_cell(maze, wsp).is_bottom_available()==true)
	{
		if (return_cell(maze, dol).visited == false)
			return true;
	}

	return false;
}

pair<int, int> zwroc_pair_dla_sasiada(int kierunek, pair<int, int> para)
{	//jezeli jakis zakres mial by przekroczyc GLOBAL_SIZE
	//to zostanie zwrocona para -1 -1
	pair<int, int> do_zwrocenia;
	if(kierunek==LEWO)
	{
		do_zwrocenia = make_pair(para.first,para.second-1);
	}
	else if(kierunek == PRAWO)
	{
		do_zwrocenia = make_pair(para.first, para.second+1);
	}
	else if(kierunek == GORA)
	{
		do_zwrocenia = make_pair(para.first-1, para.second);
	}
	else if (kierunek == DOL)
	{
		do_zwrocenia = make_pair(para.first+1, para.second);
	}

	if (do_zwrocenia.first >= GLOBAL_SIZE || do_zwrocenia.second >= GLOBAL_SIZE || do_zwrocenia.first<0 || do_zwrocenia.second<0)
		return make_pair(-1, -1);
	
	else
		return do_zwrocenia;
}

cell& return_cell(cell** maze, pair<int, int>& wsp)
{
	return maze[wsp.first][wsp.second];
}

void print_maze(int size, cell** maze)
{

	for (int w = 0; w < size; w++)
	{
		string linia1{""};
		string linia2{""};
		string linia3{""};
		for (int k = 0; k < size; k++)
		{

			//linia1
			linia1 += "#";
			if (maze[w][k].istop == true)
				linia1 += " ";
			else
				linia1 += "#";
			linia1 += "#";

			//linia2
			if (maze[w][k].isleft == true)
				linia2 += " ";
			else
				linia2 += "#";
			
			linia2 += " ";

			if (maze[w][k].isright == true)
				linia2 += " ";
			else
				linia2 += "#";

			//linia3
			linia3 += "#";

			if (maze[w][k].isbottom == true)
				linia3 += " ";
			else
				linia3 += "#";
			linia3 += "#";

		}
		cout << linia1 << endl;
		cout << linia2 << endl;
		cout << linia3 << endl;
		linia1.clear();
		linia2.clear();
		linia3.clear();

	}

}

void print_maze_path(int size, cell** maze)
{

	for (int w = 0; w < size; w++)
	{
		string linia1{ "" };
		string linia2{ "" };
		string linia3{ "" };
		for (int k = 0; k < size; k++)
		{
			pair<int, int>	cord{ w,k };
			pair<int, int>	lewo	=	zwroc_pair_dla_sasiada(LEWO,cord);
			pair<int, int>	prawo	=	zwroc_pair_dla_sasiada(PRAWO, cord);
			pair<int, int>	gora	=	zwroc_pair_dla_sasiada(GORA, cord);
			pair<int, int>	dol		=	zwroc_pair_dla_sasiada(DOL, cord);

			//linia1
			linia1 += "#";
			
			if (maze[w][k].top != nullptr)
			{
				if (maze[w][k].isPath && maze[gora.first][gora.second].isPath)
					linia1 += ".";
				else
					linia1 += " ";
			}
			else
			{
				linia1 += "#";
			}
			linia1 += "#";
			//linia 2
			if(maze[w][k].left!=nullptr)
			{ 
				if (maze[w][k].isPath == true && maze[lewo.first][lewo.second].isPath == true)
				{
					linia2 += ".";
				}
				else
				{
					linia2 += " ";
				}
			}
			else
			{
				linia2 += "#";
			}

			/*
			000
			0X0
			000
			*/
			if (maze[w][k].isPath)
			{
				linia2 += ".";
			}
			else
			{
				linia2 += " ";
			}


			if (maze[w][k].right != nullptr)
			{
				if (maze[w][k].isPath && maze[prawo.first][prawo.second].isPath)
				{
					linia2 += ".";
				}
				else
				{
					linia2 += " ";
				}
			}
			else
			{
				linia2 += "#";
			}
			//linia3

			linia3 += "#";
			if (maze[w][k].bottom != nullptr)
			{
				if (maze[w][k].isPath && maze[dol.first][dol.second].isPath)
					linia3 += ".";
				else
					linia3 += " ";
			}
			else
			{
				linia3 += "#";
			}
			linia3 += "#";
		}
		cout << linia1 << endl;
		cout << linia2 << endl;
		cout << linia3 << endl;


	}

}


/*void print_maze_path(int size, cell** maze)
{

	for (int w = 0; w < size; w++)
	{
		string linia1{ "" };
		string linia2{ "" };
		string linia3{ "" };
		for (int k = 0; k < size; k++)
		{
			pair<int, int>	cord{ w,k };
			pair<int, int>	lewo = zwroc_pair_dla_sasiada(LEWO, cord);
			pair<int, int>	prawo = zwroc_pair_dla_sasiada(PRAWO, cord);
			pair<int, int>	gora = zwroc_pair_dla_sasiada(GORA, cord);
			pair<int, int>	dol = zwroc_pair_dla_sasiada(DOL, cord);

			//linia1
			linia1 += "#";
			if (maze[w][k].istop == true)
				linia1 += " ";
			else
				linia1 += "#";
			linia1 += "#";

			//linia2
			if (maze[w][k].isleft == true)
				linia2 += " ";
			else
				linia2 += "#";

			if (maze[w][k].isPath == true)
				linia2 += "o";
			else
				linia2 += " ";

			if (maze[w][k].isright == true)
				linia2 += " ";
			else
				linia2 += "#";

			//linia3
			linia3 += "#";

			if (maze[w][k].isbottom == true)
				linia3 += " ";
			else
				linia3 += "#";
			linia3 += "#";

		}
		cout << linia1 << endl;
		cout << linia2 << endl;
		cout << linia3 << endl;


	}

}*/
