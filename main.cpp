#include <iostream>
#include "map.h"

using namespace std;

int main(int argc, char **argv) {

    Map board(10);
    string instruction;

    // Boucle du jeu
    while (true) {
        // Affichage du titre, des règles et du menu
        cout << "\n\t\t- - - - - - - - - - - - - - - - - - - - - -" << endl
             << "\t\t-      Jeu exceptionnel tres original     - " << endl
             << "\t\t- - - - - - - - - - - - - - - - - - - - - -\n" << endl;
        cout
                << "REGLES DU JEU : "
                << "Positionnez vos tourelles ('T') de sorte a empecher les ennemies ('E') d'arriver a gauche de la map, si 3 ennemis arrivent a passer, c'est la fin de la partie !"
                << endl
                << "Chaque tourelle vous coutera 250 et vous recuperez 150 si vous la detruisez vous meme, vous gagnez aussi 50 pour chaque ennemie tue et 300 tous les 3 tours a la fin de chaque vague"
                << endl << "C'est compris ? alors tapez 'n' pour debuter une nouvelle partie !" << endl;
        cin >> instruction;
        if (instruction == "n") {
            // La boucle de la partie
            int argent = 1000;
            int vie = 3;
            board.nouvellePartie();
            while (vie > 0) {

                board.afficher();
                srand(time(NULL));

                cout << "\tVotre budget est de " << argent << endl;
                cout << "\tIl vous reste " << vie << " vies \n\n" << endl;
                cout << "Entrez '0' pour placer une bombe" << endl;
                cout << "Entrez '1' pour placer une tourelle" << endl;
                cout << "Entrez '2' pour supprimer une tourelle" << endl;
                cout << "Entrez '3' pour lancer la premiere vague" << endl;
                cin >> instruction;
                if (instruction == "0") {
                    argent = board.poserBombe(argent);
                } else if (instruction == "1") {
                    argent = board.ajouterTourelle(argent);
                } else if (instruction == "2") {
                    argent = board.supprimerTourelle(argent);
                } else if (instruction == "3") {
                    // La fonction vague renvoie plusieurs variables donc on utilise un tuple pour les attribuer
                    tuple<int, int> vieArgent(vie, argent);
                    vieArgent = board.vague(vie, argent);
                    vie = get<0>(vieArgent);
                    argent = get<1>(vieArgent);
                }
            }
            cout << "Game Over" << endl;
        }
    }
}