// Projeto Curto Circuito – Conectando dois Arduinos (Receptor)
// == SLAVE ==

//Biblioteca
#include <SoftwareSerial.h>

// Comunicação Serial
SoftwareSerial HC05(10, 11); // Simula TX e RX nas portas 10 e 11

// Variáveis e Componentes
#define led 13 // Define led na porta 13
int  state ;  // Variável para avaliar os comando recebidos

void setup()
{
  pinMode(led, OUTPUT);  // Declara que led como OUTPUT
  digitalWrite(led, LOW);// Inicia com o led desligado
  HC05.begin(38400);     // Taxa de transmissão do Módulo
  Serial.begin(9600);    // Taxa de transmissão na serial
}
void loop()
{
  if (HC05.available() > 0)
  { // Se o sinal recebido no HC05 for maior que 0

    state = HC05.read(); // state será igual ao valor de mySerial
   
   
    if (state != 1)
    {// Se o valor for diferente de 1
      digitalWrite(led, HIGH); // Liga o LED
      delay(10);               // Aguarda 10 ms
    }
  }
  digitalWrite(led, LOW);     // Desliga o LED 
}
