const int s1 = 2;  // the number of the pushbutton pin
const int s2 = 3;
const int PIN1_R   = 6;
const int PIN1_G = 7;
const int PIN2_R  = 8;
const int PIN2_G = 9;

// variables will change:
int score = 0;
int lvl = 1;
int workpin = 0;
int workpin_r = 0;
int workpin_g = 0;

void setup() {
  pinMode(PIN1_R,   OUTPUT);
  pinMode(PIN1_G, OUTPUT);
  pinMode(PIN2_R,   OUTPUT);
  pinMode(PIN2_G, OUTPUT);
  
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  digitalWrite(s1, LOW);
  digitalWrite(s2, LOW);
  
  Serial.begin(9600);
}

void loop() {
  int good = 1;//random(0, 2);
  int button = 1; //random(1, 6);
  int wait = 0;

  if(lvl == 1){
    wait = 3000;
  } else if (lvl == 2){
    wait = 2000;
  } else {
    wait = 1000;
  }
  assign(wait, button, good);
  delay(20);
}

void blink(int wait, int button, int rpin, int gpin, int good) {
  int state = digitalRead(button);
  if(state == HIGH){
    analogWrite(PIN1_R, 255);
    analogWrite(PIN1_G, 255);
    if(good == 1){
      score += 10;
    } else {
      score -= 5;
    }
    Serial.println(score);
    delay(2000);
  }
  digitalWrite(button, LOW);
  
}

void assign(int wait, int button, int good) {
  if(button == 1){
    if(good == 1){
      analogWrite(PIN1_G, 100);
      blink(wait, s1, PIN1_R, PIN1_G, good);
    } else {
      analogWrite(workpin_r, 100);
      blink(wait, s1, PIN1_R, PIN1_G, good);
    }
  } else if(button == 2){
    workpin = s2;
    workpin_r = PIN2_R;
    workpin_g = PIN2_G;
  } 
}