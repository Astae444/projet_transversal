#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Map {
protected:
    vector<vector<string>> jardin;

public:
    // On initialise la grille pour qu'elle ait la bonne taille et qu'elle soit remplie par des 0
    Map(int taille) : jardin(taille, vector<string>(taille, " ")) {}


    void print(ostream &out) const {
        out << endl << "\n\tMode infini\n\t";
        // On affiche la ligne définissant les coordonnées de chaque colonne
        for (int i = 0; i < jardin.size(); i++) {
            out << i << "    ";
        }
        // On affiche le reste des lignes
        out << "\n\n";
        // Cette boucle définit le nombre de lignes du jeu
        for (int i = 0; i < jardin.size() - 3; i++) {
            out << i << "\t";
            for (int j = 0; j < jardin[i].size(); j++) {
                out << jardin[i][j] << "    ";
            }
            out << "\n";
        }
        cout << endl;
    }

    string GetValue(int ligne, int colonne) const {
        // use wraparound for too-large values
        // alternatively you could throw if row and/or col are too large
        return jardin[ligne % jardin.size()][colonne % jardin.size()];
    }

    int ajouterTourelle(int argent) {
        if (argent >= 250) {
            cout << "\nEntrez la ligne: ";
            int ligne;
            cin >> ligne;
            while (ligne > 6 or ligne < 0 or !cin) { // On vérifie s'il y a bien un input de l'utilisateur
                cout << "\nEntrez une ligne correcte: ";
                cin >> ligne;
            }
            cout << "Entrez la colonne: ";
            int colonne;
            cin >> colonne;
            while (colonne > 9 or colonne < 0) { // On vérifie s'il y a bien un input de l'utilisateur
                cout << "Entrez une colonne correcte: ";
                cin >> colonne;
            }
            jardin[ligne % jardin.size()][colonne % jardin.size()] = "T";
            argent = argent - 250;
        } else {
            cout << endl << "ERREUR : Il vous faut 250 pour pouvoir construire une tourelle" << endl;
        }
        return argent;
    }

    int supprimerTourelle(int argent) {
        cout << "\nEntrez la ligne: ";
        int ligne;
        cin >> ligne;
        while (ligne > 6 or ligne < 0 or !cin) { // On vérifie s'il y a bien un input de l'utilisateur
            cout << "\nEntrez une ligne correcte: ";
            cin >> ligne;
        }
        cout << "Entrez la colonne: ";
        int colonne;
        cin >> colonne;
        while (colonne > 9 or colonne < 0) { // On vérifie s'il y a bien un input de l'utilisateur
            cout << "Entrez une colonne correcte: ";
            cin >> colonne;
        }
        if (jardin[ligne % jardin.size()][colonne % jardin.size()] == "T") {
            jardin[ligne % jardin.size()][colonne % jardin.size()] = " ";
            argent = argent + 150;
        } else {
            cout << endl << "ERREUR : Il n'y a pas de tourelle a cet emplacement" << endl;
        }
        return argent;
    }

    void apparitionEnnemie() {
        int ligne = rand() % 7;
        jardin[ligne][9] = "E";
    }

    void avancerEnnemie() {
        for (int i = 0; i < jardin.size() - 3; i++) {
            for (int j = 0; j < jardin[i].size(); j++) {
                if (jardin[i][j] == "E") {
                    jardin[i][j] = " ";
                    jardin[i][j - 1] = "E";
                }
            }
        }
    }

};