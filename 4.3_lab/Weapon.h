#pragma once
#include <iostream>
using namespace std;

class Weapon
{
public:
    string name;
    float damage;
    float weight;

    Weapon(string name, float damage, float weight);

    Weapon();

    ~Weapon();

    bool canlift(float maxWeight);

    float sumWeights(float addedWeight);

    float sumWeights(Weapon* addedWeapon);
};

