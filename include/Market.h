#ifndef MARKET_H
#define MARKET_H
#include <list>
#include <string>

#include <../include/myTeam.h>

class Market {
private:
	std:: list <Item*> Weapons;
	std:: list <Item*> Armors;
	std:: list <Item*> Potions;
	std:: list <Spell*> IceSpells;
	std:: list <Spell*> FireSpells;
	std:: list <Spell*> LightingSpells;

	std:: list <Spell*> SpellsOnSell;
	std:: list <Item*> ItemOnSell;
	MyTeam *Squad;	//pointing directly to 'myteam'

public:
	explicit Market(MyTeam*);
	void Insert_Weapon(std::string,int,int,int,int);
	void Insert_Armor(std::string,int,int,int);
	void Insert_Potion(std::string,int,int,int);
	void Insert_IceSpell(std::string,int,int,int,int,int);
	void Insert_FireSpell(std::string,int,int,int,int,int);
	void Insert_LightningSpell(std::string,int,int,int,int,int);
	void DisplayMarket();
	void DisplayOnSell();
	void Display_Items();
	void Display_Spells();
	Item* Search_Items(std::string);
	Spell* Search_Spells(std::string);
	Item* Search_ItemOnSell(std::string);
	Spell* Search_SpellsOnSell(std::string);
	void buy();
	void buy_Item(std::string);
	void buy_Spell(std::string);
	void sell();
	void sell_Item(std::string);
	void sell_Spell(std::string);
	void visit_Market();
	void print_effects();
	std::string catch_wrongName(std::string, std::string);
	MyTeam* get_myTeam();
	~Market();
};

#endif