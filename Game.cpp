#include "Game.h"

using namespace std;

Game::Game() {}

void Game::introMenu()
{
    // Intro statement
    cout << "Welcome to the Odyssey!" << endl;

    return;
}

// Function to split a string into a vector of substrings based on a delimeter character
vector<string> splitString(string str, char delimeter) 
{
    string temp = "";
    vector<string> substrings;
    int count = 0;
    if (str == "") 
    {
        return substrings;
    }
    for (size_t i = 0; i < str.length(); i++) 
    {
        if (str[i] != delimeter) 
        {
            temp += str[i];
        } 
        else 
        {
            substrings.push_back(temp);
            count++;
            temp = "";
        }
    }
    substrings.push_back(temp);
    return substrings;
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
                // New line from the txt file
                getline(file_in, line);

                // Make a new Entity object to hold the character info from the txt file
                string _name;
                char _type;
                double _HP;
                double _stamina;
                double _defense;
                char _condition;
                bool _advantage;
                char _elemental_weakness;
                int _gold;
                vector<int> _items;
                vector<Potion> _potions;
                vector<Equipment> _equipped;
                vector<Equipment> _inventory;
                string _ultimate;

                if (line.length() > 0)
                {
                    size_t pos = 0;
                    string token1;
                    int idx = 0;

                    // use find() function to get the position of the delimiters
                    while ((pos = line.find(delim)) != string::npos)
                    {
                        token1 = line.substr(0, pos); // store the substring
                        line.erase(0, pos + delim.length()); /* erase() function store the current positon and move to next token. */
                        switch (idx)
                        {
                        case 0:
                            _name = token1;
                            // cout << "Name: " << _name <<endl;
                            break;
                        case 1:
                            _type = token1.at(0);
                            // cout << "Type: " << _type <<endl;
                            break;
                        case 2:
                            _HP = stod(token1);
                            // cout << "HP: " << _HP <<endl;
                            break;
                        case 3:
                            _stamina = stod(token1);
                            // cout << "Stamina: " << _stamina <<endl;
                            break;
                        case 4:
                            _defense = stod(token1);
                            // cout << "Defense: " << _defense <<endl;
                            break;
                        case 5:
                            _condition = token1.at(0);
                            // cout << "Condition: " << _condition <<endl;
                            break;
                        case 6:
                            if (token1 == "False") {
                                _advantage = false;
                            } else {
                                _advantage = true;
                            }
                            // cout << "Advantage: " << _advantage <<endl;
                            break;
                        case 7:
                            _elemental_weakness = token1.at(0);
                            // cout << "Elemental Weakness: " << _elemental_weakness <<endl;
                            break;
                        case 8:
                            _gold = stoi(token1);
                            // cout << "Gold: " << _gold <<endl;
                            break;
                        case 9:
                        {
                            int temp_pos;
                            string item1;
                            string item2;

                            temp_pos = token1.find(", ");
                            item1 = token1.substr(0, temp_pos); // store the substring
                            item2 = token1.substr(temp_pos+2);

                            // cout << "Item1: " << item1 <<endl;
                            // cout << "Item2: " << item2 <<endl;
                            break;
                        }
                        case 10:
                        {
                            int temp_pos;
                            int item_num1;
                            int item_num2;

                            temp_pos = token1.find(",");
                            item_num1 = stoi(token1.substr(0, temp_pos)); // store the substring
                            item_num2 = stoi(token1.substr(temp_pos+1));

                            _items.push_back(item_num1);
                            _items.push_back(item_num2);
                            // cout << "Items length: " << _items.size() << endl;
                            break;
                        }
                        default:
                            break;
                        }
                        idx++;
                    }
                    _ultimate = line;
                    if (_type == 'P') {
                        Entity new_entity = Entity(_name, _HP, _stamina, _defense, _condition, _advantage, _elemental_weakness, _gold, _items);
                        _players.push_back(new_entity);
                    } else {
                        Entity new_entity = Entity(_name, _HP, _stamina, _defense, _condition, _advantage, _elemental_weakness, _gold, _items);
                        _enemies.push_back(new_entity);
                    }
                }
            }
        }
    }
    file_in.close();
}

vector<Entity> Game::getPlayers()
{
    return _players;
}

vector<Entity> Game::getEnemies()
{
    return _enemies;
}

void Game::setPlayer(Entity player, int player_num)
{
    if (player_num == 1) {
        _player1 = player;
    } else if (player_num == 2)
    {
        _player2 = player;
    }
    return;
}

Entity Game::getPlayer1() {
    return _player1;
}

Entity Game::getPlayer2() {
    return _player2;
}

void Game::loadPotionsEquipment(string filename) {
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
                continue;
            }
            else
            {
                getline(file_in, line);
                vector<string> substrings = splitString(line, '|');
                if (substrings.size() == 0) {
                    continue;
                } else if (substrings[4] == "None") { // This means is a potion
                    Potion new_potion;
                    new_potion.name = substrings[0];
                    new_potion.description = substrings[1];
                    new_potion.type = substrings[2].at(0);
                    new_potion.effect_value = stod(substrings[3]);
                    new_potion.element = substrings[4].at(0);
                    new_potion.price = stod(substrings[5]);
                    new_potion.quantity = 1;
                    _allPotions.push_back(new_potion);
                } else { // Therefore this is a potion
                    Equipment new_equipment;
                    new_equipment.name = substrings[0];
                    new_equipment.description = substrings[1];
                    new_equipment.type = substrings[2].at(0);
                    if (new_equipment.type == 'D') {
                        new_equipment.damage = stod(substrings[3]);
                        new_equipment.defense = 0;
                    } else {
                        new_equipment.damage = 0;
                        new_equipment.defense = stod(substrings[3]);
                    }
                    new_equipment.element = substrings[4].at(0);
                    new_equipment.price = stod(substrings[5]);
                    _allEquip.push_back(new_equipment);
                }
            }
        }
    }
    return;
}

vector<Potion> Game::getPotions() {
    return _allPotions;
}

vector<Equipment> Game::getEquipment() {
    return _allEquip;
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