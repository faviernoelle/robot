/*
Met a jour les coordonnees du centre du robot et son orientation, relatives a la position de depart.
Exemple d'utilisation dans le .h associe.
By Damien and Quentin (quentin.chouiller@ense3.grenoble-inp.fr)
MAJ 22/04/15 Quentin : tableau en paramètre d'entrée
MAJ 06/05/15 Quentin : orientation theta du robot entre -Pi et Pi, modif pas des codeurs
*/

#include <mutex>
#include "eqep.h"
#include "math.h"
#include <time.h>
#include <math.h>
#include <chrono>


// Création des objets eQEP (muxage, période, mode, position inclus)
eQEP eqep1(eQEP1, eQEP::eQEP_Mode_Absolute, 1);
eQEP eqep2(eQEP2, eQEP::eQEP_Mode_Absolute, 2);

//Constantes et variables
const float e=280.0;   //Ecartement des roues codeuses (en mm)
const float N=4000.0;  //Nombre d'incrÃ©ments par tour des codeurs
const float p1=0.04132; //Ajustes a la main. Pas du codeur 1, theoriquement p=0,034910948 mm/incrÃ©mement
const float p2=0.04132; //Pas du codeur 2
float n1, n2;          //Nombre d'increments sur chacune des roues produits depuis la derniÃ¨re lecture
float dx, dy, dtheta, w1, w2, dtheta1, dtheta2;
std::mutex mutProtectionEcriture;



void calculer_odometrie(float tab[7], float Te)
{
	//tab = [x, y, alpha, thetad, wd, thetag, wg]

	
	//Lecture des increments produits depuis la derniere lecture
	n1 = eqep1.get_position(false);  
	n2 = eqep2.get_position(false);
	eqep1.set_position(0);           //Raz des registres contenant les nombres d'increments
	eqep2.set_position(0);


	//Position du robot
	dtheta = (p2*n2-p1*n1)/e;                     //Calcul de la variation d'orientation en rad
	dx = cosf(tab[2]+dtheta)*(p1*n1+p2*n2)/2000;  //Calcul de la variation de x en m
	dy = sinf(tab[2]+dtheta)*(p1*n1+p2*n2)/2000;  //Calcul de la variation de y en m


	//Positions angulaires des roues codeuses
	dtheta1 = n1*(2.0*M_PI/N);
	dtheta2 = n2*(2.0*M_PI/N);


	//Vitesses des roues codeuses
       	w1 = dtheta1*(1000.0/Te);         //en rad/sec
       	w2 = dtheta2*(1000.0/Te);


	//Mise a jour des variables
	mutProtectionEcriture.lock();    //Protection lors de l'écriture pour éviter d'eventuels conflits
	tab[0] -= dx;
	tab[1] -= dy;
	tab[2] += dtheta;                //orientation entre [-Pi, Pi[
//	if ((tab[2] - M_PI) > 0) (tab[2] -= 2.0*M_PI);
//	if ((tab[2] + M_PI) <= 0) (tab[2] += 2.0*M_PI);
	tab[3] += dtheta1;
	tab[4] = w1;
	tab[5] += dtheta2;
	tab[6] = w2;
	mutProtectionEcriture.unlock();

	
	///Debogage
	//std::cout << "n1 : " << n1 << std::endl;
	//std::cout << "n2 : " << n2 << std::endl;
	//std::cout << "x : " << tab[0] << std::endl;
	//std::cout << "y : " << tab[1] << std::endl;
	//std::cout << "alpha : " << tab[2] << std::endl;
	//std::cout << "w1 : " << w1 << std::endl;
	//std::cout << "w2 : " << w2 << std::endl;
	//std::cout << "theta1 : " << tab[3] << std::endl;
	//std::cout << "theta2 : " << tab[5] << std::endl;
	//std::cout << std::endl;
	

}

