//
//  Created by Bassoch & Palmieri on 22/03/2016.
//  Copyright (c) 2016. All rights reserved.
//

#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <ratio>
#include <ctime>
#include <mutex>
#include <math.h>


#include "../headers/strategie.h"
#include "../headers/calculer_odometrie.h"
#include "../headers/protocole_com_serie.h"
#include "../headers/eqep.h"
#include "../headers/comMoteur.h"
#include "../headers/commandes_actionneurs.h"
#include "../headers/deplacement.h"


// fonction stratégie pour homologation

using namespace std;

void strategie(int valCapteur[7]){
    int vitesseDeplacement(150),vitesseApproche(100);
    float tabOdometrie[]={0,0,0,0,0,0,0};
    const float angle1=M_PI/4;
    int sleeping_time = 250;
    cout<<"début du déplacement"<<endl;

    tabOdometrie[0]=0;
    tabOdometrie[1]=0;
    tabOdometrie[2]=0;


if ( valCapteur[8]==0) // violet
{

//----------POUSSER LES PLOTS----------
sortir_les_bras_coquillage();
this_thread::sleep_for(chrono::milliseconds(sleeping_time));

asserTourner(-8.5,0.4,1,tabOdometrie,valCapteur);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));

ligneDroite(0.9,0.5,1,tabOdometrie,valCapteur,1);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));

ligneDroite(0.450,0.5,-1,tabOdometrie,valCapteur,1);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));

rentrer_les_bras_coquillage();
this_thread::sleep_for(chrono::milliseconds(sleeping_time));

//----------FERMER LES PORTES----------/

asserTourner(-60,0.4,1,tabOdometrie,valCapteur);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
// je recule vers la première porte
ligneDroite(0.85,0.5,-1,tabOdometrie,valCapteur,0);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
// je vais vers la deuxieme porte
ligneDroite(0.15,0.5,1,tabOdometrie,valCapteur,0);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
// Tourner pour aller à la deuxième porte
asserTourner(90,0.4,1,tabOdometrie,valCapteur);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));

ligneDroite(0.30,0.5,-1,tabOdometrie,valCapteur,0);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));

asserTourner(-90,0.4,1,tabOdometrie,valCapteur);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
//Reculer vers la deuxième porte
ligneDroite(0.3,0.5,-1,tabOdometrie,valCapteur,0);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));

//----------JE VAIS A LA PECHE ----------
// Je me degage de la porte
ligneDroite(0.06,0.4,1,tabOdometrie,valCapteur,0);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
// je m'oriente pour traverser la carte
asserTourner(6,0.4,1,tabOdometrie,valCapteur);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
//Je bourrine sur la moitie de la carte
ligneDroite(0.66,0.4,1,tabOdometrie,valCapteur,1);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));

// je fais un quart de tour pour retourner en zone de depart
asserTourner(83,0.4,1,tabOdometrie,valCapteur);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
// je recule en zone de depart
ligneDroite_fin_course(0.65,0.3,-1,tabOdometrie,valCapteur,1);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));

// j'avance pour retourner vers le bac à poissons
ligneDroite(0.37,0.4,1,tabOdometrie,valCapteur,1);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
// je moriente pour aller pecher
asserTourner(78,0.4,1,tabOdometrie,valCapteur);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
// jarrive au bout de la carte
ligneDroite_fin_course(1.4,0.4,-1,tabOdometrie,valCapteur,1);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
// je ravance pour me positionner
ligneDroite(0.08,0.4,1,tabOdometrie,valCapteur,1);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
// je tourne pour sortir les bras a poissons
asserTourner(-67,0.4,1,tabOdometrie,valCapteur);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));

ligneDroite(0.04,0.4,1,tabOdometrie,valCapteur,1);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
//Je sors mon bras
sortir_bras_poisson_droit(valCapteur);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));

// 1er passage sur les poissons
ligneDroite(0.25,0.4,1,tabOdometrie,valCapteur,0);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
// je rentre les bras
rentrer_bras_poisson_droit (valCapteur);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
//petit angle
asserTourner(4,0.4,1,tabOdometrie,valCapteur);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
// je vais vers les filet
ligneDroite(0.4,0.4,1,tabOdometrie,valCapteur,0);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
//je sors le bras
sortir_bras_poisson_droit(valCapteur);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
// je racle les poissons
asserTourner(75,0.4,1,tabOdometrie,valCapteur);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
// je rentre les bras
rentrer_bras_poisson_droit(valCapteur);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
// je tourne pour me recalibrer sur les poissons
asserTourner(7,0.4,1,tabOdometrie, valCapteur);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
// je me calibre sur les poissons
ligneDroite(0.15,0.4,-1,tabOdometrie,valCapteur,1);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
// javance pour attrapper les coquillages
ligneDroite(0.3,0.4,1,tabOdometrie,valCapteur,1);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));

asserTourner(83,0.4,1,tabOdometrie,valCapteur);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));

sortir_les_bras_coquillage();
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
// javance pour recuperer les coquillages
ligneDroite(0.89,0.4,1,tabOdometrie,valCapteur,1);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
// je tourne pour aller en zone de depart
asserTourner(-76,0.4,1,tabOdometrie,valCapteur);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
// je retourne en zone de depart
ligneDroite(0.4,0.3,1,tabOdometrie,valCapteur,1);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));

ligneDroite(0.2,0.3,-1,tabOdometrie,valCapteur,1);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));

}else
 { // vert
sortir_les_bras_coquillage();
this_thread::sleep_for(chrono::milliseconds(sleeping_time));

asserTourner(8.5,0.4,1,tabOdometrie,valCapteur);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));

ligneDroite(0.9,0.4,1,tabOdometrie,valCapteur,1);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));

ligneDroite(0.450,0.5,-1,tabOdometrie,valCapteur,1);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));

rentrer_les_bras_coquillage();
this_thread::sleep_for(chrono::milliseconds(sleeping_time));

//----------FERMER LES PORTES----------/

asserTourner(58,0.4,1,tabOdometrie,valCapteur);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));

ligneDroite(0.85,0.5,-1,tabOdometrie,valCapteur,0);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
// je vais vers la deuxieme porte
ligneDroite(0.2,0.5,1,tabOdometrie,valCapteur,0);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
// Tourner pour aller à la deuxième porte
asserTourner(-85,0.4,1,tabOdometrie,valCapteur);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));

ligneDroite(0.25,0.5,-1,tabOdometrie,valCapteur,0);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));

asserTourner(90,0.4,1,tabOdometrie,valCapteur);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
//Reculer vers la deuxième porte
ligneDroite(0.35,0.5,-1,tabOdometrie,valCapteur,0);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));


//----------JE VAIS A LA PECHE ----------
// Je me degage de la porte
ligneDroite(0.05,0.4,1,tabOdometrie,valCapteur,0);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
// je m'oriente pour traverser la carte
asserTourner(-5,0.4,1,tabOdometrie,valCapteur);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
//Je bourrine sur la moitie de la carte
ligneDroite(0.7,0.4,1,tabOdometrie,valCapteur,1);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));

// je fais un quart de tour pour retourner en zone de depart
asserTourner(-64,0.4,1,tabOdometrie,valCapteur);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
// je recule en zone de depart
ligneDroite_fin_course(0.60,0.3,-1,tabOdometrie,valCapteur,1);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));

// j'avance pour retourner vers le bac à poissons
ligneDroite(0.38,0.4,1,tabOdometrie,valCapteur,1);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
// je moriente pour aller pecher
asserTourner(-73,0.4,1,tabOdometrie,valCapteur);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
// jarrive au bout de la carte
ligneDroite_fin_course(1.2,0.45,-1,tabOdometrie,valCapteur,1);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));

// je ravance pour me positionner
ligneDroite(0.1,0.4,1,tabOdometrie,valCapteur,1);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
// je tourne pour sortir les bras a poissons
asserTourner(-72,0.4,1,tabOdometrie,valCapteur);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));

ligneDroite(0.08,0.4,-1,tabOdometrie,valCapteur,1);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
//Je sors mon bras
sortir_bras_poisson_droit(valCapteur);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));

// 1er passage sur les poissons
ligneDroite(0.25,0.4,-1,tabOdometrie,valCapteur,1);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
// je rentre les bras
rentrer_bras_poisson_droit (valCapteur);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
//petit angle
asserTourner(-4,0.4,1,tabOdometrie,valCapteur);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
// je vais vers les filet
ligneDroite(0.6,0.4,-1,tabOdometrie,valCapteur,1);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
//je sors le bras
sortir_bras_poisson_droit(valCapteur);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
// je racle les poissons
asserTourner(100,0.4,1,tabOdometrie,valCapteur);//-75
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
// je rentre les bras
rentrer_bras_poisson_droit(valCapteur);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
// je tourne pour me recalibrer sur les poissons
asserTourner(-15,0.4,1,tabOdometrie, valCapteur);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
// je me calibre sur les poissons
ligneDroite(0.3,0.4,-1,tabOdometrie,valCapteur,1);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
// javance pour attrapper les coquillages
ligneDroite(0.3,0.4,1,tabOdometrie,valCapteur,1);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));

asserTourner(-66,0.4,1,tabOdometrie,valCapteur);//-83
this_thread::sleep_for(chrono::milliseconds(sleeping_time));

sortir_les_bras_coquillage();
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
// javance pour recuperer les coquillages
ligneDroite(1.09,0.4,1,tabOdometrie,valCapteur,1);//ici
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
// je tourne pour aller en zone de depart
asserTourner(78,0.4,1,tabOdometrie,valCapteur);
this_thread::sleep_for(chrono::milliseconds(sleeping_time));
// je retourne en zone de depart
ligneDroite(0.65,0.3,1,tabOdometrie,valCapteur,1);//0.4
this_thread::sleep_for(chrono::milliseconds(sleeping_time));

  }

}
