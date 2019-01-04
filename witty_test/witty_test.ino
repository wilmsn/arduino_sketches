/*  Use with Witty board
 *  Board (for Arduino-IDE: LOLIN(WEMOS) D1 R2 & mini
 *  Press "flash" while power on!
 */
 
#define LED_RT D8
#define LED_BL D7
#define LED_GN D6
#define LDR A0

int sensorValue;

void setup() {
  pinMode(LED_RT, OUTPUT);
  pinMode(LED_BL, OUTPUT);
  pinMode(LED_GN, OUTPUT);
  pinMode(LDR, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_RT,1);
  digitalWrite(LED_BL,1);
  digitalWrite(LED_GN,1);
  sensorValue = analogRead(LDR);
  Serial.println(sensorValue);
  delay(1000);
  digitalWrite(LED_RT,0);
  digitalWrite(LED_BL,0);
  digitalWrite(LED_GN,0);
  sensorValue = analogRead(LDR);
  Serial.println(sensorValue);
  delay(1000);
  digitalWrite(LED_RT,1);
  digitalWrite(LED_BL,0);
  digitalWrite(LED_GN,0);
  sensorValue = analogRead(LDR);
  Serial.println(sensorValue);
  delay(1000);
  digitalWrite(LED_RT,0);
  digitalWrite(LED_BL,1);
  digitalWrite(LED_GN,0);
  sensorValue = analogRead(LDR);
  Serial.println(sensorValue);
  delay(1000);
  digitalWrite(LED_RT,0);
  digitalWrite(LED_BL,0);
  digitalWrite(LED_GN,1);
  sensorValue = analogRead(LDR);
  Serial.println(sensorValue);
  delay(1000);

}
