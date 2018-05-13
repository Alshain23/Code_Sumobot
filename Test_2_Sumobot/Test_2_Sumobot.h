    #include "Arduino.h"
static const uint8_t MOT_G_DIR2  = 5;
static const uint8_t MOT_G_DIR1  = 6;
static const uint8_t MOT_D_DIR1  = 10;
static const uint8_t MOT_D_DIR2  = 11;
static const uint8_t TCRT  = A3;
static const uint8_t TCRT_POWER  = 2;

static const uint8_t ULTRASON_TRIGGER = 12;
static const uint8_t ULTRASON_ECHO = 13;


static const uint8_t MOT_3_DIR1  = 8;
static const uint8_t MOT_3_DIR2  = 9;

static const uint8_t MOT_4_DIR1  = 3;
static const uint8_t MOT_4_DIR2  = 4;

 
void avancer();
void reculer();
void gauche();
void droite();
long ultrason_distance();
void stopMot();
void chercher();
void attaquer();
void retourner();
int test_IR();
bool ligne();
void bite();
