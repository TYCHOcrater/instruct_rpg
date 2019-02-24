#include <iostream>
#include <string>
#include <list>
#include <ctime>
#include <cstdlib>
#include <iterator>

#include "../include/Grid.h"

#define RST  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define FRED(x) KRED x RST
#define FGRN(x) KGRN x RST
#define FYEL(x) KYEL x RST
#define FBLU(x) KBLU x RST
#define FMAG(x) KMAG x RST
#define FCYN(x) KCYN x RST
#define FWHT(x) KWHT x RST

#define BOLD(x) "\x1B[1m" x RST
#define UNDL(x) "\x1B[4m" x RST

using namespace std;

Grid::Grid(Market *M) {
	Map = new int*[LENGTH];
	for (int i = 0; i < LENGTH; ++i)
	{
		Map[i] = new int[WIDTH];

		for (int i = 0; i < LENGTH; ++i)
		{
			for (int j = 0; j < WIDTH; ++j)
			{
				int possibility = rand()%100+1;
				if (possibility<=20)
				{
					if ((i>0)&&(j>0) && ((Map[i-1][j-1]==2) || (Map[i-1][j+1]) || (Map[i-1][j+1]==2)))
						Map[i][j] = 0;
					else
						Map[i][j] = 2;
				}
				else if(possibility<=50)
					Map[i][j] = 1;
				else
					Map[i][j] = 0;

				if(((i==0) && (j==1)) || ((i==1) && (j==0)))
					Map[i][j] = 1;
			}
			Map[0][0] = 0;
		}

		this->location = 0;
		this->last_location = 0;
		this->play = 0;
		this->myMarket = M;
	}

	void Grid::move() {
		string dest;
		cout << "Time for our next destination! Choose your move: ";
		cin >> dest;
		if ((dest == "W") || (dest == "w"))
		{
			if(move_forward()!=-1)
				show_location();
			else {
				cout << "You cannot enter the realm of the lost souls for whomever joins the dead never sees light again." << endl;
				location = last_location;
				replay_move();
			}
		}
		else if((dest == "S") || (dest == "s")){
			if(move_backwards()!=-1)
				show_location();
			else{
				cout << "You cannot enter the realm of the lost souls for whomever joins the dead never sees light again." << endl;
				location = last_location;
				replay_move();
			}
		}
		else if((dest == "A") || (dest == "a")){
			if(move_right()!=-1)
				show_location();
			else{
				cout << "You cannot enter the realm of the lost souls for whomever joins the dead never sees light again." << endl;
				location = last_location;
				replay_move();
			}
		}
		else if((dest == "D") || (dest == "d")){
			if(move_left()!=-1)
				show_location();
			else {
				cout << "You cannot enter the realm of the lost souls for whomever joins the dead never sees light again." << endl;
				location = last_location;
				replay_move();
			}
		}
		else if((dest == "EXIT") || (dest == "exit")) {
			quitGame();
			cout << "Are you sure you wanna quit the game? ";
			string s;
			cin >> s;
			if((s == "NO") || (s == "no") || (s == "n"))
				this->play = 0;
			else if((s != "YES") && (s != "yes")) {
				cout << "Not a valid answer! Try again." << endl;
				while((s != "YES") && (s != "yes")) //finish this one!!!!
			}
		}
	}
}