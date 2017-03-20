/*
 *********************Arduino Source File Header**************************
__file_name__ = Serial_Command_Rele.ino"
__description__="Codice quarta lezione corso Arduino Base"
__author__ = "Emiliano Agostini"
__copyright__ = "Informazioni di Copyright"
__license__ = "GPL"
__email__ = "beviugo2@gmail.com"
__status__ = "Development[]";"Test[]";"Production[X]";
__History__: (repeat the following line as many times as applicable)
__version__ = "1.0"
***************************************************************************
*/

#define PinRele 2                                                // definizione del pin per il rele'

void setup() {                                                   // inizializzo la modalita' del pin rele' e la comunicazione seriale
  pinMode(PinRele, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  int Serial_command = Serial.read();                            // Scrivo nella variabile "Serial_command" il risultato della lettura seriale

  switch(Serial_command)                                         // L'istruzione "switch" permette diverse possibilita' di utilizzo del codice
  {
        case '1':                                                // Nel caso il valore della variabile "Serial_command" sia '1'...
                 Serial.println("Rele' attivato");               // Eseguo delle istruzioni...
                 digitalWrite(PinRele, HIGH);
                 break;
        case '2':                                                // Nel caso il valore della variabile "Serial_command" sia '2'...
                 Serial.println("Rele' disattivato");            // Eseguo delle istruzioni...
                 digitalWrite(PinRele, LOW);
                 break;
        default:                                                 // Nel caso il valore della variabile "Serial_command" non corrsiponda a nessun caso
                 Serial.println("Comando non riconosciuto !!!"); // Stampo sul monitor seriale, un messaggio di errore
                 break; 
  }
}
