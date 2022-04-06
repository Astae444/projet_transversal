#include <iostream>
#include <vector>

using namespace std;

class Tourelle {
private:
    string nom;

protected:
    int position;


public:
    Tourelle(string nom, int position) {
        this->nom = nom;
        this->position = position;
    }
};