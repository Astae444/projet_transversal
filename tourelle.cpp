#include <iostream>
#include <vector>

using namespace std;

class Tourelle {
private:
    string nom;
    int prix;

protected:
    int x;
    int y;

public:
    Tourelle(string nom, int x, int y) {
        this->nom = nom;
        this->x = x;
        this->x = y;
    }
};