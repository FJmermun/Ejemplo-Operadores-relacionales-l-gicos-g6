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

  //Incremento
  //dato = dato + 1;
  dato++;

  if (dato >= 8){
    dato = 0;
  }

  Serial.print("El dato es igual a ");Serial.println(dato);

  //dato %= 8; //Limitado
  //dato = dato % 8;

  //int residuo = dato % 8;

   delay (1000);
  
}// Fin de void loop

// Funcioes del usuario
