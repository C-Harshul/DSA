#include <LiquidCrystal.h>
#include <Servo.h>
Servo myservo;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int ledPin = 8;
int pir_sensor = 7;
int pir_reader;
int buzzer = 9;
String ssid = "Simulator Wifi";     // SSID to connect to
String password = "";               // Our virtual wifi has no password
String host = "api.thingspeak.com"; // Open Weather Map API
const int httpPort = 80;
String url = "/update?api_key=ME3KEDKJ4N20TVQ2&field1=";
int slots = 10, dist;
int d1 = 0, d2 = 0;
int d1o = 0, d2o = 0;
int data;
int setupESP8266(void)
{
    // Start our ESP8266 Serial Communication
    Serial.begin(115200); // Serial connection over USB to computer
    Serial.println("AT"); // Serial connection on Tx / Rx port to ESP8266
    delay(10);            // Wait a little for the ESP to respond
    if (!Serial.find("OK"))
        return 1;
    // Connect to 123D Circuits Simulator Wifi
    Serial.println("AT+CWJAP=\"" + ssid + "\",\"" + password + "\"");
    delay(10); // Wait a little for the ESP to respond
    if (!Serial.find("OK"))
        return 2;
    / Open TCP connection to the host : Serial.println("AT+CIPSTART=\"TCP\",\"" + host + "\"," + httpPort);
    delay(50); // Wait a little for the ESP to respond
    if (!Serial.find("OK"))
        return 3;
    return 0;
}
long microsecondsToCentimeters(long microseconds)
{
    return microseconds / 58;
}
int Dist1()
{
    pinMode(6, OUTPUT);
    digitalWrite(6, LOW);
    delayMicroseconds(2);
    digitalWrite(6, HIGH);
    delayMicroseconds(5);
    digitalWrite(6, LOW);
    pinMode(6, INPUT);
    long duration, cm;
    duration = pulseIn(6, HIGH);
    cm = microsecondsToCentimeters(duration);
    // Serial.print("Distance: ");
    // Serial.print(cm);
    // Serial.println("cm");
    dist = cm;
    if (cm < 200)
    {
        return (int(1));
    }
    else
    {
        return 0;
    }
}
int Dist2()
{
    pinMode(7, OUTPUT);
    digitalWrite(7, LOW);
    delayMicroseconds(2);
    digitalWrite(7, HIGH);
    delayMicroseconds(5);
    digitalWrite(7, LOW);
    pinMode(7, INPUT);
    long duration, cm;
    duration = pulseIn(7, HIGH);
    cm = microsecondsToCentimeters(duration);
    // Serial.print("Distance: ");
    // Serial.print(cm);
    // Serial.println("cm");
    dist = cm;
    if (cm < 200)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}
void entry()
{
    slots--;
    moveservo(90);
    delay(2000);
    moveservo(0);
}
void exit()
{
    slots++;
}
void moveservo(int angle)
{
    myservo.write(angle);
}

void setup()
{
    setupESP8266();
    myservo.attach(13);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    lcd.begin(16, 2);
    lcd.setCursor(1, 0);
    lcd.print("Parking system");
    lcd.setCursor(4, 1);
    lcd.print("19BEC0052");
    delay(1000);
    lcd.clear();
}
void loop()
{
    moveservo(0);
    d1o = d1;
    d2o = d2;
    d1 = Dist1();
    d2 = Dist2();
    Serial.println("---------");
    Serial.print(d1);
    Serial.println(d2);
    Serial.println("Total slot: 10");
    Serial.print("Avaialble slot:");
    Serial.println(slots);
    Serial.println("---------");
    if (d1 == 0 && d1o == 1)
        entry();
    if (d2 == 0 && d2o == 1)
        exit();
    Serial.print('Status:');
    Serial.println(slots);

    lcd.setCursor(0, 0);
    lcd.print("Slots Remaning:");
    lcd.setCursor(0, 1);
    lcd.print(slots);
    if (slots > 0)
    {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Total Slots:10");
        lcd.setCursor(0, 1);
        lcd.print("Available:");
        lcd.print(slots);
    }
    else
    {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Parking full");
    }
    if (slots == 0)
    {
        full();
    }
    else
        allclear();
    anydata();
}
void allclear()
{
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
}
void full()
{
    digitalWrite(9, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(10, HIGH);
    delay(100);
    digitalWrite(8, LOW);
    delay(100);
}
void anydata()
{
    data = slots;
    String httpPacket = "GET " + url + String(data) + " HTTP/1.1\r\nHost: " + host + "\r\n\r\n";
    int length = httpPacket.length();
    // Send our message length
    Serial.print("AT+CIPSEND=");
    Serial.println(length);
    delay(10); // Wait a little for the ESP to respond if (!Serial.find(">")) return -1;
    // Send our http request
    Serial.print(httpPacket);
    delay(10); // Wait a little for the ESP to respond
    if (!Serial.find("SEND OK\r\n"))
        ;
}