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
};

int main()
{
    setlocale(LC_ALL, "");

    Weapon fireball = Weapon("Огненный шар", 50, 10);
    Weapon gun;

    cout << "Fireball: " << fireball.name << ", damage - " << fireball.damage << ", weight - " << fireball.weight << endl;
    cout << "Gun: " << gun.name << ", damage - " << gun.damage << ", weight - " << gun.weight << endl;

}
