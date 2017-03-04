/*
 *********************Arduino Source File Header**************************
__file_name__ = "LED_RGB.ino"
__description__="Codice seconda lezione corso Arduino Base"
__author__ = "Emiliano Agostini"
__copyright__ = "Informazioni di Copyright"
__license__ = "GPL"
__email__ = "beviugo2@gmail.com"
__status__ = "Development[]";"Test[]";"Production[X]";
__History__: (repeat the following line as many times as applicable)
__version__ = "1.0"
***************************************************************************
*/

#define LEDRosso 6
#define LEDVerde 5
#define LEDBlu 3

void setup() {

 pinMode(LEDRosso, OUTPUT);
 pinMode(LEDVerde, OUTPUT);
 pinMode(LEDBlu, OUTPUT);
 
}

void loop() {

 // Dichiaro tre variabili intere per scriverci un numero casuale, corrispondente all'intensità del singolo colore
 
 int RandomValueRosso = random(0, 225);
 int RandomValueVerde = random(0, 225);
 int RandomValueBlu = random(0, 225);

// Piloto i singoli LED (RGB) con i valori assegnati dalla funzione random, generando dei colori casuali
 
 analogWrite(LEDRosso, RandomValueRosso);
 analogWrite(LEDVerde, RandomValueVerde);
 analogWrite(LEDBlu, RandomValueBlu);
 delay(400);
 
}
