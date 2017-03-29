

/*
 *********************Arduino Source File Header**************************
__file_name__ = "Pir_minimal.ino"
__description__="Codice quinta lezione corso Arduino Base"
__author__ = "Daniele Forsi"
__copyright__ = "Informazioni di Copyright"
__license__ = "GPL"
__email__ = "dforsi@gmail.com"
__status__ = "Development[]";"Test[]";"Production[X]";
__History__: (repeat the following line as many times as applicable)
__version__ = "1.0"
***************************************************************************
*/

#define SENSOR_PIN 2
#define ALARM_LED_PIN LED_BUILTIN
#define SENSOR_WARMUP_TIME_MS 10000

void setupSensor()
{
  // I sensori PIR hanno bisogno di tempo per stabilizzarsi dopo l'accensione
  delay(SENSOR_WARMUP_TIME_MS);
  pinMode(SENSOR_PIN, INPUT);
}

bool isSensorActive()
{
  return digitalRead(SENSOR_PIN) == HIGH;
}

void alarmOn()
{
  digitalWrite(ALARM_LED_PIN, HIGH);
}

void alarmOff()
{
  digitalWrite(ALARM_LED_PIN, LOW);
}

void setupAlarm()
{
  alarmOff();
  pinMode(ALARM_LED_PIN, OUTPUT);
}

void setup()
{
  setupAlarm();
  setupSensor();
}

void loop()
{
  if (isSensorActive()) {
    alarmOn();
  } else {
    alarmOff();
  }
}

