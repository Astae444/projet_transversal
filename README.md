# projet_transversal
Projet transversal C++


#include <iostream>
#include <vector>

using namespace std;

int ligne = 5;
int colonne = 25;
vector<vector<string> > map;
string cases = " . ";

void creer_map() {
for (int i = 0; i < ligne; i++) {
vector<string> v1;

        for (int j = 0; j < colonne; j++) {
            v1.push_back(cases);
        }

        map.push_back(v1);
    }
}


void afficher(vector<vector<string> > map) {
for (int i = 0; i < map.size(); i++) {
for (int j = 0; j < map[i].size(); j++)
cout << map[i][j] << " ";
cout << endl;
}
}
