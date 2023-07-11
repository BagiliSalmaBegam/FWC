#include <Arduino.h>
#ifdef ESP32
  #include <WiFi.h>
  #include <AsyncTCP.h>
#else
  #include <ESP8266WiFi.h>
  #include <ESPAsyncTCP.h>
#endif
#include <ESPAsyncWebServer.h>
#include"libr.h"

AsyncWebServer server(80);

const char* ssid = "vivo1726";
const char* password = "salma1234";

const char* input_parameter00 = "input00";
const char* input_parameter01 = "input01";
const char* input_parameter10 = "input10";
const char* input_parameter11 = "input11";
const char* matrix1[2]={input_parameter00,input_parameter01};
const char* matrix2[2]={input_parameter10,input_parameter11};

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html><head>
  <title>POSITIONVECTOR</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    html {font-family: Times New Roman; display: inline-block; text-align: center;}
    h2 {font-size: 2.0rem; color: blue;}
  </style> 
  </head><body>
  <h2>TO FIND POSITION VECTOR</h2> 
  <p>Enter the values of points P,Q
  <form action="/get">
    Enter the values of Point P: <input type="number" name="input00"><br><input type="number" name="input01"><br>
    Enter the values of Point Q: <input type="number" name="input10"><br><input type="number" name="input11"><br>
    <input type="submit" value="Submit">
    

  </form><br>
</body></html>)rawliteral";

void notFound(AsyncWebServerRequest *request) {
  request->send(404, "text/plain", "Not found");
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connecting...");
    return;
  }
  Serial.println();
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html);
  });

  server.on("/get", HTTP_GET, [] (AsyncWebServerRequest *request) {
    double **P,**Q,**r1;
    double m=2,n=1;
    P=load_ser(request,matrix1);
    Q=load_ser(request,matrix2);
    scalarmul(2,P);
    r1=linalg_sub(Q,P,m,n);
    scalarmul(-1,r1);
	request->send(200, "text/html", "The position matrix of P and Q is<b>" + r1[0][0] +" " r1[1][0]+" <br><a href=\"/\">Return to Home Page</a>") 




  });
  server.onNotFound(notFound);
  server.begin();
}

void loop() {
  
}
