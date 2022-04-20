#include <iostream>
#include <cstdlib>
#include <vector>
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


    // La fonction permettant de remettre à 0 le jardin pour commencer une nouvelle partie
    void nouvellePartie() {
        for (int i = 0; i < jardin.size() - 3; ++i) {
            for (int j = 0; j < jardin.size(); ++j) {
                jardin[i][j] = " ";
            }
        }
    }

    void afficher() {
        cout << endl << "\n\tMode infini\n\t";
        // On affiche la ligne définissant les coordonnées de chaque colonne
        for (int i = 0; i < jardin.size(); i++) {
            cout << i << "    ";
        }
        // On affiche le reste des lignes
        cout << "\n\n";
        // Cette boucle définit le nombre de lignes du jeu
        for (int i = 0; i < jardin.size() - 3; i++) {
            cout << i << "\t";
            for (int j = 0; j < jardin[i].size(); j++) {
                cout << jardin[i][j] << "    ";
            }
            cout << "\n";
        }
        cout << endl << endl;
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


    int poserBombe(int argent) {
        if (argent >= 300) {
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
            jardin[ligne % jardin.size()][colonne % jardin.size()] = "B";
            argent = argent - 300;
        } else {
            cout << endl << "ERREUR : Il vous faut 300 pour pouvoir construire une bombe" << endl;
        }
        return argent;
    }


    int exploser(int argent) {
        for (int i = 0; i < jardin.size() - 3; i++) {
            for (int j = 0; j < jardin[i].size(); j++) {
                if (jardin[i][j] == "B") {
                    if (jardin[i][j + 1] == "E") {
                        jardin[i][j + 1] = " ";
                        argent = argent + 50;
                    }
                    if (jardin[i][j - 1] == "E") {
                        jardin[i][j - 1] = " ";
                        argent = argent + 50;
                    }
                    if (jardin[i + 1][j] == "E") {
                        jardin[i + 1][j] = " ";
                        argent = argent + 50;
                    }
                    if (jardin[i - 1][j + 1] == "E") {
                        jardin[i - 1][j + 1] = " ";
                        argent = argent + 50;
                    }
                    jardin[i][j] = " ";
                }
            }
        }
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


    // La fonction qui fait tirer des projectiles aux tourelles, on s'assure que les projectiles tirés ne viennent pas
    // détruire une tourelle qui suivrait la première et que le projectile tuerait bien l'ennemie s'il venait à apparaître sur lui
    int tirer(int argent) {
        for (int i = 0; i < jardin.size() - 3; i++) {
            for (int j = 0; j < jardin[i].size(); j++) {
                if (jardin[i][j] == "T") {
                    if (jardin[i][j + 1] == "T") {
                        jardin[i][j + 3] = "-";
                    } else if (jardin[i][j + 1] == "E") {
                        jardin[i][j + 1] = " ";
                        argent = argent + 50;
                    } else {
                        jardin[i][j + 1] = "-";
                    }
                }
            }
        }
        return argent;
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
                    } else {
                        jardin[i][j + 1] = "-";
                    }
                }
            }
        }
        return argent;
    }


    // La fonction vague retournera un tuple, car elle prend en compte toutes les fonctions précédentes
    // donc certaines qui utilisent la notion d'argent et d'autre de vie
    tuple<int, int> vague(int vie, int argent) {
        int tour = 0;
        for (int i = 0; i < 3; ++i) {
            // On vérifie que le joueur a encore des vies avant de relancer un tour
            if (vie > 0) {
                // 2 Ennemis maximums apparaissent par tour
                apparitionEnnemie();
                apparitionEnnemie();
                // Les tourelles tirent tous les 3 tours
                if (tour % 2 == 0) {
                    argent = tirer(argent);
                }
                argent = exploser(argent);
                afficher();
                // On attend une seconde pour laisser au joueur le temps de comprendre la partie
                sleep_for(1s);
                vie = avancerEnnemie(vie);
                argent = avancerProjectile(argent);
                tour = tour + 1;
            }
        }
        argent = argent + 300;
        tuple<int, int> vieArgent(vie, argent);
        return vieArgent;
    }

};