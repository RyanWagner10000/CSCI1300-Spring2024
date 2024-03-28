#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
// #include <Potion.h>
// #include <Equipment.h>
#include <list>

using namespace std;

class Entity {
    private:
        string _name;
        double _HP;
        double _stamina;
        double _defense;
        char _condition;
        bool _advantage;
        // Potion _potions;
        // Equipment _equipped;
        // Equipment _inventory;
        list<int> _items;
        float _calamity;
    public:
        // Constructor
        Entity();
        
        // Parametrized Constructor
        Entity(string Name, float hp, float stamina, float defense, char condition, bool advantage, char elemental_weakness, int gold, bool starting_items);
        
        string getName();
        
        // user can change weapons or potions depending on userChoice
        void swap(int userChoice);
        
        // user can drop weapons or potions depending on userChoice
        void drop(int userChoice);
        
        // user can use potion depending on userChoice
        void usePotion(int userChoice);
        
        // uses given weapon to update weapon at a particular index (equipIndex)
        // void updateEquipment(int equipIndex, Equipment weapon);
        
        // setter for setting equipment
        void setEquipment(string name, string description, char type, int effect_value, char element, int price);

};

#endif