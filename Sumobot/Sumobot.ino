#include "Sumobot.h"

void setup() {
  // put your setup code here, to run once:
  //configuration des pin sur la carte arduino
  pinMode(MOT_G_DIR1, OUTPUT);
  pinMode(MOT_G_DIR2, OUTPUT);
  pinMode(MOT_D_DIR2, OUTPUT);
  pinMode(MOT_D_DIR1, OUTPUT);
  pinMode(ULTRASON_TRIGGER, OUTPUT);
  pinMode(ULTRASON_ECHO, INPUT);
  pinMode(TCRTG, INPUT);
  pinMode(TCRT_POWERG, OUTPUT); 

  pinMode(BOUTON, INPUT_PULLUP);

  pinMode(TCRTD, INPUT);
  pinMode(TCRT_POWERD, OUTPUT);

  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);

  

  Serial.begin(9600);//communication série test
  Serial.println("test");

  //init  pin TCRT 5000
  pinMode(3,OUTPUT);

  
}


/*fin test*/






















//programme principale ou on ordonne au robot de faire certaine action 
void loop()
{
  bool sens = true;
  long mesure = 0;
  

while(!digitalRead(BOUTON))
{
  delay(1000);
  
  while(1){
    chercher();
    bool trouver = true ;
    
    while(trouver){

      
      
      
      mesure = suivie(sens);
      
      if(mesure < 40)
      {
        avancer(100);
      }
      else{
        sens = !sens;
        trouver = false;
      }
    
    }
  
  }
}
}



