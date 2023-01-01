// Mode de jeux
void solo();
void serveur();
void client();

// Déclaration des structures

struct parametre{
  int dimension;
  int manche;
};

struct jeu{
  int tableau[9][9];
  int axeX;
  int axeY;
  
  int gagner;

  int mancheCpt;
  int essaiCpt;
  int toucheCpt;
  int bateauCpt;
  
  int toucheMsg;
};

// Déclaration des protototypes

void entete(void);
void afficheur(int dimension, int tableau[9][9], int bateau[9][9], int essai, int manche, int partie, int bateauNombre, int win, int touche);
void toucheMs(int toucheMsg);
int modeDeJeux(void);
int modeDeSelectionReseau(void);
int modeDeSelectionMap(void);
int modeDeSelectionManche(void);
void commande(int *axeX, int *axeY);
void initialisationTableau(struct parametre parametre, struct jeu jeu);
int initialisationBateau(struct parametre parametre, struct jeu jeu);
void calculateur(struct parametre *parametre, struct jeu *jeu);