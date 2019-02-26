#include <iostream>
#include <string>

#include "../include/Items.h"

using namespace std;

Item::Item(string n, int c, int level) : name(n), cost(c), minLevel(level) {}

int Item::get_classType() {
    return this->cost;
}

int Item::get_unlock_level() {
    return this->minLevel;
}

string Item::get_name() {
    return this->name;
}

int Item::get_damage() {
    return -1;
}

int Item::get_IF_used() {
    return -1;
}

int Item::get_rate() {
    return -1;
}

int Item::get_reduction() {
    return -1;
}

int Item::get_min_magicL() {
    return -1;
}

int Item::Damage() {
    return -1;
}

int Item::get_hand_control() {
    return -1;
}

void Item::set_damage(int strength) {
    return;
}

Item::~Item() {}

//class weapon

Weapon::Weapon(string name, int c, int level, int loss, int oneh) : Item(name,c,level), damage(loss), handControl(oneh) {}

int Weapon::get_damage() {
    return this->damage;
}

int Weapon::get_hand_control() {
    return this->handControl;
}

string Weapon::get_classType() {
    return "Weapon";
}

void Weapon::set_damage(int strength) {
    this->damage += strength;
}

Weapon::~Weapon(){}

Potion::Potion(string name, int c, int level, int RI) : Item(name,c,level), statisticsRI(RI) {}

int Potion::get_rate() {
    return this->statisticsRI;
}

string Potion::get_classType() {
    return "Potion";
}

Potion::~Potion() {}

//class armor
Armor::Armor(string name, int c, int level, int RP) : Item(name,c,level), damageRP(RP) {}

int Armor::get_reduction() {
    return this->damageRP;
}

string Armor::get_classType() {
    return "Armor";
}

Armor::~Armor() {}