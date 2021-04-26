//Programa: Sensor ultrassônico Arduino acender LED
//Autor: Luan Alves - www.guiarobotica.com

#include "Ultrasonic.h"
Ultrasonic ultrasonic(3,2);// Trigger na porta 3 e Echo na porta 2
 
//Declarando os LED como constantes em seus respectivos pinos
const int vibrador = 7;

long microsec = 0; // variaveis de controle
float distanciaCM = 0;
 
void setup() {
  Serial.begin(9600); //Inicializando o serial monitor
  digitalWrite(vibrador,LOW);  
  pinMode(vibrador,OUTPUT); //declarando o modulo vibratorio como saida
}
 
void loop() {  
  //Lendo o valor do sensor
  microsec = ultrasonic.timing(); 
 
  //Convertendo a distância em CM
  distanciaCM = ultrasonic.convert(microsec, Ultrasonic::CM); 

  ledDistancia();
 
  Serial.print(distanciaCM);// mostrar a distancia na porta serial
  Serial.println(" cm");// colocar unidade de medida
  delay(500);// espera de 500 milissegundos
}

void ledDistancia() {
   
  //Desliga o modulo vibrador
  digitalWrite(vibrador,LOW);  

   
   // criando as condicoes
  if (distanciaCM <= 60) {
    digitalWrite(vibrador, HIGH); 
    delay(600);
    digitalWrite(vibrador ,LOW);
  } if (distanciaCM <= 120 and distanciaCM > 60){
    digitalWrite(vibrador, HIGH); 
    delay(1000);
    digitalWrite(vibrador ,LOW);
    }
    if (distanciaCM <= 180 and distanciaCM > 120){
    digitalWrite(vibrador, HIGH); 
    delay(1500);
    digitalWrite(vibrador ,LOW);
    }

}
