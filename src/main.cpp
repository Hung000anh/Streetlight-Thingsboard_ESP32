#include <WiFi.h>
#include <PubSubClient.h>

#define WIFI_SSID "Wokwi-GUEST"
#define WIFI_PASSWORD ""
#define TOKEN "muVXtktIfnk1WchCUXgD"
#define THINGSBOARD_SERVER "thingsboard.cloud"
#define THRESHOLD 800

const int LDR = 34; 
const int LED = 5;

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  Serial.print("Kết nối WiFi...");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" Đã kết nối WiFi!");
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Đang kết nối ThingsBoard...");
    if (client.connect("ESP32Client", TOKEN, NULL)) {
      Serial.println(" Thành công!");
    } else {
      Serial.print(" Thất bại, mã lỗi = ");
      Serial.print(client.state());
      Serial.println(". Thử lại sau 5 giây.");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  setup_wifi();
  client.setServer(THINGSBOARD_SERVER, 1883);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  int input_val = analogRead(LDR);
  Serial.print("LDR value is: ");
  Serial.println(input_val);

  String status;

  if (input_val > THRESHOLD) {
    status = "HIGH";
    digitalWrite(LED, HIGH);
  } else {
    status = "LOW";
    digitalWrite(LED, LOW);
  }

  // Tạo payload JSON
  String payload = "{";
  payload += "\"ambient_light\":" + String(input_val) + ",";
  payload += "\"status\":\"" + status + "\"";
  payload += "}";

  Serial.println("Gửi dữ liệu: " + payload);
  client.publish("v1/devices/me/telemetry", payload.c_str());

  delay(1000);  // Gửi mỗi 5 giây
}
