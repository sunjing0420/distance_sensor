int trigPin=13;
int echoPin=12;
int ledPin=11;
int buzzerPin = 9;


void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  
  long duration, distance;
  
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
 
  if (distance < 4) {  
    digitalWrite(ledPin,HIGH); 
    tone(buzzerPin, 1000); // Send 1KHz sound signal...
   
    }else {
    digitalWrite(ledPin,LOW);
    noTone(buzzerPin);     // Stop sound...
 
    }
  
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
    
    }else {
    Serial.print(distance);
    Serial.println(" cm");
    }
    
  delay(500);
}
