//-----Incluimos Librerias........
#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

#define America   A1  //Pulsador
#define Asia      A0  //Pulsador
#define Africa    A3  //Pulsador
#define Europa    A2  //Pulsador
#define Australia A4  //Pulsador

#define AmericaRELAY 2
#define AsiaRELAY  5
#define AfricaRELAY  3
#define EuropaRELAY  4
#define AustraliaRELAY  6

int Estado1 = 0;  //Creamos una variable que tendra un valor de 0
int Estado2 = 0;  //Creamos una variable que tendrá un valor de 0
int Estado3 = 0;  //Creamos una variable que tendrá un valor de 0
int Estado4 = 0;  //Creamos una variable que tendrá un valor de 0
int Estado5 = 0;  //Creamos una variable que tendrá un valor de 0

int estado1= 0;   //Creamos una variable que tendrá un valor de 0
int estado2= 0;   //Creamos una variable que tendrá un valor de 0
int estado3= 0;   //Creamos una variable que tendrá un valor de 0
int estado4= 0;   //Creamos una variable que tendrá un valor de 0
int estado5= 0;   //Creamos una variable que tendrá un valor de 0

int REC1 = 1;     //Creamos una variable que tendrá un valor de 1
int REC2 = 1;     //Creamos una variable que tendrá un valor de 1
int REC3 = 1;     //Creamos una variable que tendrá un valor de 1
int REC4 = 1;     //Creamos una variable que tendrá un valor de 1
int REC5 = 1;     //Creamos una variable que tendrá un valor de 1

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

void setup() {
    mySoftwareSerial.begin(9600);  //Inicia DFPlayer
    Serial.begin(9600);  //Inicia monitor serial
    
    pinMode(America,INPUT_PULLUP); //Se declara como entrada activando una resistencia en Pull UP
    pinMode(Asia,INPUT_PULLUP);    //Se declara como entrada activando una resistencia en Pull UP
    pinMode(Africa,INPUT_PULLUP);  //Se declara como entrada activando una resistencia en Pull UP
    pinMode(Europa,INPUT_PULLUP);   //Se declara como entrada activando una resistencia en Pull UP
    pinMode(Australia,INPUT_PULLUP);  //Se declara como entrada activando una resistencia en Pull UP
    
    pinMode(AmericaRELAY,OUTPUT);      //Se declara como salida
    pinMode(AsiaRELAY,OUTPUT);         //Se declara como salida
    pinMode(AfricaRELAY,OUTPUT);       //Se declara como salida
    pinMode(EuropaRELAY,OUTPUT);       //Se declara como salida
    pinMode(AustraliaRELAY,OUTPUT);    //Se declara como salida
    
  // Verifique si el DFPlayer se está ejecutando con precisión o no.
  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Si no no hay comunicación con el softwareSerial imprimir lo siguiente:
    Serial.println(F("No se puede Iniciar"));
    Serial.println(F("1. ¡Por favor, verifique la conexión!"));
    Serial.println(F("2. ¡Por favor inserte la tarjeta SD!"));
    while(true);
  }
  Serial.println(F("DFPlayer Mini en Línea."));

  myDFPlayer.setTimeOut(500); //establecer tiempo de comunicación en 500 ms
  myDFPlayer.volume(30);  //Seleccionamos el volumen entre 0 a 30.
//myDFPlayer.volumeUp(); //Volumen Up
//myDFPlayer.volumeDown(); //Volumen Down
  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);
  
//----Establecer el dispositivo, usamos SD como predeterminado----
//  myDFPlayer.outputDevice(DFPLAYER_DEVICE_U_DISK);
    myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);
//  myDFPlayer.outputDevice(DFPLAYER_DEVICE_AUX);
//  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SLEEP);
//  myDFPlayer.outputDevice(DFPLAYER_DEVICE_FLASH);


  digitalWrite(AmericaRELAY,LOW);   //Se enciende por ser catodo comun
  digitalWrite(AsiaRELAY,LOW);      //Se enciende por ser catodo comun
  digitalWrite(AustraliaRELAY,LOW); //Se enciende por ser catodo comun
  digitalWrite(AfricaRELAY,LOW);    //Se enciende por ser catodo comun
  digitalWrite(EuropaRELAY,LOW);    //Se enciende por ser catodo comun
  
  myDFPlayer.play(1);  //Reproduce Pista 0001
  delay(1000);
   
}

void loop(){

  Estado1 = digitalRead(America); //Indicamos que la variable "Estado1"Sea igual a la lectura del "boton1"
  Estado2 = digitalRead(Asia); //Indicamos que la variable "Estado2"Sea igual a la lectura del "boton2"
  Estado3 = digitalRead(Africa); //Indicamos que la variable "Estado3"Sea igual a la lectura del "boton3"
  Estado4 = digitalRead(Europa); //Indicamos que la variable "Estado4"Sea igual a la lectura del "boton4"
  Estado5 = digitalRead(Australia); //Indicamos que la variable "Estado5"Sea igual a la lectura del "boton5"

delay(100);
//myDFPlayer.play(random(1,1));

    if(Estado1 == 0 &&  REC1 == 1){ //ASIA
      if (estado1 == 0){
        myDFPlayer.loopFolder(4); //carpeta 04
  digitalWrite(AmericaRELAY,HIGH);   //Se apaga por ser catodo comun 
  digitalWrite(AsiaRELAY,LOW);      //Se enciende por ser catodo comun   
  digitalWrite(AustraliaRELAY,HIGH);  //Se apaga por ser catodo comun 
  digitalWrite(AfricaRELAY,HIGH);    //Se apaga por ser catodo comun   
  digitalWrite(EuropaRELAY,HIGH);    //Se apaga por ser catodo comun       
        estado1 = 1;
    }
    else {
        myDFPlayer.stop(); 
        digitalWrite(AmericaRELAY,LOW);   //Se enciende por ser catodo comun
        digitalWrite(AsiaRELAY,LOW);      //Se enciende por ser catodo comun
        digitalWrite(AustraliaRELAY,LOW); //Se enciende por ser catodo comun
        digitalWrite(AfricaRELAY,LOW);    //Se enciende por ser catodo comun
        digitalWrite(EuropaRELAY,LOW);    //Se enciende por ser catodo comun
        estado1 = 0;    
        }
      }
  else if(Estado2 == 0 &&  REC2 == 1){ //Africa
if (estado2 == 0){
        myDFPlayer.loopFolder(2); //carpeta 02
  digitalWrite(AmericaRELAY,HIGH);   //Se apaga por ser catodo comun
  digitalWrite(AsiaRELAY,HIGH);      //Se apaga por ser catodo comun   
  digitalWrite(AustraliaRELAY,HIGH);  //Se apaga por ser catodo comun
  digitalWrite(AfricaRELAY,LOW);    //Se enciende por ser catodo comun  
  digitalWrite(EuropaRELAY,HIGH);    //Se apaga por ser catodo comun        
        estado2 = 1;
    }
    else {
        myDFPlayer.stop(); 
        digitalWrite(AmericaRELAY,LOW);   //Se enciende por ser catodo comun
        digitalWrite(AsiaRELAY,LOW);      //Se enciende por ser catodo comun
        digitalWrite(AustraliaRELAY,LOW); //Se enciende por ser catodo comun
        digitalWrite(AfricaRELAY,LOW);    //Se enciende por ser catodo comun
        digitalWrite(EuropaRELAY,LOW);    //Se enciende por ser catodo comun
        estado2 = 0;    
        }
  }
  else if(Estado3 == 0 &&  REC3 == 1){ //Europa 
if (estado3 == 0){
        myDFPlayer.loopFolder(3); //carpeta 03
  digitalWrite(AmericaRELAY,HIGH);   //Se apaga por ser catodo comun
  digitalWrite(AsiaRELAY,HIGH);      //Se apaga por ser catodo comun
  digitalWrite(AustraliaRELAY,HIGH);  //Se apaga por ser catodo comun
  digitalWrite(AfricaRELAY,HIGH);    //Se apaga por ser catodo comun
  digitalWrite(EuropaRELAY,LOW);    //Se enciende por ser catodo comun       
        estado3 = 1;
    }
    else {                            
        myDFPlayer.stop(); 
        digitalWrite(AmericaRELAY,LOW);   //Se enciende por ser catodo comun
        digitalWrite(AsiaRELAY,LOW);      //Se enciende por ser catodo comun
        digitalWrite(AustraliaRELAY,LOW); //Se enciende por ser catodo comun
        digitalWrite(AfricaRELAY,LOW);    //Se enciende por ser catodo comun
        digitalWrite(EuropaRELAY,LOW);    //Se enciende por ser catodo comun
        estado3 = 0;  
    } 
    }
  else if(Estado4 == 0 &&  REC4 == 1){ // AMERICA
  if (estado4 == 0){
        myDFPlayer.loopFolder(1); //carpeta 01
  digitalWrite(AmericaRELAY,LOW);   //Se enciende por ser catodo comun
  digitalWrite(AsiaRELAY,HIGH);      //Se apaga por ser catodo comun
  digitalWrite(AustraliaRELAY,HIGH);  //Se apaga por ser catodo comun
  digitalWrite(AfricaRELAY,HIGH);    //Se apaga por ser catodo comun
  digitalWrite(EuropaRELAY,HIGH);    //Se apaga por ser catodo comun        
        estado4 = 1;
    }
    else {
        myDFPlayer.stop(); 
        digitalWrite(AmericaRELAY,LOW);   //Se enciende por ser catodo comun
        digitalWrite(AsiaRELAY,LOW);      //Se enciende por ser catodo comun
        digitalWrite(AustraliaRELAY,LOW); //Se enciende por ser catodo comun
        digitalWrite(AfricaRELAY,LOW);    //Se enciende por ser catodo comun
        digitalWrite(EuropaRELAY,LOW);    //Se enciende por ser catodo comun
        estado4 = 0;  
    }
  }
  
  else if(Estado5 == 0 &&  REC5 == 1){  // Australia
    if (estado5 == 0){
        myDFPlayer.loopFolder(5); //carpeta 05
  digitalWrite(AmericaRELAY,HIGH);   //Se apaga por ser catodo comun
  digitalWrite(AsiaRELAY,HIGH);      //Se apaga por ser catodo comun
  digitalWrite(AustraliaRELAY,LOW);  //Se enciende por ser catodo comun
  digitalWrite(AfricaRELAY,HIGH);    //Se apaga por ser catodo comun
  digitalWrite(EuropaRELAY,HIGH);    //Se apaga por ser catodo comun        
        estado5 = 1;
    }
    else {
        myDFPlayer.stop(); 
        digitalWrite(AmericaRELAY,LOW);   //Se enciende por ser catodo comun
        digitalWrite(AsiaRELAY,LOW);      //Se enciende por ser catodo comun
        digitalWrite(AustraliaRELAY,LOW); //Se enciende por ser catodo comun
        digitalWrite(AfricaRELAY,LOW);    //Se enciende por ser catodo comun
        digitalWrite(EuropaRELAY,LOW);    //Se enciende por ser catodo comun
        estado5 = 0;  
    }
  }
        REC1=Estado1;
        REC2=Estado2;
        REC3=Estado3;
        REC4=Estado4;
        REC5=Estado5;
   
}
