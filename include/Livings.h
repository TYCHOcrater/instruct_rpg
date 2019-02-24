#ifndef LIVINGS_H
#define LIVINGS_H
#include <iostream>
#include <string>
#include <list>

#include "../include/Items.h"
#include "../include/Spells.h"

class Living {
protected:
	std::string name;
	int level;
	int healthPower;

public:
	explicit Living(std::string);
	Living(std::string, int);

	std::string get_name();
	int get_level();
	virtual int get_healthP();
	virtual void decrease_healthP(int);

	virtual void levelUp() = 0;
	virtual ~Living();
};

class Hero : public Living {
protected:
	int magicPower;
	int strength, agility, dexterity;
	int money;
	int experience;
	std:: list <Item*> Items;
	std:: list <Spell*> Spells;

public:
	Hero(std::string, int, int, int, int, int, int);
	virtual void levelUp() = 0;
	virtual std::string get_classType();

	void set_strength(int);
	void set_agility(int);
	void set_dexerity(int);
	void set_magicPower(int);
	void set_money(int);
	void set_experience(int);
	void set_health(int);

	int get_magicPower();
	int get_healthP();
	int get_money();
	int get_strength();
	int get_agility();
	int get_dexterity();
	int get_experience();

	void decrease_magicP(int);
	void decrease_healthP(int);
	void buy(Item*);
	void buy(Spell*);
	void sell(Item*);
	void sell(Spell*);
	Item* Search_Items(std::string);
	Spell* Search_Spells(std::string);
	void checkInvetory();
	void checkInvetory(std::string);
	std::string searchInvetory(std::string);
	void equip(std::string);
	void equip();
	void use(std::string);
	void use();
	Spell* castSpell();
	Spell* castSpell(std::string);
	int checkIfEmpty(std::string);
	virtual ~Hero();
};

class Warrior : public Hero {
public: 
	Warrior(std::string, int, int, int, int, int, int);
	void levelUp();
	std::string get_classType();
	~Warrior();
};

class Sorcerer : public Hero {
public:
	Sorcerer(std::string, int, int, int, int, int, int);
	void levelUp();
	std::string get_classType();
	~Sorcerer();
};

class Paladin : public Hero {
public:
	Paladin(std::string, int, int, int, int, int, int);
	void levelUp();
	std::string get_classType();
	~Paladin();
};

class Monster : public Living {
protected:
	int damage;
	int defence;
	int attack_AP;
	int damage_range;
public:
	Monster(std::string, int, int, int, int, int);
	int get_damage();
	int get_defence();
	int get_attackAP();
	int get_damageRange();
	virtual void levelUp() = 0;
	void decrease_damage(int);
	void reduce_damageR(int);
	void reduce_defence(int);
	void reduce_attackAP(int);
	void Attacked(Spell*);
	virtual ~Monster();
};

class Dragon : public Monster {
public:
	Dragon(std::string, int, int, int, int, int);
	void levelUp();
	~Dragon();
};

class Exoskeleton : public Monster {
public: 
	Exoskeleton(std::string, int, int, int, int, int);
	void levelUp(){}
	~Exoskeleton();
};

class Spirit : public Monster {
public:
	Spirit(std::string, int, int, int, int, int);
	void levelUp(){}
	~Spirit();
};

#endif