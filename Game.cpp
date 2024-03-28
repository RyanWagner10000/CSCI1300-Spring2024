#include "Game.h"

using namespace std;

Game::Game() {}

void Game::introMenu()
{
    // Intro statement
    cout << "Welcome to the Odyssey!" << endl;

    // Load heros and enemies
    loadEntity("data//entity.txt");

    return;
}

void Game::loadEntity(string filename)
{
    ifstream file_in(filename);
    if (file_in.fail())
    {
        cout << "Could not open entity.txt file." << endl;
        return;
    }
    else if (file_in.is_open())
    {
        string line = "";
        string delim = "|";
        int idx = 0;
        while (!file_in.eof())
        {
            if (idx == 0)
            {
                idx++;
                getline(file_in, line);
                continue;
            }
            else
            {
                getline(file_in, line);
                if (line.length() > 0)
                {
                    size_t pos = 0;
                    string token1; // define a string variable

                    // use find() function to get the position of the delimiters
                    while ((pos = line.find(delim)) != string::npos)
                    {
                        token1 = line.substr(0, pos); // store the substring
                        cout << token1 << endl;
                        line.erase(0, pos + delim.length()); /* erase() function store the current positon and move to next token. */
                    }
                    cout << line << endl; // it print last token of the string.
                }
            }
        }
    }
    file_in.close();
}

Entity Game::getPlayer(int entity_num)
{
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