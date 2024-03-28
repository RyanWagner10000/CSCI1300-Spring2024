#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Entity.h"
#include <list>
#include <fstream>
#include <string>
#include "Potion.h"
#include "Equipment.h"
#include <cstring>

using namespace std;

class Game
{
private:
    list<Entity> _players;
    list<Entity> _enemies;
    list<Potion> _allPotions;
    list<Equipment> _allEquip;

public:
    Game();
    void introMenu();
    void loadEntity(string filename);
    // Entity getPlayer(int entity_num);
    list<Entity> getPlayers();
    list<Entity> getEnemies();
    int combat(Entity player, Entity enemy);
    // void shop(Potion all_potions, Equipment all_equip);
    void playGame();
};

#endif