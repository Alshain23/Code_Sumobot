    #include "Arduino.h"
static const uint8_t MOT_G_DIR2  = 5;
static const uint8_t MOT_G_DIR1  = 6;
static const uint8_t MOT_D_DIR1  = 10;
static const uint8_t MOT_D_DIR2  = 11;
static const uint8_t TCRTD  = A3;
static const uint8_t TCRT_POWERD  = 3;

static const uint8_t TCRTG  = A4;
static const uint8_t TCRT_POWERG  = 9;

static const uint8_t ULTRASON_TRIGGER = 12;
static const uint8_t ULTRASON_ECHO = 13;

 


 
void avancer();
void reculer();
void gauche();
void droite();
long ultrason_distance();
void stopMot();
void chercher();
void attaquer();
void retourner();
int test_IRG();
int test_IRD();
bool ligne();
void lith();
