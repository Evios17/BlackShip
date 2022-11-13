void entete(void);
void afficheur(int dimension, int manche, int partie, int tir, int tableau[9][9], int bateau[9][9]);
int modeDeJeux(void);
int modeDeSelectionReseau(void);
int modeDeSelectionMap(void);
int modeDeSelectionManche(void);
void commande(int *axeX, int *axeY);
void initialisationTableau1(int dimension, int tableau[9][9]);
void initialisationBateau(int dimention, int bateau[9][9]);