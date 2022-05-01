/*
 * Lectura de botones - Encendido de Leds
 * Por: Javier Merino
 * Fecha: 24 de abril del 2022
 * 
 * Este programa muestra las instrucciones básicas
 * para la lectura de botones y el encendido de leds
 */

//Bibliotecas

//Constantes

const int boton1 = 4;
const int led1 = 2;

//Variales

int dato1;

// Definición de objetos

// Condiciones iniciales - Se ejecuta sólo una vez al energizar
void setup() {// Inicio de void setup ()
  // Aquí va tu código
  pinMode(boton1, INPUT_PULLUP);  //Configurar el pin donde se conecta el botón como entrada
  pinMode(led1, OUTPUT); //Configura el pin donde se conecta el LED como salida de voltaje
  digitalWrite(led1, LOW); //0, false, low, 1, true,HIGH
  
}// Fin de void setup

// Cuerpo del programa - Se ejecuta constamente
void loop() {// Inicio de void loop
  // put your main code here, to run repeatedly:
  dato1 = digitalRead (boton1); //Leer el boton
  digitalWrite (led1, !dato1);

}// Fin de void loop

// Funciones del usuario
