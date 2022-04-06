#include <iostream>
#include "map.cpp"
#include "argent.cpp"
#include "ennemie.cpp"

using namespace std;

int main(int argc, char **argv) {
    Map* map = new Map("infini", 6, 20);
    map->afficher();
    while (true) {
        string instruction;
        cout << "Votre budget est de " << argent << endl;
        cout << "Entrez 'p' pour placer des tourelles" << endl;
        cout << "Entrez 'd' pour detruire des tourelles" << endl;
        cout << "Entrez 'v' pour lancer la premiere vague" << endl;
        cin >> instruction;
        if (instruction == "p") {

        } else if (instruction == "d") {

        } else if (instruction == "v") {

        }
    }
}
