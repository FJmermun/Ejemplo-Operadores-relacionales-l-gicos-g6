/*
 * Ejemplo de operadores
 * Por: Hugo Vargas
 * Fecha: 8 de Abril de 2022
 * 
 * Este programa permite experimentr el uso y
 * aplicación del operador módulo
 */

// Bibliotecas

// Constantes

// Variables
int dato = 0;
double timeStart, timeFinish;

// Definición de objetos

// Condiciones iniciales - Se ejecuta sólo una vez al energizar
void setup() {// Inicio de void setup ()
  // Aquí va tu código
  Serial.begin(115200);//Iniciar comunicación Serial
  Serial.println("Comunicación Serial iniciada");
  delay(5000);

}// Fin de void setup

// Cuerpo del programa - Se ejecuta constamente
void loop() {// Inicio de void loop
  // put your main code here, to run repeatedly:

  timeStart= micros();

  for (int i=0; i> 1000; i++){
    dato++;
    if (dato >= 8){
      dato = 0;
    }
  }

  timeFinish = micros();

  Serial.print("If funct: ");Serial.println(timeFinish - timeStart); //Imprimir el valor del contador
  delay (10000);

  timeStart= micros();

  for (int i=0; i> 1000; i++){
    dato++;
    dato%=8;
  }

  timeFinish = micros();
  
  Serial.print("Fast mode: ");Serial.println(timeFinish - timeStart); //Imprimir el valor del contador
  delay (10000);
  
}// Fin de void loop

// Funciones del usuario
