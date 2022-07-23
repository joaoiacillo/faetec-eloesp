/**
 * Trabalho - Aula 02/06/2022
 * Porta Lógica XOR
 *
 * Aluno: João Pedro Iacillo Soares
 * Turma: 3151
 *
 * Esse trabalho ficou incompleto :/
 **/

const int BOTAO1 = 3;
const int BOTAO2 = 2;

const int LED1 = 13;
const int LED2 = 12;

int estadoBotao1;
int estadoBotao2;
int sum;

 
void setup()
{
  Serial.begin(9600);
  
  pinMode(BOTAO1, INPUT);
  pinMode(BOTAO2, INPUT);
  
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop()
{
  estadoBotao1 = digitalRead(BOTAO1);
  estadoBotao2 = digitalRead(BOTAO2);
  
  sum = estadoBotao1 + estadoBotao2;
  
  String message;
  message += "IN0 = ";
  message += estadoBotao1;
  message += "; IN1 = ";
  message += estadoBotao2;
  message += "; OUT = ";
  
  if (sum == 1)
  {
    message += sum;
  }
}
