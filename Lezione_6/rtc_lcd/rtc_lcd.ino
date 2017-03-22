/*
 *********************Arduino Source File Header**************************
__file_name__ = "rtc_lcd.ino"
__description__="Codice sesta lezione corso Arduino Base. Real Time Clock + Liquid Crystal Display"
__author__ = "Stefano Baldacci"
__copyright__ = "Informazioni di Copyright"
__license__ = "GPL"
__email__ = ""
__status__ = "Development[]";"Test[]";"Production[X]";
__History__: (repeat the following line as many times as applicable)
__version__ = "1.0"
***************************************************************************
*/

// Servizio ORA ESATTA http://www.inrim.it/ntp/webclock_i.shtml da usare per impostare l'ora dell'RTC

#include <virtuabotixRTC.h>    //libreria per RTC
#include <LiquidCrystal_I2C.h> // Libreria per LCD con interfaccia I2C

#define USE_LCD
// alimento modulo RTC direttamente dai PIN di I/O di Arduino
#define VCC_PIN 8
#define GND_PIN 9

// collegamenti dati del modulo RTC DS1302
#define CLK_PIN 10
#define DAT_PIN 11
#define RST_PIN 12

// array di interi per memorizzare i valori per settare l'RTC
byte dateTime[7]={0,0,0,0,0,0,0};

#ifdef USE_LCD
//definisco oggetto lcd del tipo LiquidCrystal_I2C
LiquidCrystal_I2C lcd(0x3F, 16, 2);
#endif

//Creo oggetto virtuabotixRTC(uint8_t CLK, uint8_t DAT, uint8_t RST);  
virtuabotixRTC myRTC(CLK_PIN, DAT_PIN, RST_PIN);

void setup()  {      
  
  Serial.begin(115200);
  //creo alimentazione per RTC attraverso i pin di IO
  //creo VCC
 digitalWrite(VCC_PIN,HIGH);
 pinMode(VCC_PIN,OUTPUT);
  //creao GND 
 digitalWrite(GND_PIN,LOW);
 pinMode(GND_PIN,OUTPUT);
  //myRTC.initRTC(CLK_PIN, DAT_PIN, RST_PIN);

#ifdef USE_LCD
    // Retroilluminazione del display
  lcd.begin(); 
  lcd.backlight();
  lcd.setCursor(0, 0); // Sposto il cursore nella prima colonna, prima riga
  lcd.print("RTC+LCD Gulli");   // Stampo il messaggio
  delay(3000);
#endif
}


void loop()  {
// aggiorno la lettura del tempo dal modulo RTC
  myRTC.updateTime();

// controllo se ci sono comandi da serialie per rimettere l'orologio
  if (Serial.available()){
      if (Serial.peek()=='s') { // 's' significa che volgio rimettere la data e l'ora. 'q' per annullare l'operazione
        Serial.read();
        Serial.println("Inserisci la data ed il tempo nel");
        Serial.println("formato: aa,mm,gg,gs,hh,mm,ss oppure q per annullare");
        while(!Serial.available());
        delay(20);
        //Serial.println(Serial.available());
        // se ho inviato 'q' oppure una stringa non valida di dimensioni inferiori a 19 caratteri allora annullo tutto
          if(Serial.peek()=='q'||Serial.available()<19) { 
            Serial.read(); //elimino carattere dal registro di ingresso della seriale
            Serial.println("Dato non valido");
            return;
          }
        for (int i=0;i<7;i++){ // estraggo 7 numeri dalla stringa inviata via seriale
          dateTime[i]=Serial.parseInt();
          //Serial.println(dateTime[i]);
        }
        // adesso aggiorno data ed ora nel modulo RTC
        myRTC.setDS1302Time(dateTime[6],dateTime[5],dateTime[4],dateTime[3],dateTime[2],dateTime[1],dateTime[0]+2000);
      }
      Serial.read();//elimino carattere dal registro di ingresso della seriale
      } 


#ifdef USE_LCD
  lcd.setCursor(0, 0); // Sposto il cursore nella prima colonna, prima riga per stampare la DATA
  lcd.print("Date: ");
  lcd.print(myRTC.year);
  lcd.print("/");
  
  // se il valore da stampare è di una sola cifra stampo 0 e 
  // poi a seguire stampo la cifra singola per non sporcare il display
  if(myRTC.month<10)lcd.print(0); 
  lcd.print(myRTC.month);
  lcd.print("/");
  if(myRTC.dayofmonth<10)lcd.print(0);
  lcd.print(myRTC.dayofmonth);

// Sposto il cursore nella prima colonna, seconda riga per stampare l' ORARIO
  lcd.setCursor(0, 1);
  lcd.print("Time: ");
  if(myRTC.hours<10)lcd.print(0); 
  lcd.print(myRTC.hours);
  lcd.print(":");
  if(myRTC.minutes<10)lcd.print(0); 
  lcd.print(myRTC.minutes);
  lcd.print(":");
  if(myRTC.seconds<10)lcd.print(0); 
  lcd.print(myRTC.seconds);
#endif

  Serial.print(myRTC.dayofmonth);
  Serial.print("/");
  Serial.print(myRTC.month); 
  Serial.print("/");
  Serial.print(myRTC.year);
  Serial.print("  ");
  Serial.print(myRTC.hours);
  Serial.print(":");
  Serial.print(myRTC.minutes);
  Serial.print(":");
  Serial.println(myRTC.seconds);                                                                                                       
  delay( 1000);

}                                                                                     



  
