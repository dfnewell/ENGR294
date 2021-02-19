//INITAL VARIABLES
int sampleSize=10;
int long sensorValue1;
float total=0;
float vrms; 
float vavg;
int dutyCycle;

//BEGIN SETUP
void setup() {
  // initialize serial communication at 9600 bits per second:
  pinMode(5,OUTPUT);
  Serial.begin(9600);
  dutyCycle = 100;
  analogWrite(5,dutyCycle);
}
//END SETUP

//USER FUNCTION: ANALOGREADRMS()
float analogReadRMS(){
  float rms;
  for(int j=0;j<sampleSize;++j){
  sensorValue1 = analogRead(A0);
  total= total + sensorValue1*sensorValue1*(5.0/1023)*(5.0/1023);
  }
  rms=sqrt(total/sampleSize);
  total=0;
  return rms;
}
//END USER FUNCTION

//USER FUNCTION: ANALOGREADAVG()
float analogReadAVG(){
  float avg;
  for(int j=0;j<sampleSize;++j){
    sensorValue1 = analogRead(A0);
    total= total + sensorValue1*(5.0/1023);
  }
  avg = total/sampleSize;
  total = 0;
  return avg;
  }


//BEGIN LOOP:
void loop() {
  vrms=analogReadRMS();
  vavg=analogReadAVG();
  Serial.print("Measured RMS voltage = ");
  Serial.println(vrms);
  Serial.print("Measured average voltage = ");
  Serial.println(vavg);
}
