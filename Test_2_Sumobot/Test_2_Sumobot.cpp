
#include "Test_2_Sumobot.h"

void avancer(){ // le robot avance
  analogWrite(MOT_D_DIR1, 180); // on fait avancer le moteur droit
  analogWrite(MOT_D_DIR2, 0);


  analogWrite(MOT_G_DIR1,200); // on fait avancer le moteur gauche
  analogWrite(MOT_G_DIR2,0);
}

void reculer(){
   analogWrite(MOT_D_DIR1,0); 
  analogWrite(MOT_D_DIR2, 255); // on fait reculer le moteur droit


  analogWrite(MOT_G_DIR1,0);
  analogWrite(MOT_G_DIR2, 255); // on fait reculer le moteur gauche
}

void gauche(){
  analogWrite(MOT_D_DIR1,255); // on fait avancer le moteur droit
  analogWrite(MOT_D_DIR2, 0);


  analogWrite(MOT_G_DIR1,0);
  analogWrite(MOT_G_DIR2, 255); // on fait reculer le moteur droit
}

void droite(){
  analogWrite(MOT_D_DIR1,0); 
  analogWrite(MOT_D_DIR2, 255); // on fait reculer le moteur droit


  analogWrite(MOT_G_DIR1,255); // on fait avancer le moteur gauche
  analogWrite(MOT_G_DIR2, 0);
}
void stopMot(){ // on arrete les moteurs
  analogWrite(MOT_D_DIR1,0);
  analogWrite(MOT_D_DIR2, 0);


  analogWrite(MOT_G_DIR1,0);
  analogWrite(MOT_G_DIR2, 0);
}

void chercher() // on cherche l'adversaire en tournant sur soi meme
{
  long mesure; 

  do // tant que on ne capte pas l'adversaire on tourne a gauche
  { 
    gauche();
    mesure = ultrason_distance();
    Serial.println(mesure); 
    
  }while ((mesure > 40 ) || ( mesure == 0));
}



void attaquer(){ // on cherche et on avance vers l'adversaire
 chercher();
 avancer();
 delay(100);
 

}


void retourner()
{
  analogWrite(MOT_D_DIR1,0);
  analogWrite(MOT_D_DIR2, 255);


  analogWrite(MOT_G_DIR1,255);
  analogWrite(MOT_G_DIR2, 0);

  delay (2000);
  
  analogWrite(MOT_D_DIR1,0);
  analogWrite(MOT_D_DIR2, 0);


  analogWrite(MOT_G_DIR1,0);
  analogWrite(MOT_G_DIR2, 0);
  
  
}

long ultrason_distance() // calcul la distance de l'adversaire
{
  long mesure;
  
  // On envoie le trigger
  digitalWrite(ULTRASON_TRIGGER, LOW);
  delayMicroseconds(2);
  digitalWrite(ULTRASON_TRIGGER, HIGH); 
  delayMicroseconds(10);
  digitalWrite(ULTRASON_TRIGGER, LOW);
  
  // On mesure le temps à l'état haut de la pin echo
  // On ajoute un timeout de 25ms pour le cas où aucun objet n'est devant le capteur
  mesure = pulseIn(ULTRASON_ECHO, HIGH, 25000); 
  
  // On attend le minimum de 200µs requit par le capteur
  delayMicroseconds(200);
  
  // On effectue la conversion en centimètres
  mesure = mesure * 17/1000;

  Serial.println(mesure);
  
  return mesure;
}

int test_IR()
{
  int noiseandsignal, noise, denoisedsignal;
  
  digitalWrite(TCRT_POWER,HIGH); //turn ON LED 
  delayMicroseconds(500); 
  noiseandsignal = analogRead(TCRT); 
  digitalWrite(TCRT_POWER,LOW);  //turn OFF LED
  delayMicroseconds(500);  
  noise = analogRead(TCRT);
  denoisedsignal = noiseandsignal - noise; 
  Serial.print("analog : "); 
  Serial.print(denoisedsignal);  //signal 
  Serial.print(" --- digital : "); 
  Serial.println(digitalRead(TCRT));
  
  return(denoisedsignal);
}

bool ligne()
{
  if ( test_IR() > 300)
  {
    return true;
  }else
  {
    return false;
  }
}

void lith()
{
  gauche();
  delay(2700);
  
  stopMot();
  delay(500);
  
  avancer();
  delay(2000);

  stopMot();
  delay(500);

  

  analogWrite(MOT_D_DIR1,0);
  analogWrite(MOT_D_DIR2, 200);


  analogWrite(MOT_G_DIR1,255);
  analogWrite(MOT_G_DIR2, 0);

  delay(1800);

  
  stopMot();
  delay(500);

   avancer();
  delay(2000);

   stopMot();
  delay(500);

    gauche();
  delay(2600);

    stopMot();
  delay(500);

  

  

  
}

