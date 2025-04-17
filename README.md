Dưới đây là **README** cho dự án **Streetlight-Thingsboard_ESP32** của bạn, bao gồm các phần với **3 ảnh minh họa**: **mạch điện**, **kết quả terminal**, và **trực quan hóa trên dashboard ThingsBoard**.

---

# Streetlight-Thingsboard_ESP32

A smart streetlight project using **ESP32** and **ThingsBoard** to monitor ambient light, control light status automatically or manually, and send real-time telemetry via MQTT/HTTP.

## Features:
- **Automatic Control**: Turns the light ON/OFF based on ambient light levels (using an LDR sensor).
- **Manual Control**: Allows remote control of the light via a dashboard switch on ThingsBoard.
- **Telemetry**: Sends ambient light level and status ("ON"/"OFF") to ThingsBoard.
- **Visualization**: Real-time data visualization on the ThingsBoard dashboard.

---

## 1. Connect a Streetlight Device to ThingsBoard

### Steps:

**a) Create a new Device on ThingsBoard**  
- Go to your **ThingsBoard** instance and create a new device (e.g., "Streetlight-001").
- Generate the **access token** for the device to authenticate the connection.

**b) Generate the Access Token**  
- Copy the access token generated in the ThingsBoard device page.

**c) On Your Device (ESP32)**  
- Read the **LDR sensor** data to measure the ambient light.
- If brightness is below a certain threshold, consider it "night" and turn the light ON.

**d) Send Telemetry to ThingsBoard via MQTT or HTTP**  
- Send the telemetry data in the following format:

```json
{
  "ambient_light": 150,
  "status": "ON"
}
```

**e) Visualize Data on a Dashboard**  
- Create a **ThingsBoard dashboard** to visualize the telemetry data such as **ambient light** and **status**.

---

## Circuit Diagram

Below is the **circuit diagram** showing how the **ESP32** is connected to the **LDR sensor** and other components (e.g., LED, power supply).

![Circuit Diagram](/output/circuit.png)

---

## Terminal Output

Here is an example of the **terminal output** when the ESP32 sends telemetry data to ThingsBoard via MQTT or HTTP:

```bash
MQTT Connected to ThingsBoard
Sending Telemetry:
{
  "ambient_light": 150,
  "status": "ON"
}
```

![Terminal Output](/output/terminal.png)

---

## ThingsBoard Dashboard Visualization

The ThingsBoard dashboard allows you to visualize real-time data such as **ambient light levels**, **light status (ON/OFF)**, and other telemetry values.

Below is an example of the **ThingsBoard dashboard** that shows the real-time data:

![ThingsBoard Dashboard](/output/dashboard.png)

---

## Conclusion

This project demonstrates how to connect an **ESP32** to **ThingsBoard** and create a **smart streetlight system** that reacts to changes in ambient light and allows manual control through the ThingsBoard dashboard.

---

### Requirements:
- **ESP32** development board
- **LDR Sensor**
- **ThingsBoard** account
- **MQTT/HTTP client** on the ESP32

---
