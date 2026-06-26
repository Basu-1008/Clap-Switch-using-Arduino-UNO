const int Sensor = 2;
const int relay = 3;

bool relayState = LOW;
bool lastSensorState = HIGH;

void setup() {
  pinMode(Sensor, INPUT);
  pinMode(relay, OUTPUT);

  digitalWrite(relay, relayState);
}

void loop() {
  bool sensorState = digitalRead(Sensor);

  // Detect one clap (HIGH → LOW)
  if (lastSensorState == HIGH && sensorState == LOW) {
    relayState = !relayState;          // Toggle relay
    digitalWrite(relay, relayState);
    delay(300);                        // Ignore extra pulses
  }

  lastSensorState = sensorState;
}