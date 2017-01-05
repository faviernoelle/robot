//
//  thread_ligne_droite.cpp
//  test_asservissement
//
//  Created by Sylvain Richard on 05/05/2015.
//  Copyright (c) 2015 Sylvain Richard. All rights reserved.
//




#include <iostream>
#include <vector>
#include <thread>
#include <math.h>
#include <fstream>
#include "comMoteur.h"
#include "protocole_com_serie.h"
#include "deplacement.h"
#include "calculer_odometrie.h"
#include "detecter.h"

using namespace std;

#define angleDiminutionVitesse 15
#define gainProportionel 500
#define rapportDeRampeLigneDroite 20
#define vitesseRotationNominale 100
#define rapportDeRampeRotation 10
#define conditionArretRotation 5
#define Te 20
#define vitesseLenteLigneDroite 70

void calculerAngleEtdistance(float tab_odometrie [],float xDesire,float yDesire,float* d,float* angle){
    float x=tab_odometrie[0],y=tab_odometrie[1];
    float deltaX=(xDesire-x),deltaY=(yDesire-y);
    cout<<"x="<<x<<" xDesire "<<xDesire<<"yDesire"<<yDesire<<"DeltaX:"<<deltaX<<" y="<<y<<" Delta Y:"<<deltaY<<endl;
    *d=sqrtf(deltaX*deltaX+deltaY*deltaY);
    *angle=acosf(deltaX/ *d);
    cout<<"acos: "<<*angle<<" asin"<<(asinf(deltaY/ *d))<<endl;
    if (asinf(deltaY/ *d)>0);
    else {
        *angle=-*angle;
    }
    cout << endl << " et angle " << *angle << endl;
}


void avancer (float tab_odometrie[], int val_capteurs[],float distanceDemande,int vitesseNominal, int sens){
    using chrono::system_clock;
    float asservissement[5];
    int intAsservissement[3];
    const float te=Te;
    
    cout<<"debut avancer"<<endl;
    
    asservissement[0]=0;
    asservissement[1]=distanceDemande;
    asservissement[2]=tab_odometrie[2];
    asservissement[3]=tab_odometrie[0];
    asservissement[4]=tab_odometrie[1];
    intAsservissement[0]=sens;
    intAsservissement[1]=0;
    intAsservissement[2]=vitesseNominal;
    
    // affichage pour debugage
//        cout<<"distance parcouru: "<<asservissement[0]<<endl;
//        cout<<" distancedemande "<<asservissement[1]<<endl;
//        cout<<" angleDemande "<<asservissement[2]<<endl;
//        cout<<"x "<< asservissement[3]<<endl;
//        cout<<"y "<< asservissement[4]<<endl;
//        cout<<"sens "<<intAsservissement[0]<<endl;
//        cout<<"vitesse actuelle "<<intAsservissement[1]<<endl;
    
    comMotDroit(0);
    comMotGauche(0);
    
    system_clock::time_point now = system_clock::now(); //prise de la date pour periode d'échantiollonage
    system_clock::time_point end;
    now = system_clock::now();
    end=now+chrono::seconds(10);
    while ((asserLigneDroite(tab_odometrie, asservissement, intAsservissement)!=1) && (system_clock::now()<end)) {
        calculer_odometrie(tab_odometrie, te);
        receptionserie(val_capteurs);
        detecter(intAsservissement, val_capteurs, tab_odometrie);
        //cout<<"deplacement en cours"<<endl;
        this_thread::sleep_until(now+chrono::milliseconds((int)te));
        now = system_clock::now();
    }
    cout<<"fin avancer"<<endl;
    this_thread::sleep_for(chrono::milliseconds(400));
    
}

void tourner(float tab_odometrie[],int val_capteurs[],float angle){
    using chrono::system_clock;
    float te=Te;
    int vitesseRotationActuelle=0;
    system_clock::time_point now = system_clock::now(); //prise de la date pour periode d'échantiollonage
    system_clock::time_point end;
    end=now+chrono::seconds(10);
    while ((asserTourner(tab_odometrie, angle, &vitesseRotationActuelle)!=1) && (system_clock::now()<end)) {
        calculer_odometrie(tab_odometrie, te);
        receptionserie(val_capteurs);
        this_thread::sleep_until(now+chrono::milliseconds((int)te));
        now = system_clock::now();
    }
    this_thread::sleep_for(chrono::milliseconds(400));
}

/*
 
 tourne le robot dans la position voulue
 
 retourne 1 lorsque le déplacement est terminé, 0 sinon
 
 parametres: float tab_odometrie []: cf caluler odometrie
 float thetades : angle desiré (rad)
 int* vitesseActuelle: vitesse de rotation actuelle (entre 0 et 255);
 
 
 */


int asserTourner (float tab_odometrie[],float thetades,int* vitesseActuelle)
{
    //        cout << "debut tourner" << endl;
    //        cout << "theta = " << tab_odometrie[2] << endl;
    //        cout << "angleDemande " << thetades << endl;
    
    
    if (thetades>tab_odometrie[2]){
        
        //        cout << "angle >0" << endl;
        //        cout << "sens trigo" << endl;
        if (*vitesseActuelle<vitesseRotationNominale) {
            *vitesseActuelle+=vitesseRotationNominale/rapportDeRampeRotation;
        }
        if (180/M_PI*(thetades-tab_odometrie[2])<angleDiminutionVitesse){
            *vitesseActuelle=vitesseRotationNominale/2;
        }
        comMotDroit(*vitesseActuelle);
        comMotGauche(-(*vitesseActuelle));
        //        cout<<"theta = "<<tab_odometrie[2]<<endl;
    }
    else {
        //                cout << "angle <0" << endl;
        //        cout << "sens antitrigo" << endl;
        if (*vitesseActuelle<vitesseRotationNominale) {
            *vitesseActuelle+=vitesseRotationNominale/rapportDeRampeRotation;
        }
        if (fabs(180/M_PI*(thetades-tab_odometrie[2]))<angleDiminutionVitesse){
            *vitesseActuelle=vitesseRotationNominale/2;
        }
        comMotDroit(-(*vitesseActuelle));
        comMotGauche(*vitesseActuelle);
        //            cout<<"theta = "<<tab_odometrie[2]<<endl;
        //            cout<<"vitesseActuelle ="<<*vitesseActuelle<<endl;
    }
    
    //    cout<<"delta theta "<<thetades-tab_odometrie[2]<<endl;
    if ((180/M_PI*fabs(thetades-tab_odometrie[2]))<conditionArretRotation) {
        cout<< "fin tourner" <<endl;
        comMotGauche(0);
        comMotDroit(0);
        *vitesseActuelle=0;
        return 1;
    }
    return 0;
    
}

/*
 Asservissement avec correcteur sur l'angle du déplacement et rampe au démarrage
 
 retourne 1 si le déplacement est terminé et arrete les moteurs.
 retourne 0 sinon.
 
 paramètres: float tab_odometrie []: cf caluler odometrie
 float asservissement []: distance parcourue, distance Demande, angleConsigne,xPrecedent,yPrecedent
 int intAsservissement []: sens(1 marche avant -1 marche arrière), vitesseActuelle, vitesseNominale.
 
 
 */


int asserLigneDroite(float tab_odometrie [],float asservissement[],int intAsservissement[])
{
    float x=tab_odometrie[0],y=tab_odometrie[1],distanceParcourue=asservissement[0], distanceDemande=asservissement[1],alpha=tab_odometrie[2],proportionel,angleConsigne=asservissement[2],xPrecedent=asservissement[3],yPrecedent=asservissement[4];
    int vitesseNominale=intAsservissement[2],consigneMotDroit,consigneMotGauche,vitesseActuelle=intAsservissement[1],sens=intAsservissement[0];
    
    // Prise en sens du sens:
    
    vitesseNominale=vitesseNominale*sens;
    
    //correcteur proportionnel sur la direction du robot:
    
    proportionel=gainProportionel*(alpha-angleConsigne);
    
    if (std::abs(vitesseActuelle)<std::abs(vitesseNominale)){
        vitesseActuelle=vitesseActuelle+vitesseNominale/rapportDeRampeLigneDroite;
    }
    
    if ((distanceDemande-distanceParcourue)<0.1) {
        vitesseActuelle=vitesseLenteLigneDroite;
    }
    
    //calcul des commandes des moteurs:
    
    consigneMotDroit=vitesseActuelle-proportionel;
    consigneMotGauche=vitesseActuelle+proportionel;
    
    //envoi des consignes
    
    comMotDroit(consigneMotDroit);
    comMotGauche(consigneMotGauche);
    
    //calcul de la distance parcourue:
    
    distanceParcourue+=sqrt((xPrecedent-x)*(xPrecedent-x)+(yPrecedent-y)*(yPrecedent-y));
    
    
    //enregistrement des variables:
    asservissement[0]=distanceParcourue;
    asservissement[3]=x;
    asservissement[4]=y;
    
    intAsservissement[1]=vitesseActuelle;
    
    // debug:
    
    //cout<<"ligne droite en cours"<<endl;
    //    cout<<"distance parcourue:"<<asservissement[0]<<endl;
    //    cout<<"x= "<<asservissement[3]<<endl;
    //    cout<<"y= "<<asservissement[4]<<endl;
    //    cout<<"vitesse actuelle "<<intAsservissement[1]<<endl;
    
    //verification du critère d'arret:
    
    if (distanceParcourue>distanceDemande) {
        comMotDroit(0);
        comMotGauche(0);
        cout<<"fin ligne droite"<<endl;
        intAsservissement[1]=0;
        return 1;
    }
    return 0;
}

void deplacement(float xDesire,float yDesire, int val_capteurs[],float tab_odometrie[],int vitesseNominal,int sens){
    int vitesseRotationActuelle=0,intAsservissement[3];
    float te=Te,asservissement[5],distanceDemande,angleDemande;
    using std::chrono::system_clock;
    system_clock::time_point now = system_clock::now(); //prise de la date pour periode d'échantiollonage
    system_clock::time_point end;
    
    //calcul de la trajectoire a avoir:
    
    calculer_odometrie(tab_odometrie, te);
    calculerAngleEtdistance(tab_odometrie, xDesire, yDesire,&distanceDemande,&angleDemande);
    
    
    if (sens==-1) {
        if (angleDemande<0){
            angleDemande=M_PI+angleDemande;
        }
        else angleDemande=-M_PI+angleDemande;
    }
    
    cout<<"angle a effectué:"<<angleDemande<<endl;
    //permière rotation:
    now = system_clock::now();
    end=now+chrono::seconds(10);
    while ((asserTourner(tab_odometrie, angleDemande, &vitesseRotationActuelle)!=1) && (system_clock::now()<end)) {
        calculer_odometrie(tab_odometrie, te);
        receptionserie(val_capteurs);
        this_thread::sleep_until(now+chrono::milliseconds((int)te));
        now = system_clock::now();
    }
    
    this_thread::sleep_for(chrono::milliseconds(400));
    // ligne droite:
    asservissement[0]=0;
    asservissement[1]=distanceDemande;
    asservissement[2]=angleDemande;
    asservissement[3]=tab_odometrie[0];
    asservissement[4]=tab_odometrie[1];
    intAsservissement[0]=sens;
    intAsservissement[1]=0;
    intAsservissement[2]=vitesseNominal;
    
    // affichage pour debugage
    cout<<"distance parcouru: "<<asservissement[0]<<endl;
    cout<<" distancedemande "<<asservissement[1]<<endl;
    cout<<" angleDemande "<<asservissement[2]<<endl;
    cout<<"x "<< asservissement[3]<<endl;
    cout<<"y "<< asservissement[4]<<endl;
    cout<<"sens "<<intAsservissement[0]<<endl;
    cout<<"vitesse actuelle "<<intAsservissement[1]<<endl;
    
    comMotDroit(0);
    comMotGauche(0);
    
    now = system_clock::now();
    end=now+chrono::seconds(10);
    while ((asserLigneDroite(tab_odometrie, asservissement, intAsservissement)!=1) && (system_clock::now()<end)) {
        calculer_odometrie(tab_odometrie, te);
        receptionserie(val_capteurs);
        detecter(intAsservissement, val_capteurs, tab_odometrie);
        //cout<<"deplacement en cours"<<endl;
        this_thread::sleep_until(now+chrono::milliseconds((int)te));
        now = system_clock::now();
    }
    //comMotDroit(0);
    //comMotGauche(0);
    
    cout<<"fin déplacement"<<endl;
    
}