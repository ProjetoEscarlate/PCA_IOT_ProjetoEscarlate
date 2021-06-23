// Projeto Curto Circuito – Conectando dois Arduinos (Receptor)
// == SLAVE ==

//Biblioteca
#include <SoftwareSerial.h>

// Comunicação Serial
SoftwareSerial HC05(10, 11); // Simula TX e RX nas portas 10 e 11

// Variáveis e Componentes
#define ledzinho 6
int  state ;  // Variável para avaliar os comando recebidos
// Pino ligado ao REC do modulo
int pino_rec = 9;
// Pino ligado ao P-E (PLAYE) do modulo
int pino_playe = 8 ;


void setup()
{
  pinMode(pino_rec, OUTPUT);  // Declara que modulo audio grava como OUTPUT
  pinMode(pino_playe, OUTPUT);  // Declara que modulo audio play como OUTPUT
  pinMode(ledzinho, OUTPUT); 
  digitalWrite(ledzinho, HIGH);
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
      delay(10); 
      digitalWrite(pino_playe, HIGH);
                    
    }
  }
}
