
/*
 *********************Arduino Source File Header**************************
__file_name__ = "Pir.ino"
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

#define DEBUG 2

#define SENSOR_PIN 2
#define ALARM_LED_PIN 4
#define ENABLE_LED LED_BUILTIN
#define ENABLE_BUTTON_PIN 3
#define SENSOR_WARMUP_TIME_MS 10000
#define SENSOR_BLINK_TIME_MS 500

bool alarmEnabled = false;

void toggleAlarmEnabled()
{
  alarmEnabled = !alarmEnabled;
  if (alarmEnabled) {
#if DEBUG >= 1
    Serial.println("Alarm enabled");
#endif
    digitalWrite(ENABLE_LED, HIGH);
  } else {
#if DEBUG >= 1
    Serial.println("Alarm disabled");
#endif
    digitalWrite(ENABLE_LED, LOW);
    alarmOff();
  }
}

bool isButtonPressed()
{
  if (digitalRead(ENABLE_BUTTON_PIN) == HIGH) {
    return false;
  }
  delay(50);
  if (digitalRead(ENABLE_BUTTON_PIN) == HIGH) {
#if DEBUG >= 2
    Serial.println("Ignoring button bounce");
#endif
    return false;
  }
  while (digitalRead(ENABLE_BUTTON_PIN) == LOW)
    ;
#if DEBUG >= 2
  Serial.println("Button pressed");
#endif
  return true;
}

void setupButton()
{
  pinMode(ENABLE_BUTTON_PIN, INPUT_PULLUP);
  pinMode(ENABLE_LED, OUTPUT);
}

void setupSensor()
{
  // I sensori PIR hanno bisogno di tempo per stabilizzarsi dopo l'accensione
  for (int i = 0; i < SENSOR_WARMUP_TIME_MS; i += SENSOR_BLINK_TIME_MS * 2) {
#if DEBUG >= 2
    Serial.println("Blinking...");
#endif
    digitalWrite(ENABLE_LED, HIGH);
    delay(SENSOR_BLINK_TIME_MS);
    digitalWrite(ENABLE_LED, LOW);
    delay(SENSOR_BLINK_TIME_MS);
  }
  pinMode(SENSOR_PIN, INPUT);
}

bool isSensorActive()
{
  return digitalRead(SENSOR_PIN) == HIGH;
}

void alarmOn()
{
#if DEBUG >= 3
  Serial.println("Alarm on");
#endif
  digitalWrite(ALARM_LED_PIN, HIGH);
}

void alarmOff()
{
#if DEBUG >= 3
  Serial.println("Alarm off");
#endif
  digitalWrite(ALARM_LED_PIN, LOW);
}

void setupAlarm()
{
  alarmOff();
  pinMode(ALARM_LED_PIN, OUTPUT);
}

void setup()
{
#if DEBUG > 1
  Serial.begin(9600);
#endif
  setupButton();
  setupAlarm();
  setupSensor();
  toggleAlarmEnabled();
}

void loop()
{
  if (isButtonPressed()) {
    toggleAlarmEnabled();
  }

  if (isSensorActive()) {
    alarmOn();
  } else {
    alarmOff();
  }
}

