#include "CTBot.h"  //Pendeklarasian Library
CTBot myBot;

String ssid = "Veendy-Suseno";    //nama ssid wifi kalian
String pass = "Admin12345";  //password wifi kalian
String token = "XXXX";    //token bot baru kalian
const int id = XXXX;      //id telegram kalian

#define ledPin D7  // Pemilihan Pin dan pendeklarasian variabel
#define pirPin D1 
int pirValue; 

void setup(){  //Pengaturan Pin dan Variabel
    Serial.begin(9600);
    Serial.println("Starting TelegramBot...");
    myBot.wifiConnect(ssid, pass);
    myBot.setTelegramToken(token);
    if (myBot.testConnection()) {
        Serial.println("Koneksi Bagus");
    } else {
        Serial.println("Koneksi Jelek");
    }
    pinMode(ledPin, OUTPUT);
    pinMode(pirPin, INPUT);
    digitalWrite(ledPin, LOW);
}

void loop(){ //Perulangan Program
    pirValue = digitalRead(pirPin);
    digitalWrite(ledPin, pirValue);
    if (pirValue == HIGH)  //Apabila Terdeteksi Gerakan
    { 
        Serial.println("Gerakan terdeteksi");
        myBot.sendMessage(id, "Gerakan terdeteksi");
    }
    delay(100);
}
