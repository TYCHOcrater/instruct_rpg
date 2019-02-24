#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <string>
#include <list>
#include <ctime>

#include "../include/Market.h" //todo

#define LENGTH 8
#define WIDTH 8

class Grid {
private:
	int **Map;
	Market *myMarket;
	int location;
	int last_location;
	int play;
	std::list <Monster*> Dragons;
	std::list <Monster*> Spirits;
	std::list <Monster*> Exoskeletons;
	std::list <Monster*> myMonsters;
public:
	explicit Grid(Market*);
	void move();
	void replay_move();
	int move_forward();
	int move_backwards();
	int move_left();
	int move_right();
	void show_location();
	void Display_Map();
	void display_status();
	void display_monsterStatus();
	void display_monsterStatus(std::string);
	void display_heroStatus();
	void display_heroStatus(std::string);
	void Insert_Dragon( std::string, int, int, int, int, int );
	void Insert_Spirit( std::string, int, int, int, int, int );
	void Insert_Exoskeletons ( std::string, int, int, int, int, int );
	void Fight();
	void attack(std::string);
	int H_TotalPower();
	int M_TotalPower();
	void get_standarBonus(std::string);
	void gameplay();
	void castSpell(std::string);
	void quitGame();
	void BasicInfo();
	void print_effects(int);
	~Grid();
};

#endif