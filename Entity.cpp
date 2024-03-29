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
    vector<int> temp = {};
    _items = temp;
}

Entity::Entity(string Name, double hp, double stamina, double defense, char condition, bool advantage, char elemental_weakness, int gold, vector<int> starting_items)
    : _name(Name), _HP(hp), _stamina(stamina), _defense(defense), _condition(condition), _advantage(advantage), _elemental_weakness(elemental_weakness), _gold(gold), _items(starting_items)
{
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