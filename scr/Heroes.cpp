#include <iostream>
#include <string>
#include "../include/Livings.h"

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

Living::Living(string n)
                : name(n), level(1), healthPower(200) {}

string Living::get_name(){
    return this->name;
}

Living::Living(string n, int lev)
                : name(n), level(lev), healthPower(200) {}

int Living::get_healthP() {
    if(this->healthPower < 0)
        this->healthPower = 0;
    return this->healthPower;
}

int Living::get_level() {
    return this->level;
}

void Living::decrease_healthP(int num) {
    this->healthPower = healthPower - num;
}

Living::~Living(){}


Hero::Hero(string n, int magicP, int str, int ag, int dext, int m, int exp) : Living(n), magicPower(magicP), strength(str), agility(ag), dexterity(dext), money(m), experience(exp) {}

void Hero::set_strength(int plus) {
    this->strength += plus;
}

void Hero::set_dexterity(int plus) {
    this->dexterity += plus;
}

void Hero::set_magicPower(int plus) {
    this->magicPower += plus;
}

void Hero::set_money(int plus) {
    this->money += plus;
}

void Hero::set_experience(int plus) {
    this->experience += plus;
}

void Hero::set_healthP(int plus) {
    this->healthPower += plus;
}

std::string Hero::get_classType() {
    return "Hero";
}

int Hero::get_magicPower() {
    return this->magicPower;
}

int Hero::get_money() {
    return this->money;
}

int Hero::get_strength() {
    return this->strength;
}

int Hero::get_agility() {
    return this->agility;
}

int Hero::get_experience() {
    return this->experience;
}

int Hero::get_healthP() {
    if(this->healthPower < 0)
        this->healthPower = 0;
    return this->healthPower;
}

void Hero::decrease_magicP(int decr) {
    this->magicPower = this->magicPower - decr;
}

void Hero::decrease_healthP(int num) {
    this->healthPower = this->healthPower - num;
}

void Hero::buy(Item* item) {
    this->money = this->money + (item->get_cost()/2);
    list <Item*> :: iterator it;

    for(it = Items.begin(); it!=Items.end(); it++) {
        if(item->get_name() == (*it)->get_name()) {
            it = Items.erase(it);
            break;
        }
    }
}

void Hero::buy(Spell* spell) {
    this->money = this->money - spell->get_cost();
    Spells.push_back(spell);

    set_dexterity(spell->get_damage());
    int damage = this->get_level()/100;
    spell->set_damage(damage);
}

void Hero::sell(Spell* spell) {
    this->money = this->money + (spell->get_cost()/2);
    list <Spell*> :: iterator it;

    for(it = Spells.begin(); it!=Spells.end(); it++) {
        if(spell->get_name() == (*it)->get_name()) {
            it = Spells.erase(it);
            break;
        }
    }
}

Item* Hero::Search_Items(string name) {
    list <Item*> :: iterator it;
    for(it = Items.begin(); it!=Items.end();it++) {
        if((*it)->get_name() == name)
            return *it;
    }
    cout << "No valid Name. Please Try Again." << endl;
    return NULL;
}

void Hero::checkInvetory() {
    if((Items.empty()) && (Spells.empty())) {
        cout << "Empty" << endl;
        return;
    }

    list <Item*> :: iterator ti;
    cout << " Items bought" << endl;
    cout << "***************" << endl;
    cout << "Type of Item" << "\t\t" << "Name" << "\t\t\t" << "Cost" << "\t     " << "Unlock level" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    for(ti = Items.begin(); ti!=Items.end(); ++ti)
        cout << (*ti)->get_classType() << "\t\t\t" << (*ti)->get_name() << "\t\t\t " << (*ti)->get_cost() << "\t\t" << (*ti)->get_unlock_level() << endl;
    cout << endl <<endl;

    list <Spell*> :: iterator it;
    cout << " Spells bought" << endl;
    cout << "***************" << endl;
    cout << "Type of Spell" << "\t\t" << "Name" << "\t\t\t" << "Cost" << "\t    " << "Unlock level" << "\t\t" << endl;
    cout << "----------------------------------------------------------------------------------" << endl;
    for(it = Spells.begin(); it!=Spells.end(); ++it)
        cout << (*it)->get_classType() << "\t\t" << (*it)->get_name() << "\t\t" << (*it)->get_cost() << "\t\t" << (*it)->get_unlock_level() << endl;
    cout << endl;
}

void Hero::checkInvetory(string s) {
    cout << endl << endl;
    if(s == "item") {
        if(Items.empty()) {
            cout << "You haven't bought any items yet!" << endl << endl;
            return;
        }

        list <Item*> :: iterator ti;
        cout << " Items bought" << endl;
        cout << "***************" << endl;
        cout << "Type of Item" << "\t\t" << "Name" << "\t\t\t" << "Cost" << "\t   " << "Unlock Level" << endl;
        cout << "---------------------------------------------------------------------------" << endl;
        for(ti = Items.begin(); ti!=Items.end(); ++ti)
            cout << (*ti)->get_classType() << "\t\t\t" << (*ti)->get_name() << "\t\t\t " << (*ti)->get_cost() << "\t\t" << (*ti)->get_unlock_level() << endl;
        cout << endl <<endl;
    }
    else if(s == "spell") {
        if(Spells.empty()) {
            cout << "You haven't bought any spells yet!" << endl << endl;
            return;
        }

        list <Spell*> :: iterator it;
        cout << " Spells bought" << endl;
        cout << "****************" << endl;
        cout << "Type of Spell" << "\t\t" << "Name" << "\t\t\t" << "Cost" << "\t   " << "Unlock Level" << "\t\t" << "Damage" << endl;
        cout << "--------------------------------------------------------------------------------------------" << endl;
        for(it = Spells.begin(); it!=Spells.end(); ++it)
            cout << (*it)->get_classType() << "\t\t" << (*it)->get_name() << "\t\t" << (*it)->get_cost() << "\t\t" << (*it)->get_unlock_level() << "\t\t" << (*it)->get_damage() << endl;
        cout << endl;
    }
}

string Hero::searchInvetory(string name) {
    string ch_name;
    int found = 0;
    list <Item*> :: iterator it;
    for(it = Items.begin(); it!=Items.end(); ++it) {
        if ((*it)->get_name() == name)
            return name;
    }

    list <Spell*> :: iterator ti;
    for(ti = Spells.begin();ti!=Spells.end();++ti) {
        if((*ti)->get_name() == name)
            return name;
    }

    while (found == 0) {
        cout << "Wrong Name. Please try again." << endl;
        string n;
        cin >> n;

        for(it = Items.begin(); it!=Items.end(); ++it) {
            if((*it)->get_name() == n) {
                ch_name = n;
                found = 1;
                break;
            }
        }

        for(ti = Spells.begin(); ti!=Spells.end(); ++ti) {
            if((*it)->get_name() == n) {
                ch_name = n;
                found = 1;
                break;
            }
        }

        for(ti = Spells.begin();ti!=Spells.end(); ++ti) {
            if((*ti)->get_name() == n) {
                ch_name = n;
                found = 1;
                break;
            }
        }
    }
    return ch_name;
}

void Hero::equip(string name) {
    name = searchInvetory(name);

    Item *item = Search_Items(name);
    if(item->get_classType() == "Weapon")
        item->set_damage(this->get_strength());
    else
        this->set_agility(item->get_reduction());
    cout << "\t\t\t\t\t\t\t" << item->get_name() << " " << "just equiped" << endl;
}

void Hero::equip() {
    if(checkIfEmpty("Items") == 1) {
        cout << endl << ednl << KRED << "\t\t\t\t\t\t\t W A R N I N G! " << KWHT << endl << endl;
        cout << "\t\t\t\t\tYou haven't bought any items yet, use your first to attack" << endl;
        return;
    }

    int flag = 0;
    while(flag == 0) {
        checkInvetory("item");
        cout << "Press 1 to change Weapon" << endl;
        cout << "Press 2 to change Armor" << endl;
        cout << "Press 3 to do both" << endl;
        string in;
        cin >> in;
        if(in == "1") {
            if(checkIfEmpty("Weapon") == 1) {
                cout << endl << endl << KRED << "\t\t\t\t\t\t\t W A R N I N G!" << KWHT << endl << endl;
                cout << "\t\t\t\t\tYou haven't bought any Weapons yet, equip something else or use your first to attack" << endl;
                return;
            }
            flag = 1;
            cout << endl << "Enter the Name of Weapon" << endl;
            string name;
            cin >> name;
            this->equip(name);
        }
        else if(in == "2") {
            if(checkIfEmpty("Armor") == 1) {
                cout << endl << endl << KRED << "\t\t\t\t\t\t\t W A R N I N G! " << KWHT << endl << endl;
                cout << "\t\t\t\tYou haven't bought any Armors yet, equip something else or use your first to attack" << endl;
                return;
            }

            flag = 1;
            cout << endl << "Enter the Name of Armor" << endl;
            string name;
            cin >> name;
            this->equip(name);
        }
        else if(in == "3") {
            flag = 1;
            string name;
            if(checkIfEmpty("Weapon") != 1) {
                cout << endl << "Enter the Name of Weapon" << endl;
                cin >> name;
                this->equip(name);
            }
            if(checkIfEmpty("Armor") != 1) {
                cout << endl << "Enter the Name of Armor" << endl;
                cin >> name;
                this->equip(name);
            }
        }
        else {
            cout << "Did you made a Typo? Please try again." << endl;
        }
    }
}

void Hero::use(string name) {
    Item *item = Search_Items(name);
    list <Item*> :: iterator it;
    for(it = Items.begin(); it!=Items.end();++it) {
        //finish this one
    }
}