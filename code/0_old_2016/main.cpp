#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <ratio>
#include <ctime>


#include "protocole_com_serie.h"
#include "eqep.h"
#include "comMoteur.h"
#include "commandes_actionneurs.h"
#include "strategie.h"


using namespace std;


//Références aux variables globales déclarées dans variables_globales.h

using namespace std;

int main()
{
    int valCapteur[]={0,0,0,0,0,0,1,0,0,0};
    //Initialisation
    std::cout << protocole_com_serie_init() << std::endl;
    initialiser_actionneurs(valCapteur);
    while (valCapteur[6]==1) {
        receptionserie(valCapteur);
        
        //        debug:
        //        cout<<"capteur départ: "<<valCapteur[6]<<endl;
        //        this_thread::sleep_for(chrono::milliseconds(500));
    }
    cout<<"début partie"<<endl;
    
    thread threadStrategie(strategie,valCapteur);
    this_thread::sleep_for(chrono::seconds(89));
    comMotDroit(0);
    comMotGauche(0);
    comMotAscenseur(0);
    return 0;
}

