#include "DHT.h"

#define DHT_PIN 4
#define DHT_TYPE DHT11
#define LDR_PIN 34

unsigned long previousTime = 0;
unsigned long intervalTime = 2000;

DHT dht(DHT_PIN,DHT_TYPE);

String threshold_temperature(float temperature);
String threshold_humidity(float humidity);
String checkStatus(float temperature,float humidity);
String check_Light_status(int LDR_Value);
void show_reading_serialMonitor(float temperature,float humidity,String Sensor_Status,int LDR_Value,String Light_Status,String temp_Status, String humidity_Status);

void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(LDR_PIN,INPUT);
  Serial.println("ESP32 IoT Environment Monitor - Day 1");
}

void loop() {
  unsigned long currentTime = millis();
  if(currentTime - previousTime >= intervalTime){
    previousTime = currentTime;
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();
    String Sensor_Status = checkStatus(temperature,humidity);
    int LDR_Value = digitalRead(LDR_PIN);
    String Light_Status = check_Light_status(LDR_Value);
    String temp_status = threshold_temperature(temperature);
    String humidity_status = threshold_humidity(humidity);
    show_reading_serialMonitor(temperature,humidity,Sensor_Status,LDR_Value,Light_Status,temp_status,humidity_status);
  }
}

String checkStatus(float temperature,float humidity){
  if(isnan(temperature) || isnan(humidity)){
    return "Error";
  }
  else{
    return "OK";
  }
}

String threshold_humidity(float humidity){
  if(humidity < 30){
    return "DRY";
  }
  else if(humidity >=30 && humidity<=70){
    return "SAFE";
  }
  else{
    return "HUMID";
  }
}


String threshold_temperature(float temperature){
  if(temperature < 35){
    return "SAFE";
  }
  else if(temperature >=35 && temperature < 40){
    return "WARNING";
  }
  else{
    return "DANGER";
  }
}

String check_Light_status(int LDR_Value){
  if(LDR_Value == 0){
    return "Bright";
  }
  else{
    return "Dark";
  }
}

void show_reading_serialMonitor(float temperature,float humidity,String Sensor_Status,int LDR_Value,String Light_Status,String temp_Status,String humidity_Status){
    Serial.println("------------------------------------");
    Serial.print("Sensor Status: ");
    Serial.println(Sensor_Status);
    if(Sensor_Status == "OK"){
     Serial.print("Temperature: ");
     Serial.print(temperature);
     Serial.println("C");
     Serial.print("Temperature Status: ");
     Serial.println(temp_Status);
     Serial.print("Humidity: ");
     Serial.print(humidity);
     Serial.println("%");
     Serial.print("Humidity Status: ");
     Serial.println(humidity_Status);
    }
    else{
    Serial.println("DHT11 reading failed");
    }
    Serial.print("LDR Value: ");
    Serial.println(LDR_Value);
    Serial.print("Light Status: ");
    Serial.println(Light_Status);
    Serial.println("------------------------------------");
}
  