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
#include <vector>

using namespace std;

class Game
{
private:
    vector<Entity> _players;
    vector<Entity> _enemies;
    vector<Potion> _allPotions;
    vector<Equipment> _allEquip;
    Entity _player1;
    Entity _player2;

public:
    Game();
    void introMenu();
    void loadEntity(string filename);
    vector<Entity> getPlayers();
    vector<Entity> getEnemies();
    vector<Potion> getPotions();
    vector<Equipment> getEquipment();
    void setPlayer(Entity player, int player_num);
    Entity getPlayer1();
    Entity getPlayer2();
    void loadPotionsEquipment(string filename);
    int combat(Entity player, Entity enemy);
    // void shop(Potion all_potions, Equipment all_equip);
    void playGame();
};

#endif