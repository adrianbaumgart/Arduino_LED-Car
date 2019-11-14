#include <LiquidCrystal_I2C.h>
#include <Wire.h>
int p, f, l, sd, timeLL, finish;
long blinkRandom, newsRandom;
unsigned long timer;
LiquidCrystal_I2C Display(0x3F,16,2);
void setup() {
  for(p=0;p<14;p=p+1) {
    pinMode(p, OUTPUT);
  }
  Display.init();
  Display.begin(20, 2);
  Display.backlight();
  laufLicht(4);
  start();
}

void loop() {
  Display.init();
  Display.begin(20, 2);
  Display.backlight();
  timer = millis(); 
  if (timer >= 90000) {
    endF();
  }
  delay(1500);
  blinkRandom = random(1,14);
  if ((blinkRandom == 8) || (blinkRandom == 13)) {
    blinker(blinkRandom);
  }
  newsRandom = random(1,20);
  if (newsRandom < 6) {
    breakingNews(newsRandom);
  }
  delay(400);
}

void breakingNews(int number) {
  Display.init();
  Display.begin(20, 2);
  Display.backlight();
  Display.clear();
  Display.setCursor(0,0);
  Display.print("Newsflash!");
  tone(11, 698);
  delay(200);
  tone(11, 466);
  delay(200);
  tone(11, 587);
  delay(200);
  tone(11, 523);
  delay(400);
  tone(11, 349);
  delay(200);
  noTone(11);
  delay(200);
  tone(11, 349);
  delay(200);
  noTone(11);
  laufLicht(2);
  delay(2000);
  if (number == 1) {
    tone(11, 262);
    delay(70);
    noTone(11);
    delay(70);
    tone(11, 294);
    delay(120);
    noTone(11);
    delay(120);
    tone(11, 349);
    delay(200);
    noTone(11);
    delay(200);
    Display.clear();
    delay(200);
    Display.setCursor(0,0);
    Display.print("Message");
    Display.setCursor(0,1);
    Display.print("1");
    delay(2000);
  }
  else if (number == 2) {
    tone(11, 262);
    delay(70);
    noTone(11);
    delay(70);
    tone(11, 294);
    delay(120);
    noTone(11);
    delay(120);
    tone(11, 349);
    delay(200);
    noTone(11);
    delay(200);
    Display.clear();
    delay(200);
        Display.setCursor(0,0);
    Display.print("Message");
    Display.setCursor(0,1);
    Display.print("2");
    delay(2000);
  }
  else if (number == 3) {
    tone(11, 262);
    delay(70);
    noTone(11);
    delay(70);
    tone(11, 294);
    delay(120);
    noTone(11);
    delay(120);
    tone(11, 349);
    delay(200);
    noTone(11);
    delay(200);
    Display.clear();
    delay(200);
        Display.setCursor(0,0);
    Display.print("Message 3");
    delay(2000);
  }
  else if (number == 4) {
    tone(11, 262);
    delay(70);
    noTone(11);
    delay(70);
    tone(11, 294);
    delay(120);
    noTone(11);
    delay(120);
    tone(11, 349);
    delay(200);
    noTone(11);
    delay(200);
    Display.clear();
    delay(200);
    Display.setCursor(0,0);
    Display.print("Message");
    Display.setCursor(0,1);
    Display.print("4");
    delay(2000);
  }
  else if (number == 5) {
    tone(11, 262);
    delay(70);
    noTone(11);
    delay(70);
    tone(11, 294);
    delay(120);
    noTone(11);
    delay(120);
    tone(11, 349);
    delay(200);
    noTone(11);
    delay(200);
    Display.clear();
    delay(200);
    Display.setCursor(0,0);
    Display.print("Message");
    Display.setCursor(0,1);
    Display.print("5");
    delay(2000);
  }
  Display.clear();
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(7, HIGH);
}

void blinker(int side) {
  Display.init();
  Display.begin(20, 2);
  Display.backlight();
  Display.clear();
  tone(11, 440);
  if(side == 8) {
    Display.setCursor(0,0); 
    Display.print("<-");
  }
  else if (side == 13) {
    Display.setCursor(14,0); 
    Display.print("->");
  }
  digitalWrite(side, HIGH);
  delay(100);
  noTone(11);
  delay(400);
  tone(11, 349);
  Display.clear();
  digitalWrite(side, LOW);
  delay(100);
  noTone(11);
  delay(400);
  tone(11, 440);
  if(side == 8) {
    Display.setCursor(0,0); 
    Display.print("<-");
  }
  else if (side == 13) {
    Display.setCursor(14,0); 
    Display.print("->");
  }
  digitalWrite(side, HIGH);
  delay(100);
  noTone(11);
  delay(400);
  tone(11, 349);
  Display.clear();
  digitalWrite(side, LOW);
  delay(100);
  noTone(11);
  delay(400);
  tone(11, 440);
  if(side == 8) {
    Display.setCursor(0,0); 
    Display.print("<-");
  }
  else if (side == 13) {
    Display.setCursor(14,0); 
    Display.print("->");
  }
  digitalWrite(side, HIGH);
  delay(100);
  noTone(11);
  delay(400);
  tone(11, 349);
  Display.clear();
  digitalWrite(side, LOW);
  delay(100);
  noTone(11);
  delay(400);
}

void endF() {
  Display.init();
  Display.begin(20, 2);
  Display.backlight();
  Display.setCursor(3,0);
  Display.print("Finished!");
  finish = 1;
  Display.backlight();
  tone(11, 196);
  delay(175);
  tone(11, 262);
  delay(175);
  tone(11, 330);
  delay(175);
  tone(11, 392);
  delay(175);
  tone(11, 523);
  delay(175);
  tone(11, 659);
  delay(175);
  tone(11, 784);
  delay(350);
  tone(11, 659);
  delay(350);
  tone(11, 207);
  delay(175);
  tone(11, 262);
  delay(175);
  tone(11, 311);
  delay(175);
  tone(11, 415);
  delay(175);
  tone(11, 523);
  delay(175);
  tone(11, 622);
  delay(175);
  tone(11, 831);
  delay(350);
  tone(11, 622);
  delay(350);
  tone(11, 233);
  delay(175);
  tone(11, 294);
  delay(175);
  tone(11, 349);
  delay(175);
  tone(11, 466);
  delay(175);
  tone(11, 587);
  delay(175);
  tone(11, 698);
  delay(175);
  tone(11, 932);
  delay(350);
  tone(11, 988);
  delay(87);
  noTone(11);
  delay(87);
  tone(11, 988);
  delay(87);
  noTone(11);
  delay(87);
  tone(11, 988);
  delay(175);
  tone(11, 1047);
  delay(525);
  noTone(11);
  while(finish < 11) {
    Display.setCursor(0,0);
  Display.print("0 0 0 0 0 0 0 0 ");
  Display.setCursor(0,1);
  Display.print(" 0 0 0 0 0 0 0 0");
  delay(400);
  Display.setCursor(0,0);
  Display.print(" 0 0 0 0 0 0 0 0");
  Display.setCursor(0,1);
  Display.print("0 0 0 0 0 0 0 0 ");
  delay(400);
    finish=finish+1;
  }
  delay(2000);
  for(f=255;f>-1;f=f-10) {
    analogWrite(3, f);
    analogWrite(5, f);
    analogWrite(6, f);
    delay(10);
  }
  analogWrite(3, 0);
  analogWrite(5, 0);
  analogWrite(6, 0);
  delay(200);
  noTone(11);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);
  digitalWrite(7, LOW);
  for(sd=0;sd<4;sd=sd+1) {
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(2, LOW);
    digitalWrite(4, LOW);
    digitalWrite(7, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(7, HIGH);
  }
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);
  digitalWrite(7, LOW);
  Display.init();
  Display.clear();
  Display.noBacklight();
  while(true) {
  }
}

void laufLicht(int tll) {
  for(timeLL=1;timeLL<=tll;timeLL=timeLL+1) {
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(2, LOW);
    digitalWrite(4, LOW);
    digitalWrite(7, LOW);
    digitalWrite(9, HIGH);
    delay(70);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    delay(70);
    digitalWrite(10, LOW);
    digitalWrite(2, HIGH);
    delay(70);
    digitalWrite(2, LOW);
    digitalWrite(4, HIGH);
    delay(70);
    digitalWrite(4, LOW);
    digitalWrite(7, HIGH);
    delay(70);
    digitalWrite(7, LOW);
    delay(70);
  }
}

void start() {
  Display.init();
  Display.begin(20, 2);
  Display.backlight();
  Display.setCursor(5,0);
  Display.print("Ready?");
  delay(2000);
  Display.clear();
  tone(11, 450);
  Display.setCursor(7,0);
  Display.print("5");
  digitalWrite(9, HIGH);
  delay(500);
  noTone(11);
  delay(500);
  Display.clear();
  tone(11, 450);
  Display.setCursor(7,0);
  Display.print("4");
  digitalWrite(10, HIGH);
  delay(500);
  noTone(11);
  delay(500);
  Display.clear();
  tone(11, 450);
  Display.setCursor(7,0);
  Display.print("3");
  digitalWrite(2, HIGH);
  delay(500);
  noTone(11);
  delay(100);
  digitalWrite(12, HIGH);
  l=10;
  for(f=0;f<256;f=f+10) {
    analogWrite(3, f);
    analogWrite(5, f);
    analogWrite(6, f);
    //tone(9, l);
    tone(11, l);
    l=l+20;
    delay(10);
  }
  noTone(11);
  delay(150);
  Display.clear();
  tone(11, 450);
  Display.setCursor(7,0);
  Display.print("2");
  digitalWrite(4, HIGH);
  delay(500);
  noTone(11);
  delay(500);
  Display.clear();
  tone(11, 450);
  Display.setCursor(7,0);
  Display.print("1");
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);
  delay(500);
  noTone(11);
  delay(500);
  Display.clear();
  tone(11, 600);
  Display.setCursor(6,0);
  Display.print("GO!");
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(7, HIGH);
  delay(500);
  noTone(11);
  delay(1000);
  Display.clear();
}
