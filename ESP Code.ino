#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <Wire.h>

// Replace with your credentials
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";
const char* authToken = "YOUR_BLYNK_AUTH_TOKEN";

// Sensor pins
#define pH_PIN A0
#define TURBIDITY_PIN A1

// Calibration values (adjust based on sensor calibration)
const float pH_OFFSET = 0.0; // Example: pH 7 = 2.5V
const float TURBIDITY_OFFSET = 0.0;

void setup() {
  Serial.begin(115200);
  Blynk.begin(authToken, ssid, password);

  // Initialize sensors
  pinMode(pH_PIN, INPUT);
  pinMode(TURBIDITY_PIN, INPUT);
}

void loop() {
  Blynk.run();

  // Read pH (analog voltage)
  float pHValue = analogRead(pH_PIN) * (5.0 / 4095.0); // Convert to voltage
  pHValue = map(pHValue, 0, 5, 0, 14); // Map voltage to pH scale (calibrate as needed) <button class="citation-flag" data-index="2">

  // Read turbidity (NTU)
  float turbidityValue = analogRead(TURBIDITY_PIN); // Raw ADC value
  turbidityValue = turbidityValue * (5.0 / 4095.0); // Convert to voltage <button class="citation-flag" data-index="7">

  // Read dissolved oxygen (via I2C, example code)
  float doValue = readDO(); // Placeholder for DO sensor integration <button class="citation-flag" data-index="8">

  // Send data to Blynk
  Blynk.virtualWrite(V1, pHValue);
  Blynk.virtualWrite(V2, turbidityValue);
  Blynk.virtualWrite(V3, doValue);

  Serial.println("pH: " + String(pHValue) + " | Turbidity: " + String(turbidityValue) + " | DO: " + String(doValue));
  delay(5000); // Adjust for real-time updates
}

float readDO() {
  // Example I2C communication for dissolved oxygen sensor (SEN0321)
  Wire.beginTransmission(0x70); // Default I2C address for SEN0321
  Wire.write(0x01); // Command to read DO value
  Wire.endTransmission();
  Wire.requestFrom(0x70, 2);
  byte msb = Wire.read();
  byte lsb = Wire.read();
  return (msb << 8 | lsb) / 100.0; // Example conversion <button class="citation-flag" data-index="8">
}
