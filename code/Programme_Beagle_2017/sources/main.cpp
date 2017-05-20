#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <ratio>
#include <ctime>
#include <fstream>
#include <time.h>
#include <cmath>

#include "../headers/calculer_odometrie.h"
#include "../headers/protocole_com_serie.h"
#include "../headers/eqep.h"
#include "../headers/comMoteur.h"
#include "../headers/commandes_actionneurs.h"
#include "../headers/strategie.h"

using namespace std;




int main()
{
    int valCapteur[]={0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0};

    // Initialisation ///////////////////////////////////
    std::cout << protocole_com_serie_init() << std::endl;
    initialiser_actionneurs(valCapteur);

    cout<<"Fin Initialisation"<<endl;

    // Boucle de départ : tant que le fil bleu n'est pas tiré, on attend

    while (valCapteur[7]==1) {
        receptionserie(valCapteur);
    }

    /////////////////////////////////////////////////////
    cout<<"fil bleu tiré - stratégie lancée"<<endl;

    thread threadStrategie(strategie,valCapteur);
    this_thread::sleep_for(chrono::seconds(90)); // Au bout de 90 sec. on arrete tout
    comMotDroit(0);
    comMotGauche(0);
    
    /////////////////////////////////////////////////////
    funny_action(); // On lance la funny action

    return 0;
}
