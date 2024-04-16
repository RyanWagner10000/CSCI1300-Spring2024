#include "Game.h"
#include <ctype.h>
#include <cstring>

using namespace std;

// g++ -Wall -Wpedantic -std=c++17 GameDriver.cpp Game.cpp Entity.cpp -o playGame && ./playGame

int main(){
    // initialize
    Game m_game;

    // print menu
    m_game.introMenu();

    // Load heros and enemies
    m_game.loadEntity("data//entity.txt");
    
    // cout << "You have " << m_game.getPlayers().size() << " Players to choose from." << endl;
    // cout << "Which character would you like to play as?" << endl;
    
    // vector<Entity> players = m_game.getPlayers();
    // int idx = 1;
    // int user_input = -1;

    // for (auto& it : players) {
    //     cout << "(" << idx << ") " << it.getName() << " ";
    //     idx++;
    //     if (idx > (int) players.size()) {
    //         cout << endl << "Player choice: ";
    //         cin.clear();
    //         cin >> user_input;
    //     }
    // }
    // if (user_input > 0 && user_input <= (int) m_game.getPlayers().size()) {
    //     m_game.setPlayer(players.at(user_input-1), 1);
    //     cout << m_game.getPlayer1().getName() << " chosen sucessfully!" << endl;
    // } else {
    //     cout << "Incorrect input type. Please rerun." << endl;
    //     return -1;
    // }

    // // Set player 2 to random other character
    // int player2_choice = 0;
    // srand(time(NULL));
    // while (true) {
    //     player2_choice = (rand() % m_game.getPlayers().size()) + 1;
    //     if (player2_choice != user_input) {
    //         m_game.setPlayer(players.at(player2_choice-1), 2);
    //         cout << "\nRandom Player 2 choice is " << m_game.getPlayer2().getName() << endl;
    //         break;
    //     }
    // }

    // m_game.loadPotionsEquipment("data//items.txt");
    // cout << "Num potions = " << m_game.getPotions().size() << endl;
    // cout << "Num equips = " << m_game.getEquipment().size() << endl;

    // Visit shop before game starts


    // // Combat testing
    // // let's say I haven't figured out how to connect things to the game's list of entities yet, but I want to get my combat function out of the way
    // // I can still work on creating the general idea of my combat function and worry about putting it into everything later

    // // here I am just manually creating some players to test with
    // Entity player = Entity("Argos", 120.0, 100.0, 20.0, 'H', false, 'W', 50, false);
    // Entity enemy = Entity("Sirens", 150.0, 100.0, 25.0, 'H', false, 'E', 25, true);
    
    // // manually providing Equipment to each one
    // // NOTE: your setEquipment should have more parameters than mine does
    // player.setEquipment("Bow of Odysseus", "Increases damage by 10", 'D', 10, 'W', 100);
    // enemy.setEquipment("Lotus Staff", "Increases damage by 10", 'D', 10, 'E', 80);

    // // calling my combat function to test - output is in the GitHub under Combat
    // m_game.combat(player, enemy);

    return 0;
}
