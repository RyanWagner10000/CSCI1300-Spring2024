#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Equipment {
    string name;
    string description;
    char type;
    char element;
    double damage;
    double defense;
    double price;
};

#endif