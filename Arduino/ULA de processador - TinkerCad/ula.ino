/*** Pinos ***/

const int selectionLeds[] = {6,7,8,9,10,11,12,13};
const int selector = 2;
const int chave1 = 4;
const int chave2 = 5;
const int ledSaida = 3;


/*** Variáveis Digitais ***/

bool ent1, ent2, saida;

bool selClicado, ultimoSelClicado;


/*** Variáveis ***/

int selection=0;
int i;

/*** Constantes ***/

const String portas[] = {
  "BUFFER",
  "NOT",
  "AND",
  "NAND",
  "OR",
  "NOR",
  "XOR",
  "XNOR"
};


/*** Configurações ***/

void setup() {
  Serial.begin(9600);

  // setando os leds e o botão de seleção de porta
  pinMode(selector, INPUT);
  for(i = 0; i < 8; i++) pinMode(selectionLeds[i], OUTPUT);

  // setando as chaves e o led de saída
  pinMode(chave1, INPUT);
  pinMode(chave2, INPUT);
  pinMode(ledSaida, OUTPUT);

  // leitura inicial do estado do botão para ser utilizado
  // pelo ultimoSelClicado.
  selClicado = digitalRead(selector);

  atualizarLedsDeSelecao();
}


/*** Programa ***/

void loop() {
  ultimoSelClicado = selClicado;
  selClicado = digitalRead(selector);

  // joga para o próxima porta lógica apenas uma vez
  if (ultimoSelClicado && !selClicado) proximaPorta();
  
  ent1 = !digitalRead(chave1);
  ent2 = !digitalRead(chave2);
  
  executarPortaLogica();
  digitalWrite(ledSaida, saida);
  serialKiller();
  delay(10);
}


/*** Seleção de Porta ***/

// acende apenas o LED que representa a seleção atual
void atualizarLedsDeSelecao() {
  for (i = 0; i < 8; i++) digitalWrite(selectionLeds[i], LOW);
  digitalWrite(selectionLeds[selection], HIGH);
}

void proximaPorta() {
  selection++;
  if (selection > 7) selection = 0;
  atualizarLedsDeSelecao();
}


/*** Serial ***/

// função que irá imprimir no Serial:
// "IN0=X; IN1=X; OUT=X; PORT=X;"
void serialKiller() {
  Serial.print("IN0 = ");
  Serial.print(ent1);
  Serial.print("; IN1 = ");
  Serial.print(ent2);
  Serial.print("; OUT = ");
  Serial.print(saida);
  Serial.print("; PORT = ");
  Serial.print(portas[selection]);
  Serial.println(";");
}


/*** Portas Lógicas ***/

void executarPortaLogica() {
  switch (selection) {
    // BUFFER
    case 0:
    	pbuffer();
    	break;
    // NOT
    case 1:
    	pnot();
    	break;
    // AND
    case 2:
    	pand();
    	break;
    // NAND
    case 3:
    	pnand();
    	break;
    // OR
    case 4:
    	por();
    	break;
    // NOR
    case 5:
    	pnor();
    	break;
    // XOR
    case 6:
    	pxor();
    	break;
    // XNOR
    case 7:
    	pxnor();
    	break;
  }
}

void pbuffer() {
  saida = ent1;
}

void pnot() {
  saida = !ent1;
}

void pand() {
  saida = ent1 && ent2;
}

void pnand() {
  saida = !(ent1 && ent2);
}

void por() {
  saida = ent1 || ent2;
}

void pnor() {
  saida = !(ent1 || ent2);
}

void pxor() {
  if (ent1 == ent2) saida = 0;
  else saida = 1;
}

void pxnor() {
  if (ent1 == ent2) saida = 1;
  else saida = 0;
}