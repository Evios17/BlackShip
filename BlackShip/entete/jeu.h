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

void solo();
void client();
void serveur();
void debug();


void entete();

int modeDeJeux();
int modeDeSelectionReseau();
int modeDeSelectionMap();
int modeDeSelectionManche();
void commande(struct jeu *jeu);

void afficheur(int modeDeJeux, struct parametre parametre, struct jeu jeu);
void toucheMs(struct jeu jeu);

void initialisationTableau(struct jeu *jeu);
int initialisationBateau(struct parametre parametre, struct jeu *jeu);
void calculateur(struct jeu *jeu);