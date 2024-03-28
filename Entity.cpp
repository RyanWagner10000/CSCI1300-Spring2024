#include "Entity.h"

Entity::Entity() {}

Entity::Entity(string Name, double hp, double stamina, double defense, char condition, bool advantage, char elemental_weakness, int gold, list<int> starting_items) {
    Entity entity = {};
}

Entity Entity::makeEntity(string Name, double hp, double stamina, double defense, char condition, bool advantage, char elemental_weakness, int gold, list<int> starting_items) {
    Entity entity;
    entity._name = Name;
    entity._HP = hp;
    entity._stamina = stamina;
    entity._defense = defense;
    entity._condition = condition;
    entity._advantage = advantage;
    entity._elemental_weakness = elemental_weakness;
    entity._gold = gold;
    entity._items = starting_items;
    return entity;
}

string Entity::getName(Entity entity) {
    return entity._name;
}

void Entity::swap(int userChoice) {

}

void Entity::drop(int userChoice) {

}

void Entity::usePotion(int userChoice) {

}

// void Entity::updateEquipment(int equipIndex, Equipment weapon) {
    
// }