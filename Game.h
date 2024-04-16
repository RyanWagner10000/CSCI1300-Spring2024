#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <fstream>
#include <string>
#include <cstring>

#include "Entity.h"
#include "Potion.h"
#include "Equipment.h"

using namespace std;

class Game
{
private:
    Entity _players[100];
    Entity _enemies[100];
    Potion _allPotions[100];
    Equipment _allEquip[100];
    Entity _player1;
    Entity _player2;

public:
    Game();
    void introMenu();
    void loadEntity(string filename);
    void setEnemy(Entity newEntity) {
        std::cout << "HERE1" << std::endl;
        int idx = 0;
        while(true) {
            if (getEntity("E", idx).getName().length() == 0) {
                this->_enemies[idx] = newEntity;
                return;
            } else {
                idx++;
            }
        }
    } 
    void setPlayer(Entity newEntity) {
        int idx = 0;
        while(true) {
            if (getEntity("P", idx).getName().length() == 0) {
                this->_enemies[idx] = newEntity;
                return;
            } else {
                idx++;
            }
        }
    }
    Entity getEntity(string type, int idx) {
        if (type == "E") {
            return this->_enemies[idx];
        } else {
            return this->_players[idx];
        }
        
    }
    void setPlayer(Entity player, int player_num);
    Entity getPlayer1();
    Entity getPlayer2();
    void loadPotionsEquipment(string filename);
    int combat(Entity player, Entity enemy);
    // void shop(Potion all_potions, Equipment all_equip);
    void playGame();
};

#endif