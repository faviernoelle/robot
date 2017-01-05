#ifndef COMMANDES_ACTIONNEURS_H
#define COMMANDES_ACTIONNEURS_H

void avancer (float x, float y);
void tourner (float angle);

void sortir_bras_gauche ();
void sortir_bras_droite ();
void baisser_bras_droite ();
void rentrer_bras_gauche ();
void rentrer_bras_droite ();
void baisser_bras_gauche ();

void fermer_pince_arriere_gauche ();
void fermer_pince_arriere_droite ();
void ouvrir_pince_arriere_gauche ();
void ouvrir_pince_arriere_droite ();
void repos_pince_arriere_droite();
void repos_pince_arriere_gauche();

void fermer_pince_ascenseur ();
void ouvrir_pince_ascenseur ();

void ouvrir_gouttiere ();
void entre_ouvrir_gouttiere ();
void fermer_gouttiere ();
void repos_goutiere ();

void monter_ascenseur(int tab_capteurs[7]);
void descendre_ascenseur(int tab_capteurs[7]);

void initialiser_actionneurs(int tab_capteurs[7]);
void prendre_cylindre(int tab_capteurs[7]);
void deposer_pile(int tab_capteurs[7]);


#endif // COMMANDES_ACTIONNEURS_H

