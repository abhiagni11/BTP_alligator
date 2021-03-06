/*
Measuring Current Using ACS712
*/
const int analogIn = A0;
int mVperAmp = 100; // use 100 for 20A Module and 66 for 30A Module
int RawValue= 0;
int ACSoffset = 2500; 
double Voltage = 0;
double mAmps = 0;

void setup(){ 
 Serial.begin(9600);
}

void loop(){
 
 RawValue = analogRead(analogIn);
 Voltage = (RawValue / 1024.0) * 5000; // Gets you mV
 mAmps = ((Voltage - ACSoffset) / mVperAmp)*1000;
 
 
 //Serial.print("Raw Value = " ); // shows pre-scaled value 
 //Serial.print(RawValue); 
 //Serial.print("\t mV = "); // shows the voltage measured 
 //Serial.print(Voltage,3); // the '3' after voltage allows you to display 3 digits after decimal point
 //Serial.print("\t Amps = "); // shows the voltage measured 
 Serial.println(mAmps,3); //in milliamps// the '3' after voltage allows you to display 3 digits after decimal point
 delay(10); 
 
}
