#include <iostream>
#include "Weapon.h"

int main()
{
    setlocale(LC_ALL, "");
    
    Weapon gun;
    cout << "Weapon: " << gun.name << ", damage - " << gun.damage << ", weight - " << gun.weight << endl;

    Weapon* boomerang = new Weapon("Бумеранг", 30, 5);
    cout << "Weapon: " << (*boomerang).name << ", damage - " << (*boomerang).damage << ", weight - " << (*boomerang).weight << endl;

    cout << "Можно поднять бумеранг (4) - " << boolalpha << (*boomerang).canlift(4) << endl;

    cout << "Вес бумерагна и пистолета - " << (*boomerang).sumWeights(&gun) << endl;

    cout << "Вес бумерагна и пистолета - " << gun.sumWeights((*boomerang).weight) << endl;

    cout << "Бумеранг и дополнительный вес (11) - " << (*boomerang).sumWeights(11) << endl;

    cout << "Вес бумерагна и пистолета - " << gun.sumWeights(boomerang) << endl;

    delete boomerang;
}


