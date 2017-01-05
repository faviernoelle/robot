//
//  commandes_actionneurs.cpp
//
//  Update on 24/04/2015 by Quentin and Pierre
//  Update on 09/05/2015 by Quentin
//  Update on 10/05/2015 by Quentin
//  Update on 11/05/2015 by Quentin : ajout de fonctions liees a l'ascenseur
//  Update on 13/05/2015 by Quentin
//  Update on 14/05/2015 10h45 by Quentin : correction sur monter/descendre
//
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


/***************************************************/
void avancer (float x, float y)  //! (x,y), coordonnées en m
{
	//FONCTION ASSERVIE DE SYLVAIN
}


/***************************************************/
void tourner (float angle)  //! angle en degres
{
	//FONCTION DE SYLVAIN
}

/***************************************************/
void baisser_bras_droite ()
{
    servo(2, 175);
}


/***************************************************/
void sortir_bras_droite ()
{
	servo(2, 150);	
}


/***************************************************/
void rentrer_bras_droite ()  
{
	servo(2, 78);	
}



/***************************************************/
void baisser_bras_gauche ()
{
	servo(1, 50);
}

void sortir_bras_gauche ()
{
    servo(1, 90);
}

/***************************************************/
void rentrer_bras_gauche ()
{
    servo(1, 150);
}


/***************************************************/
void fermer_pince_arriere_droite ()  
{
	servo(5, 46);
}


/***************************************************/
void repos_pince_arriere_droite () 
{
	servo(5, 10);
}


/***************************************************/
void ouvrir_pince_arriere_droite ()
{
	servo(5, 100);
}


/***************************************************/
void fermer_pince_arriere_gauche () 
{
	//Pas encore de pince arrière gauche
}


/***************************************************/
void repos_pince_arriere_gauche () 
{
	//Pas encore de pince arrière gauche
}


/***************************************************/
void ouvrir_pince_arriere_gauche () 
{
	//Pas encore de pince arrière gauche
}


/***************************************************/
void fermer_pince_ascenseur ()
{
	servo(3, 78);
	servo(4, 111);
}


/***************************************************/
void ouvrir_pince_ascenseur ()
{
	servo(3, 135);
	servo(4, 45);
}


/***************************************************/
void fermer_gouttiere () 
{
	servo(6, 50);
}


/***************************************************/
void ouvrir_gouttiere () 
{
	servo(6, 150);
}


/***************************************************/
void entre_ouvrir_gouttiere () 
{
	servo(6, 60);
}

void repos_goutiere (){
    servo(6, 0);
}



/***************************************************/
void monter_ascenseur(int tab_capteurs[7])
{
    //[5] = capteur ascenceur haut

    chrono::system_clock::time_point end;
    end=chrono::system_clock::now();
    end=end+chrono::seconds(5);
        cout << "\n je commence monter ascenseur"<< endl;
	receptionserie(tab_capteurs);
	comMotAscenseur(100);		// On commande le moteur tant qu'on est pas en butée

	while ( (tab_capteurs[5] == 0) && (chrono::system_clock::now()<end))
	{
			//cout << "\n je suis dans le while"<< endl;
			receptionserie(tab_capteurs);
			std::this_thread::sleep_for(std::chrono::milliseconds((int)(20))); //Pause pour liberer thread avant de re-tester

	}

	comMotAscenseur(0);

	cout << "j'ai fini monter ascenseur"<< endl;
}


/***************************************************/
void descendre_ascenseur(int tab_capteurs[7])
{
	//[4] = capteur ascenceur bas

    chrono::system_clock::time_point end;
    end=chrono::system_clock::now();
    end=end+chrono::seconds(5);
        cout << "\n je commence descendre ascenseur"<< endl;
	receptionserie(tab_capteurs);
	comMotAscenseur(-85);		// On commande le moteur tant qu'on est pas en butée

    while ( (tab_capteurs[4] == 0) && (chrono::system_clock::now()<end))
	{
			//cout << "\n je suis dans le while"<< endl;
			receptionserie(tab_capteurs);
			std::this_thread::sleep_for(std::chrono::milliseconds((int)(50))); //Pause pour liberer thread avant de re-tester

	}

	comMotAscenseur(0);

	cout << "j'ai fini descendre ascenseur"<< endl;
}


/***************************************************/
void initialiser_actionneurs(int tab_capteurs[7])
{
	rentrer_bras_gauche();
	rentrer_bras_droite();
	fermer_pince_ascenseur();
	repos_pince_arriere_droite();
	repos_pince_arriere_gauche();
	ouvrir_gouttiere();
	monter_ascenseur(tab_capteurs);
	this_thread::sleep_for(chrono::milliseconds(500));  //Temps que les actionneurs se mettent en place
}


/***************************************************/
void prendre_cylindre(int tab_capteurs[7])
{	
	entre_ouvrir_gouttiere();
	ouvrir_pince_ascenseur();
	descendre_ascenseur(tab_capteurs);
	fermer_pince_ascenseur();
	monter_ascenseur(tab_capteurs);
	fermer_gouttiere();
}


/***************************************************/
void deposer_pile(int tab_capteurs[7])
{
	entre_ouvrir_gouttiere();
	descendre_ascenseur(tab_capteurs);
	ouvrir_pince_ascenseur();
	ouvrir_gouttiere();
}


