/*
 *********************Arduino Source File Header**************************
__file_name__ = "LED_RGB2.ino"
__description__="Codice2 per seconda lezione corso Arduino Base: 
                Pilota un LED RGB facendo alternare i tre colori alla pressione di un tasto"
__author__ = "Stefano Baldacci"
__copyright__ = "Informazioni di Copyright"
__license__ = "GPL"
__email__ = ""
__status__ = "Development[]";"Test[]";"Production[X]";
__History__: (repeat the following line as many times as applicable)
__version__ = "1.0" 06/03/2017
***************************************************************************
*/

// Definisco i pin di collegamenti dei LED e del tasto senza occupare la memoria di Arduino
#define LEDRosso 2
#define LEDVerde 3
#define LEDBlu 4
#define Tasto 8

// variabile byte per gestire il cambio di colore del LED
  // R G B  color
  // 0 0 0  (0) OFF
  // 1 0 0  (1) LED ROSSO
  // 0 1 0  (2) LED VERDE
  // 0 0 1  (3) LED BLU
byte color=0;



void setup() {
  
  // Inizializzazione dei pin di I/O
 pinMode(Tasto, INPUT_PULLUP);
 pinMode(LEDRosso, OUTPUT);
 pinMode(LEDVerde, OUTPUT);
 pinMode(LEDBlu, OUTPUT);
 
}

void loop() {
  
  // Controllo se il tasto viene premuto e rilasciato
 if(!digitalRead(Tasto)){ // tasto premuto
  delay(100); // per limitare il problema dei rimbalzi
  while(!digitalRead(Tasto)); //tasto ancora premuto
   
   // tasto rilasciato
   // Ogni volta incremento la variabile color e poi ne faccio modulo 4
  color=(color + 1) % 4;


   // Pilto i LED in base alla tabella sotto
  // R G B  color
  // 0 0 0  (0) OFF
  // 1 0 0  (1) LED ROSSO
  // 0 1 0  (2) LED VERDE
  // 0 0 1  (3) LED BLU

  digitalWrite(LEDRosso,color==1?1:0);
  digitalWrite(LEDVerde,color==2?1:0);
  digitalWrite(LEDBlu,color==3?1:0 );
}
delay(25);
}
