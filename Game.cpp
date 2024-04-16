#include "Game.h"

using namespace std;

Game::Game() {}

void Game::introMenu()
{
    // Intro statement
    cout << "Welcome to the Odyssey!" << endl;

    return;
}

void Game::loadEntity(string filename)
{
    ifstream file_in(filename);
    if (file_in.fail())
    {
        cout << "Could not open " << filename << " file." << endl;
        return;
    }
    else if (file_in.is_open())
    {
        string line = "";
        int idx = 0;
        while (!file_in.eof())
        {
            if (idx == 0)
            {
                idx++;
                getline(file_in, line);
                // std::cout << line << std::endl;
                continue;
            }
            else
            {
                // New line from the txt file
                getline(file_in, line);

                if (line.length() < 1) {
                    continue;
                }

                string line_array[12] = {""};
                int array_idx = 0;
                size_t pos = 0;
                string token;
                string delimiter = "|";
                while ((pos = line.find(delimiter)) != std::string::npos) {
                    token = line.substr(0, pos);
                    line_array[array_idx] = token;
                    line.erase(0, pos + delimiter.length());
                    array_idx++;
                }
                Entity newEntity(line_array);
                if (line_array[1][0] == 'P') {
                    std::cout << "Setting Player " << line_array[0] << std::endl;
                    setPlayer(newEntity);
                } else {
                    std::cout << "Setting Enemy " << line_array[0] << std::endl;
                    setEnemy(newEntity);
                }
            }
        }
    }
    file_in.close();
    return;
}

void Game::setPlayer(Entity player, int player_num)
{
    // if (player_num == 1) {
    //     _player1 = player;
    // } else if (player_num == 2)
    // {
    //     _player2 = player;
    // }
    // return;
}

Entity Game::getPlayer1() {
    return _player1;
}

Entity Game::getPlayer2() {
    return _player2;
}

void Game::loadPotionsEquipment(string filename) {
    // ifstream file_in(filename);
    // if (file_in.fail())
    // {
    //     cout << "Could not open " << filename << " file." << endl;
    //     return;
    // }
    // else if (file_in.is_open())
    // {
    //     string line = "";
    //     int idx = 0;
    //     while (!file_in.eof())
    //     {
    //         if (idx == 0)
    //         {
    //             idx++;
    //             getline(file_in, line);
    //             continue;
    //         }
    //         else
    //         {
    //             getline(file_in, line);
    //         }
    //     }
    // }
    return;
}

int Game::combat(Entity player, Entity enemy)
{
    return 0;
}

// void Game::shop(Potion all_potions, Equipment all_equip) {

// }

void Game::playGame()
{
}