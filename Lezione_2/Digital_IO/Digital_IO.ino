/*
 *********************Arduino Source File Header**************************
__file_name__ = "Digital_IO.ino"
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
# define Pulsante 7
# define LedVerde 2
# define LedRosso 3
byte StatoPulsante = 0;
byte UltimoStatoPulsante = 0;
byte StatoSistema = 0;
byte Antirimbalzo = 50;

void setup() {
  pinMode(Pulsante, INPUT);
  pinMode(LedVerde, OUTPUT);
  pinMode(LedRosso, OUTPUT);
}

void loop() {
  StatoPulsante = digitalRead(Pulsante);
  if(StatoPulsante != 0) {
    delay(Antirimbalzo);
    StatoPulsante = digitalRead(Pulsante);
    if((StatoPulsante == HIGH && UltimoStatoPulsante == LOW)) {
      StatoSistema = 1 - StatoSistema;
    }
  }
    UltimoStatoPulsante = StatoPulsante;
    if(StatoSistema == 1) {
      digitalWrite(LedRosso, HIGH);
      digitalWrite(LedVerde, LOW);
    } else if(StatoSistema == 0) {
      digitalWrite(LedRosso, LOW);
      digitalWrite(LedVerde, HIGH);      
    }
}

