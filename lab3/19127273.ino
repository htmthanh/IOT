// C++ code
//
int LED=2;
int PIEZO=4;
int POTEN=A0;
int PHOTO=A1;
int PIR_MOTION=7;
void setup()
{
  pinMode(LED,OUTPUT);
  pinMode(PIEZO,OUTPUT);
  pinMode(POTEN,INPUT);
  pinMode(PHOTO,INPUT);
  pinMode(PIR_MOTION,INPUT);
}

void loop()
{
  int value_PHOTO=analogRead(PHOTO);
  int value_POTEN=analogRead(POTEN);
  int x=map(value_POTEN,0,1023,1,310);
  int value_PIR=digitalRead(PIR_MOTION);
  if(x>value_PHOTO)
    digitalWrite(LED,HIGH);
  if(x>value_PHOTO && value_PIR==HIGH){
  	digitalWrite(PIEZO,HIGH);
    tone(PIEZO,800);
    delay(200);
    noTone(PIEZO);
    digitalWrite(LED,HIGH);
    delay(200);
    digitalWrite(PIEZO,LOW);
    delay(200);
    digitalWrite(LED,LOW);
    delay(200);
  }
  if(x<value_PHOTO && value_PIR==HIGH){
  	digitalWrite(PIEZO,HIGH);
    tone(PIEZO,800);
    delay(200);
    noTone(PIEZO);
  	digitalWrite(PIEZO,LOW);
    delay(200);
  }
  if(x<value_PHOTO)
    digitalWrite(LED,LOW);
}