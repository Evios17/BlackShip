// Déclaration des defines
#define serv true
#define multi false
#define seul true

// Déclaration des structures

struct parametre{
  int dimension;
  int manche;
};

struct jeu {
  int tableauTmp[9][9];
  int tableau1[9][9];
  int tableau2[9][9];
  int axeX;
  int axeY;

  int gagner;
  int gagnant;

  int tour;
  int toucheMsg;
  int touchePrf;
  int mancheCpt;

  int essaiCpt;
  int toucheCpt;
  int bateauCpt;

  char joueurPsd1;
  char joueurPsd2;
  int joueurScr1;
  int joueurScr2;

  int send;
};


// Déclaration des protototypes

void solo();
void client();
void serveur();
void debug();

int ipcmd(char ip[20]);

void entete();

int modeDeJeux();
int modeDeSelectionReseau();
int modeDeSelectionMap();
int modeDeSelectionManche();
void commande(struct jeu *jeu);

void afficheur(int modeDeJeux, struct parametre parametre, struct jeu jeu);
void tourMs(struct jeu jeu);
void toucheMs(int modeDeJeux, struct jeu jeu);
void fin(struct jeu jeu, struct parametre parametre);

void initialisationTableau(struct parametre parametre, struct jeu *jeu);
void calculateur(int modeDeJeux, struct jeu *jeu);

// Debug

void netdeb(int a, int b);