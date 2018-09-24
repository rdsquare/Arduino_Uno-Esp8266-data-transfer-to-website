#include "SoftwareSerial.h"
String ssid="YOUR_WIFI_SSID"; // wifi name change to yours
String password="YOUR_WIFI_PASSWORD"; // wifi password change to yours
SoftwareSerial esp(6,7); // esp(RX_pin, TX_pin) you can change it
String data;
String server = "feathery-glues.000webhostapp.com"; //Change to whatever your website name is
String uri="/esp8266.php"; // Change scipt to yours 
String nam, rollno;

void setup() {
  esp.begin(115200);
  Serial.begin(9600);
  reset(); //reset the wifi module
  connectWifi(); //connecting to the wifi
}

void loop() {
  nam =  "Rahul";
  rollno = "cse014";
  data  = "myname="+nam+"&rollno="+rollno; //data sent to server
  httppost();
  delay(10000);
}

//sending post request to server
void httppost() {
  esp.println("AT+CIPSTART=\"TCP\",\""+server+"\",80"); //start a 
  //tcp connection with server
  if(esp.find("OK")){
    Serial.println("TCP Connection ready");
  }
  delay(1000);
  String postRequest = 
  "POST " + uri + "HTTP/1.0\r\n" + 
  "Host: " + server + "\r\n" + 
  "Accept: *"+"/"+"*\r\n"  +
  "Content-Length: " + data.length() + "\r\n"+
  "Content-Type: application/x-www-form-urlencoded\r\n" +
  "\r\n" + data;
  String sendCmd = "AT+CIPSEND=";
  esp.print(sendCmd);
  esp.println(postRequest.length());
  delay(500);

  if(esp.find(">")) {
    Serial.println("Sending...");
  esp.print(postRequest);
  if(esp.find("SEND OK")) {
    Serial.println("Packet sent.");
    esp.println("AT+CIPCLOSE");
  }
  }
}

//reset the esp8266 module
void reset() {
  esp.println("AT+RST");
  delay(1000);
  if(esp.find("OK")) Serial.println("Module Reset");
}

//connect esp8266 with wifi

void connectWifi() {
  String cmd="AT+CWJAP=\""+ssid+"\",\""+password+"\"";
  esp.println(cmd);
  delay(4000);
  if(esp.find("OK")){
    Serial.println("Connected to the " + ssid + " wifi...");
  } else {
    Serial.println("Cannot connect to " + ssid + " wifi...");
    Serial.println("Reconnecting....");
    connectWifi();
  }
}

