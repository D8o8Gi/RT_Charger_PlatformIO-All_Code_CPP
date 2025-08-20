// #include <WiFi.h>
// #include <ArduinoOTA.h>

// const char* ssid = "Dalai-5G";
// const char* password = "dalia2025";

// void setup_OTA() {
//   Serial.begin(115200);

//   WiFi.begin(ssid, password);
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }
//   Serial.println("WiFi connected");

//   ArduinoOTA.setHostname("RT_Charger");

//   ArduinoOTA.onStart([]() {
//     Serial.println("Start OTA update");
//   });
//   ArduinoOTA.onEnd([]() {
//     Serial.println("\nEnd OTA update");
//   });
//   ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
//     Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
//   });
//   ArduinoOTA.onError([](ota_error_t error) {
//     Serial.printf("Error[%u]: ", error);
//   });

//   ArduinoOTA.begin();
//   Serial.println("OTA Ready");
// }

// void loop_OTA() {
//   ArduinoOTA.handle();
//   // Servo, motor, control logic энд үргэлжилнэ
// }
