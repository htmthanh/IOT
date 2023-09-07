// C++ code
//
int trig_pin = 2;
int echo_pin = 3;
//led 1
int LED_blue = 4;
//led 2
int LED_red = 7;
//led 3
int LED_orange = 8;
int piezo = 5;
long distanceCm;
long getDistance()
{
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  
  long duration = pulseIn(echo_pin, HIGH);
  long distanceCm = duration*0.034/2;
  return distanceCm;
  
}
void setup()
{
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  pinMode(LED_blue, OUTPUT);
  pinMode(LED_red, OUTPUT);
  pinMode(LED_orange, OUTPUT);
  pinMode(piezo,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  distanceCm=getDistance();
  Serial.println(distanceCm);
  // vùng 1: xe ở khoảng cách an toàn
  if(distanceCm>=150){
  	digitalWrite(LED_blue,HIGH);
    digitalWrite(piezo,LOW);
    distanceCm=getDistance();
  }
  // vùng 2: xe vào vùng cảnh báo nguy hiểm
  if(distanceCm<150 and distanceCm>50){
  	digitalWrite(LED_blue,LOW);
    digitalWrite(LED_orange,LOW);
    digitalWrite(LED_red,HIGH);
    delay(300);
    digitalWrite(piezo, HIGH);
    tone(piezo,800);
    delay(500);
    noTone(piezo);
    digitalWrite(LED_red,LOW);
    delay(1000);
    digitalWrite(piezo, LOW);
    delay(1200);
    distanceCm=getDistance();
  }
  // vùng 3: xe vào vùng nguy hiểm
  if(distanceCm<=50){
    if(distanceCm<=30){
      digitalWrite(LED_blue,HIGH);
      digitalWrite(LED_red,HIGH); 
      digitalWrite(LED_orange,HIGH);
      delay(100);
      digitalWrite(LED_blue,LOW);
      digitalWrite(LED_red,LOW);
      digitalWrite(LED_orange,LOW);
      delay(100);
      tone(piezo,800);
      delay(300);
      noTone(piezo);
      distanceCm=getDistance();
    }
    else {
    	digitalWrite(LED_blue,HIGH);
    	digitalWrite(LED_red,HIGH); 
    	digitalWrite(LED_orange,HIGH);
   	 	delay(300);
    	digitalWrite(LED_blue,LOW);
    	digitalWrite(LED_red,LOW);
   	 	digitalWrite(LED_orange,LOW);
   	 	delay(300);
   	 	tone(piezo,800);
    	delay(500);
    	noTone(piezo);
    	distanceCm=getDistance();
    }
  }
  
}