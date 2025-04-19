#include<SoftwareSerial.h>
SoftwareSerial gsm (10,11);

String txt1 = "";
String txt2 = "";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 
  Serial.println("Testing Sim800l");
  gsm.begin(9600);
  gsm.println("AT");
  delay(100);
  if(gsm.available())
  {
    Serial.println(gsm.readString());
  }
    gsm.println("AT+CMGF=1");           //AT+CNMI=1,2,0,0,0
    delay(200);
    gsm.println("AT+CNMI=1,2,0,0,0");   //AT+CNMI=1,2,0,0,0
    delay(200);

}

void loop() {
  
 if(gsm.available())
 {
    txt1 = gsm.readString();
    Serial.println(txt1);

      String number = txt1.substring(18,31);
      Serial.println("FROM=>"+number);
    if(number == "YOUR NUMBER")
    {
      gsm.println("ATA");
      delay(2000);
    }
    else
    {
      gsm.println("ATH");
    }
 }
   
    if(Serial.available())
  {
    txt2 = Serial.readString();
    gsm.println("AT+CMGS=\"YOUR NUMBER\"");
    delay(200);
    gsm.println(txt2);
    delay(200);
    gsm.write(26);
  }
}
