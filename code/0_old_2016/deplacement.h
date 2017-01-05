//
//  thread_ligne_droite.h
//  test_asservissement
//
//  Created by Sylvain Richard on 05/05/2015.
//  Copyright (c) 2015 Sylvain Richard. All rights reserved.
//

#ifndef __test_asservissement__thread_ligne_droite__
#define __test_asservissement__thread_ligne_droite__

#include <stdio.h>

int asserLigneDroite(float tab_odometrie [],float asservissement[],int intAsservissement[]);

void calculerAngleEtdistance(float tab_odometrie [],float xDesire,float yDesire,float* d,float* angle);

int asserTourner (float tab_odometrie[],float thetades,int* vitesseActuelle);

void calculerAngleEtdistance(float tab_odometrie [],float xDesire,float yDesire,float* d,float* angle);

void tourner(float tab_odometrie[],int val_capteurs,float angle);

void avancer (float tab_odometrie[], int val_capteurs[],float distanceDemande,int vitesseNominal, int sens);

void deplacement(float xDesire,float yDesire, int val_capteurs[],float tab_odometrie[],int vitesseNominal,int sens);

#endif /* defined(__test_asservissement__thread_ligne_droite__) */
