#ifndef POTION_H
#define POTION_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>


using namespace std;

struct Potion {
    string name;
    string description;
    char type;
    double effect_value = 0;
    char element;
    double price;
    int quantity;
};

#endif