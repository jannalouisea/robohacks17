int delayTime = 500;
int distThresh = 100;

int leftIrPin = A0;
int rightIrPin = A1;
int upIrPin = A3;
int downIrPin = A4;

int leftDist = 0;
int rightDist = 0;
int upDist = 0;
int downDist = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}
 
void loop()
{
  readLeft();
  readRight();
  readUp();
  readDown();
  if (leftDist > distThresh || rightDist > distThresh){
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW); 
  }
  delay(delayTime);
}

void readLeft(){
  leftDist = analogRead(leftIrPin);
  Serial.print("Left: ");
  Serial.print(leftDist); 
}

void readRight(){
  rightDist = analogRead(rightIrPin);
  Serial.print(" Right: ");
  Serial.print(rightDist); 
}

void readUp(){
  upDist = analogRead(upIrPin);
  Serial.print(" Up: ");
  Serial.print(upDist); 
}

void readDown(){
  downDist = analogRead(downIrPin);
  Serial.print(" Down: ");
  Serial.println(downDist); 
}
