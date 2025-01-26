#include <Wire.h>
#include <TinyGPS.h>
#include <SoftwareSerial.h>
#include <MPU6050.h>

SoftwareSerial Gsm(9, 10);          // RX, TX pins for GSM module
char phone_no[] = "+918848087420";  // Put Your phone number
TinyGPS gps;
int buttonState;
unsigned long buttonPressTime;
bool isSMSsent = false;

// Define the buzzer pin
#define BUZZER_PIN 4

// Fall detection threshold
int fallThreshold = 20000;  // Adjust this value for sensitivity

// MPU-6050 setup
MPU6050 mpu;
int16_t ax, ay, az;
float filtered_ax = 0, filtered_ay = 0, filtered_az = 0;  // Filtered accelerometer data
float alpha = 0.5;  // Smoothing factor for low-pass filter (0 < alpha < 1)

void setup() {
  Serial.begin(9600);
  Gsm.begin(9600);

  Gsm.print("AT+CMGF=1\r");
  delay(100);

  Gsm.print("AT+CNMI=2,2,0,0,0\r");
  delay(100);

  pinMode(5, INPUT_PULLUP);  // Button pin as input
  pinMode(BUZZER_PIN, OUTPUT);  // Buzzer pin as output
  digitalWrite(BUZZER_PIN, LOW);  // Ensure buzzer is off at startup

  // Initialize MPU-6050
  Wire.begin();
  mpu.initialize();
  if (!mpu.testConnection()) {
    Serial.println("MPU6050 connection failed!");
    while (1);
  }
  Serial.println("MPU6050 initialized successfully!");
}

void loop() {
  bool newData = false;
  unsigned long chars;
  unsigned short sentences, failed;

  // Read GPS data
  for (unsigned long start = millis(); millis() - start < 1000;) {
    while (Serial.available()) {
      char c = Serial.read();
      Serial.print(c);  // Output GPS data to the Serial Monitor
      if (gps.encode(c))
        newData = true;  // Check if there is new GPS data
    }
  }

  // Read raw accelerometer data from MPU-6050
  mpu.getAcceleration(&ax, &ay, &az);

  // Apply low-pass filter
  filtered_ax = alpha * ax + (1 - alpha) * filtered_ax;
  filtered_ay = alpha * ay + (1 - alpha) * filtered_ay;
  filtered_az = alpha * az + (1 - alpha) * filtered_az;

  // Calculate magnitude using filtered accelerometer data
  int accelerationMagnitude = filtered_ax * filtered_ax + filtered_ay * filtered_ay + filtered_az * filtered_az;

  // Check for fall detection
  if (accelerationMagnitude > fallThreshold) {  // Fall detected
    if (!isSMSsent) {
      sendSMS();  // Send SMS with GPS location
      buzz();  // Activate buzzer
      isSMSsent = true;
    }
  } else {
    isSMSsent = false;
  }

  // Check for button press to send manual help request
  buttonState = digitalRead(5);
  if (buttonState == LOW) {  // Button is pressed
    if (!isSMSsent) {
      buttonPressTime = millis();

      float flat, flon;
      unsigned long age;
      gps.f_get_position(&flat, &flon, &age);

      Gsm.print("AT+CMGF=1\r");
      delay(400);
      Gsm.print("AT+CMGS=\"");
      Gsm.print(phone_no);
      Gsm.println("\"");
      Gsm.println("Alert! I need help...");
      Gsm.print("http://maps.google.com/maps?q=loc:");
      Gsm.print(flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat, 6);
      Gsm.print(",");
      Gsm.print(flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon, 6);
      delay(200);
      Gsm.println((char)26);  // ASCII for Ctrl+Z to send message
      delay(200);
      Serial.println("SMS Sent");

      // Activate the buzzer for 1 second
      buzz();

      isSMSsent = true;
    }
  } else {
    isSMSsent = false;
    delay(10);
  }

  Serial.println(failed);
}

// Function to control the buzzer
void buzz() {
  digitalWrite(BUZZER_PIN, HIGH);  // Turn the buzzer ON
  delay(1000);                     // Keep the buzzer ON for 1 second
  digitalWrite(BUZZER_PIN, LOW);   // Turn the buzzer OFF
}

// Function to send emergency SMS with GPS location
void sendSMS() {
  float flat, flon;
  unsigned long age;
  gps.f_get_position(&flat, &flon, &age);

  Gsm.print("AT+CMGF=1\r");
  delay(400);
  Gsm.print("AT+CMGS=\"");
  Gsm.print(phone_no);
  Gsm.println("\"");
  Gsm.println("Alert! Fall detected...");
  Gsm.print("http://maps.google.com/maps?q=loc:");
  Gsm.print(flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat, 6);
  Gsm.print(",");
  Gsm.print(flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon, 6);
  delay(200);
  Gsm.println((char)26);  // ASCII for Ctrl+Z to send message
  delay(200);
  Serial.println("SMS Sent");
}