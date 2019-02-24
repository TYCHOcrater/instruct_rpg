#ifndef SPELLS_H
#define SPELLS_H
#include <iostream>
#include <string>

class Spell {
protected:
	std::string name;
	int cost;
	int minLevel;
	int damage;
	int minMagicPower;
public:
	Spell(std::string,int,int,int,int);
	int get_min_magicP();
	int get_damage();
	int get_cost();
	int get_unlock_level();
	std::string get_name();
	void set_damage(int);

	virtual int get_reduction() = 0;
	virtual std::string get_classType() = 0;
	virtual ~Spell();
};

class IceSpell : public Spell {
private:
	int reduction;
public:
	IceSpell(std::string,int,int,int,int,int);
	int get_reduction();
	std::string get_classType();
	~IceSpell();
};

class FireSpell : public Spell {
private:
	int reduction;
public:
	FireSpell(std::string,int,int,int,int,int);
	int get_reduction();
	std::string get_classType();
	~FireSpell();
};

class LightningSpell : public Spell {
private:
	int reduction;
public:
	LightningSpell(std::string,int,int,int,int,int);
	int get_reduction();
	std::string get_classType();
	~LightningSpell();
};

#endif