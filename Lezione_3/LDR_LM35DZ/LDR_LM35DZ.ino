/*
 *********************Arduino Source File Header**************************
__file_name__ = "LDR.ino"
__description__="Codice terza lezione corso Arduino Base"
__author__ = "Emiliano Agostini"
__copyright__ = "Informazioni di Copyright"
__license__ = "GPL"
__email__ = "beviugo2@gmail.com"
__status__ = "Development[]";"Test[]";"Production[X]";
__History__: (repeat the following line as many times as applicable)
__version__ = "1.0"
***************************************************************************
*/

#define LDR A0 // Pin Fotoresistenza
#define LED 11 // Pin LED
#define LM35DZ A1 // Pin Sensore Temperatura

void setup()
{
    Serial.begin(9600); // inizializzo la comunicazione seriale
    pinMode(LED, OUTPUT); // inizializzo il pin LED in modalità OUTPUT 
}

void loop()
{
    int LDR_RAW = analogRead(LDR); // Scrivo il valore grezzo rilevato sul pin collegato alla LDR
    int LDRValue = map(LDR_RAW, 0, 300, 255, 0); 
    analogWrite(LED, LDRValue);  // Con analogWrite piloto un segnale PWM grande quanto il valore di LDRValue
    // Serial.println(LDRValue); // Scrivo sul monitor seriale il valore di LDRValue         

    int ValoreSensoreTemp = analogRead(LM35DZ); // Leggo il valore della sonda
    float GradiCeltius = (5.0 * ValoreSensoreTemp * 100)/1023.0; // Trasformo il valore rilevato in gradi celtius

    Serial.print("Temperatura rilevata = "); // Stampo sul monitor seriale il valore espresso in gradi celtius
    Serial.print(GradiCeltius);
    Serial.println(" °C");
    delay(10);
}
