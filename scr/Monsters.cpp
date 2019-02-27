#include <iostream>
#include <string>

#include "../include/Livings.h"

using namespace std;

Monster::Monster(string n,int lev,int d,int def,int attack,int damage_r) : Living(n,lev), damage(d), defence(def), attack_AP(attack), damage_range(damage_r) {}

int Monster::get_damage() {
    if(this->damage <= 0)
        return 0;
    return this->damage;
}

int Monster::get_defence() {
    if(this->defence <= 0)
        return 0;
    return this->defence;
}

int Monster::get_attackAP() {
    if(this->attack_AP <= 0)
        return 0;
    return this->attack_AP;
}

int Monster::get_damageRange() {
    if(this->damage_range <= 0)
        return 0;
    return this->damage_range;
}

void Monster::Attacked(Spell* spell) {
    string Type;

    Type = spell->get_classType();
    if(Type == "LightingSpell") {
        reduce_attackAP(spell->get_reduction());
    }
    else if(Type == "FireSpell") {
        reduce_defence(spell->get_reduction());
    }
    else {
        reduce_damageR(spell->get_reduction());
    }
}

void Monster::decrease_damage(int decr) {
    this->damage = this->damage - decr;
}

void Monster::reduce_damageR(int reduce) {
    this->damage_range = this->damage_range + reduce;
}

void Monster::reduce_defence(int reduce) {
    this->defence = this->defence - reduce;
}

void Monster::reduce_attackAP(int reduce) {
    this->attack_AP = this->attack_AP - reduce;
}

Monster::~Monster() {}

Dragon::Dragon(string n,int lev, int d,int def,int attack,int damage_r) : Monster(n,lev,d,def,attack,damage_r) {}

Dragon::~Dragon() {}

Exoskeleton::Exoskeleton(strin n,int lev,int d,int def,int attack,int damage_r) : Monster(n,lev,d,def,attack,damage_r) {}

Exoskeleton::~Exoskeleton() {}

Spirit::Spirit(strin n,int lev,int d,int def,int attack,int d,int damage_r) : Monster(n,lev,d,def,attack,damage_r) {}

Spirit::~Spirit() {}