// Déclaration des structures

struct parametre{
  int dimension;
  int manche;
};

struct jeu{
  int tableau1[9][9];
  int tableau2[9][9];
  int axeX;
  int axeY;

  int gagner;

  int tour;
  int toucheMsg;
  int mancheCpt;

  int essaiCpt;
  int toucheCpt;
  int bateauCpt;

  int send;
};


// Déclaration des protototypes

void solo();
void client();
void serveur();
void debug();

void ip();

void entete();

int modeDeJeux();
int modeDeSelectionReseau();
int modeDeSelectionMap();
int modeDeSelectionManche();
void commande(struct jeu *jeu);

void afficheur(int modeDeJeux, struct parametre parametre, struct jeu jeu);
void toucheMs(struct jeu jeu);

void initialisationTableau(struct parametre parametre, struct jeu *jeu);
void calculateur(int modeDeJeux, struct jeu *jeu);