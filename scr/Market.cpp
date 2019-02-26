#include <iostream>
#include <string>
#include <list>
#include <cstdlib>
#include <iterator>

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

#include "../include/Market.h"

using namespace std;

Market::Market(MyTeam* Team) {
    this->Squad = Team;
}

void Market::Insert_Weapon(string name, int cost, int unlockL, int damage, int handControl) {
    Item *NewItem = new Weapon(name,cost,unclockL,damage,handControl);
    Weapons.push_back(NewItem);
}

void Market::Insert_Armor(string name,int cost,int unlockL,int damageRP) {
    Item *NewItem = new Armor(name,cost,unlockL,damageRP);
    Armors.push_back(NewItem);
}

void Market::Insert_Potion(string name,int cost, int unlockL,int statisticsRI) {
    Item *NewItem = new Potion(name,cost,unlockL,statisticsRI);
    Potions.push_back(NewItem);
}

void Market::Insert_IceSpell(string name, int cost, int unlockL, int statisticsRI) {
    Spell *NewSpell = new IceSpell(name,cost,unlockL,damage,minMagicP,reduction);
    IceSpells.push_back(NewSpell);
}

void Market::Insert_FireSpell(string name, int cost, int unlockL, int damage, ing minMagicP, int reduction) {
    Spell *NewSpell = new FireSpell(name,cost,unlockL,damage,minMagicP,reduction);
    FireSpells.push_back(NewSpell);
}

void Market::Insert_LightningSpell(string name, int cost, int unlockL, int damage, int minMagicP, int reduction) {
    Spell *NewSpell = new LightingSpell(name,cost,unlockL,damage,minMagicP,reduction);
    LightningSpell.push_back(NewSpell);
}

void Market::Display_Items() {
    list <Item*> :: iterator it;

    cout << endl << endl << endl;
    cout << " Available Weapons" << endl;
    cout << "********************" << endl;
    cout << "Name" << "\t\t" << "Cost" << "\t   " << "Unlock Level" << "\t  " << "Damage" << endl;
    cout << "------------------------------------------------------" << endl;
    for(it = Weapons.begin(); it!=Weapons.end(); ++it)
        cout << (*it)->get_name() << "\t\t" << (*it)->get_cost() << "\t\t" << (*it)->get_unlock_level() << "\t\t" << (*it)->get_damage() << endl;
    cout << endl << endl;

    cout << " Available Armors" << endl;
    cout << "********************" << endl;
    cout << "Name" << "\t\t" << "Cost" << "\t   " << "Unlock Level" << "\t  " << "Damage" << endl;
    cout << "------------------------------------------------------" << endl;
    for(it=Armors.begin(); it!=Armors.end(); ++it)
        cout << (*it)->get_name() << "\t\t" << (*it)->get_cost() << "\t\t" << (*it)->get_unlock_level() << "\t\t" << (*it)->get_damage() << endl;
    cout << endl;
}

void Market::DisplayMarket() {
    cout << "You have entered the Market!" << endl;
        Display_Items();
        Display_Spells();
        DisplayOnSell();
}

std::string Market::catch_wrongName(string name, string clasType){

    string ch_name;
    if(classType == "Items") {
        list <Item*> :: iterator it;
        int found = 0;
        for(it = Weapons.begin(); it!=Weapons.end();++it) {
            if((*it)->get_name() == name)
                return name;
        }

        for
    }
}