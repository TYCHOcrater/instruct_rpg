#ifndef MYTEAM_H
#define MYTEAM_H
#include <iostream>
#include <list>
#include <string>

#include "../include/Livings.h"

class myTeam {
private:
	std::list <Hero*> my_heroes;
	std:: list <Hero*> Sorcerers;
	std:: list <Hero*> Warriors;
	std:: list <Hero*> Paladins;

public:
	MyTeam();
	void Insert_Warrior(std::string,int,int,int,int,int,int);
	void Insert_Sorcerers(std::string,int,int,int,int,int,int);
	void Insert_Paladins(std::string,int,int,int,int,int,int);
	void add_player(std::string);
	void Display_Team();
	void Display_Team(int);
	void Display_Heroes();
	Hero* Search_Hero(std::string);
	std::string catch_wrongName(std::string);
	std::list <Hero*> get_myHeroes();
	~MyTeam();
};

#endif