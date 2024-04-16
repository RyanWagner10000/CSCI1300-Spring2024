#include "Entity.h"

Entity::Entity()
{
    _name = "";
    _HP = 0;
    _stamina = 0;
    _defense = 0;
    _condition = 'a';
    _advantage = false;
    _elemental_weakness = 'a';
    _gold = 0;
    // _items[255] = {0};
}

Entity::Entity(string initVariables[])
{
    _name = initVariables[0];
    _type = initVariables[1][0];
    _HP = stod(initVariables[2]);
    _stamina = stod(initVariables[3]);
    _defense = stod(initVariables[4]);
    _condition = initVariables[5][0];
    if (initVariables[6][0] == 'T' || initVariables[6][0] == 't') {
        _advantage = true;
    } else {
        _advantage = false;
    }
    _elemental_weakness = initVariables[7][0];
    _gold = stoi(initVariables[8]);

    size_t pos = 0;
    string token;
    string delimiter = ", ";
    pos = initVariables[9].find(delimiter);
    token = initVariables[9].substr(0, pos);
    Potion newPotion;
    newPotion.name = token;
    
    initVariables[9].erase(0, pos + delimiter.length());
    
    pos = initVariables[9].find(delimiter);
    token = initVariables[9].substr(0, pos);
    Equipment newEquipment;
    newEquipment.name = token;

    _potions[0] = newPotion;
    _inventory[0] = newEquipment;

    pos = 0;
    delimiter = ",";
    pos = initVariables[10].find(delimiter);
    token = initVariables[10].substr(0, pos);
    _items[0] = stoi(token);
    
    initVariables[9].erase(0, pos + delimiter.length());
    
    pos = initVariables[10].find(delimiter);
    token = initVariables[10].substr(0, pos);
    _items[1] = stoi(token);

    _ultimate = initVariables[12];
    _calamity = 0;
}

string Entity::getName() {
    return _name;
}

void Entity::swap(int userChoice) {

}

void Entity::drop(int userChoice) {

}

void Entity::usePotion(int userChoice) {

}

void Entity::updateEquipment(int equipIndex, Equipment weapon) {

}

void Entity::setEquipment(string name, string description, char type, int effect_value, char element, int price) {

}