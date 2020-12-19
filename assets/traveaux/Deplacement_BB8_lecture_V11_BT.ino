#include <motorshield.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include <Servo.h>

#define rxPin 11                                              //Broche 11 en tant que RX, a raccorder sur TX 
#define txPin 10                                              //Broche 10 en tant que TX, a raccorder sur RX

//variable moteur --------------------------------------------------------------------------------------

motorshield MotorShield;
const int M1front = 2;                                        //constante car sorti broch
const int M2front = 9;                                        //constante car sorti broch
const int M1back = 10;                                        //constante car sorti broch
const int M2back = 6;                                         //constante car sorti broch
const int M1speed = 3;                                        //constante car sorti broch
const int M2speed = 5;                                        //constante car sorti broch

const int vitesse_max = 255;                                  //constante pour variable vitesse max a vitesse 255/255
const int vitesse_min = 50;                                   //constante pour variable vitesse min a vitisse 50/255
const int vitesse_moy = 150;                                  //constante pour variable vitesse moy a vitesse 150/255
const int vitesse_reduite = 100;                              //constante pour variable vitesse reduite a vitesse 100/255
int vitesse = 100;                                            //declaration variable vitesse egale a 100/255


//variable servo ---------------------------------------------------------------------------------------

Servo myservo;
const int angle_max = 180;                                    //constante pour variable limite angle à 180° pour le servo moteur
const int angle_min = 0;                                      //constante pour variable limite angle à 0° pour le servo moteur
int pos = 0;

int vitesse_pos = 10;


//variable communication--------------------------------------------------------------------------------

SoftwareSerial mySerialBT(rxPin, txPin);
int touche_recu;                                              //declaration variable touche_recu
int touche_recuBT;                                            //declaration variable touche_recuBT



//control robot auto------------------------------------------------------------------------------------


void autotest()                                               //varaible pour l'autoteste  
{ 
  analogWrite(M2speed, 80);                                   //Moteur à Vitesse 80/255
  analogWrite(M1speed, 80);                                   //Moteur à Vitesse 80/255
  digitalWrite(M1front, 1);                                   //En marche de la Roue Droite reculer 
  digitalWrite(M2front, 0);         
  digitalWrite(M1back, 1);                                    //En marche de la roue Gauche reculer 
  digitalWrite(M2back, 0);
  delay(1000);                                                //delée de 1 seconde 
  digitalWrite(M1front, 0); 
  digitalWrite(M2front, 1);                                   //En marche de la roue Gauche avance 
  digitalWrite(M1back, 0);
  digitalWrite(M2back, 1);                                    //En marche de la roue Droite avance 
  delay(1000);                                                //delée de 1 seconde 
}

void programme_test_carre ()                                  //Varrible pour le programme teste carré
{
  Serial.println("le  robot fait un carré");                  //afficher le message entre guillemet
  analogWrite(M2speed, 100);                                  //Moteur à vitesse 100/255
  analogWrite(M1speed, 100);                                  //Moreur à vitesse 100/255
  digitalWrite(M1front, 1);                                   //En marche de la roue Droite recule
  digitalWrite(M2front, 0);                                   
  digitalWrite(M1back, 1);                                    //En marche de la roue Gauche recule 
  digitalWrite(M2back, 0);
  delay(1000);                                                //Deléé de 1 seconde
  digitalWrite(M1front, 0);                                   //Arret de tout les moteur pour une pause 
  digitalWrite(M2front, 0);
  digitalWrite(M1back, 0);
  digitalWrite(M2back, 0);
  delay(500);                                                 //Delée de 0,5 seconde 
  analogWrite(M2speed, 150);                                  //Moteur à vitesse 150/255
  analogWrite(M1speed, 150);                                  //Moteur à vitesse 150/255
  digitalWrite(M1front, 1);                                   //En marche de la roue Droite recule
  digitalWrite(M2front, 1);                                   //En marche de la roue Gauche avance 
  digitalWrite(M1back, 0);
  digitalWrite(M2back, 0);
  delay(900);                                                 //Délée de 0,9 seconde 
  digitalWrite(M1front, 0);                                   //Arret de tout les moteur pour une pause 
  digitalWrite(M2front, 0);
  digitalWrite(M1back, 0);
  digitalWrite(M2back, 0);
  delay(500);                                                 //Délée de 0,5 seconde 
  analogWrite(M2speed, 100);                                  //Moteur à vitesse 100/255
  analogWrite(M1speed, 100);                                  //Moteur à vitesse 100/255
  digitalWrite(M1front, 1);                                   //En marche de la roue Droite recule 
  digitalWrite(M2front, 0);
  digitalWrite(M1back, 1);                                    //En marche de la roue Gauche recule
  digitalWrite(M2back, 0);
  delay(1000);                                                //Délée de 1 seconde 
  digitalWrite(M1front, 0);                                   //Arret de tout les moteur pour une pause 
  digitalWrite(M2front, 0);
  digitalWrite(M1back, 0);
  digitalWrite(M2back, 0);
  delay(500);                                                 //Délée de 0,5 seconde 
  analogWrite(M2speed, 150);                                  //Moteur à vitesse 150/255
  analogWrite(M1speed, 150);                                  //Moteur à vitesse 150/255
  digitalWrite(M1front, 1);                                   //En marche de la roue Droite recule
  digitalWrite(M2front, 1);                                   //En marche de la roue Gauche avance 
  digitalWrite(M1back, 0);
  digitalWrite(M2back, 0);
  delay(900);                                                  
  digitalWrite(M1front, 0);                                   //Arret de tout les moteur pour une pause 
  digitalWrite(M2front, 0);
  digitalWrite(M1back, 0);
  digitalWrite(M2back, 0);
  delay(500);                                                 //Délée de 0,5 seconde 
  analogWrite(M2speed, 100);                                  //Moteur à vitesse 100/255
  analogWrite(M1speed, 100);                                  //Moteur à vitesse 100/255
  digitalWrite(M1front, 1);                                   //En marche de la roue Droite recule
  digitalWrite(M2front, 0);
  digitalWrite(M1back, 1);                                    //En marche de la roue Gauche recule 
  digitalWrite(M2back, 0);
  delay(1000);                                                //Délée de 1 seconde 
  digitalWrite(M1front, 0);                                   //Arret de tout les moteur pour une pause 
  digitalWrite(M2front, 0); 
  digitalWrite(M1back, 0);
  digitalWrite(M2back, 0);
  delay(500);                                                 //Délée de 0,5 seconde 
  analogWrite(M2speed, 150);                                  //Moteur à vitesse 150/255
  analogWrite(M1speed, 150);                                  //Moteur à vitesse 150/255
  digitalWrite(M1front, 1);                                   //En marche de la roue Droite recule
  digitalWrite(M2front, 1);                                   //En marche de la roue Gauche avance 
  digitalWrite(M1back, 0);
  digitalWrite(M2back, 0);
  delay(900);                                                 //Délée de 0,9 seconde
  digitalWrite(M1front, 0);                                   //Arret de tout les moteur pour une pause
  digitalWrite(M2front, 0);
  digitalWrite(M1back, 0);
  digitalWrite(M2back, 0);
  delay(500);                                                 //Délée de 0,5 seconde
  analogWrite(M2speed, 100);                                  //Moteur à vitesse 100/255
  analogWrite(M1speed, 100);                                  //Moteur à vitesse 100/255
  digitalWrite(M1front, 1);                                   //En marche de la roue Droite recule
  digitalWrite(M2front, 0);
  digitalWrite(M1back, 1);                                    //En marche de la roue Gauche recule 
  digitalWrite(M2back, 0);
  delay(1000);                                                //Délée de 1 seconde 
  digitalWrite(M1front, 0);                                   //Arret de tout les moteur pour une pause 
  digitalWrite(M2front, 0);
  digitalWrite(M1back, 0);
  digitalWrite(M2back, 0);
  delay(500);                                                 //Délée de 0,5 seconde 
  analogWrite(M2speed, 150);                                  //Moteur à vitesse 150/255
  analogWrite(M1speed, 150);                                  //Moteur à vitesse 150/255
  digitalWrite(M1front, 1);                                   //En marche de la roue Droite recule
  digitalWrite(M2front, 1);                                   //En marche de la roue Gauche avance 
  digitalWrite(M1back, 0);
  digitalWrite(M2back, 0);
  delay(900);                                                 //Délée de 0,9 seconde
  digitalWrite(M1front, 0);                                   //Arret de tout les moteur pour une pause
  digitalWrite(M2front, 0);
  digitalWrite(M1back, 0);
  digitalWrite(M2back, 0);
}                                                             //Fin de programme de démo carré

void programme_test_rond ()                                   //Variable pour le programme test rond 
{
  analogWrite(M2speed, 160);
  analogWrite(M1speed, 100);
  digitalWrite(M1front, 1);
  digitalWrite(M2front, 1);
  digitalWrite(M1back, 0);
  digitalWrite(M2back, 0);
  delay (5000);
  digitalWrite(M1front, 0);
  digitalWrite(M2front, 0);
  digitalWrite(M1back, 0);
  digitalWrite(M2back, 0);
}


//control manuel robot-------------------------------------------------------------------------------------

void avancer()                                                //variable pour avancer 
{
  digitalWrite(M1front, 0);         
  digitalWrite(M2front, 1);                                   //En marche de la roue Gauche avance 
  digitalWrite(M1back, 0);
  digitalWrite(M2back, 1);                                    //En marche de la roue Droite avance 
  Serial.println("le robot avance");                          //affiche le message entre guillemet 
}

void reculer()                                                //variable pour reculer
{
  digitalWrite(M1front, 1);                                   //En marche de la roue Gauche reculer 
  digitalWrite(M2front, 0);   
  digitalWrite(M1back, 1);                                    //En marche de la roue Droite reculer 
  digitalWrite(M2back, 0); 
  
  Serial.println("le robot recule");                          //affiche le message entre guillemet 
}
void arret()                                                  //variable pour s'arreter
{
  digitalWrite(M1front, 0);                                   //Arret de tout les moteurs
  digitalWrite(M2front, 0);
  digitalWrite(M1back, 0); 
  digitalWrite(M2back, 0); 
  Serial.println("le robot est arreter");                     //affiche le message entre guillemet 
} 
void droite()                                                 //Variable  pour tourner a Droite 
{
  digitalWrite(M1front, 1);                                   //En marche de la roue Gauche reculer 
  digitalWrite(M2front, 1);                                   //En marche de la roue Droite avencer 
  digitalWrite(M1back, 0);
  digitalWrite(M2back, 0);
  Serial.println("le robot tourne a droite");                 //affiche le message entre guillemet 
}
void gauche()                                                 //Variable pour tourner a Gauche 
{
  digitalWrite(M1front, 0);
  digitalWrite(M2front, 0);
  digitalWrite(M1back, 1);                                    //En marche de la roue Droite reculer 
  digitalWrite(M2back, 1);                                    //En marche de la roue Gauche avance
  Serial.println("le robot tourne a gauche");                 //afficher le message entre guillemet 
}
void vitesse_rapide()                                         //variable pour Vitesse Rapide 
{
  analogWrite(M2speed, vitesse = vitesse_max);                //moteur droit
  analogWrite(M1speed, vitesse = vitesse_max);                //moteur gauche
  Serial.println("Le robot utilise sa vitesse maximale");
}
void vitesse_moyenne()                                        //variable pour Vitesse moyenne 
{
  analogWrite(M2speed, vitesse = vitesse_moy);                //moteur droit
  analogWrite(M1speed, vitesse = vitesse_moy);                //moteur gauche
  Serial.println("Le robot utilise sa vitesse moyenne");
}
void vitesse_lente()                                          //variable pour Vitesse lente 
{
  analogWrite(M2speed, vitesse = vitesse_reduite);            //moteur droit
  analogWrite(M1speed, vitesse = vitesse_reduite);            //moteur gauche
  Serial.println("Le robot utilise sa vitesse lente");        //afficher le message entre guillemet 
}
void acceleration()                                           //variable pour l'accéleration 
{
  vitesse = vitesse +10;
  if (vitesse > vitesse_max) vitesse = vitesse_max;
  analogWrite(M2speed,vitesse);                               //Moteur droit 
  analogWrite(M1speed, vitesse);                              //Moteur gauche 
  Serial.println("decelartion");                              //affiche le message entre guillemet 
  Serial.println(vitesse);                                    //affiche la valeur de "vitesse"
}
void deceleration()                                           //variable pour décélération 
{
  vitesse = vitesse -10;
  if( vitesse < vitesse_min) vitesse = vitesse_min;
  analogWrite(M2speed, vitesse);                              //Moteur droit 
  analogWrite(M1speed, vitesse);                              //Moteur gauche
  Serial.println("acceleration");                             //affiche le message entre guillemet 
  Serial.println(vitesse);                                    //affiche la valeur de "vitesse" 
}
void LED_allumer()                                            //variable pour allumer la LED
{
  digitalWrite(LED_BUILTIN, HIGH);                            //mettre la LED en ON 
  Serial.println("LED allumer");                              //affiche la valeur entre guillemet 
}
void LED_eteinte()                                            //variable pour eteindre la LED 
{
  digitalWrite(LED_BUILTIN, LOW) ;                            //mettre la LED en OFF
  Serial.println("LED eteinte");                              //affiche la valeur entre guillemet 
}




//  partie servo -----------------------------------------------------



void droite_servo ()
{
    pos = pos + vitesse_pos ;
    if (pos > angle_max) pos = angle_max;
    myservo.write(pos);
    Serial.print("nouvelle position: ");
    Serial.println(pos);
}


void gauche_servo ()
{
    pos = pos - vitesse_pos ;
    if (pos < angle_min) pos = angle_min;
    myservo.write(pos);
    Serial.print("nouvelle position: ");
    Serial.println(pos);
}
void vitesse_servo_lent ()
{
vitesse_pos = 10;
Serial.print("la vitesse du servo est ");
Serial.println(vitesse_pos);
if (vitesse_pos < angle_min) vitesse_pos = angle_min;
if ( vitesse_pos > angle_max) vitesse_pos = angle_max;
}

void vitesse_servo_rapide ()
{
vitesse_pos = 50;
Serial.print("la vitesse du servo est ");
Serial.println(vitesse_pos);
if (vitesse_pos < angle_min) vitesse_pos = angle_min;
if ( vitesse_pos > angle_max) vitesse_pos = angle_max;

}







//-----------------------------------------------------------------------------------


void setup()
{
    MotorShield.initialize();                                 //initialiser le matériel Motor Shield
    Serial.begin(9600);                                       //initialiser le port série
    pinMode(LED_BUILTIN, OUTPUT);                             //définit a la broche comme sortie
    pinMode(rxPin,INPUT);                                     //definit a la broche rx comme sortie
    pinMode(txPin,OUTPUT);                                    //definit a la broche tx comme entrée 
    mySerialBT.begin(9600);                                   //ouvre le port série BT, définit le débit de données à 9600 bps
    Serial.begin(9600);                                       //ouvre le port série, définit le débit de données à 9600 bps
   
    myservo.attach(8); 
    myservo.write(pos);    
}
void loop()                                        //Début de programme 
{
  if (Serial.available() )                              //traitement liaison serie        
  {
    touche_recu = Serial.read();                              
    switch (touche_recu)                                     
    {  
      case 'z':                                               //touche z
      case 'Z':                                               //touche Z
        avancer();                                            //executer la varible "avancer"
       break;                                                   //arreter 
      case 's':                                               //touche s
      case 'S':                                               //touche S  
        reculer();                                            //executer la variable "reculer"
       break;                                                   //arreter 
      case 'q':                                               //touche q
      case 'Q':                                               //touche Q
        gauche();                                             //executer la variable "gauche"
       break;                                                   //arreter 
      case 'd':                                               //touche d
      case 'D':                                               //touche D
        droite();                                             //executer la variablr "droite"
       break;                                                   //arreter 
      case 'f':                                               //touche f 
      case 'F':                                               //touche F 
        arret();                                              //executer la variable "arret"
       break;                                                   //arreter
      case 'e':                                               //touche e
      case 'E':                                               //touche E
        deceleration();                                       //executer la variable "deceleration"
       break;                                                   //arreter
      case 'a':                                               //touche a
      case 'A':                                               //touche A
        acceleration();                                       //executer la variable "accelerartion"
       break;                                                   //arreter 
      case '1':                                               //touche 1
        vitesse_lente();                                      //executer la variable "vitesse_lente"
       break;                                                   //arreter
      case '2':                                               //touche 2 
        vitesse_moyenne();                                    //executer la varible "vitesse_moyenne"
       break;                                                   //arreter
      case '3':                                               //touche  3
        vitesse_rapide();                                     //executer la vareible "vitesse_rapide"
       break;                                                   //arreter
      case 'l':                                               //touche l
      case 'L':                                               //touche L
        LED_allumer();                                        //executer la variable "LED_allumer"
       break;                                                   //arreter
      case 'm':                                               //touche m
      case 'M':                                               //touche M
        LED_eteinte();                                        //executer la varible "LED_eteinte"
       break;                                                   //arreter
      case 'n':                                               //touche n
      case 'N':                                               //touche N
        programme_test_carre();                               //executer la variable "programme_test_carre"
       break;                                                   //arreter
      case 'b':
      case 'B':
        programme_test_rond();
       break; 
      case'*':
        droite_servo();
       break;
      case'/':
        gauche_servo();
       break; 
      case'O':
      case'o':
        vitesse_servo_lent();
      break;
      case'P':
      case'p':
        vitesse_servo_rapide();
      break;
    } 
  
  }                                                     //fin traitement serie 

   if (mySerialBT.available() )                         //traitement liaison serie BT
   {
    touche_recuBT = mySerialBT.read();
    switch (touche_recuBT) 
    {   
      
      case 'z':                                               //touche z
      case 'Z':                                               //touche Z
        avancer();                                            //executer la varible "avancer"
       break;                                                   //arreter 
      case 's':                                               //touche s
      case 'S':                                               //touche S  
        reculer();                                            //executer la variable "reculer"
       break;                                                   //arreter 
      case 'q':                                               //touche q
      case 'Q':                                               //touche Q
        gauche();                                             //executer la variable "gauche"
       break;                                                   //arreter 
      case 'd':                                               //touche d
      case 'D':                                               //touche D
        droite();                                             //executer la variablr "droite"
       break;                                                   //arreter 
      case 'f':                                               //touche f 
      case 'F':                                               //touche F 
        arret();                                              //executer la variable "arret"
       break;                                                   //arreter
      case 'e':                                               //touche e
      case 'E':                                               //touche E
        deceleration();                                       //executer la variable "deceleration"
       break;                                                   //arreter
      case 'a':                                               //touche a
      case 'A':                                               //touche A
        acceleration();                                       //executer la variable "accelerartion"
       break;                                                   //arreter 
      case '1':                                               //touche 1
        vitesse_lente();                                      //executer la variable "vitesse_lente"
       break;                                                   //arreter
      case '2':                                               //touche 2 
        vitesse_moyenne();                                    //executer la varible "vitesse_moyenne"
       break;                                                   //arreter
      case '3':                                               //touche  3
        vitesse_rapide();                                     //executer la vareible "vitesse_rapide"
       break;                                                   //arreter
      case 'l':                                               //touche l
      case 'L':                                               //touche L
        LED_allumer();                                        //executer la variable "LED_allumer"
       break;                                                   //arreter
      case 'm':                                               //touche m
      case 'M':                                               //touche M
        LED_eteinte();                                        //executer la varible "LED_eteinte"
       break;                                                   //arreter
      case 'n':                                               //touche n
      case 'N':                                               //touche N
        programme_test_carre();                               //executer la variable "programme_test_carre"
       break;                                                   //arreter
      case 'b':                                               //touche b
      case 'B':                                               //touche B
        programme_test_rond();                                //executer la variable "programme_teste_rond"
       break;                                                   //arreter
      case'*':                                                //touche *
        droite_servo();                                       //executer la variable "droite_servo"
       break;
      case'/':
        gauche_servo();
       break; 
      case'O':
      case'o':
     vitesse_servo_lent();
      break;
     case'P':
     case'p':
     vitesse_servo_rapide();
      break;
   }
   
  }                                                     //fin traitement serie BT
}                                                //Fin de programme
