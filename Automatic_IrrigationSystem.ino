int sensor_pin = A0; // Soil Sensor input at Analog Pin A0
int relay_pin = 4;  // Relay - Pin 4
int sensor_pin_2 = A5;  // Water level Sensor input at Analog Pin A1
int led = 7;  // LED - Pin 7
int humidity_value;
int depth_value = 0;

void setup() {

   pinMode(sensor_pin,INPUT); 
   pinMode(sensor_pin_2,INPUT); 
   pinMode(relay_pin,OUTPUT); 
   Serial.begin(9600); 
   Serial.println("Reading From the Sensor ...");

}

 void loop() {
  
   humidity_value = analogRead(sensor_pin); 
   depth_value = analogRead(sensor_pin_2);
   humidity_value = map(humidity_value,550,10,0,100); 
   
  
   if(humidity_value<0){
      digitalWrite(relay_pin,LOW); // motor off
     }
   else{
      digitalWrite(relay_pin,HIGH); // motor on
       }
   
   if(depth_value<280){
      digitalWrite(led,HIGH); // led on
     }
   else{
      digitalWrite(led,LOW); // led off
       }
       
   
}
