#include <iostream>
#include "map.h"

using namespace std;

int main(int argc, char **argv) {

    Map board(10);
    int argent = 1500;
    int vie = 3;
    string instruction;

    // Affichage du titre, des règles et du menu
    cout << "\n- - - - - - - - - - - - - - - - - - - - - -" << endl
         << "-      Jeu exceptionnel tres original     - " << endl
         << "- - - - - - - - - - - - - - - - - - - - - -\n" << endl;
    cout
            << "REGLES DU JEU : "
            << "Positionnez vos tourelles ('T') de sorte a empecher les ennemies ('E') d'arriver a gauche de la map, si 3 ennemis arrivent a passer, c'est la fin de la partie !"
            << endl
            << "Chaque tourelle vous coutera 250 et vous recuperez 150 si vous la detruisez vous meme, vous gagnez aussi de l'argent a la fin de chaque vague"
            << endl << "C'est compris ? alors tapez 'n' pour debuter une nouvelle partie !" << endl;
    cin >> instruction;
    if (instruction == "n") {
        // La boucle du jeu
        while (vie > 0) {

            board.print(cout);
            srand(time(NULL));

            cout << "Votre budget est de " << argent << endl;
            cout << "Il vous reste " << vie << " vies \n\n" << endl;
            cout << "Entrez 'p' pour placer des tourelles" << endl;
            cout << "Entrez 's' pour supprimer des tourelles" << endl;
            cout << "Entrez 'v' pour lancer la premiere vague" << endl;
            cout << "Entrez 'a' pour avancer la premiere vague" << endl;
            cin >> instruction;
            if (instruction == "p") {
                argent = board.ajouterTourelle(argent);
            } else if (instruction == "s") {
                argent = board.supprimerTourelle(argent);
            } else if (instruction == "v") {
                board.apparitionEnnemie();
            } else if (instruction == "a") {
                vie = board.avancerEnnemie(vie);
            }
        }
    }

}