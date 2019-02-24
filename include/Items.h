#ifndef ITEMS_H
#define ITEMS_H

#include <iostream>
#include <string>

class Item {
protected:
	std::string name;
	int cost;
	int minLevel;
public:
	Item(std::string, int, int);
	int get_cost();
	int get_unlock_level();
	std::string get_name();
	virtual int get_damage();
	virtual int get_IF_used();
	virtual int get_rate();
	virtual int get_reduction();
	virtual int get_min_magicL();
	virtual int get_hand_control();
	virtual std::string get_classType() = 0;
	virtual int Damage();
	virtual void set_damage(int);
	virtual ~Item();
};

class Weapon : public Item {
private:
	int damage;
	int handControl;
public:
	Weapon(std::string, int, int, int, int);
	int get_damage();
	int get_hand_control();
	std::string get_classType();
	void set_damage(int);
	~Weapon();
};

class Potion : public Item {
private:
	int statisticsRI;
public:
	Potion(std::string, int, int, int);
	int get_rate();
	std::string get_classType();
	~Potion();
};

class Armor : public Item {
private:
	int damageRP;
public:
	Armor(std::string, int, int, int);
	int get_reduction();
	std::string get_classType();
	~Armor();
};

#endif