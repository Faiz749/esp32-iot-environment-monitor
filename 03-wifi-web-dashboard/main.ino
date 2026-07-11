#include "DHT.h"
#include <Wire.h>
#include<Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>
#include <WiFi.h>

#define DHT_PIN 4
#define DHT_TYPE DHT11
#define LDR_PIN 34
#define LED_PIN 2 
#define BUZZER_PIN 5
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

unsigned long previousTime = 0;
unsigned long intervalTime = 2000;
float temperature = NAN;
float humidity = NAN;
int LDR_Value = 0;
String sensor_Status = "ERROR";
String Light_Status = "UNKNOWN";
String temp_status = "UNKNOWN VALUE";
String humidity_status = "UNKNOWN VALUE";

const char* name = "Wifi";
const char* password = "Password";

DHT dht(DHT_PIN,DHT_TYPE);
Adafruit_SSD1306 display(SCREEN_WIDTH,SCREEN_HEIGHT,&Wire,-1);
WiFiServer server(80);

String threshold_temperature(float temperature);
String threshold_humidity(float humidity);
String checkStatus(float temperature,float humidity);
String check_Light_status(int LDR_Value);
void show_reading_serialMonitor(float temperature,float humidity,String Sensor_Status,int LDR_Value,String Light_Status,String temp_Status, String humidity_Status);
void control_LED(String Light_Status,String sensor_Status);
void control_BUZZER(String temp_status,String humidity_status,String sensor_Status);
void OLED_check(void);
void show_OLED(float temperature,float humidity,String sensor_Status,String Light_Status);
void control_wifi(void);
void show_WebServer(float temperature,float humidity,String Sensor_Status,int LDR_Value,String Light_Status,String temp_Status, String humidity_Status, unsigned long currentTime);

void setup() {

  Serial.begin(115200);
  dht.begin();
  pinMode(LDR_PIN,INPUT);
  pinMode(LED_PIN,OUTPUT);
  pinMode(BUZZER_PIN,OUTPUT);
  OLED_check();
  control_wifi();
  server.begin();

}

void loop() {
  unsigned long currentTime = millis();
  if(currentTime - previousTime >= intervalTime){
    previousTime = currentTime;
    temperature = dht.readTemperature();
    humidity = dht.readHumidity();
    sensor_Status = checkStatus(temperature,humidity);
    LDR_Value = digitalRead(LDR_PIN);
    Light_Status = check_Light_status(LDR_Value);
    temp_status = "UNKNOWN VALUE";
    humidity_status = "UNKNOWN VALUE";
    if (sensor_Status == "OK") {
      temp_status = threshold_temperature(temperature);
      humidity_status = threshold_humidity(humidity);
    }
    show_reading_serialMonitor(temperature,humidity,sensor_Status,LDR_Value,Light_Status,temp_status,humidity_status);
    control_LED(Light_Status,sensor_Status);
    control_BUZZER(temp_status,humidity_status,sensor_Status);
    show_OLED(temperature,humidity,sensor_Status,Light_Status);
  }
  show_WebServer(temperature,humidity,sensor_Status,LDR_Value,Light_Status,temp_status,humidity_status,currentTime);
}

String checkStatus(float temperature,float humidity){
  if(isnan(temperature) || isnan(humidity)){
    return "ERROR";
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
    return "BRIGHT";
  }
  else{
    return "DARK";
  }
}

void show_reading_serialMonitor(float temperature,float humidity,String Sensor_Status,int LDR_Value,String Light_Status,String temp_Status,String humidity_Status){
    Serial.println("------------------------------------");
    Serial.print("Sensor Status: ");
    Serial.println(Sensor_Status);
    if(Sensor_Status == "OK"){
     Serial.print("Temperature: ");
     Serial.print(temperature);
     Serial.println(" C");
     Serial.print("Temperature Status: ");
     Serial.println(temp_Status);
     Serial.print("Humidity: ");
     Serial.print(humidity);
     Serial.println(" %");
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
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
    Serial.println("------------------------------------");
}

void control_LED(String Light_Status,String sensor_Status){
  
  if(Light_Status == "DARK"){
    digitalWrite(LED_PIN,HIGH);
  }
  else{
    digitalWrite(LED_PIN,LOW);
   }
  }


void control_BUZZER(String temp_status,String humidity_status,String sensor_Status){
  if(sensor_Status =="OK"){
    if(temp_status == "WARNING" || humidity_status == "HUMID"||temp_status == "DANGER"){
    digitalWrite(BUZZER_PIN,HIGH);
    }
   else{
    digitalWrite(BUZZER_PIN,LOW);
    }
  } 
  else{
    digitalWrite(BUZZER_PIN,LOW);
  }
}

void OLED_check(void){
  if(!display.begin(SSD1306_SWITCHCAPVCC,0x3c)){
    Serial.println("OLED not found");
    while(true);
    }
  }

void show_OLED(float temperature,float humidity,String sensor_status,String Light_Status){

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println("ENV MONITOR");
  display.setCursor(0,15);
  display.print("S: ");
  display.println(sensor_status);
  display.setCursor(0,30);
  if(sensor_status == "OK"){
    display.print("T: ");
    display.print(temperature,1);
    display.setCursor(64,30);
    display.print("H: ");
    display.print(humidity,1);
  }
  else{
    display.println("DHT FAILED");
  }
  display.setCursor(0,45);
  display.print("L: ");
  display.println(Light_Status);
  display.display();

}

void control_wifi(void){
  WiFi.begin(name,password);
  Serial.print("Connecting to Wifi");
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println("Connected to Wifi");
}

void show_WebServer(float temperature,float humidity,String sensor_Status,int LDR_Value,String Light_Status,String temp_status, String humidity_status,unsigned long currentTime){
  WiFiClient client = server.available();
  if(client){
    while(client.connected()){
      if(client.available()){
        String request = client.readStringUntil('\r');
        client.flush();
        client.println("HTTP/1.1 200 OK");
        client.println("Content-type:text/html");
        client.println();
        client.println("<!DOCTYPE html>");
        client.println("<html>");
        client.println("<body>");
        client.println("<h1>ESP32 Local Web Server/h1>");
        client.println("<p>Status: Online </p>");
        client.print("<p>Sensor Status: ");
        client.print(sensor_Status);
        client.println("</p>");
        if(sensor_Status == "OK"){
          client.print("<p>Temperature: ");
          client.print(temperature);
          client.println(" C</p>");
          client.print("<p>Temperature Status: ");
          client.print(temp_status);
          client.println("</p>");
          client.print("<p>Humidity: ");
          client.print(humidity);
          client.println(" %</p>");
          client.print("<p>Humidity Status: ");
          client.print(humidity_status);
          client.println("</p>");
        }
        else{
            client.println("<p> DHT11 Reading Failed</p>");
        }
        client.print("<p>Light Status: ");
        client.print(Light_Status);
        client.println("</p>");
        client.print("<p> LED Alert: ");
        if(Light_Status == "DARK"){
          client.println("ON</p>");
        }
        else{
          client.println("OFF</p>");
        }
        client.print("<p>Buzzer Alert: ");
        if(temp_status == "WARNING" || humidity_status == "HUMID"|| temp_status == "DANGER"){
          client.println("ON</p>");
        }
        else{
          client.println("OFF </p>");
        }
        client.print("<p>Uptime: ");
        client.print(currentTime/1000);
        client.println(" seconds </p>");
        client.println("</body>");
        client.println("</html>");
        break;
      }
    }
    client.stop();
  }
}
