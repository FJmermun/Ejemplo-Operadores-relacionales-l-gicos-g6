/*
 * Ejemplo Sistema de casos con DHT 11
 * Por: Javier Merino
 * Fecha: 24 de abril del 2022
 * 
 * Este programa ejemplifica el uso de operadores relacionales y operadores logicos a través de un sistema de casos con activación por botones
 * 
 * Condiciones iniciales 
 * 
 * Sensor de temperatura y humedad
 * Boton1: Manual. Activa la refrigeración al ser presionado
 * Boton2: Alta demanda
 * Boton3: Sobre carga de funcionamiento
 * 
 * Led1: Refrigeracion manual
 * Led2: Refrigeración automática
 * 
 * 1. Que se encienda la refrigeracion manual cada que se presione el boton de manual  
 * 2. La refrigeracion manual tiene prioridad a la refrigeracion automática.
 * 3. Si la termperatura es alta (mayor a 28, por ejemplo), se activa la refrigeracion automática
 * 4. Si tengo alta demanda o sobre carga, se activa la refrigeración automática
 * 5. Si tengo alta demanda o sobrecarga de funcionamiento y ademas temperatura alta, se activan ambas refrigeraciones
 * 
 * Botones 14, 15, 13
 * Leds 4, 2
 * DHT11 12
 */

#include "DHT.h"

// declaracion de variables
#define DHTPIN 5
#define DHTTYPE DHT11

const int Refri_M = 6;
const int Refri_A = 7;

int boton, refrigeracion, d=10;
float temp, h, t, f, hif, hic;

// Configuración de entradas y salidas

DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  dht.begin();
  
  pinMode(2,INPUT); //Manual
  pinMode(3,INPUT); //AltaDemanda
  pinMode(4,INPUT); //Sobrecarga de Funcionamiento
  pinMode(Refri_M,OUTPUT);
  pinMode(Refri_A,OUTPUT);
  digitalWrite(Refri_M,LOW);
  digitalWrite(Refri_A,LOW);

}

// Codigo principal del programa

void loop() {
  lecturaDHT();
  lecturaBotones();
  logica();
  reporte();
}

void ambosCasos(){
  
  if(temp >= 28){
      digitalWrite(Refri_M,HIGH);
      digitalWrite(Refri_A,HIGH);
    }
    
  else{
      digitalWrite(Refri_M,LOW);
      digitalWrite(Refri_A,HIGH);
    }  
}

void lecturaDHT(){
  temp = dht.readTemperature();
  h = dht.readHumidity();
  t = dht.readTemperature();
  f = dht.readTemperature(true);
}

void lecturaBotones(){
  if (digitalRead(2)!=0){  boton = 1;  }
  if (digitalRead(3)!=0){  boton = 2;  }
  if (digitalRead(4)!=0){  boton = 3;  }
}

void logica(){
  
  switch (boton){
  
    case 1:
  
    digitalWrite(Refri_M,HIGH);
    digitalWrite(Refri_A,LOW);
    break;

    case 2:
    ambosCasos();
    break;

    case 3:
    ambosCasos();
    break;

    default:
    digitalWrite(Refri_M,LOW);
    digitalWrite(Refri_A,LOW);
    break;
  }
}

void reporte(){
  
  hif = dht.computeHeatIndex(f, h);
  hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
}
