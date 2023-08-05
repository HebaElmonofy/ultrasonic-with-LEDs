const int TRIG = 12; 
const int ECHO = 11; 
const int LED1 = 2;
const int LED2 = 3;
const int LED3  = 4;
const int LED4 = 5;
const int DISTANCE_THRESHOLD = 50; // centimeters
float duration_us, distance_cm;

void setup() {
  Serial.begin (9600);       
  pinMode(TRIG, OUTPUT); 
  pinMode(ECHO, INPUT);  
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
}

void loop() {
  digitalWrite(TRIG, LOW);
delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(ECHO, HIGH);
  // calculate the distance
  distance_cm = 0.017 * duration_us;

  if(distance_cm < DISTANCE_THRESHOLD)
    digitalWrite(LED1, HIGH);
  
    if(distance_cm < 70)
    {
   digitalWrite(LED2, HIGH);
   digitalWrite(LED1, HIGH); 
   digitalWrite(LED3, LOW); 
   digitalWrite(LED4, LOW);
   delay(100); 
    }
 if(distance_cm > 70 && distance_cm < 100)
       {
   digitalWrite(LED1, HIGH);
   digitalWrite(LED2, HIGH); 
   digitalWrite(LED3, HIGH); 
   digitalWrite(LED4, LOW);
   delay(100); 
    }
  else if(distance_cm > 100)
           {
   digitalWrite(LED1, HIGH);
   digitalWrite(LED2, HIGH); 
   digitalWrite(LED3, HIGH); 
   digitalWrite(LED4, HIGH);
   delay(100); 
    }

  // print the value to Serial Monitor
 Serial.print("distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  delay(500);
}