#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    cout << "Hello, World!" << endl;
    return 0;
}

class Tourelle {
protected:
public:
    int vieMax;
    int vie;
    int attaque;

};

class Monstre {
protected:
public:
    int vieMax;
    int vie;
    int attaque;
    int vitesse;

};

class Argent {
    int vie = 50;

};

class Soin {
    int vie = 50;

};

class Mittraillette {
    int vie = 100;
    int degats = 5;
    int range = 5;

};

class Sniper {
    int vie = 100;
    int degats = 3;
    int range = 8;

};

class Shotgun {
    int vie = 100;
    int degats = 10;
    int range = 3;

};

class Minion {
    int vie = 25;
    int degats = 10;
    int vitesse = 1;

};

class Boss {
    int vie = 50;
    int degats = 20;
    int vitesse = 2;

};
