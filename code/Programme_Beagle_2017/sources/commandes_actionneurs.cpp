#include <iostream>
#include <vector>
#include <thread>
#include <math.h>
#include <fstream>
#include "../headers/comMoteur.h"
#include "../headers/protocole_com_serie.h"
#include "../headers/calculer_odometrie.h"
#include "../headers/commandes_actionneurs.h"



using namespace std;

void saisir_cylindre ()
{

		// décomposer la fonction avec commande actionneurs de la pince

}

void deposer_cylindre ()
{

		// fonction dépôt de cylindre

}

void recuperer_boules ()
{

		// Récupérer boules blanches

}

void deposer_boules ()
{

		// Déposer boules blanches dans la zone de départ

}

void funnyAction2017 ()
{

		// Lancement de la fusée!!!

}

//////////////// Fonction année dernière /////////////////////////
void sortir_bras_coquillage_gauche ()
{
	servo(1, 45);// a faire mettre la bon valeur d'angle
}

void rentrer_bras_coquillage_gauche ()
{
	servo(1, 124);// a faire mettre la bon valeur d'angle
}

void sortir_bras_coquillage_droit ()
{
	servo(2, 160);// a faire mettre la bon valeur d'angle
}

void rentrer_bras_coquillage_droit ()
{
	servo(2, 72);// a faire mettre la bon valeur d'angle
}

void sortir_les_bras_coquillage ()
{
	sortir_bras_coquillage_gauche();
	std::this_thread::sleep_for(std::chrono::milliseconds((int)(500)));
	sortir_bras_coquillage_droit();
}

void rentrer_les_bras_coquillage ()
{
	rentrer_bras_coquillage_droit();
	std::this_thread::sleep_for(std::chrono::milliseconds((int)(500)));
	rentrer_bras_coquillage_gauche();
}

/***************************************************/
void ouvrir_bras_poisson_gauche ()
{
cout<<"j ouvre ma pince gauche"<<endl;
	servo(3, 120);// a faire mettre la bon valeur d'angle
}

void fermer_bras_poisson_gauche ()
{
	servo(3, 90);// a faire mettre la bon valeur d'angle
}

void ouvrir_bras_poisson_droit ()
{
cout<<"j ouvre ma pince droite"<<endl;
	servo(4, 120);// a faire mettre la bon valeur d'angle
}

void fermer_bras_poisson_droit ()
{
	servo(4, 95);// a faire mettre la bon valeur d'angle
}
/***************************************************/
void sortir_support_parasol ()
{
	servo(5, 70);// a faire mettre la bon valeur d'angle
}

void rentrer_support_parasol ()
{
	servo(5, 10);// a faire mettre la bon valeur d'angle
}

void fermer_parasol ()
{
	servo(6, 75);// a faire mettre la bon valeur d'angle
}

void ouvrir_parasol ()
{
	servo(6, 130);// a faire mettre la bon valeur d'angle
}

void funny_action ()
{
	sortir_support_parasol ();
  	std::this_thread::sleep_for(std::chrono::milliseconds((int)(500)));
	ouvrir_parasol ();
}
/***************************************************/
void sortir_bras_poisson_gauche(int tab_capteurs[12])
{
  //[3] capteur bras poisson bas
/*  chrono::system_clock::time_point end;
  end=chrono::system_clock::now();
  end=end+chrono::seconds(1);*/
      cout << "\n Je commence à sortir le bras à poisson gauche."<< endl;
  receptionserie(tab_capteurs);
  comMotBrasGauche(255);		// On commande le moteur tant qu'on est pas en but�e

  while ( (tab_capteurs[4] == 0))
  {
    //cout << "\n je suis dans le while"<< endl;
    receptionserie(tab_capteurs);
    std::this_thread::sleep_for(std::chrono::milliseconds((int)(20))); //Pause pour liberer thread avant de re-tester

  }

  comMotBrasGauche(0);

  cout << "J'ai fini de sortir le bras à poisson gauche."<< endl;
}



void rentrer_bras_poisson_gauche (int tab_capteurs[12])
{
  //[2] capteur bras poisson haut
  chrono::system_clock::time_point end;
  end=chrono::system_clock::now();
  end=end+chrono::seconds(1);
      cout << "\n Je commence à rentrer le bras à poisson gauche."<< endl;
  receptionserie(tab_capteurs);
  comMotBrasGauche(-90);		// On commande le moteur tant qu'on est pas en but�e

  while ((tab_capteurs[3] == 0))
  {
    //cout << "\n je suis dans le while"<< endl;
    receptionserie(tab_capteurs);
    std::this_thread::sleep_for(std::chrono::milliseconds((int)(20))); //Pause pour liberer thread avant de re-tester

  }

  comMotBrasGauche(0);

  cout << "J'ai fini de rentrer le bras à poisson gauche."<< endl;
}

/***************************************************/
void sortir_bras_poisson_droit(int tab_capteurs[12])
{
  //[3] capteur bras poisson bas
  chrono::system_clock::time_point end;
  end=chrono::system_clock::now();
  end=end+chrono::seconds(1);
      cout << "\n Je commence à sortir le bras à poisson droit."<< endl;
  receptionserie(tab_capteurs);
  comMotBrasDroit(255);		// On commande le moteur tant qu'on est pas en but�e

  while ((tab_capteurs[6] == 0))
  {
    //cout << "\n je suis dans le while"<< endl;
    receptionserie(tab_capteurs);
    std::this_thread::sleep_for(std::chrono::milliseconds((int)(20))); //Pause pour liberer thread avant de re-tester

  }

  comMotBrasDroit(0);

  cout << "J'ai fini de sortir le bras à poisson droit."<< endl;
}



void rentrer_bras_poisson_droit (int tab_capteurs[12])
{
  //[2] capteur bras poisson haut
  chrono::system_clock::time_point end;
  end=chrono::system_clock::now();
  end=end+chrono::seconds(1);
      cout << "\n Je commence à rentrer le bras à poisson droit."<< endl;
  receptionserie(tab_capteurs);
  comMotBrasDroit(-90);		// On commande le moteur tant qu'on est pas en but�e

  while ((tab_capteurs[5] == 0))
  {
    //cout << "\n je suis dans le while"<< endl;
    receptionserie(tab_capteurs);
    std::this_thread::sleep_for(std::chrono::milliseconds((int)(20))); //Pause pour liberer thread avant de re-tester

  }

  comMotBrasDroit(0);

  cout << "J'ai fini de rentrer le bras à poisson droit."<< endl;
}



void rentrer_bras_poisson_droit_mi_course (int tab_capteurs[12])
{
  //[2] capteur bras poisson haut
  chrono::system_clock::time_point end;
      cout << "\n Je commence à rentrer le bras chargé de poissons."<< endl;
  receptionserie(tab_capteurs);
  comMotBrasDroit(-90);
	this_thread::sleep_for(chrono::milliseconds(1500));
  comMotBrasDroit(0);

  cout << "J'ai les poissons suspendus à mon bras."<< endl;
}

void rentrer_bras_poisson_gauche_mi_course (int tab_capteurs[12])
{
  //[2] capteur bras poisson haut
  chrono::system_clock::time_point end;
      cout << "\n Je commence à rentrer le bras chargé de poissons."<< endl;
  receptionserie(tab_capteurs);
  comMotBrasGauche(-90);
	this_thread::sleep_for(chrono::seconds(1));
  comMotBrasGauche(0);

  cout << "J'ai les poissons suspendus à mon bras."<< endl;
}
/***************************************************/
void initialiser_actionneurs(int tab_capteurs[12])
{
	cout << "Initialisation des bras en cours."<< endl;

//  rentrer_bras_poisson_gauche (tab_capteurs);
	rentrer_bras_poisson_droit (tab_capteurs);
  //fermer_bras_poisson_gauche ();
	//fermer_bras_poisson_droit ();
  //fermer_parasol ();
  //rentrer_support_parasol ();
	rentrer_les_bras_coquillage();
	this_thread::sleep_for(chrono::milliseconds(500));  //Temps que les actionneurs se mettent en place

	cout << "\n Initialisation des bras terminée."<< endl;
}
