/* 
  Sketch generated by the Arduino IoT Cloud Thing "Untitled"
  https://create.arduino.cc/cloud/things/a8b2aad9-4605-405a-8dec-daf5db645194 

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  String sensor;
  CloudSwitch socket1;
  CloudSwitch socket2;
  int socket;
  CloudSchedule schde;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"
#include <DHT11.h>

// Variable to store the UID of the last scanned card

int S1 = 16;
int S2 = 5;
int S3 = 4;
int S4 = 2;
int IR = 12;
int LDR = 13;


DHT11 dht11(14);

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(115200);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  // delay(1500); 
  pinMode(IR, INPUT);
  pinMode(LDR, INPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(S4, OUTPUT);
  
  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}


void loop() {
  ArduinoCloud.update();
  // Your code here 
  if(schde.isActive()){
    if(socket1)
      digitalWrite(S1, LOW);
    else 
      digitalWrite(S1, HIGH);
  }
  else{
    if(socket1)
      digitalWrite(S1, HIGH);
    else 
      digitalWrite(S1, LOW);
  }
  
  
  int Select1=S1;
  if(socket==2)
  {
    Select1=S2;
  }
   else if(socket==3)
  {
    Select1=S3;
  }
   else if(socket==4)
  {
    Select1=S4;
  }
  // Add your code here to act upon Sensor change
 if (sensor == "temp") {
        int temp = 0;
        float result = dht11.readTemperature();
        if (temp > 30){
          digitalWrite(Select1, HIGH);
          Serial.println("temperature=");
          Serial.println(result);
        }
        else{
          digitalWrite(Select1, LOW);
        }
      }
      else if (sensor == "ldr"){
        int light = digitalRead(LDR);

        Serial.println(light);
        if (light){
          digitalWrite(Select1, HIGH);
        }
        else {
          digitalWrite(Select1, LOW);
        }
      }
      else if (sensor == "ir"){
         int motion = digitalRead(IR);
        Serial.println(motion);
        if(motion){
          digitalWrite(Select1, HIGH);
        }
        else{
          digitalWrite(Select1, LOW);
        }
      }
}


/*
  Since Socket1 is READ_WRITE variable, onSocket1Change() is
  executed every time a new value is received from IoT Cloud.
*/
void onSocket1Change()  {
  // Add your code here to act upon Socket1 change
  if(socket1)
    digitalWrite(S1, HIGH);
  else 
    digitalWrite(S1, LOW);
}

/*
  Since Socket2 is READ_WRITE variable, onSocket2Change() is
  executed every time a new value is received from IoT Cloud.
*/
void onSocket2Change()  {
  // Add your code here to act upon Socket2 change
  if(socket2)
    digitalWrite(S2, HIGH);
  else 
    digitalWrite(S2, LOW);
    
}

/*
  Since Schde is READ_WRITE variable, onSchdeChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onSchdeChange()  {
  // Add your code here to act upon Schde change
}




















/*
  Since Socket is READ_WRITE variable, onSocketChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onSocketChange()  {
  // Add your code here to act upon Socket change
}

/*
  Since Sensor is READ_WRITE variable, onSensorChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onSensorChange()  {
  // Add your code here to act upon Sensor change
}