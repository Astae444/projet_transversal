#include <iostream>
#include "map.h"

using namespace std;

int main(int argc, char **argv) {
    Map board(10);
    int argent = 1500;

    cout << "- - - - - - - - - - - - - - - - - - - -" << endl << " -   Jeu exceptionnel tres original   - " << endl << "- - - - - - - - - - - - - - - - - - - -";
    // La boucle du jeu
    while(true)
    {
        board.print(cout);
        srand(time(NULL));
        string instruction;

        cout << "Votre budget est de " << argent << endl << endl;
        cout << "Entrez 'p' pour placer des tourelles" << endl;
        cout << "Entrez 's' pour supprimer des tourelles" << endl;
        cout << "Entrez 'v' pour lancer la premiere vague" << endl;
        cout << "Entrez 'a' pour lancer la premiere vague" << endl;
        cin >> instruction;
        if (instruction == "p") {
            argent = board.ajouterTourelle(argent);
        } else if (instruction == "s") {
            argent = board.supprimerTourelle(argent);
        } else if (instruction == "v") {
            board.apparitionEnnemie();
        } else if (instruction == "a") {
            board.avancerEnnemie();
        }

        // other game logic...
    }

    // On affiche le board une dernière fois avant de quitter le jeu
    cout << "Game over. Final board: \n";
    board.print(cout);

}