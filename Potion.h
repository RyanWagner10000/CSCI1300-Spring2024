#ifndef POTION_H
#define POTION_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Potion {
    string name;
    char type;
    double effect_value = 0;
    double price;
    int quantity;
};

#endif