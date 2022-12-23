#include <iostream>
#include <string>

using namespace std;

class Weapon {
    friend class Characteristic; 
private:
    string name; 
    float damage;
    float weight;

public:

    string getName() { 
        return name;
    }

    float getDamage() { 
        return damage;
    }

    float getWeight() { 
        return weight;
    }

    void setDamage(float addDamage) { 
        damage = addDamage;
    }

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

class Characteristic { 
private:
    float strength; 

public:
    Characteristic(float strength) {
        this->strength = strength;
    };

    float getDamage(Weapon weapon) { 
        return (weapon.getDamage() + strength);
    }
};

class MyMath { 
public:
    static int counter; 

    static void Add() { 
        counter++; 
    };
    static void Sub() { 
        counter++;
    };
    static void Mult() { 
        counter++;
    };
    static void Div() { 
        counter++; 
    };
};

int MyMath::counter = 0;

int main()
{
    setlocale(LC_ALL, "");

    Weapon sword("Меч", 20, 15);
    //cout << "Новое оружие: название - " << sword.name << endl; 
    cout << "Weapon: " << sword.getName() << ", damage - " << sword.getDamage() << ", weight - " << sword.getWeight() << endl;

    sword.setDamage(10);
    cout << "урон оружия " << sword.getName() <<
        " " << sword.getDamage() << endl;

    Weapon spear("Копье", 7, 2);
    Characteristic ch = Characteristic(9);
    cout << "Сумма силы - " <<
        ch.getDamage(spear) << endl;

    MyMath::Add();
    MyMath::Sub();
    MyMath::Mult();
    MyMath::Div();

    /*
    cout << "Add(сложение) 2 + 9 = " << MyMath.Add() << endl;
    cout << "Sub(вычитание) 6 - 1 = " << MyMath.Sub() << endl;
    cout << "Mult(умножение) 2 * 2 = " << MyMath.Mult() << endl;
    cout << "Div(деление) 9 / 3 = " << MyMath.Div() << endl;
    */

    cout << "Методы класса MyMath вызваны - " << MyMath::counter << " раз." << endl;
}