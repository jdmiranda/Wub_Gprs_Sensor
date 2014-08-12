#include <TinkerKit.h>
#include <SoftwareSerial.h>
#include <SPI.h>


SoftwareSerial mySerial(7,8);
int newStatus = 0;
int oldStatus = 0;
boolean changeStatus = false;
TKButton button1(I0);
TKButton button2(I1);
TKLed ledRed(O0);
TKLed ledGreen(O1);

void setup() 
{
  mySerial.begin(19200);
  Serial.begin(19200);
  delay(500);
}

void loop()
{
  
  if (Serial.available())
    Serial.read();
    {
     // BridgeUp();
      SubmitHttpRequest();
     /*
     if (button1.toggle()==HIGH)
     {
     ledGreen.on();
     ledRed.off();
     BridgeDown();
     delay(100);
     Serial.println("Bridge down");
     }
     if (button1.toggle()==LOW)
     {
     ledRed.on();
     ledGreen.off();
     BridgeUp();
     delay(100);
     Serial.println("Bridge up");
     }
     delay(30000);
  */
   }
    
    if (mySerial.available())
          Serial.write(mySerial.read());
          
}
void BridgeDown()
{
  mySerial.println("AT+CSQ");
  delay(100);
  
  ShowSerialData();
  
  mySerial.println("AT+CGATT?");
  delay(100);
  
  ShowSerialData();
  
  mySerial.println("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"");
  delay(1000);
  
  mySerial.println("AT+SAPBR=3,1,\"APN\",\"CMNET\"");
  delay(4000);
  
  ShowSerialData();
  
  mySerial.println("AT+SAPBR=1,1");
  delay(2000);
  
  ShowSerialData();
  
  mySerial.println("AT+HTTPINIT");
  delay(2000);
  
  ShowSerialData();
  
  mySerial.println("AT+HTTPPARA=\"URL\",\"whatupbridge.com\"");
  delay(1000);
  
  ShowSerialData();
  
  mySerial.println("AT+HTTPACTION=2");
  delay(10000);
  
  ShowSerialData();
  
  mySerial.println("what=mngDevice.DeviceUpdateBridgeStatus&did=69887458-5deg-58edk-k56t-4587r8ft925&status=0");
  
  delay(1000);
  
  ShowSerialData();
  
  
}

void BridgeUp()
{
  mySerial.println("AT+CSQ");
  delay(100);
  
  ShowSerialData();
  
  mySerial.println("AT+CGATT?");
  delay(100);
  
  ShowSerialData();
  
  mySerial.println("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"");
  delay(1000);
  
  mySerial.println("AT+SAPBR=3,1,\"APN\",\"CMNET\"");
  delay(4000);
  
  ShowSerialData();
  
  //mySerial.println("AT+SAPBR=1,1");
  //delay(2000);
  
  ShowSerialData();
  
  mySerial.println("AT+HTTPINIT");
  delay(2000);
  
  ShowSerialData();
  
  mySerial.println("AT+HTTPPARA=\"URL\",\"whatupbridge.com\"");
  delay(1000);
  
  ShowSerialData();
  
  mySerial.println("AT+HTTPACTION=2");
  delay(10000);
  
  ShowSerialData();
  
  mySerial.println("?what=mngDevice.DeviceUpdateBridgeStatus&did=69887458-5deg-58edk-k56t-4587r8ft925&status=1");
  
  delay(1000);
  
  ShowSerialData();
  
  
}
void SubmitHttpRequest()
{
  mySerial.println("AT+CSQ");
  delay(100);
 
  ShowSerialData();// this code is to show the data from gprs shield, in order to easily see the process of how the gprs shield submit a http request, and the following is for this purpose too.
 
  mySerial.println("AT+CGATT?");
  delay(100);
 
  ShowSerialData();
 
  mySerial.println("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"");//setting the SAPBR, the connection type is using gprs
  delay(1000);
 
  ShowSerialData();
 
  mySerial.println("AT+SAPBR=3,1,\"APN\",\"CMNET\"");//setting the APN, the second need you fill in your local apn server
  delay(4000);
 
  ShowSerialData();
 
  mySerial.println("AT+SAPBR=1,1");//setting the SAPBR, for detail you can refer to the AT command mamual
  delay(2000);
 
  ShowSerialData();
 
  mySerial.println("AT+HTTPINIT"); //init the HTTP request
 
  delay(2000); 
  ShowSerialData();
 
  mySerial.println("AT+HTTPPARA=\"URL\",\"whatupbridge.com\"");// setting the httppara, the second parameter is the website you want to access
  delay(1000);
 
  ShowSerialData();
 
  mySerial.println("AT+HTTPACTION=1");//submit the request 
  delay(10000);//the delay is very important, the delay time is base on the return from the website, if the return datas are very large, the time required longer.
  //while(!mySerial.available());
 
  ShowSerialData();
 mySerial.println("what=mngDevice.DeviceUpdateBridgeStatus&did=69887458-5deg-58edk-k56t-4587r8ft925&status=1");
  
  //mySerial.println("AT+HTTPREAD");// read the data from the website you access
  delay(300);
 
  ShowSerialData();
 mySerial.println("AT+HTTPTERM");
  mySerial.println("");
  delay(100);
}
void ShowSerialData()
{
  while(mySerial.available()!=0)
    Serial.write(mySerial.read());
    Serial.println("");
}
  

