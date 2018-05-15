#include "Test_2_Sumobot.h"

void setup() {
  // put your setup code here, to run once:
  pinMode(MOT_G_DIR1, OUTPUT);
  pinMode(MOT_G_DIR2, OUTPUT);
  pinMode(MOT_D_DIR2, OUTPUT);
  pinMode(MOT_D_DIR1, OUTPUT);
  pinMode(ULTRASON_TRIGGER, OUTPUT);
  pinMode(ULTRASON_ECHO, INPUT);
  pinMode(TCRT, INPUT);
  pinMode(TCRT_POWER, OUTPUT); 

  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  

  Serial.begin(9600);
  Serial.println("test");

  //init  pin TCRT 5000
  pinMode(3,OUTPUT);
}







/* blablabla test branch*/























void loop()
{

 





  /* if (ligne()) // si le robot capte la ligne blanche, on recule
  {
    reculer();
    delay(1000);
    stopMot();
  }
  else  // sinon on cherche l'adversaire et on avance vers lui
  {
    attaquer();
  } */
  lith();

 
}

