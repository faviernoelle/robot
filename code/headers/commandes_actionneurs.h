#ifndef COMMANDES_ACTIONNEURS_H
#define COMMANDES_ACTIONNEURS_H

void avancer (float x, float y);
void tourner (float angle);
void sortir_bras_coquillage_gauche ();
void rentrer_bras_coquillage_gauche ();
void sortir_bras_coquillage_droit ();
void rentrer_bras_coquillage_droit ();
void sortir_les_bras_coquillage ();
void rentrer_les_bras_coquillage ();
void ouvrir_bras_poisson_gauche ();
void fermer_bras_poisson_gauche ();
void ouvrir_bras_poisson_droit ();
void fermer_bras_poisson_droit ();
void sortir_support_parasol ();
void rentrer_support_parasol ();
void fermer_parasol ();
void ouvrir_parasol ();
void funny_action ();
void sortir_bras_poisson_gauche(int tab_capteurs[12]);
void rentrer_bras_poisson_gauche (int tab_capteurs[12]);
void sortir_bras_poisson_droit(int tab_capteurs[12]);
void rentrer_bras_poisson_droit (int tab_capteurs[12]);
void initialiser_actionneurs(int tab_capteurs[12]);
void rentrer_bras_poisson_droit_mi_course(int tab_capteurs[12]);
void rentrer_bras_poisson_gauche_mi_course(int tab_capteurs[12]);


#endif // COMMANDES_ACTIONNEURS_H
