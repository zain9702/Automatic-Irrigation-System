// Define Motor Parameters for Motor Driver // 
int ena = 9;
int in1 = 8;
int in2 = 7;
int pwm:
int MotorSpeed;
MotorSpeed = 50;
pwm = (pwm/100)*255;
//////////////////////////////////////////////
// Define Sensor Parameters for Soil Moisture Sensor // 
#define moisture_read A0
const int dry = 950;
const int wet = 640;
unsigned int Sensor_val = 0;
unsigned int percentage_moisture;
long timer=0;
long Periodic_Time = 10000; // in millisecond
//////////////////////////////////////////////


void motor_drive(int pwm)
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA,255);
  analogWrite(enA,0);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA,analog);
  delay(2000);
  analogWrite(enA,0);
  
}

void setup() {
  pinMode(ena, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  Serial.begin(9600)
  Serial.println("The System is about to begin ");
  Serial.print("The Speed of motor is");
  Serial.println(pwm);
  Serial.print("The Motor Speed Test will about to begin");
  delay(1000);
  motor_drive(pwm);
  timer = millis(); 
}

void loop() 
{
  if((millis()-timer)>(Periodic_Time))
  {
    Sensor_val = analogRead(moisture_read);
    Sensor_val = constrain(Sensor_val,wet,dry);
    percentage_moisture = map(Sensor_val,wet,dry,100,0);
    Serial.print("Moisutre_Value);
    Serial.print(percentage_moisture);
    Serial.print("%");
    Serial.print(" , ");
    Serial.print("Sensor_value");
    Serial.print(analogRead(Sensor_val));
    if(Moisutre_Value<=50)
    {
      Serial.print("The pump is activated for 2 seconds");
      motor_drive(pwm);
    }
  }
}
