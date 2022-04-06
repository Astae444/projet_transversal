#include <iostream>

using namespace std;

int ligne = 5;
int colonne = 25;

class Map {
private:
    string niveau;

protected:
    int ligne;
    int colonne;

public:
    Map(string niveau, int ligne, int colonne) {
        this->niveau = niveau;
        this->ligne = ligne;
        this->colonne = colonne;
    }

    void afficher() {
        int num_ligne = 1;
        cout << "Niveau " << this->niveau << " : " << endl;
        cout << "      A     B     C     D     E     F     G     H     I     J     K     L     M     N     O     P     Q     R     S\n\n";
        for (int i = 0; i < Map::ligne; ++i) {
            cout << num_ligne << endl << endl;
            num_ligne = num_ligne + 1;
        }
    }
};