int delayTime = 500;
int distThresh = 100;

int leftIrPin = A0;
int rightIrPin = A1;

int leftDist = 0;
int rightDist = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}
 
void loop()
{
  readLeft();
  readRight();
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
  Serial.println(rightDist); 
}

