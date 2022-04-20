#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <tuple>

using namespace std;
using namespace this_thread;
using namespace chrono;

class Map {
private:
    vector<vector<string>> jardin;

public:
    // On initialise la grille pour qu'elle ait la bonne taille et qu'elle soit remplie par des espaces
    Map(int taille) : jardin(taille, vector<string>(taille, " ")) {}


    void afficher(ostream &out) const {
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
        cout << endl << endl;
    }


    string GetValue(int ligne, int colonne) const {
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


    int avancerEnnemie(int vie) {
        for (int i = 0; i < jardin.size() - 3; i++) {
            for (int j = 0; j < jardin[i].size(); j++) {
                if (jardin[i][j] == "E") {
                    jardin[i][j] = " ";
                    if (j > 0) {
                        jardin[i][j - 1] = "E";
                    } else if (j == 0) {
                        vie = vie - 1;
                    }
                }
            }
        }
        return vie;
    }


    void tirer() {
        for (int i = 0; i < jardin.size() - 3; i++) {
            for (int j = 0; j < jardin[i].size(); j++) {
                if (jardin[i][j] == "T") {
                    if (jardin[i][j + 1] == "T") {
                        jardin[i][j + 3] = "-";
                    } else {
                        jardin[i][j + 1] = "-";
                    }
                }
            }
        }
    }


    int avancerProjectile(int argent) {
        for (int i = 0; i < jardin.size() - 3; i++) {
            for (int j = jardin.size() - 3; j > 0; j--) {
                if (jardin[i][j] == "-") {
                    jardin[i][j] = " ";
                    // On vérifie la présence éventuelle d'ennemie ou de tourelle sur la colonne suivante
                    if (jardin[i][j + 1] == "E") {
                        jardin[i][j + 1] = " ";
                        argent = argent + 50;
                    } else if (jardin[i][j + 1] == "T") {
                        jardin[i][j + 2] = "-";
                    }
                    else {
                        jardin[i][j + 1] = "-";
                    }
                }
            }
        }
        return argent;
    }


    tuple<int, int> vague(int vie, int argent) {
        int tour = 0;
        for (int i = 0; i < 3; ++i) {
            apparitionEnnemie();
            apparitionEnnemie();
            if (tour % 3 == 0) {
                tirer();
            }
            afficher(cout);
            sleep_for(1s);
            vie = avancerEnnemie(vie);
            argent = avancerProjectile(argent);
            tour = tour + 1;
        }
        argent = argent + 300;
        tuple<int, int> vieArgent(vie, argent);
        return vieArgent;
    }

};