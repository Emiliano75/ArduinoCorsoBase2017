/*
 *********************Arduino Source File Header**************************
__file_name__ = "Blink.ino"
__description__="Codice prima lezione corso Arduino Base"
__author__ = "Stefano Baldacci"
__copyright__ = "Informazioni di Copyright"
__license__ = "GPL"
__email__ = "stefano.baldacci@gmail.com"
__status__ = "Development[]";"Test[]";"Production[X]";
__History__: (repeat the following line as many times as applicable)
__version__ = "1.0"
***************************************************************************
*/

#define RED_LED 3
#define GREEN_LED 9

void setup() {
  // put your setup code here, to run once:
pinMode(RED_LED, OUTPUT);
pinMode(GREEN_LED, OUTPUT);
analogWrite(RED_LED, 0);
analogWrite(GREEN_LED, 0);


for(byte i=0; i<=16; i++){
  analogWrite(RED_LED, pow(i,2)-1);
  analogWrite(GREEN_LED, pow(i,2)-1);
  delay(100);
}
delay(250);
}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(RED_LED, HIGH);
digitalWrite(GREEN_LED, LOW);
delay(250);
digitalWrite(RED_LED, LOW);
digitalWrite(GREEN_LED, HIGH);
delay(250);


}
