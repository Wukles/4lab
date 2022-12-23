#include "Weapon.h"
#include <string>

Weapon::Weapon(string name, float damage, float weight) {
    this->name = name;
    this->damage = damage;
    this->weight = weight;
};

Weapon::Weapon() : Weapon("Пистолет", 5, 1) {};

Weapon::~Weapon() {

    cout << "Weapon: " << name << ", damage - " << damage << ", weight - " << weight;
    cout << " // удален" << endl;
};

bool Weapon::canlift(float maxWeight) {
    if (maxWeight < weight) return true;
    return false;
};

float Weapon::sumWeights(float addedWeight) {
    return (weight + addedWeight);
};

float Weapon::sumWeights(Weapon* addedWeapon) {
    return sumWeights((*addedWeapon).weight);
};
