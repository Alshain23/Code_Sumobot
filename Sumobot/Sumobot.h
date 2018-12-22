     #include "Arduino.h"
static const uint8_t MOT_G_DIR2  = 5;
static const uint8_t MOT_G_DIR1  = 6;
static const uint8_t MOT_D_DIR1  = 10;
static const uint8_t MOT_D_DIR2  = 11;
static const uint8_t TCRTD  = A3;
static const uint8_t TCRT_POWERD  = 3;
static const uint8_t GND_BOUTON = 2;
static const uint8_t VCC_BOUTON = 3;
static const uint8_t BOUTON = 7;
static const uint8_t TCRTG  = A4;
static const uint8_t TCRT_POWERG  = 9;

static const uint8_t ULTRASON_TRIGGER = 12;
static const uint8_t ULTRASON_ECHO = 13;


void strat1();
void strat2();
 
void avancer(); // fait avancer le robot 

void reculer(); // fait reculer le robot
 
void gauche(); // fait tourner le robot sur lui meme vers la gauche a l'infini

void gauche_90(); // fait tourner le robot sur lui meme vers la gauche de 90 degrés

void droite(); // fait tourner le robot sur lui meme vers la droite a l'infine

void droite_90(); // fait tourner le robot sur lui meme vers la droite de 90 degrés

long ultrason_distance(); // mesure la distance de l'obstacle le plus proche en centimètre

void stopMot(); // arrete les moteurs du robot

void chercher(); // tourne sur lui meme a gauche pour trouver un obstacle, une fois trouver il s'arrete de tourner

long suivie(bool sens);

void attaquer(); // avance vers l'obstacle pendant 100 ms

void retourner(); // tourne sur lui meme de 180 degres

/* A utiliser si les capteur de ligne marche */
int test_IRG(); // fonction de test du capteur de ligne gauche

int test_IRD (); // fonction de test du capteur de ligne droit

bool ligne(); // fonction qui renvoie "true" si il detecte la ligne blanche, "false" sinon (analogique)

bool ligne_2(); // fonction qui renvoie "true" si il detecte la ligne blanche, "false" sinon (digital)

/* A ne pas utiliser */

void lith(); // programme secret
