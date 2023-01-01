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

int modeDeJeux(void);
int modeDeSelectionReseau(void);
int modeDeSelectionMap(void);
int modeDeSelectionManche(void);
void commande(struct jeu *jeu);

void afficheur(struct parametre parametre, struct jeu jeu);
void toucheMs(struct jeu jeu);

void initialisationTableau(struct parametre parametre, struct jeu jeu);
int initialisationBateau(struct parametre parametre, struct jeu jeu);
void calculateur(struct parametre *parametre, struct jeu *jeu);