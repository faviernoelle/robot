//
//  strategie.cpp
//  homologation
//
//  Created by Sylvain Richard on 09/05/2015.
//  Copyright (c) 2015 Sylvain Richard. All rights reserved.
//

#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <ratio>
#include <ctime>
#include <mutex>
#include <math.h>


#include "strategie.h"
#include "calculer_odometrie.h"
#include "protocole_com_serie.h"
#include "eqep.h"
#include "deplacement.h"
#include "comMoteur.h"
#include "commandes_actionneurs.h"
#include "detecter.h"
// fonction stratégie pour homologation

using namespace std;

void strategie(int valCapteur[7]){
    int vitesseDeplacement(150),vitesseApproche(100);
    float tabOdometrie[]={0,0,0,0,0,0,0};
    const float angle1=M_PI/4;
    cout<<"début du déplacement"<<endl;
    
    if (valCapteur[7]==1) {//vert
        tabOdometrie[0]=0.55;
        tabOdometrie[1]=1;
        //deplacement(0.87, 1.355, 0, valCapteur, tabOdometrie,vitesseDeplacement,0);
        //pousser les plot
        deplacement(0.65, 1,  valCapteur, tabOdometrie,vitesseDeplacement,1);
        deplacement(1.2, 1.75, valCapteur, tabOdometrie,vitesseDeplacement,1);
        //deplacement(0.9, 1.50, 0, valCapteur, tabOdometrie,vitesseDeplacement,-1);
        avancer(tabOdometrie, valCapteur, 0.2, vitesseDeplacement,-1);
        //virer le verre
        deplacement(0.45, 1.9,  valCapteur, tabOdometrie,vitesseDeplacement,-1);
        deplacement(0.25, 1.6, valCapteur, tabOdometrie,vitesseDeplacement,-1);
        deplacement(0.50, 1.8,  valCapteur, tabOdometrie,vitesseDeplacement,1);
        //fermer les clapes
        deplacement(0.03, 1.87, valCapteur, tabOdometrie,vitesseApproche,-1);
        sortir_bras_gauche();
        this_thread::sleep_for(chrono::seconds(1));
        deplacement(0.45, 1.87,  valCapteur, tabOdometrie,vitesseDeplacement,1);
        rentrer_bras_gauche();
        deplacement(0.75, 1.87,  valCapteur, tabOdometrie,vitesseDeplacement,1);
        sortir_bras_gauche();
        deplacement(1.05, 1.87,  valCapteur, tabOdometrie,vitesseDeplacement,1);
        rentrer_bras_gauche();
        //rentrer a la base
        deplacement(0.95, 0.9,  valCapteur, tabOdometrie,vitesseDeplacement,1);
        deplacement(0.4, 1,  valCapteur, tabOdometrie,vitesseDeplacement,-1);
        
        //Aller fermer le clappe chez l'adversaire
        deplacement(1.50,1,valCapteur,tabOdometrie,vitesseDeplacement,1);
        deplacement(2.7,2,valCapteur,tabOdometrie,vitesseDeplacement,1);
        sortir_bras_gauche();
        deplacement(2.2,2,valCapteur,tabOdometrie,vitesseDeplacement,-1);
        rentrer_bras_gauche();
        deplacement(1.5,1,valCapteur,tabOdometrie,vitesseDeplacement,-1);
        deplacement(0.55,1,valCapteur,tabOdometrie,vitesseDeplacement,-1);
    }
    else{
        tabOdometrie[0]=0.55;
        tabOdometrie[1]=1;
        //deplacement(0.87, 1.355, 0, valCapteur, tabOdometrie,vitesseDeplacement,0);
        //pousser les plot
        deplacement(0.65, 1,  valCapteur, tabOdometrie,vitesseDeplacement,1);
        deplacement(1.2, 0.25, valCapteur, tabOdometrie,vitesseDeplacement,1);
        //deplacement(0.9, 1.50, 0, valCapteur, tabOdometrie,vitesseDeplacement,-1);
        avancer(tabOdometrie, valCapteur, 0.2, vitesseDeplacement,-1);
        //virer le verre
        deplacement(0.45, 0.1,  valCapteur, tabOdometrie,vitesseDeplacement,-1);
        deplacement(0.25, 0.4, valCapteur, tabOdometrie,vitesseDeplacement,-1);
        deplacement(0.50, 0.2,  valCapteur, tabOdometrie,vitesseDeplacement,1);
        //fermer les clapes
        deplacement(0.03, 0.13, valCapteur, tabOdometrie,vitesseApproche,-1);
        sortir_bras_droite();
        this_thread::sleep_for(chrono::seconds(1));
        deplacement(0.45, 0.13,  valCapteur, tabOdometrie,vitesseDeplacement,1);
        rentrer_bras_droite();
        deplacement(0.75, 0.13,  valCapteur, tabOdometrie,vitesseDeplacement,1);
        sortir_bras_droite();
        deplacement(1.05, 0.13,  valCapteur, tabOdometrie,vitesseDeplacement,1);
        rentrer_bras_droite();
        //rentrer a la base
        deplacement(0.95, 1,  valCapteur, tabOdometrie,vitesseDeplacement,1);
        deplacement(0.4, 1,  valCapteur, tabOdometrie,vitesseDeplacement,-1);
        
        //Aller fermer le clappe chez l'adversaire
        deplacement(1.50,1,valCapteur,tabOdometrie,vitesseDeplacement,1);
        deplacement(2.7,0.20,valCapteur,tabOdometrie,vitesseDeplacement,1);
        sortir_bras_droite();
        deplacement(2.2,0.20,valCapteur,tabOdometrie,vitesseDeplacement,-1);
        rentrer_bras_droite();
        deplacement(1.5,1,valCapteur,tabOdometrie,vitesseDeplacement,-1);
        deplacement(0.55,1,valCapteur,tabOdometrie,vitesseDeplacement,-1);
        
    }
     
}

