int relay = 12;
int sensor = 10;

const unsigned long interval = 3000;
unsigned long previousTime = 0;


void setup () {
  pinMode (sensor, INPUT);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);
  Serial.begin (9600);
}

void loop() {
  // read the input on analog pin 5:
  int value = analogRead(A5);
  int sense = digitalRead(sensor);

  unsigned long currentTime = millis();

  Serial.print("Analog read: "); Serial.println(sense);

  if ( sense == 1 ) {
    digitalWrite(relay, HIGH);
  }
  else {
          digitalWrite(relay, LOW);  
       if (currentTime - previousTime >= interval) {
        digitalWrite(relay, HIGH);       
        previousTime = currentTime;

      }
     delay(1000);
  }

}
