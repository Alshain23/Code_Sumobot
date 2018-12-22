
#include "Sumobot.h"
// Les anolog write est une valeur en pwm situé entre 0 et 255
void avancer(){ // le robot avance a la vitesse 0,154 m/s
  analogWrite(MOT_D_DIR1, 255); // on fait avancer le moteur droit
  analogWrite(MOT_D_DIR2, 0);


  analogWrite(MOT_G_DIR1,255); // on fait avancer le moteur gauche
  analogWrite(MOT_G_DIR2,0);
}


//fonction qui met la direction de recule a 100% sur les 2 moteurs du robot
void reculer(){
   analogWrite(MOT_D_DIR1,0); 
  analogWrite(MOT_D_DIR2, 255); // on fait reculer le moteur droit


  analogWrite(MOT_G_DIR1,0);
  analogWrite(MOT_G_DIR2, 255); // on fait reculer le moteur gauche
}

void gauche(){ // 185.5 deg/s 3.23rad/s
  analogWrite(MOT_D_DIR1,255); // on fait avancer le moteur droit
  analogWrite(MOT_D_DIR2, 0);


  analogWrite(MOT_G_DIR1,0);
  analogWrite(MOT_G_DIR2, 255); // on fait reculer le moteur droit
}
//fonction qui permet de tourner à gauche de 90°
void gauche_90(){
  gauche();
  delay(485);//delay en ms
  stopMot();//stop les moteur
}

void droite(){
  analogWrite(MOT_D_DIR1,0); 
  analogWrite(MOT_D_DIR2, 255); // on fait reculer le moteur droit


  analogWrite(MOT_G_DIR1,255); // on fait avancer le moteur gauche
  analogWrite(MOT_G_DIR2, 0);
}
//fonction qui permet de tourner à droite de 90°
void droite_90(){
  droite();
  delay(485);//delay en ms
  stopMot();//stop les moteur
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
    droite();
    mesure = ultrason_distance();
    Serial.println(mesure); 
    
  }while ((mesure > 40 ) || ( mesure == 0));
}

long suivie(bool sens) // on cherche l'adversaire en tournant sur soi meme
{
  long mesure = ultrason_distance();  
  int compteur = 0;


  while (((mesure > 40 ) || ( mesure == 0))&& compteur < 5 )
  {
    
    if (sens == true){
      gauche();
    }
    else{
      droite();
    }
    mesure = ultrason_distance();

    compteur ++;
    delay(50);
    
  }

  return(mesure);
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

  delay (1200);
  
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

  //Serial.println(mesure);
  
  return mesure;
}

int test_IRD()
{
  int noiseandsignal, noise, denoisedsignal;
  
  digitalWrite(TCRT_POWERD,HIGH); //turn ON LED 
  delayMicroseconds(500); 
  noiseandsignal = analogRead(TCRTD); 
  digitalWrite(TCRT_POWERD,LOW);  //turn OFF LED
  delayMicroseconds(500);  
  noise = analogRead(TCRTD);
  denoisedsignal = noiseandsignal - noise; 
  Serial.print("analog : "); 
  Serial.print(denoisedsignal);  //signal 
  Serial.print(" --- digital : "); 
  Serial.println(digitalRead(TCRTD));
  
  return(denoisedsignal);
}
int test_IRG()
{
  int noiseandsignal, noise, denoisedsignal;
  
  digitalWrite(TCRT_POWERG,HIGH); //turn ON LED 
  delayMicroseconds(500); 
  noiseandsignal = analogRead(TCRTG); 
  digitalWrite(TCRT_POWERG,LOW);  //turn OFF LED
  delayMicroseconds(500);  
  noise = analogRead(TCRTG);
  denoisedsignal = noiseandsignal - noise; 
  Serial.print("analog : "); 
  Serial.print(denoisedsignal);  //signal 
  Serial.print(" --- digital : "); 
  Serial.println(digitalRead(TCRTG));
  
  return(denoisedsignal);
}

bool ligne()
{
  if ( test_IRG() > 400)
  {
    return true;
  }else
  {
    return false;
  }
}

bool ligne_2()
{
  int ligne;
  ligne = digitalRead(TCRTG);
  if ( ligne == 0 )
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

void strat1()
{
  while(1){
    
     if (ligne()) // si le robot capte la ligne blanche, on recule
    {
      reculer();
      delay(1000);
      stopMot();
    }
    else  // sinon on cherche l'adversaire et on avance vers lui
    {
      attaquer();
    }

  }
}

void strat2()
{
  while(1){
    chercher();
    int compteur = 0;
    
    while(compteur < 5){
      mesure = suivie(sens);
      if(mesure < 40)
      {
        avancer();
        delay(100);
      }
      else{
        sens = !sens;
        compteur++;
      } 
    }
    
  }
  
}
}

