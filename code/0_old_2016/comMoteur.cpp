//
//  comMoteur.cpp
//  communicationserie
//
//  Created by Sylvain Richard on 25/02/2015.
//  Copyright (c) 2015 Sylvain Richard. All rights reserved.
//

#include "comMoteur.h"
#include "protocole_com_serie.h"
#include <iostream>

// Commande des différents moteurs (fonctionnent de la même manière)
// prend un commande entre -255 et 255 pour une commande entre la tension min et la tension max
// Limite à cette plage sinon.

//MAJ 8/05: adaptation des pin, renommage des fonctions et création d'une fonction pour l'ascenseur.

// Attention! Les deux controleurs moteurs n'ont pas la même logique pour la gestion des PWM et du sens.
// Ceux avec bouton: cf comMotDtroit
// Ceux sans bouton: cf comMotAscenseur

bool comMotDroit(int val){
    bool reussite=false;
    unsigned char valeurenvoye;
    // adaptation de la valeur à envoyé
    if (val>0)
    {
        if (val>255) valeurenvoye=255;
        else {
            valeurenvoye=val;
        }
        if (GPIO_off(43)) if (PWM(4,valeurenvoye)) reussite=true;
    }
    else
    {
        if (val<-255) valeurenvoye=255;
        else {
            valeurenvoye=255+val;
        }
        if (GPIO_on(43)) if (PWM(4,valeurenvoye)) reussite=true;
    }
    // envoi des données
    return reussite;
}

bool comMotGauche(int val){
    bool reussite=false;
    unsigned char valeurenvoye;
    // adaptation de la valeur à envoyé
    if (val>0)
    {
        if (val>255) valeurenvoye=255;
        else {
            valeurenvoye=val;
        }
        if (GPIO_off(45)) if (PWM(3,valeurenvoye)) reussite=true;
    }
    else
    {
        if (val<-255) valeurenvoye=255;
        else {
            valeurenvoye=255+val;
        }
        if (GPIO_on(45)) if (PWM(3,valeurenvoye)) reussite=true;
    }
    // envoi des données
    return reussite;
}

bool comMotAscenseur(int val){
    bool reussite=false;
    unsigned char valeurenvoye;
    // adaptation de la valeur à envoyé
    if (val>=0)
    {
        if (val>255) valeurenvoye=255;
        else {
            valeurenvoye=val;
        }
        if (GPIO_off(6)) if (PWM(5,valeurenvoye)) reussite=true;
    }
    else
    {
        if (val<-255) valeurenvoye=255;
        else {
            valeurenvoye=-val;
        }
        if (GPIO_on(6)) if (PWM(5,valeurenvoye)) reussite=true;
    }
    // envoi des données
    return reussite;
}
