/*
 *********************Arduino Source File Header**************************
__file_name__ = "LED_RGB.ino"
__description__="Codice seconda lezione corso Arduino Base: 
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

#define LEDRosso 2
#define LEDVerde 3
#define LEDBlu 4
#define Tasto 8

byte color=0;

void setup() {
 pinMode(Tasto, INPUT_PULLUP);
 pinMode(LEDRosso, OUTPUT);
 pinMode(LEDVerde, OUTPUT);
 pinMode(LEDBlu, OUTPUT);
 
}

void loop() {

 if(!digitalRead(Tasto)){
  delay(100);
  while(!digitalRead(Tasto));
  color=(color + 1)% 4;

  // R G B  color
  // 0 0 0  (0) OFF
  // 1 0 0  (1) LED ROSSO
  // 0 1 0  (2) LED VERDE
  // 0 0 1  (3) LED BLU

  digitalWrite(LEDRosso,color==1?1:0);
  digitalWrite(LEDVerde,color==2?1:0);
  digitalWrite(LEDBlu, color==3?1:0 );
}
 
 delay(25);
 
}
