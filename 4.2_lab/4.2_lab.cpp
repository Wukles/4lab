#include <iostream>
#include <string>

using namespace std;

class Weapon {
public:
    string name;
    float damage;
    float weight;

    Weapon(string name, float damage, float weight) {
        this->name = name;
        this->damage = damage;
        this->weight = weight;
    };

    Weapon() : Weapon("Пистолет", 5, 1) {};

    ~Weapon() { 
        
        cout << "Weapon: " << name << ", damage - " << damage << ", weight - " << weight;
        cout << " // удален" << endl;
    };

    bool canlift(float maxWeight) { 
        if (maxWeight < weight) return true;
        return false;
    };

    float sumWeights(float addedWeight) { 
        return (weight + addedWeight);
    };

    float sumWeights(Weapon* addedWeapon) { 
        return sumWeights((*addedWeapon).weight);
    };
};

int main()
{
    setlocale(LC_ALL, "");

    Weapon gun;
    cout << "Weapon: " << gun.name << ", damage - " << gun.damage << ", weight - " << gun.weight << endl;

    Weapon* boomerang = new Weapon("Бумеранг", 30, 5);
    cout << "Weapon: " << (* boomerang).name << ", damage - " << (*boomerang).damage << ", weight - " << (*boomerang).weight << endl;

    cout << "Можно поднять бумеранг (4) - " << boolalpha << (*boomerang).canlift(4) << endl;

    cout << "Вес бумерагна и пистолета - " << (*boomerang).sumWeights(&gun) << endl;

    cout << "Вес бумерагна и пистолета - " << gun.sumWeights((*boomerang).weight) << endl;

    cout << "Бумеранг и дополнительный вес (11) - " << (*boomerang).sumWeights(11) << endl;

    cout << "Вес бумерагна и пистолета - " << gun.sumWeights(boomerang) << endl;

    delete boomerang;
}