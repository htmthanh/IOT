
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int button=13;
int tmp=A0;
int count=1;
int buttonState=0;
int lastButtonState=0;
void setup() {
  Serial.begin(9600);
  pinMode(tmp,INPUT);
  pinMode(button,INPUT);
  lcd.begin(16,2);
}

void loop() {
  float temperature=analogRead(tmp);
  float celsius=(temperature*5/1023)/0.01-50;
  buttonState=digitalRead(button);
  if(buttonState!=lastButtonState){
    if(buttonState==HIGH){
    	count++;
      lcd.clear();
    }
  }
  lastButtonState=buttonState;
  if(count==1){
  	lcd.setCursor(4,0);
    lcd.print("CLASS");
    lcd.setCursor(4,1);
    lcd.print("19CLC3");
  }
  if(count>3){
  	count=1;
  }
  if(count==2){
  	lcd.noDisplay();
    delay(500);
    lcd.setCursor(0,0);
    lcd.print("HUYNH T MY THANH");
    lcd.setCursor(4,1);
    lcd.print("19127273");
    lcd.display();
    delay(500);
  }
  if(count==3){
  	lcd.setCursor(2,0);
    lcd.print("TEMP: ");
    lcd.setCursor(8,0);
    lcd.print(celsius);
  }
}
 