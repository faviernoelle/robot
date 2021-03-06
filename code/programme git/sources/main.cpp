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
    //Initialisation
    std::cout << protocole_com_serie_init() << std::endl;
    initialiser_actionneurs(valCapteur);

    while (valCapteur[7]==1) {
        receptionserie(valCapteur);
        //        debug:
        //        cout<<"capteur départ: "<<valCapteur[6]<<endl;
        //        this_thread::sleep_for(chrono::milliseconds(500));
    }


    cout<<"début partie,tirette enlevée"<<endl;

    thread threadStrategie(strategie,valCapteur);
    this_thread::sleep_for(chrono::seconds(90));
    comMotDroit(0);
    comMotGauche(0);
    funnyAction2017();


    return 0;
}
