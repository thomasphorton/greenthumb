#define M0 A0 //The definition of AO pin IO-A0 
#define M1 A1
#define M2 A2
#define DO 7        //The definition of DO pin IO-7  

int wetValue = 0;
int dryValue = 1023;

int friendlyWetValue = 100;
int friendlyDryValue = 0;

void setup() {  
  pinMode(M0, INPUT);//Define A0 as input mode  
  pinMode(M1, INPUT);
  pinMode(M2, INPUT);
  Serial.begin(9600);  
}  
  
void loop() {  
  //Returns the serial measurement data
  Serial.println("Soil Humidity Measurements:");
  
  int rawValue0 = analogRead(M0);
  Serial.print("Raw0: ");
  Serial.print(rawValue0);

  Serial.print(" | ");

  int friendlyValue0 = map(rawValue0, dryValue, wetValue, friendlyDryValue, friendlyWetValue);
  
  Serial.print("Friendly0: ");  
  Serial.print(friendlyValue0);

  Serial.println("%");

  int rawValue1 = analogRead(M1);
  Serial.print("Raw1: ");
  Serial.print(rawValue1);

  Serial.print(" | ");

  int friendlyValue1 = map(rawValue1, dryValue, wetValue, friendlyDryValue, friendlyWetValue);
  
  Serial.print("Friendly1: ");  
  Serial.print(friendlyValue1);

  Serial.println("%");

  int rawValue2 = analogRead(M2);
  Serial.print("Raw2: ");
  Serial.print(rawValue2);

  Serial.print(" | ");

  int friendlyValue2 = map(rawValue2, dryValue, wetValue, friendlyDryValue, friendlyWetValue);
  
  Serial.print("Friendly2: ");  
  Serial.print(friendlyValue2);

  Serial.println("%");
  delay(60 * 1000);  
} 
