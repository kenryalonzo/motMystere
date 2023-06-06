#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

#include "jeu.hpp"

using namespace std;

void melangerlettres(string *mot)
    {
        string melange;
        int position(0);
        cout << *mot << endl;

        // Tant qu'on n'as pas extrait tout les lettres du mot, on fat :
        while (mot -> size() != 0)
        {
            // on choisir un numero de lettre u harsard dans le mot
            position = rand() % mot -> size();
            // on ajoute la lettre dans le mot a melanger
            melange += mot -> at(position);
            // on retire cette lettre du mot mystere
            // pour ne pas la prendre une deuxieme fois
            mot -> erase(position, 1);
        }

        // on assigne le mot melanger au pointeur
        *mot = melange;

    }

int main()
{
    string motMystere, motUtilisateur;
    string *motMelange(nullptr);

    // Initialiasation des nombres aleatoires

    // 1- on demande se saisir un mot
    cout << "Saisissez un mot a l'abri des regards : " << endl;
    cin >> motMystere;

    motMelange = new string(motMystere);

    // 2- on recupere le mot avec les lettres nelanger dans motMelange
    melangerlettres(motMelange);

    // 3- on demande a l'utilisateur quel est le mot mystere
    while (motUtilisateur != motMystere)
    {
        cout << "Quel est ce mot ? " << *motMelange << endl;
        cin >> motUtilisateur;
        if (motUtilisateur == motMystere)
        {
            cout << "Bravo vous avez devinez c'est le bon mot !!!" << endl;
        }
        else
        {
            cout << "Ce n'est pas grave vous ferez mieu la prochaine manche" << endl;
        }
        
    }
    // on recomance tant qu'i n'as pas trouver

    delete motMelange;

    return 0;
}