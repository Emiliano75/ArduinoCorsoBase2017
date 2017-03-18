/*
 *********************Arduino Source File Header**************************
__file_name__ = "LDR.ino"
__description__="Codice terza lezione corso Arduino Base. Luxmetro con LDR"
__author__ = "Stefano Baldacci"
__copyright__ = "Informazioni di Copyright"
__license__ = "GPL"
__email__ = ""
__status__ = "Development[]";"Test[]";"Production[X]";
__History__: (repeat the following line as many times as applicable)
__version__ = "1.0"
***************************************************************************
*/

#define LDR A0 // Pin Fotoresistenza
#define RPD 10 // resistenza pull down della LDR in KOhm


// Calcolo valore in Lux dal valore dell resistenza: L=(R*10^(-b))^(1/m) dove vale la formula log(R)=m*log(L)+b che approssima il grafico
// log-log della caratteristica Luminosità-Resistenza della LDR come da Datasheet
#define b 1.544f
#define m -0.622f

float LDR_Res=0.0; // valore della resistenza della LDR
float Vin=0.0; // Valore lettura ingresso Analogico
float Lux=0.0; // Valore in Lux dell'illuminamento

//calcola il valore in Lux ricavato dalla resistenza della LDR
float  R2Lux(float Res){
  // implemento la funzione  L=(R*10^(-b))^(1/m)
  return pow(Res*pow(10,-b),1/m);
}


void setup()
{
    Serial.begin(115200); // inizializzo la comunicazione seriale
}

void loop()
{
    Vin= (float)analogRead(LDR); // leggo la tensione sulla Resistenza PD

    //calcolo il valore in Ohm della LDR
    LDR_Res=(float)(RPD*(1023-Vin)/Vin);
    Lux=R2Lux(LDR_Res);
    Serial.print("RES= "); // Scrivo sul monitor seriale il valore di LDRValue  
    Serial.println(LDR_Res);
    Serial.print("LUX= "); // Scrivo sul monitor seriale il valore di LDRValue  
    Serial.println(Lux);
    Serial.println("========================");

    delay(100);
}
