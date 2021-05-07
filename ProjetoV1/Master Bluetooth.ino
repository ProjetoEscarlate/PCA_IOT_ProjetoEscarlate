// Projeto Curto Circuito – Conectando dois Arduinos (Emissor)
// == MASTER ==

// Biblioteca
#include <SoftwareSerial.h>

// Comunicação Serial
SoftwareSerial HC05(10, 11); // Simula TX e RX nas portas 10 e 11

// Variáveis e Componentes
int led = 13;          // Defini led na porta 13
int buttonState = 1; // Variável para avaliar o status do Botão

void setup()
{
  pinMode(led, OUTPUT);   // Declara que led como OUTPUT
  HC05.begin(38400);      // Taxa de transmissão do Módulo
  Serial.begin(9600);     // Taxa de transmissão na serial
}
void loop()
{
  if (buttonState == 1)
  { // Se o botão estiver pressionado
    Serial.println("Motor de vibração ON");        // Sinaliza com a palavra "ON"
    HC05.println(2);             // HC05 escreve o valor 2 na serial
    digitalWrite(led, 1);        // Liga o LED
  }
  else
  {
    Serial.println("Motor de vibração OFF");      // Sinaliza com a palavra "OFF"
    digitalWrite(led, 0);       // Desliga o LED
  }
  HC05.flush();                 // Limpa a memória
  delay(20);                    // Aguarda 20 ms antes de retornar ao loop
}
